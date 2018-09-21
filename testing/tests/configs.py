# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for validating error handling with configs set in ``conf.py``.
"""
from __future__ import unicode_literals
import re
import textwrap

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides


def assert_message_not_present(test, message, text, flags=0):
    """
    Assert that ``message`` **is** found in ``text``.

    This method is useful for creating consistent error messages when a test fails,
    including printing out what the contents of ``message`` and ``text`` were.

    **Parameters**

    ``test`` (:class:`ExhaleTestCase <testing.base.ExhaleTestCase>`)
        The test case to call ``assertTrue`` with, should just be ``self`` for most test
        cases in the framework.

    ``message`` (:class:`python:str`)
        The message to search for in ``text``.  This will be the ``pattern`` parameter
        for a call to :func:`python:re.search`.

    ``text`` (:class:`python:str`)
        The text to be searched.  This will be the ``string`` parameter for a call to
        :func:`python:re.search`.

    ``flags`` (:class:`python:int`)
        Optional flags to supply as ``flags`` to :func:`python:re.search`.  Default of
        ``0`` means no special flags sent.
    """
    test.assertTrue(
        re.search(message, text, flags) is None,
        textwrap.dedent('''\
            Sphinx message stream contained '{message}' but should not have.

            Stream contents:
            {vsep}
            {text}
            {vsep}
        ''').format(
            message=message, vsep=("*" * 44), text=text
        )
    )


def assert_message_present(test, message, text, flags=0):
    """
    Assert that ``message`` is **not** found in ``text``.

    This method is useful for creating consistent error messages when a test fails,
    including printing out what the contents of ``message`` and ``text`` were.

    **Parameters**

    ``test`` (:class:`ExhaleTestCase <testing.base.ExhaleTestCase>`)
        The test case to call ``assertTrue`` with, should just be ``self`` for most test
        cases in the framework.

    ``message`` (:class:`python:str`)
        The message to search for in ``text``.  This will be the ``pattern`` parameter
        for a call to :func:`python:re.search`.

    ``text`` (:class:`python:str`)
        The text to be searched.  This will be the ``string`` parameter for a call to
        :func:`python:re.search`.

    ``flags`` (:class:`python:int`)
        Optional flags to supply as ``flags`` to :func:`python:re.search`.  Default of
        ``0`` means no special flags sent.
    """
    test.assertTrue(
        re.search(message, text, flags) is not None,
        textwrap.dedent('''\
            Sphinx message stream did not contain '{message}' but should have.

            Stream contents:
            {vsep}
            {text}
            {vsep}
        ''').format(
            message=message, vsep=("*" * 44), text=text
        )
    )


class ConfigurationStatusTests(ExhaleTestCase):
    """
    Tests to ensure expected status messages are displayed.
    """

    test_project = "cpp_nesting"
    """
    .. testproject:: cpp_nesting

    .. note::

        The ``cpp_nesting`` project is just being recycled, the tests for that project
        take place in
        :class:`CPPNesting <testing.tests.cpp_nesting.CPPNesting>`.
    """

    treeview_add_start_message = r"Exhale: adding tree view css / javascript\."
    """
    Start message displayed only when :data:`createTreeView <exhale.configs.createTreeView>` is ``True``.
    """

    treeview_add_close_message = r"Exhale: added tree view css / javascript\."
    """
    Closing message displayed only when :data:`createTreeView <exhale.configs.createTreeView>` is ``True``.
    """

    def test_no_treeview(self):
        """
        Verify no notification for adding CSS / JavaScript issued when no Tree View requested.
        """
        sphinx_status = self.app._status.getvalue()
        assert_message_not_present(self, self.treeview_add_start_message, sphinx_status)
        assert_message_not_present(self, self.treeview_add_close_message, sphinx_status)

    @confoverrides(exhale_args={"createTreeView": True})
    def test_treeview(self):
        """
        Verify notification for adding CSS / JavaScript issued when Tree View requested.
        """
        sphinx_status = self.app._status.getvalue()
        assert_message_present(self, self.treeview_add_start_message, sphinx_status)
        assert_message_present(self, self.treeview_add_close_message, sphinx_status)


class ConfigurationWarningTests(ExhaleTestCase):
    """
    Tests to ensure non-fatal configuration discrepancies receive warnings.
    """

    test_project = "cpp_nesting"
    """
    .. testproject:: cpp_nesting

    .. note::

        The ``cpp_nesting`` project is just being recycled, the tests for that project
        take place in
        :class:`CPPNesting <testing.tests.cpp_nesting.CPPNesting>`.
    """

    @confoverrides(exhale_args={"createTreeView": False, "treeViewIsBootstrap": True})
    def test_treeview_mismatch(self):
        """
        Verify warning issued with ``createTreeView=False`` but ``treeViewIsBootstrap=True``.
        """
        sphinx_warnings = self.app._warning.getvalue()
        expected = "Exhale: `treeViewIsBootstrap=True` ignored since `createTreeView=False`"
        self.assertTrue(
            expected in sphinx_warnings,
            "Sphinx Warnings did not contain '{0}'.".format(expected)
        )
