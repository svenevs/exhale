########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

"""
Defines the core sphinx project based test case utilities.

All project based test cases should inherit from :class:`testing.base.ExhaleTestCase`.
"""

import os
import shutil
import unittest

import pytest

from six import with_metaclass

from .decorators import confoverrides, default_confoverrides
from . import TEST_DOC_DIR


def make_default_config(project):
    """
    Return a default configuration for exhale.

    **Parameters**
        ``project`` (str)
            The name of the project that will be searched for in
            ``testing/projects/{project}``.

    **Return**
        ``dict``
            The global default testing configuration to supply to ``confoverrides``
            with ``@pytest.mark.sphinx``, these are values that would ordinarily be
            written in a ``conf.py``.
    """
    return {
        "breathe_projects": {
            project: "./_doxygen/xml"
        },
        "breathe_default_project": project,
        "exhale_args": {
            "containmentFolder": "./api",
            "rootFileName": "index.rst",
            "rootFileTitle": "API Documentation",
            "doxygenStripFromPath": "..",
            "exhaleExecutesDoxygen": True,
            "exhaleDoxygenStdin": "INPUT = ../projects/{0}/include".format(project)
        }
    }


class ExhaleTestCaseMetaclass(type):
    """
    Metaclass to enforce mandatory attributes on :class:`testing.base.ExhaleTestCase`.
    """

    def __new__(mcs, name, bases, attrs):
        """
        Return a new instance with the specified attributes.

        **Parameters**
            ``mcs`` (type)
                This metaclass (:class:`testing.base.ExhaleTestCaseMetaclass`).

            ``name`` (str)
                The name of the class being instantiated.

            ``bases`` (list)
                The list of base classes of ``name``.

            ``attrs`` (dict)
                The class-level attributes.  These will be inspected / modified as
                needed to produce a final class definition that can use sphinx test
                applications where desired.
        """

        if attrs['__module__'] == __name__:
            # we skip everything if we're creating ExhaleTestCase below
            return super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs)
        elif attrs.get('test_project', None) is None:
            # otherwise we need a ``test_project`` attribute
            raise RuntimeError('ExhaleTestCase subclasses must define a "test_project" attribute')

        # looking for test methods ("test_*")
        has_tests = False
        for n, attr in attrs.items():
            if callable(attr) and n.startswith('test_'):
                has_tests = True
                break

        # if there are tests, we set the app attribute using the ``sphinx.testing.fixtures.app`` fixture
        if has_tests:
            def _set_app(self, app):
                # before the test
                self.app = app
                yield  # the test runs
                # cleanup after the test: exhale and sphinx output dirs and breathe project dirs
                dirs = [app.config.exhale_args['containmentFolder'], os.path.dirname(app.outdir)]
                for d in app.config.breathe_projects.values():
                    # get only first directory of breathe project directory relative to srcdir
                    dirs.append(os.path.relpath(os.path.join(app.srcdir, d), app.srcdir).split(os.sep)[0])
                for d in dirs:
                    if not os.path.isabs(d):
                        # d is a relative dir, make it absolute
                        d = os.path.join(app.srcdir, d)
                    shutil.rmtree(d, ignore_errors=True)
            attrs['_set_app'] = pytest.fixture(autouse=True)(_set_app)

        # applying the default configuration override, which is overridden using the @confoverride decorator
        # at class or method level
        return default_confoverrides(
            super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs),
            make_default_config(attrs['test_project'])
        )


class ExhaleTestCase(with_metaclass(ExhaleTestCaseMetaclass, unittest.TestCase)):
    """
    The primary project based test class to inherit from.

    The ``__metaclass__`` is set to :class:`testing.base.ExhaleTestCaseMetaclass`.
    Inherits from :class:`python:unittest.TestCase`.
    """

    #: The string representing the project to run Doxygen / exhale on.
    #:
    #: This value **must** be set in subclasses.
    test_project = None

    #: The Sphinx testing application.
    #:
    #: Will be automatically populated by the meta-class, in test-cases users may
    #: simply access the Sphinx application with ``self.app``.
    app = None
