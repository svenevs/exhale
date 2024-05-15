########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Defines the core sphinx project based test case utilities.

All project based test cases should inherit from :class:`testing.base.ExhaleTestCase`.
"""

import os
import platform
import re
import shutil
import textwrap
import unittest
from importlib import import_module

import exhale
import pytest
import six
from six import add_metaclass
from sphinx.testing.path import path

from . import TEST_PROJECTS_ROOT, get_exhale_root
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
                        project = "{test_project}"
                        extensions = ["breathe", "exhale"]
                        master_doc = "index"
                        source_suffix = [".rst"]
                    ''').format(
                        test_project=test_project
                    ))
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

            # Create a default test that will validate some common tests
            def test_common(self):
                marks  = getattr(self, "pytestmark", False)
                no_run = marks and any('no_run' in m.args for m in marks)
                if not no_run:
                    self.checkRequiredConfigs()
                    self.checkAllFilesGenerated()
                    self.checkAllFilesIncluded()

            attrs["test_common"] = test_common

            # Import the default hierarchy dictionaries from the testing/projects folder
            # and make it available to the class directly.
            proj_mod = import_module(
                "testing.projects.{test_project}".format(test_project=test_project))

            default_class_hierarchy_dict = proj_mod.default_class_hierarchy_dict

            def class_hierarchy_wrapper(self):
                return default_class_hierarchy_dict()
            attrs["class_hierarchy_dict"] = class_hierarchy_wrapper

            default_file_hierarchy_dict = proj_mod.default_file_hierarchy_dict

            def file_hierarchy_wrapper(self):
                return default_file_hierarchy_dict()
            attrs["file_hierarchy_dict"] = file_hierarchy_wrapper

            attrs["test_project_module"] = proj_mod  # In case it's ever needed...

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

    def cross_validate(self, contents, required=None, forbidden=None):
        """
        Validate *all* ``required`` and *no* ``forbidden`` items found in ``contents``.

        For each item in ``required`` an assertion of ``item in contents`` is made, and
        for each item in ``forbidden`` an assertion of ``item not in contents`` is made.

        If neither ``required`` nor ``forbidden`` are supplied, no checks are performed.

        **Parameters**

        ``contents`` (:class:`python:str` or Iterable)
            The contents to cross validate that all required items and no forbidden
            items are found in.

        ``required`` (:data:`python:None` or Iterable)
            The listing of all required entries that are required to be in ``contents``.

        ``forbidden`` (:data:`python:None` or Iterable)
            The listing of all forbidden entries that are not allowed in ``contents``.
        """
        if required:
            for item in required:
                self.assertTrue(
                    item in contents,
                    "Required entry [{item}] not found in:\n{contents}".format(
                        item=item, contents=contents
                    )
                )
        if forbidden:
            for item in forbidden:
                self.assertTrue(
                    item not in contents,
                    "Forbidden entry [{item}] found in:\n{contents}".format(
                        item=item, contents=contents
                    )
                )

    def contents_for_node(self, node):
        """
        Return the generated file contents for the specified ``node``.

        **Parameters**

        ``node`` (:class:`exhale.graph.ExhaleNode`)
            The node whose generated file contents are desired.  Note that this must be
            a proper :class:`~exhale.graph.ExhaleNode` instance, since
            ``node.file_name`` is what is used.  That is, a mocked testing node should
            not be used!

        **Return** (:class:`python:str`)
            The contents of ``node.file_name``.

        **Raises**
            If ``os.path.join(self.getAbsContainmentFolder(), node.file_name)`` does
            not exist.
        """
        node_path = os.path.join(self.getAbsContainmentFolder(), node.file_name)
        with open(node_path) as f:
            return f.read()

    def getAbsContainmentFolder(self):
        r"""
        Return the absolute path to ``"containmentFolder"``.

        If ``exhale_args["containmentFolder"]`` is an absolute path, it will be returned
        unchanged.  Otherwise, it will be resolved against ``app.srcdir``.

        **Return**
            ``str``
                An absolute path to the ``"containmentFolder"`` where Exhale will be
                generating its reStructuredText documents.

                .. note::

                    When ``platform.system() == "Windows"``, this string will **always**
                    be prefixed with ``\\?\`` to deal with maximum path length issues.
                    This is to accommodate the somewhat long containment folders
                    generated by using the testing class name as well as the test name.
                    See :data:`~exhale.configs.MAXIMUM_WINDOWS_PATH_LENGTH` for more
                    information.

                    If this is not done, then even if ``self.app.build()`` is skipped
                    for the test cases that cause this (in
                    :class:`~testing.tests.cpp_long_names.CPPLongNames`),
                    :func:`python:shutil.rmtree` will crash during test teardown.
                    Better to just always include it.
        """
        containmentFolder = self.app.config.exhale_args["containmentFolder"]
        if not os.path.isabs(containmentFolder):
            containmentFolder = os.path.abspath(os.path.join(
                self.app.srcdir, containmentFolder
            ))

        # Guarantee Windows can cope with this path.
        if platform.system() == "Windows":
            # NOTE: containmentFolder is *ALREADY* an absolute path, this prefix
            #       requires absolute paths!  See documentation for
            #       configs.MAXIMUM_WINDOWS_PATH_LENGTH.
            containmentFolder = "{magic}{containmentFolder}".format(
                magic="{slash}{slash}?{slash}".format(slash="\\"),  # \\?\ I HATE YOU WINDOWS
                containmentFolder=containmentFolder
            )

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

        .. autotested::
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

    def checkAllFilesGenerated(self):
        """
        Validate that all files are actually generated.

        .. autotested::
        """
        root = get_exhale_root(self)
        containmentFolder = self.getAbsContainmentFolder()
        for node in root.all_nodes:
            if node.kind in ["enumvalue", "group"]:
                continue
            gen_file_path = os.path.join(containmentFolder, node.file_name)
            self.assertTrue(
                os.path.isfile(gen_file_path),
                "File for {kind} node with refid=[{refid}] not generated to [{gen_file_path}]!".format(
                    kind=node.kind, refid=node.refid, gen_file_path=gen_file_path
                )
            )

    def checkAllFilesIncluded(self):
        """
        Validate that all files are actually included in the library root.

        .. autotested::
        """
        # TODO: config objects: this import can go away
        from exhale.configs import unabridgedOrphanKinds

        # build path to unabridged api document that adds all toctree directives
        root = get_exhale_root(self)
        containmentFolder = self.getAbsContainmentFolder()
        unabridged_api_path = os.path.join(containmentFolder, "unabridged_api.rst.include")
        unabridged_orphan_path = os.path.join(containmentFolder, "unabridged_orphan.rst")

        # gather lines that match the indented part of the toctree
        #
        # .. toctree::
        #    :maxdepth: {toctreeMaxDepth}
        #
        #    some_node.file_name.rst
        #
        # so just lazily look for the leading three spaces and ending with .rst
        full_api_toctrees = []
        under_toctree_re = re.compile(r"^   .+\.rst$")
        with open(unabridged_api_path) as unabridged_api:
            for line in unabridged_api:
                if under_toctree_re.match(line):
                    full_api_toctrees.append(line.strip())

        orphan_toctrees = []
        if os.path.isfile(unabridged_orphan_path):
            with open(unabridged_orphan_path) as unabridged_orphan:
                for line in unabridged_orphan:
                    if under_toctree_re.match(line):
                        orphan_toctrees.append(line.strip())

        # Scan all nodes and make sure they were found in the toctrees above.
        doxygen_mainpage_was_used = False
        for node in root.all_nodes:
            if node.kind in {"enumvalue", "group"}:
                continue

            # When doxygen \mainpage command is used, the .. doxygenpage:: index
            # is .. include::'ed in the root file document.  Those checks come
            # after this loop.
            if node.kind == "page" and node.refid == "indexpage":
                doxygen_mainpage_was_used = True
                continue

            if node.kind in unabridgedOrphanKinds or \
                    (node.kind == "class" and "struct" in unabridgedOrphanKinds) or \
                    (node.kind == "struct" and "class" in unabridgedOrphanKinds):
                toctrees = orphan_toctrees
                doc = unabridged_orphan_path
            else:
                toctrees = full_api_toctrees
                doc = unabridged_api_path

            self.assertTrue(
                node.file_name in toctrees,
                "Node refid=[{refid}] and basename=[{file_name}] not found in [{doc}]!".format(
                    refid=node.refid, file_name=node.file_name, doc=doc
                )
            )

        # Make sure every document expected to be .. include::'ed in the library root
        # has actually been included.
        full_root_file_path = root.full_root_file_path
        root_file_includes = []
        with open(full_root_file_path, "r") as full_root_f:
            for line in full_root_f:
                include_mark = ".. include::"
                if line.startswith(include_mark):
                    root_file_includes.append(line.split(include_mark)[-1].strip())

        index_include = False  # page_index.rst comes from doxygen \mainpage
        page_hierarchy_include = False  # page_view_hierarchy.rst
        class_hierarchy_include = False  # class_view_hierarchy.rst
        file_hierarchy_include = False  # file_view_hierarchy.rst
        unabridged_api_include = True  # unabridged_api.rst.  Always included.
        orphan_api_include = False  # unabridged_orphan.rst.  Never included.
        for node in root.all_nodes:
            if node.kind == "page":
                if node.refid == "indexpage":
                    index_include = True
                else:
                    page_hierarchy_include = True
            elif node.kind in exhale.utils.CLASS_LIKE_KINDS:
                class_hierarchy_include = True
            elif node.kind in {"dir", "file"}:
                file_hierarchy_include = True

        self.assertTrue(
            doxygen_mainpage_was_used == index_include,
            "Mismatch: doxygen_mainpage_was_used != index_include!")

        include_map = {
            "page_index.rst.include": index_include,
            os.path.basename(root.page_hierarchy_file): page_hierarchy_include,
            os.path.basename(root.class_hierarchy_file): class_hierarchy_include,
            os.path.basename(root.file_hierarchy_file): file_hierarchy_include,
            os.path.basename(root.unabridged_api_file): unabridged_api_include,
            os.path.basename(root.unabridged_orphan_file): orphan_api_include
        }
        root_file_base = os.path.basename(full_root_file_path)
        for key, val in include_map.items():
            if val:
                check = getattr(self, "assertTrue")
                msg = "*WAS* expected in {root_file_base}, but was *NOT* found!".format(
                    root_file_base=root_file_base
                )
            else:
                check = getattr(self, "assertFalse")
                msg = "was *NOT* expected in {root_file_base}, but *WAS* found!".format(
                    root_file_base=root_file_base
                )
            check(
                key in root_file_includes,
                "Page '{key}' {msg}".format(key=key, msg=msg))

        # Some tests may want the toctree names afterward.
        return full_api_toctrees, orphan_toctrees
