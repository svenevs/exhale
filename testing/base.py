# -*- coding: utf8 -*-
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

from __future__ import unicode_literals
import os
import shutil
import textwrap
import unittest

import exhale
import pytest
import six
from six import add_metaclass
from sphinx.testing.path import path

from . import TEST_PROJECTS_ROOT
from .decorators import default_confoverrides


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

    def __new__(mcs, name, bases, attrs):  # noqa: N804
        """
        Return a new instance with the specified attributes.

        **Parameters**
            ``mcs`` (:class:`python:type`)
                This metaclass (:class:`testing.base.ExhaleTestCaseMetaclass`).

            ``name`` (:class:`python:str`)
                The name of the class being instantiated.

            ``bases`` (:class:`python:list`)
                The list of base classes of ``name``.

            ``attrs`` (:class:`python:dict`)
                The class-level attributes.  These will be inspected / modified as
                needed to produce a final class definition that can use sphinx test
                applications where desired.
        """
        if attrs["__module__"] == __name__:
            # we skip everything if we're creating ExhaleTestCase below
            return super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs)

        # Make sure `test_project` is defined in all derived classes.
        test_project = attrs.get("test_project", None)
        if test_project is None:
            # otherwise we need a ``test_project`` attribute
            raise RuntimeError(
                "ExhaleTestCase subclasses must define a 'test_project' attribute"
            )
        if not isinstance(test_project, six.string_types):
            raise RuntimeError(
                "'test_project' in class {0} must be a string!".format(name)
            )

        # looking for test methods ("test_*")
        has_tests = False
        for n, attr in attrs.items():
            if callable(attr) and n.startswith("test_"):
                has_tests = True
                break

        # if there are tests, we set the app attribute using the
        # ``sphinx.testing.fixtures.app`` fixture
        if has_tests:
            ############################################################################
            # Make the sphinx test application available as `self.app`.                #
            ############################################################################
            def _set_app(self, app):
                # before the test
                self.app = app
                yield  # the test runs
                # @no_cleanup sets self.testroot to [self.testroot] as a flag that
                # cleanup should not transpire
                if isinstance(self.testroot, six.string_types):
                    # This cleanup happens between each test case, do not delete docs/
                    # until all tests for this class are done!
                    containmentFolder = self.getAbsContainmentFolder()
                    if os.path.isdir(containmentFolder):
                        shutil.rmtree(containmentFolder)
                    # Delete the doctrees as well as e.g. _build/html, app.outdir is going
                    # to be docs/_build/{builder_name}
                    _build = os.path.abspath(os.path.dirname(app.outdir))
                    if os.path.isdir(_build):
                        shutil.rmtree(_build)
                    # Make sure doxygen output is deleted between runs
                    doxy_xml_dir = app.config.breathe_projects[test_project]
                    if not os.path.isabs(doxy_xml_dir):
                        doxy_xml_dir = os.path.abspath(os.path.join(
                            self.app.srcdir, doxy_xml_dir
                        ))
                    doxy_dir = os.path.dirname(doxy_xml_dir)
                    if os.path.isdir(doxy_dir):
                        shutil.rmtree(doxy_dir)
                self.app = None

            ############################################################################
            # Automatically create docs_Class_test/{conf.py,index.rst} for this test.  #
            ############################################################################
            def _rootdir(self, app_params):
                # Create the test project's 'docs' dir with a conf.py and index.rst.

                # the root directory name is generated from the test name
                testroot = os.path.join(
                    TEST_PROJECTS_ROOT,
                    self.test_project,
                    "docs_{0}_{1}".format(self.__class__.__name__, self._testMethodName)
                )
                if os.path.isdir(testroot):
                    shutil.rmtree(testroot)
                os.makedirs(testroot)

                # Make the testing root available for this test case for when separate
                # source / build directories are used (in this case, self.app.srcdir
                # is a subdirectory of testroot).
                self.testroot = testroot

                # set the 'testroot' kwarg so that sphinx knows about it
                app_params.kwargs["srcdir"] = path(testroot)

                # Sphinx demands a `conf.py` is present
                with open(os.path.join(testroot, "conf.py"), "w") as conf_py:
                    conf_py.write(textwrap.dedent('''\
                        # -*- coding: utf-8 -*-
                        extensions = ["breathe", "exhale"]
                        master_doc = "index"
                        source_suffix = [".rst"]
                    '''))
                    # Absurd test cases may need an increased recursion limit for Sphinx
                    if self.test_project in ["cpp_long_names"]:
                        conf_py.write(textwrap.dedent('''
                            import sys
                            sys.setrecursionlimit(2000)
                        '''))

                # If a given test case needs to run app.build(), make sure index.rst
                # is available as well
                with open(os.path.join(testroot, "index.rst"), "w") as index_rst:
                    index_rst.write(textwrap.dedent('''
                        Exhale Test Case
                        ================
                        .. toctree::
                           :maxdepth: 2

                           {containmentFolder}/{rootFileName}
                    ''').format(
                        # containmentFolder and rootFileName are always in exhale_args
                        **app_params.kwargs["confoverrides"]["exhale_args"])
                    )

                # run the test in testroot
                yield testroot

                # perform cleanup by deleting the docs dir
                # @no_cleanup sets self.testroot to [self.testroot] as a flag that
                # cleanup should not transpire
                if isinstance(self.testroot, six.string_types) and os.path.isdir(self.testroot):
                    shutil.rmtree(self.testroot)

                self.testroot = None

            # Create the class-level fixture for creating / deleting the docs/ dir
            attrs["_rootdir"] = pytest.fixture(autouse=True)(_rootdir)
            attrs["_set_app"] = pytest.fixture(autouse=True)(_set_app)

        # applying the default configuration override, which is overridden using the
        # @confoverride decorator at class or method level
        return default_confoverrides(
            super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs),
            make_default_config(attrs["test_project"])
        )


