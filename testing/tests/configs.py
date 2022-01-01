# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
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

import pytest
from sphinx.errors import ConfigError

from testing import get_exhale_root
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


class ListingExcludeTests(ExhaleTestCase):
    """Test for expected failures when invalid configurations are given in ``conf.py``."""

    test_project = "cpp_nesting"
    """
    .. testproject:: cpp_nesting

    .. note::

        The ``cpp_nesting`` project is just being recycled, the tests for that project
        take place in
        :class:`CPPNesting <testing.tests.cpp_nesting.CPPNesting>`.
    """

    class BadStr(object):
        """
        Helper for :func:`ListingExcludeTests.test_invalid_report_index`.
        """

        def __str__(self):
            """Raise :class:`python:AttributeError`."""
            raise AttributeError("No string for you!")

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"listingExclude item at index 1 cannot be unpacked as `pattern, flags = item`:"
    )
    @confoverrides(exhale_args={
        "listingExclude": [r"valid", BadStr()]
    })
    def test_invalid_report_index(self):
        """Verify list index is indicated when item cannot be converted to string."""
        pass

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"Unable to compile specified listingExclude"
    )
    @confoverrides(exhale_args={
        "listingExclude": [(r"some_string", "an invalid flag")]
    })
    def test_invalid_regex_flags(self):
        """Verify invalid regex ``flags`` are rejected."""
        pass

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"Unable to compile specified listingExclude"
    )
    @confoverrides(exhale_args={
        "listingExclude": [
            r"valid", r"*I don't compile$"
        ]
    })
    def test_bad_regex(self):
        """Verify string pattern that does not compile is gracefully rejected."""
        pass

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"listingExclude item .* cannot be unpacked as `pattern, flags = item`:"
    )
    @confoverrides(exhale_args={
        "listingExclude": [
            r"valid",
            (r"valid", 0),
            (r"invalid", 0, 1)  # length 3 and longer cannot unpack
        ]
    })
    def test_too_many(self):
        """
        Verify that length three item is rejected.

        Only ``pattern:str`` or ``(pattern:str, flags:int)`` are allowed.
        """
        pass

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"listingExclude item .* cannot be unpacked as `pattern, flags = item`:"
    )
    @confoverrides(exhale_args={
        "listingExclude": [1]
    })
    def test_invalid_pattern(self):
        """Verify that non-string argument for pattern is rejected."""
        pass


class UnabridgedOrphanKindsTests(ExhaleTestCase):
    """Test various values of :data:`~exhale.configs.unabridgedOrphanKinds`."""

    test_project = "cpp_long_names"
    """
    .. testproject:: cpp_long_names

    The ``cpp_long_names`` project essentially has 1 compound of each kind, which makes
    it an ideal project to reuse here.
    """

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"^The type of the value for key `unabridgedOrphanKinds`"
    )
    @confoverrides(exhale_args={
        "unabridgedOrphanKinds": False
    })
    def test_not_iterable_fails(self):
        """Verify that non-list/set values raise a configuration error."""
        pass

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"^`unabridgedOrphanKinds` must be a list of strings."
    )
    @confoverrides(exhale_args={
        "unabridgedOrphanKinds": ["file", 22, "dir"]
    })
    def test_non_string_fails(self):
        """Verify that non-string entries raise a configuration error."""
        pass

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"^Unknown kind `jabooty` given in `unabridgedOrphanKinds`."
    )
    @confoverrides(exhale_args={
        "unabridgedOrphanKinds": ["file", "jabooty", "dir"]
    })
    def test_invalid_kind(self):
        """Verify that invalid ``kind`` raises a configuration error."""
        pass

    def total(self, root):
        """Count all nodes that are not ``enumvalue`` and ``group``."""
        # TODO: probably should make this available in ExhaleRoot...
        return sum(n.kind not in {"group", "enumvalue"} for n in root.all_nodes)

    @confoverrides(exhale_args={"unabridgedOrphanKinds": []})
    def test_no_exclusion(self):
        """Verify empty list means no exlusions from full API."""
        full_names, orphan_names = self.checkAllFilesIncluded()
        root = get_exhale_root(self)
        total = self.total(root)
        assert len(full_names) == total
        assert len(orphan_names) == 0

    def _validate_diff_for_kinds(self, diff, *kinds):
        """Check if ``diff`` items got orphaned."""
        # Initial check: verify expected lengths.
        full_names, orphan_names = self.checkAllFilesIncluded()
        root = get_exhale_root(self)
        total = self.total(root)
        assert len(full_names) == total - diff
        assert len(orphan_names) == diff

        # Verify the right things actually got excluded.
        for node in root.all_nodes:
            if node.kind in kinds:
                assert node.file_name in orphan_names
            else:
                assert node.file_name not in orphan_names

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"namespace"}})
    def test_orphan_namespace(self):
        """Verify excluding ``namespace`` behaves as expected."""
        self._validate_diff_for_kinds(1, "namespace")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"class"}})
    def test_orphan_class(self):
        """Verify excluding ``class`` behaves as expected."""
        self._validate_diff_for_kinds(2, "class", "struct")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"struct"}})
    def test_orphan_struct(self):
        """Verify excluding ``struct`` behaves as expected."""
        self._validate_diff_for_kinds(2, "struct", "class")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"class", "struct"}})
    def test_orphan_class_struct(self):
        """Verify excluding ``class`` and ``struct`` behaves as expected."""
        self._validate_diff_for_kinds(2, "class", "struct")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"enum"}})
    def test_orphan_enum(self):
        """Verify excluding ``enum`` behaves as expected."""
        self._validate_diff_for_kinds(1, "enum")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"union"}})
    def test_orphan_union(self):
        """Verify excluding ``union`` behaves as expected."""
        self._validate_diff_for_kinds(1, "union")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"function"}})
    def test_orphan_function(self):
        """Verify excluding ``function`` behaves as expected."""
        self._validate_diff_for_kinds(1, "function")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"variable"}})
    def test_orphan_variable(self):
        """Verify excluding ``variable`` behaves as expected."""
        # There are two variables in the project.
        self._validate_diff_for_kinds(2, "variable")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"define"}})
    def test_orphan_define(self):
        """Verify excluding ``define`` behaves as expected."""
        # There are two define's in the project.
        self._validate_diff_for_kinds(2, "define")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"typedef"}})
    def test_orphan_typedef(self):
        """Verify excluding ``typedef`` behaves as expected."""
        self._validate_diff_for_kinds(1, "typedef")

    @confoverrides(exhale_args={"unabridgedOrphanKinds": {"file"}})
    def test_orphan_file(self):
        """Verify excluding ``file`` behaves as expected."""
        self._validate_diff_for_kinds(1, "file")
