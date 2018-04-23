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
import unittest

import exhale
import pytest
from six import add_metaclass

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

    def __new__(mcs, name, bases, attrs):  # noqa N804
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
        test_project_root = os.path.join(TEST_PROJECTS_ROOT, test_project)
        attrs["test_project_root"] = test_project_root

        # looking for test methods ("test_*")
        has_tests = False
        for n, attr in attrs.items():
            if callable(attr) and n.startswith('test_'):
                has_tests = True
                break

        # if there are tests, we set the app attribute using the ``sphinx.testing.fixtures.app`` fixture
        if has_tests:
            # Make the sphinx test application available as `self.app`.  Because this
            # has an `app` parameter, pytest and sphinx automatically call this.
            def _set_app(self, app):
                # before the test
                self.app = app
                yield

            attrs['_set_app'] = pytest.fixture(autouse=True)(_set_app)

        # applying the default configuration override, which is overridden using the @confoverride decorator
        # at class or method level
        return default_confoverrides(
            super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs),
            make_default_config(attrs['test_project'])
        )


@add_metaclass(ExhaleTestCaseMetaclass)
class ExhaleTestCase(unittest.TestCase):
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

    test_project_root = None
    """
    The root of this test project, populated by the meta-class.

    .. code-block:: py

       os.path.join(TEST_PROJECTS_ROOT, test_project)

    So if ``test_project`` were ``"c_maths"``, then this variable will be equivalent to
    ``{repo_root}/testing/projects/c_maths``.
    """

    app = None
    """
    The Sphinx testing application.

    Will be automatically populated by the meta-class, in test-cases users may
    simply access the Sphinx application with ``self.app``.
    """

    func_to_sphinx_map = {}
    """
    Map function names to ``pytest.sphinx.mark`` decorator arguments.

    **Keys** (:class:`python:str`)
        The name of a function (e.g., ``"test_app"`` or ``"test_alt_out"``).

    **Values** (:class:`python:dict`)
        The dictionary being supplied to ``pytest.mark.sphinx`` for the given function.
        These dictionaries are a ``**kwargs`` style dictionary with string keys mapping
        to function call input.  Each dictionary must have:

        - ``"testroot" -> str``: maps to
          :data:`testing.base.ExhaleTestCase.test_project_root`.
        - ``"confoverrides" -> dict``: the overrides to ``conf.py``, including
          ``exhale_args``.

    Consider the test class:

    .. code-block:: py

       class CMathsTests(ExhaleTestCase):
           test_project = 'c_maths'

           def test_app(self):
               self.checkRequiredConfigs()

           @confoverrides(exhale_args={"containmentFolder": "./alt_api"})
           def test_alt_out(self):
               self.checkRequiredConfigs()

    Then the final value of ``func_to_sphinx_map`` might look like:

    .. code-block:: py

       {
         "test_app": {
           "testroot": "/path/to/exhale/testing/projects/c_maths/docs_CMathsTests_test_app",
           "confoverrides": {
             "breathe_projects": {
               "c_maths": "./_doxygen/xml"
             },
             "breathe_default_project": "c_maths",
             "exhale_args": {
               "containmentFolder": "./api"
               # ... other arguments ...
             }
           }
         },
         "test_alt_out": {
           "testroot": "/path/to/exhale/testing/projects/c_maths/docs_CMathsTests_test_alt_out",
           "confoverrides": {
             "breathe_projects": {
               "c_maths": "./_doxygen/xml"
             },
             "breathe_default_project": "c_maths",
             "exhale_args": {
               "containmentFolder": "./alt_api"
               # ... other arguments ...
             }
           }
         }
       }

    That is, these are the **final** arguments to ``pytest.mark.sphinx``, after all
    hierarchical ``confoverrides`` have been computed for a given test function.  The
    primary reason for saving this information is to enable
    :func:`testing.conftest.pytest_runtest_setup` and
    :func:`testing.conftest.pytest_runtest_teardown` to be able to automatically create
    the "docs" directory (defined by ``testroot``) for a given test.

    .. tip::

       All information is saved, but when writing test code you can access the sphinx
       config values (``confoverrides`` included) more directly.  For example, getting
       access to ``exhale_args`` would be done with ``self.app.config.exhale_args``.
    """

    def getAbsAgainstSrcdir(self, key):
        """
        Return an absolute path joined with ``app.srcdir`` for the specified key.

        **Parameters**
            ``key`` (str)
                The key to lookup in ``self.app.config.exhale_args``, e.g.
                ``"containmentFolder"``.

        **Return**
            ``str``
                When the specified ``key`` is not an absolute path, it is assumed to be
                a path relative to ``conf.py``.  So the result is simply
                ``os.path.join(self.app.srcdir, val)`` where
                ``val = self.app.config.exhale_args[key]``.
        """
        val = self.app.config.exhale_args[key]
        if not os.path.isabs(val):
            val = os.path.abspath(os.path.join(self.app.srcdir, val))

        return val

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
        if doxygenStripFromPath:  # this is only here to avoid a flake8 fail on a todo
            pass