@add_metaclass(ExhaleTestCaseMetaclass)
class ExhaleTestCase(unittest.TestCase):
    """
    The primary project based test class to inherit from.

    The ``__metaclass__`` is set to :class:`testing.base.ExhaleTestCaseMetaclass`.
    Inherits from :class:`python:unittest.TestCase`.

    **Attributes Populated by the Metaclass Fixtures for Each Test**
        These attributes are populated during the setup of a test function, and then
        later set to ``None`` during the test function teardown.  These are **only**
        available inside the method body of a testing function (a function with a name
        starting with ``test_``).

        ``self.app`` (``sphinx.testing.util.SphinxTestApp``)
            The sphinx testing application.  Acquire the ``conf.py`` values (and
            corresponding ``@confoverrides``) via ``self.app.config`` like any
            traditional sphinx application.

        ``self.testroot`` (:class:`python:str`)
            The ``testroot`` supplied to ``pytest.mark.sphinx``, the "docs" directory.
            Its value will be
            ``testing/projects/{test_project}/docs_{ClassName}_{test_function_name}``.

            .. todo::

               This value is saved in order to be able to distinguish when a "separate
               source and build" directory is being tested.  At this time this is not
               fully implemented, ``self.app.srcdir`` should be a subdirectory of
               ``self.testroot`` and ``conf.py`` / ``index.rst`` should be generated
               there.

               Currently, these are always generated in ``testroot``, implying that
               there is no "separate source and build" directory structure.  Solution
               requires further investigation of the sphinx testing suite.

        .. danger::

           As a consequence, running tests in parallel is not and never will be
           supported (e.g., when running ``tox -e py``).
    """

    test_project = None
    """
    The string representing the project to run Doxygen / exhale on.

    This variable is used to index into ``testing/projects/{test_project}``.  For
    example, with ``test_project = "c_maths"``, the directory used is
    ``testing/projects/c_maths``.  That is, this variable is joined with the path
    defined by :data:`testing.TEST_PROJECTS_ROOT`.

    **This class-level string variable must be set in subclasses**.
    """

    def getAbsContainmentFolder(self):
        """
        Return the absolute path to ``"containmentFolder"``.

        If ``exhale_args["containmentFolder"]`` is an absolute path, it will be returned
        unchanged.  Otherwise, it will be resolved against ``app.srcdir``.

        **Return**
            ``str``
                An absolute path to the ``"containmentFolder"`` where Exhale will be
                generating its reStructuredText documents.
        """
        containmentFolder = self.app.config.exhale_args["containmentFolder"]
        if not os.path.isabs(containmentFolder):
            containmentFolder = os.path.abspath(os.path.join(
                self.app.srcdir, containmentFolder
            ))

        return containmentFolder

    def checkRequiredConfigs(self):
        """
        Validate the four required configuration arguments in ``exhale_args``.

        1. Checks that ``{containmentFolder}`` was created.
        2. Checks that ``{containmentFolder}/{rootFileName}`` was created.
        3. Checks that ``{rootFileTitle}`` is found in
           ``{containmentFolder}/{rootFileName}``.

        .. todo::

           4. identify via a ``file_*`` method that ``{doxygenStripFromPath}``
              was correctly removed / wielded.
        """
        containmentFolder    = self.getAbsContainmentFolder()
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
        if doxygenStripFromPath:  # this is only here to avoid a flake8 fail on a todo
            pass
