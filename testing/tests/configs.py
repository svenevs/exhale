# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
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
from pathlib import Path

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
            "Sphinx Warnings did not contain '{}'.".format(expected)
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
        """Verify empty list means no exclusions from full API."""
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


@confoverrides(exhale_args={
    "exhaleDoxygenStdin": textwrap.dedent("""\
        INPUT            = ../include
        EXCLUDE_PATTERNS = */page_town_rock*.hpp
    """)})
class ManualIndexingTests(ExhaleTestCase):
    """
    Tests for :ref:`manual_indexing`.

    Includes checks for:

    - :data:`~exhale.configs.rootFileName`
    - :data:`~exhale.configs.classHierarchyFilename`
    - :data:`~exhale.configs.fileHierarchyFilename`
    - :data:`~exhale.configs.pageHierarchyFilename`
    - :data:`~exhale.configs.unabridgedApiFilename`
    - :data:`~exhale.configs.unabridgedOrphanFilename`
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    def root_file_path(self) -> Path:
        """Return the path to the ``rootFileName``."""
        root_file_name = self.app.config.exhale_args["rootFileName"]
        return Path(self.getAbsContainmentFolder()) / root_file_name

    def verify_expected_files(
        self,
        *,
        page_default: str = "page_view_hierarchy.rst.include",
        class_default: str = "class_view_hierarchy.rst.include",
        file_default: str = "file_view_hierarchy.rst.include",
        u_api_default: str = "unabridged_api.rst.include",
        u_orphan_default: str = "unabridged_orphan.rst"
    ):
        """Verify the expected files were generated and included."""
        # The files that may or may not be generated by exhale.
        containment_folder = Path(self.getAbsContainmentFolder())
        root_path = Path(self.app.exhale_root.full_root_file_path)
        page_path = Path(self.app.exhale_root.page_hierarchy_file)
        class_path = Path(self.app.exhale_root.class_hierarchy_file)
        file_path = Path(self.app.exhale_root.file_hierarchy_file)
        u_api_path = Path(self.app.exhale_root.unabridged_api_file)
        u_orphan_path = Path(self.app.exhale_root.unabridged_orphan_file)

        # Calling tests change the exhale_args and corresponding default parameter,
        # forcing manual effort deliberately for test correctness.
        def verify_name(name: str, actual: Path):
            # NOTE: doing direct path comparisons doesn't work on Windows, exhale (for
            # better or worse) currently puts the magic windows prefix
            # AssertionError: WindowsPath('//?/D:/a/exhale/...') !=
            #                 WindowsPath('D:/a/exhale/...')
            # So instead just compare names and parent directory name and quit since I
            # don't want to deal with this.
            self.assertEqual(
                name,
                actual.name,
                f"Expected {name} and {actual.name} to be the same ({str(actual)})."
            )
            self.assertEqual(
                containment_folder.name,
                actual.parent.name,
                f"Expected parent '{actual.parent.name}' from '{str(actual.parent)}' "
                f"to be '{containment_folder.name}' from '{str(containment_folder)}'."
            )

        verify_name(page_default, page_path)
        verify_name(class_default, class_path)
        verify_name(file_default, file_path)
        verify_name(u_api_default, u_api_path)
        verify_name(u_orphan_default, u_orphan_path)

        # Make sure that everything is still getting included in the root document.
        if root_path.is_file():
            with open(root_path) as f:
                root_contents = f.read()

            def verify_include_directive(f: Path):
                if f.is_file():
                    condition = f".. include:: {f.name}" in root_contents
                    prefix = f"Expected '{f.name}' to be `.. included::`ed in"
                else:
                    condition = f".. include:: {f.name}" not in root_contents
                    prefix = f"'{f.name}' should *NOT* have been `.. include::`ed in"
                self.assertTrue(
                    condition,
                    f"{prefix} '{root_path.name}':\n{root_contents}"
                )

            verify_include_directive(page_path)
            verify_include_directive(class_path)
            verify_include_directive(file_path)
            verify_include_directive(u_api_path)

    @pytest.mark.setup_raises(
        exception=ConfigError,
        match=r"The given `rootFileName` \(no_good\) did not end with '.rst'.*"
    )
    @confoverrides(exhale_args={"rootFileName": "no_good"})
    def test_invalid_root_filename(self):
        """
        Test that non-'.rst' suffix file is rejected, the root document is rst only.
        """
        pass

    @confoverrides(exhale_args={"rootFileName": "EXCLUDE"})
    def test_no_root_generated(self):
        """Test that ``rootFileName=EXCLUDE`` does not generate a file."""
        self.assertFalse(
            Path(self.app.exhale_root.full_root_file_path).exists(),
            "The rootFileName should not have been generated."
        )
        self.verify_expected_files()

    @confoverrides(exhale_args={"classHierarchyFilename": "classes.rst"})
    def test_class_hierarchy_filename(self):
        """Test changing :data:`~exhale.configs.classHierarchyFilename` works."""
        self.verify_expected_files(class_default="classes.rst")

    @confoverrides(exhale_args={"fileHierarchyFilename": "filez.rst"})
    def test_file_hierarchy_filename(self):
        """Test changing :data:`~exhale.configs.fileHierarchyFilename` works."""
        self.verify_expected_files(file_default="filez.rst")

    @confoverrides(exhale_args={
        # Setup for getting pages.
        "rootFileTitle": "",
        "exhaleDoxygenStdin": textwrap.dedent("""\
            INPUT            = ../include
            EXCLUDE_PATTERNS = */page_town_rock_alt.hpp
        """),
        "pageHierarchyFilename": "pagez.rst"
    })
    def test_page_hierarchy_filename(self):
        """Test changing :data:`~exhale.configs.pageHierarchyFilename` works."""
        page_path = Path(self.app.exhale_root.page_hierarchy_file)
        self.assertTrue(page_path.is_file(), f"Expected '{page_path.name}' to exist.")
        self.assertEqual(
            len(self.app.exhale_root.pages),
            1,
            "Internal error: incorrect number of pages found."
        )
        self.verify_expected_files(page_default="pagez.rst")

    @confoverrides(exhale_args={"unabridgedApiFilename": "ub_api.rst"})
    def test_unabridged_api_filename(self):
        """Test changing :data:`~exhale.configs.unabridgedApiFilename` works."""
        u_api_path = Path(self.app.exhale_root.unabridged_api_file)
        self.assertTrue(u_api_path.is_file(), f"Expected '{u_api_path.name}' to exist.")
        self.verify_expected_files(u_api_default="ub_api.rst")

    @confoverrides(exhale_args={"unabridgedOrphanFilename": "ub_orphan.rst"})
    def test_unabridged_orphan_filename(self):
        """Test changing :data:`~exhale.configs.unabridgedOrphanFilename` works."""
        u_orphan_path = Path(self.app.exhale_root.unabridged_api_file)
        self.assertTrue(
            u_orphan_path.is_file(),
            f"Expected '{u_orphan_path.name}' to exist."
        )
        self.verify_expected_files(u_orphan_default="ub_orphan.rst")
