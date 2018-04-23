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
import textwrap
import unittest

import pytest

from six import with_metaclass

import exhale

from .decorators import confoverrides, default_confoverrides
from . import TEST_PROJECTS_ROOT, TEST_RESULTS_COPY_DIR


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
            # required arguments
            "containmentFolder": "./api",
            "rootFileName": "{0}_root.rst".format(project),
            "rootFileTitle": "``{0}`` Test Project".format(project),
            "doxygenStripFromPath": "..",
            # additional arguments
            "exhaleExecutesDoxygen": True,
            "exhaleDoxygenStdin": "INPUT = ../include"
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

        # Make sure `test_project` is defined in all derived classes.
        test_project = attrs.get("test_project", None)
        if test_project is None:
            # otherwise we need a ``test_project`` attribute
            raise RuntimeError('ExhaleTestCase subclasses must define a "test_project" attribute')

        # Run all test projects local to the project folder
        testroot = os.path.join(TEST_PROJECTS_ROOT, test_project, "docs")
        attrs["testroot"] = testroot

        # looking for test methods ("test_*")
        has_tests = False
        for n, attr in attrs.items():
            if callable(attr) and n.startswith('test_'):
                has_tests = True
                break

        # if there are tests, we set the app attribute using the ``sphinx.testing.fixtures.app`` fixture
        if has_tests:
            ############################################################################
            # Make the sphinx test application available as `self.app`.                #
            ############################################################################
            def _set_app(self, app):
                # before the test
                self.app = app
                yield  # the test runs
                # This cleanup happens between each test case, do not delete docs/
                # until all tests for this class are done!
                containmentFolder = self.getAbsAgainstSrcdir("containmentFolder")
                if os.path.isdir(containmentFolder):
                    shutil.rmtree(containmentFolder)
                # Delete the doctrees as well as e.g. _build/html, app.outdir is going
                # to be docs/_build/{builder_name}
                _build = os.path.abspath(os.path.dirname(app.outdir))
                if os.path.isdir(_build):
                    shutil.rmtree(_build)
                # Make sure doxygen output is deleted between runs
                doxy_xml_dir = os.path.abspath(os.path.join(
                    self.app.srcdir, app.config.breathe_projects[test_project]
                ))
                doxy_dir = os.path.dirname(doxy_xml_dir)
                if os.path.isdir(doxy_dir):
                    shutil.rmtree(doxy_dir)

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

    test_project = None
    """
    The string representing the project to run Doxygen / exhale on.

    This value **must** be set in subclasses.
    """

    app = None
    """
    The Sphinx testing application.

    Will be automatically populated by the meta-class, in test-cases users may
    simply access the Sphinx application with ``self.app``.
    """

    testroot = None
    """
    The ``testroot`` specified to the sphinx test application.  This is populated by
    :class:`testing.base.ExhaleTestCaseMetaclass`, and uses
    :data:`testing.base.ExhaleTestCase.test_project` to form:

    .. code-block:: py

       os.path.join(TEST_PROJECTS_ROOT, test_project, "docs")

    So if ``test_project`` were ``"c_maths"``, then this variable will be equivalent to
    ``{repo_root}/testing/projects/c_maths/docs``.
    """
    def getAbsAgainstSrcdir(self, key):
        val = self.app.config.exhale_args[key]
        if not os.path.isabs(val):
            val = os.path.abspath(os.path.join(self.app.srcdir, val))

        return val

    def checkRequiredConfigs(self):
        """
        Validates the four required configuration arguments in ``exhale_args``.

        1. Checks that ``{containmentFolder}`` was created.
        2. Checks that ``{containmentFolder}/{rootFileName}`` was created.
        3. Checks that ``{rootFileTitle}`` is found in
           ``{containmentFolder}/{rootFileName}``.

        .. todo::

           4: identify via a ``file_*`` method that ``{doxygenStripFromPath}``
           was correctly removed / wielded.
        """
        containmentFolder    = self.getAbsAgainstSrcdir("containmentFolder")
        rootFileName         = self.app.config.exhale_args["rootFileName"]
        rootFileTitle        = self.app.config.exhale_args["rootFileTitle"]
        doxygenStripFromPath = self.app.config.exhale_args["doxygenStripFromPath"]

        # validate that the containmentFolder was created
        assert os.path.isdir(containmentFolder)
        # validate that {containmentFolder}/{rootFileName} was created
        assert os.path.isfile(os.path.join(containmentFolder, rootFileName))
        # validate that the title was included
        with open(os.path.join(containmentFolder, rootFileName), "r") as root:
            root_contents = root.read()
        root_heading = "{0}\n{1}".format(
            rootFileTitle,
            exhale.utils.heading_mark(rootFileTitle, exhale.configs.SECTION_HEADING_CHAR)
        )
        assert root_heading in root_contents

        # TODO: validate doxygenStripFromPath

    def copyThisProject(self):
        """
        Copies the generated results from ``{containmentFolder}`` to
        :data:`testing.TEST_RESULTS_COPY_DIR`.

        .. warning::

           The following are assumed:

           1. Every derived class of :class:`testing.base.ExhaleTestCase` calls this
              method **exactly once**.
           2. The test method this is called from is un-decorated.  That is, no class
              or function level ``@no_run`` or ``@confoverrides`` is used.

           For (2), it is really just important that the path to
           ``{containmentFolder}/{rootFileName}`` is the same as what is specified
           by :func:`testing.base.make_default_config`.
        """
        abs_containmentFolder = self.getAbsAgainstSrcdir("containmentFolder")

        # If this is the first test run, launching the test suite deleted the folder
        # so make sure to create it again
        if not os.path.isdir(TEST_RESULTS_COPY_DIR):
            os.makedirs(TEST_RESULTS_COPY_DIR)

        # Copy the generated reStructuredText from exhale.
        shutil.copytree(
            abs_containmentFolder,
            os.path.join(TEST_RESULTS_COPY_DIR, self.test_project)
        )
