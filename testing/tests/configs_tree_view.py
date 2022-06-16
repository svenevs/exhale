# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests specifically focused on the various tree view configurations.
"""
from __future__ import unicode_literals

import os
import platform
import re
from pathlib import Path
from textwrap import dedent

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides

this_file_dir = Path(__file__).parent.absolute()
"""The path to the directory containing this file."""

class_data_root = this_file_dir / "configs_tree_view_data" / "classes"
"""The class view hierarchy test validation data root for tree view."""

file_data_root = this_file_dir / "configs_tree_view_data" / "files"
"""The file view hierarchy test validation root for tree view."""

tree_view_keys = {"default_rst_list", "collapsible_lists", "bootstrap"}
"""Available kinds of tree views to validate against."""


def read_default_data(root: Path, file_name: str, is_html: bool) -> str:
    """
    Open, read, and return the contents of the file ``{root}/{file_name}``.

    If the default data being read is html (collapsible lists and bootstrap),
    underscores in the refid need to be replaced with dashes since the link generated
    follows an html anchor (``#``).

    The stored data files include the unix doxygen refids, on windows they are replaced
    with the expected refid.  Doxygen only seems to differ on the platforms when there
    is nesting / specialization occurring.  The tree view tests are validating against
    the ``cpp_nesting`` project which has a large amount of this going on.
    """
    # First elem: unix refid, second item: windows refid.
    # NOTE: order matters!!!  You must replace the nested ones first before their
    # parent otherwise the parent one will break the nested unix item.
    unix_to_windows_refid_map = [
        (
            "structspecial_1_1complex_1_1Fold",
            "structspecial_1_1complex_1_1_fold"
        ),
        ################################################################################
        (
            "structspecial_1_1complex_1_1has__type__member_3_01T_00_01void__t_3_01typename_01T_1_1type_01_4_01_4",  # noqa: E501
            "structspecial_1_1complex_1_1has__type__member_3_01_t_00_01void__t_3_01typename_01_t_1_1type_01_4_01_4",  # noqa: E501
        ),
        ################################################################################
        (
            "structspecial_1_1complex_1_1IntPtr",
            "structspecial_1_1complex_1_1_int_ptr"
        ),
        (
            "structspecial_1_1complex_1_1IntRef",
            "structspecial_1_1complex_1_1_int_ref"
        ),
        ################################################################################
        (
            "structspecial_1_1unique_1_1snowflake_1_1Ontology_3_0111_01_4",
            "structspecial_1_1unique_1_1snowflake_1_1_ontology_3_0111_01_4"
        ),
        (
            "structspecial_1_1unique_1_1snowflake_1_1Ontology",
            "structspecial_1_1unique_1_1snowflake_1_1_ontology"
        ),
        ################################################################################
        (
            "structspecial_1_1unique_1_1Nonsense_3_0111_00_01snowflake_1_1Ontology_3_0111_01_4_01_4",
            "structspecial_1_1unique_1_1Nonsense_3_0111_00_01snowflake_1_1_ontology_3_0111_01_4_01_4"
        ),
        (
            "structspecial_1_1unique_1_1Nonsense_3_01X_00_01snowflake_1_1Ontology_3_01X_01_4_01_4",
            "structspecial_1_1unique_1_1Nonsense_3_01_x_00_01snowflake_1_1_ontology_3_01_x_01_4_01_4"
        ),
        (
            "structspecial_1_1unique_1_1Nonsense",
            "structspecial_1_1unique_1_1_nonsense"
        ),
        ################################################################################
        (
            "structspecial_1_1Base_3_012_01_4_1_1InnerTemplatedStruct_3_014_00_01dont__use__this_01_4",
            "structspecial_1_1Base_3_012_01_4_1_1_inner_templated_struct_3_014_00_01dont__use__this_01_4"
        ),
        (
            "structspecial_1_1Base_3_012_01_4_1_1InnerTemplatedStruct",
            "structspecial_1_1Base_3_012_01_4_1_1_inner_templated_struct"
        ),
        (
            "structspecial_1_1Base_3_012_01_4_1_1InnerStruct",
            "structspecial_1_1Base_3_012_01_4_1_1_inner_struct"
        ),
        (
            "structspecial_1_1Base_3_012_01_4_1_1AnotherNestedStruct",
            "structspecial_1_1Base_3_012_01_4_1_1_another_nested_struct"
        ),
        (
            "structspecial_1_1Base_3_012_01_4",
            "structspecial_1_1_base_3_012_01_4"
        ),
        (
            "structspecial_1_1Base_1_1A",
            "structspecial_1_1Base_1_1_a"
        ),
        (
            "structspecial_1_1Base",
            "structspecial_1_1_base"
        ),
        ################################################################################
        (
            "structspecial_1_1Normal_1_1Nested_1_1Like_1_1Usual",
            "structspecial_1_1Normal_1_1Nested_1_1Like_1_1_usual"
        ),
        (
            "structspecial_1_1Normal_1_1Nested_1_1Like",
            "structspecial_1_1Normal_1_1Nested_1_1_like"
        ),
        (
            "structspecial_1_1Normal_1_1Nested",
            "structspecial_1_1Normal_1_1_nested"
        ),
        (
            "structspecial_1_1Normal",
            "structspecial_1_1_normal"
        ),
        ################################################################################
        (
            "classspecial_1_1ImageBuffer_3_01Image_3_011920_00_011080_01_4_00_01float_00_01128_01_4",
            "classspecial_1_1ImageBuffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4"
        ),
        (
            "classspecial_1_1ImageBuffer_3_01TImage_00_01Tdata__t_00_014_01_4",
            "classspecial_1_1ImageBuffer_3_01_t_image_00_01_tdata__t_00_014_01_4"
        ),
        (
            "classspecial_1_1ImageBuffer",
            "classspecial_1_1_image_buffer"
        ),
        ################################################################################
        (
            "structspecial_1_1ImageBuffer_3_01Image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1Data",
            "structspecial_1_1Image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_data"  # noqa: E501
        ),
        (
            "structspecial_1_1ImageBuffer_3_01Image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1SomeThing",    # noqa: E501
            "structspecial_1_1Image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_some_thing"  # noqa: E501
        ),
        ################################################################################
        (
            "structspecial_1_1ImageBuffer_3_01TImage_00_01Tdata__t_00_014_01_4_1_1Data",
            "structspecial_1_1Image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_data"
        ),
        (
            "structspecial_1_1ImageBuffer_3_01TImage_00_01Tdata__t_00_014_01_4_1_1SomeThing",
            "structspecial_1_1Image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_some_thing"
        ),
        ################################################################################
        (
            "structspecial_1_1ImageBuffer_1_1Data",
            "structspecial_1_1_image_buffer_1_1_data"
        ),
        (
            "structspecial_1_1ImageBuffer_1_1SomeThing",
            "structspecial_1_1_image_buffer_1_1_some_thing"
        ),
        ################################################################################
        (
            "structspecial_1_1Image",
            "structspecial_1_1_image"
        ),
    ]

    with open(root / file_name) as f:
        contents = f.read()

    if platform.system() == "Windows":
        for unix_refid, windows_refid in unix_to_windows_refid_map:
            # For html, two replacements are needed.  The generated page is named as
            # {refid}.html with underscores in tact, but the anchor names are #{refid}
            # with underscores as hyphens.
            contents = contents.replace(unix_refid, windows_refid)
            if is_html:
                unix_refid_hyphenated = unix_refid.replace("_", "-")
                windows_refid_hyphenated = windows_refid.replace("_", "-")
                contents = contents.replace(
                    unix_refid_hyphenated, windows_refid_hyphenated)

    return contents


class_hierarchy_ground_truth = {
    k: read_default_data(class_data_root, f"{k}.txt", k != "default_rst_list")
    for k in tree_view_keys
}
"""
Ground truth for the three versions of class hierarchies.

Keys and what they represent:

``"default_rst_list"``
    The reStructuredText list version (``createTreeView=False``).

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).

.. todo::

    This will break if / when doxygen refid generation changes.  In theory it should be
    possible to synthetically re-create the hierarchy without this crazy text processing.
"""

file_hierarchy_ground_truth = {
    k: read_default_data(file_data_root, f"{k}.txt", k != "default_rst_list")
    for k in tree_view_keys
}
"""
Ground truth for the three versions of file hierarchies.

Keys and what they represent:

``"default_rst_list"``
    The reStructuredText list version (``createTreeView=False``).

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).

.. todo::

   This one should be possible to re-create manually rather than relying on direct text
   comparisons.  But until you figure out how to do the class one more programmatically
   you aren't doing that lolz.
"""


# NOTE: See cpp_nesting.CPPNestingPages.{setUp,tearDown} (creates page_town_rock.hpp).
@confoverrides(exhale_args={
    "exhaleDoxygenStdin": dedent("""\
        INPUT            = ../include
        EXCLUDE_PATTERNS = */page_town_rock*.hpp
    """)})
class TreeViewHierarchyTests(ExhaleTestCase):
    """
    Naive tests on raw "reStructuredText" generated for tree views.
    """

    test_project = "cpp_nesting"
    """
    .. testproject:: cpp_nesting

    .. note::

        The ``cpp_nesting`` project is just being recycled, the tests for that project
        take place in
        :class:`CPPNesting <testing.tests.cpp_nesting.CPPNesting>`.
    """

    def class_view_hierarchy_file(self):
        """Path to ``class_view_hierarchy.rst.include`` for this test."""
        return os.path.join(
            self.getAbsContainmentFolder(), "class_view_hierarchy.rst.include")

    def file_view_hierarchy_file(self):
        """Path to ``file_view_hierarchy.rst.include`` for this test."""
        return os.path.join(
            self.getAbsContainmentFolder(), "file_view_hierarchy.rst.include")

    def raw_hierarchies(self):
        """
        Raw contents of ``{class,file}_view_hierarchy.rst.include``.

        **Return** (Length ``2`` :class:`python:tuple` of :class:`python:str`)
            The string contents of ``(class_view, file_view)``, in that order.
        """
        with open(self.class_view_hierarchy_file()) as class_view:
            class_view_contents = class_view.read()

        with open(self.file_view_hierarchy_file()) as file_view:
            file_view_contents = file_view.read()

        return (class_view_contents, file_view_contents)

    def filter_empty_lines(self, lst):
        """
        Return a copy of ``lst`` with empty / whitespace-only strings removed.

        **Parameters**
            ``lst`` (:class:`python:list` of :class:`python:str`)
                The input list of strings to filter.

        **Return** (:class:`python:list` of :class:`python:str`)
            The input ``lst`` in the same order, with empty strings and whitespace-only
            strings removed.
        """
        empty_or_whitespace = re.compile(r"^$|^\s+$")
        return [line for line in lst if not empty_or_whitespace.match(line)]

    def html_hierarchies(self):
        """
        Hierarchy text from ``{class,file}_view_hierarchy.rst``.

        When ``createTreeView=True``, the generated page has something like:

        .. code-block:: rst

            Class View Hierarchy
            --------------------

            .. raw:: html

               <ul>
                 <li> ... </li>
                 <!-- ... -->
                 <li> ... </li>
               </ul>

            .. end raw html for treeView

        What this method does is simply search for ``.. raw:: html`` and ``.. end``
        respectively, accumulating everything in between.  Since we are performing
        direct string comparisons with "ground truth" values, we specifically accumulate
        ``line.strip()`` to remove the leading indentation since it is under a
        ``.. raw:: html`` directive.  Finally, the returned output is filtered using
        :func:`filter_empty_lines`.

        **Return** (Length ``2`` :class:`python:tuple` of :class:`python:list` of :class:`python:str`)
            A length two tuple in the order ``(class_view, file_view)``.  Each item in
            the tuple is a list of strings of the parsed / filtered lines.
        """

        def strip_html_directive(hierarchy):
            hierarchy_lines = []
            found_raw_html = False
            for line in hierarchy.splitlines():
                if found_raw_html:
                    if line.startswith(".. end"):
                        break
                    hierarchy_lines.append(line.strip())
                elif line.startswith(".. raw:: html"):
                    found_raw_html = True

            return self.filter_empty_lines(hierarchy_lines)

        class_view_raw, file_view_raw = self.raw_hierarchies()
        return (strip_html_directive(class_view_raw), strip_html_directive(file_view_raw))

    def line_compare(self, expected_list, test_list):
        """
        Compare two lists of strings.

        Performs two tests:

        1. That ``len(expected_list)`` and ``len(test_list)`` are the same.
        2. That the order and values of strings in ``expected_list`` are the same as
           ``test_list``.  Mismatched values will be printed in the assertion.

        **Parameters**
            ``expected_list`` (:class:`python:list` of :class:`python:str`)
                The expected list of strings to compare with.

            ``test_list`` (:class:`python:list` of :class:`python:str`)
                The parsed list of strings to validate.
        """
        num_expected_lines = len(expected_list)
        self.assertEqual(num_expected_lines, len(test_list))

        mismatches = []
        for idx in range(num_expected_lines):
            expected = expected_list[idx]
            test = test_list[idx]
            if test != expected:
                mismatches.append((expected, test))

        self.assertTrue(
            len(mismatches) == 0,
            "Mismatches in line_compare:\n\n{0}".format(
                "\n".join(
                    "- expected: '{0}'\n  got:      '{1}'".format(*item)
                    for item in mismatches
                )
            )
        )

    def line_compare_minified(self, expected_list, test_list, bootstrap=False):
        """
        Compare two lists of tree view strings.

        This responsible expects the same input as :func:`line_compare`, but does some
        additional processing on the ``expected_list``.  To explain, let's take a look
        at the lines involved in the actual minified output:

        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | Index | Collapsible Lists (HTML Unordered List)       | Bootstrap Version (JavaScript Function Returning JSON)           |
        +=======+===============================================+==================================================================+
        | 0     | ``<ul class="treeView" id="class-treeView">`` | ``<script type="text/javascript">``                              |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 1     | ``<li>``                                      | ``function getClassHierarchyTree() {``                           |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 2     | ``<ul class="collapsibleList">``              | ``return [``                                                     |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 3     | ``<<< really long >>>``                       | ``<<< really long >>>``                                          |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 4     | ``</ul>``                                     | ``]``                                                            |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 5     | ``</li><!-- only tree view element -->``      | ``}``                                                            |
        +-------+-----------------------------------------------+------------------------------------------------------------------+
        | 6     | ``</ul><!-- /treeView class-treeView -->``    | ``</script><!-- end getClassHierarchyTree() function --></div>`` |
        +-------+-----------------------------------------------+------------------------------------------------------------------+

        By convenience and design, line ``3`` is really the thing we want to test,
        because that is the meat of the tree view.  For completeness indices ``[0,3)``
        and ``[4,6]`` are also validated, but constructing line ``3`` from the provided
        ``expected_list`` (the **non**-minified ground truth) is the focus of this
        test function.

        **Parameters**
            ``expected_list`` (:class:`python:list` of :class:`python:str`)
                The expected list of strings to compare with.

            ``test_list`` (:class:`python:list` of :class:`python:str`)
                The parsed list of strings to validate.

            ``bootstrap`` (:class:`python:bool`)
                If ``False``, test is a Collapsible Lists test.  If ``True``, test is
                a Bootstrap test.
        """  # noqa: E501
        # First, compare the head / tail of the lists.
        indices = (0, 1, 2, -1, -2, -3)
        expected_head_tail = [expected_list[idx] for idx in indices]
        test_head_tail = [test_list[idx] for idx in indices]
        self.line_compare(expected_head_tail, test_head_tail)

        # Join the remaining elements to make a comparison.
        start = max(indices) + 1 + int(bootstrap)  # TODO: uh. Why + int(bootstrap)?
        end = min(indices)
        interior = "".join(expected_list[start:end])

        if bootstrap:
            # TODO: stop copy-pasting stuff from graph.py and clean this damn framework up.................
            interior = interior.replace(': ', ':').replace(",}", "}").replace(",,", ",").replace(",]", "]")

        self.assertEqual(interior, test_list[start])

    def html_ground_truth_list(self, hierarchy, key):
        """
        Ground truth data for html-based validation tests.

        **Parameters**
            ``hierarchy`` (:class:`python:str`)
                Should **only** be ``"class"`` or ``"file"``.  Indexes into
                :data:`class_hierarchy_ground_truth` and
                :data:`file_hierarchy_ground_truth` respectively.

            ``key`` (:class:`python:str`)
                The key to lookup in either :data:`class_hierarchy_ground_truth` or
                :data:`file_hierarchy_ground_truth`.  Specifically, you really only
                want to be using ``"collapsible_lists"`` or ``"bootstrap"``, since the
                raw reStructuredText version (``createTreeView=False``) can be compared
                directly.

        **Return** (:class:`python:list` of :class:`python:str`)
            The text specified by ``hierarchy[key]``, with every line split and lines
            filtered by :func:`filter_empty_lines`.
        """
        if hierarchy == "class":
            source = class_hierarchy_ground_truth
        elif hierarchy == "file":
            source = file_hierarchy_ground_truth

        raw_text = source[key]
        return self.filter_empty_lines([
            line.strip() for line in raw_text.splitlines()
        ])

    @confoverrides(exhale_args={"createTreeView": False})
    def test_no_custom_html(self):
        """
        Verify the default reStructuredText list appears as expected.
        """
        err_fmt = dedent("""\
            Expected
            ============================================================================
            {expected}

            Got
            ============================================================================
            {got}
        """)
        test_class_view, test_file_view = self.raw_hierarchies()

        class_default = class_hierarchy_ground_truth["default_rst_list"]
        self.assertTrue(
            class_default in test_class_view,
            err_fmt.format(expected=class_default, got=test_class_view))

        file_default = file_hierarchy_ground_truth["default_rst_list"]
        self.assertTrue(
            file_default in test_file_view,
            err_fmt.format(expected=file_default, got=test_file_view)
        )

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": False,
        "treeViewIsBootstrap": False
    })
    def test_collapsible_lists(self):
        """
        Verify the *un-minified* collapsible lists html unordered list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "collapsible_lists")
        expected_file_view_lines = self.html_ground_truth_list("file", "collapsible_lists")

        self.line_compare(expected_class_view_lines, test_class_view_lines)
        self.line_compare(expected_file_view_lines, test_file_view_lines)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": True,
        "treeViewIsBootstrap": False
    })
    def test_collapsible_lists_minified(self):
        """
        Verify the *minified* collapsible lists html unordered list appears as expected.
        """
        self.maxDiff = None
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "collapsible_lists")
        expected_file_view_lines = self.html_ground_truth_list("file", "collapsible_lists")

        self.line_compare_minified(expected_class_view_lines, test_class_view_lines, bootstrap=False)
        self.line_compare_minified(expected_file_view_lines, test_file_view_lines, bootstrap=False)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": False,
        "treeViewIsBootstrap": True
    })
    def test_bootstrap(self):
        """
        Verify the *un-minified* bootstrap json data list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "bootstrap")
        expected_file_view_lines = self.html_ground_truth_list("file", "bootstrap")

        self.line_compare(expected_class_view_lines, test_class_view_lines)
        self.line_compare(expected_file_view_lines, test_file_view_lines)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "treeViewIsBootstrap": True,
        "minifyTreeView": True
    })
    def test_bootstrap_minified(self):
        """
        Verify the *minified* bootstrap json data list appears as expected.
        """
        test_class_view_lines, test_file_view_lines = self.html_hierarchies()
        expected_class_view_lines = self.html_ground_truth_list("class", "bootstrap")
        expected_file_view_lines = self.html_ground_truth_list("file", "bootstrap")

        self.line_compare_minified(expected_class_view_lines, test_class_view_lines, bootstrap=True)
        self.line_compare_minified(expected_file_view_lines, test_file_view_lines, bootstrap=True)
