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

import itertools
import os
import re
from io import StringIO
from pathlib import Path
from textwrap import dedent

from exhale.graph import ExhaleRoot

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides
from testing.hierarchies import class_hierarchy, file_hierarchy, get_exhale_root

this_file_dir = Path(__file__).parent.absolute()
"""The path to the directory containing this file."""

class_data_root = this_file_dir / "configs_tree_view_data" / "classes"
"""The class view hierarchy test validation data root for tree view."""

file_data_root = this_file_dir / "configs_tree_view_data" / "files"
"""The file view hierarchy test validation root for tree view."""

tree_view_keys = {"collapsible_lists", "bootstrap"}
"""Available kinds of tree views to validate against."""


def read_default_data(root: Path, file_name: str) -> str:
    """
    Open, read, and return the contents of the file ``{root}/{file_name}``.
    """
    with open(root / file_name) as f:
        return f.read()


class_hierarchy_ground_truth = {
    k: read_default_data(class_data_root, f"{k}.txt") for k in tree_view_keys
}
"""
Ground truth for the three versions of class hierarchies.

Keys and what they represent:

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).

.. todo::

    This will break if / when doxygen refid generation changes.  In theory it should be
    possible to synthetically re-create the hierarchy without this crazy text processing.
"""

file_hierarchy_ground_truth = {
    k: read_default_data(file_data_root, f"{k}.txt") for k in tree_view_keys
}
"""
Ground truth for the three versions of file hierarchies.

Keys and what they represent:

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).

.. todo::

   This one should be possible to re-create manually rather than relying on direct text
   comparisons.  But until you figure out how to do the class one more programmatically
   you aren't doing that lolz.

.. todo::

   It's been done programmatically for the rst lists, but that's because we need the
   refid's which change.  It's not exactly a great test though, raw comparisons are
   probably more strict.  Untodo this?  Hehehe.
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
        # TODO: refid extraction could probably be useful for all hierarchies but right
        # now I just want to be done with this.  Relying on node.name / node.location
        # may or may not be reliable for all test projects (?)  Hence TODO...
        #
        # The internal links generated by exhale for an individual node's page title
        # include the refid, which for template specializations and nested template
        # classes can change on different platforms.  To validate the rst list, which
        # will be a bulleted list
        #
        # - :ref:`exhale_internal_link_1`
        #     - :ref:`exhale_internal_link_2`
        #
        # we need to obtain the matching test and exhale nodes.  Note that for this test
        # we **assume** the hierarchies are valid, the cpp_nesting tests will test this
        # directly via hierarchies.compare_{class,file}_hierarchy (but this test will
        # also fail if those do).
        test_classes = class_hierarchy(self.class_hierarchy_dict())
        test_files = file_hierarchy(self.file_hierarchy_dict())
        test_file_dir = [n for n in test_files.all_nodes if n.kind in {"file", "dir"}]
        exhale_root = get_exhale_root(self)

        # Class and file hierarchies are validated separately, extract them into two
        # slightly more convenient lists as separate entities.
        exhale_non_file_dir = []
        exhale_file_dir = []
        for node in exhale_root.all_nodes:
            if node.kind in {"file", "dir"}:
                exhale_file_dir.append(node)
            # TODO: wtf is doxygen putting this in there for?! (cpp_nesting...)
            elif node.kind != "namespace" or \
                    (node.kind == "namespace" and node.name != "std"):
                exhale_non_file_dir.append(node)

        def _assign_refids(exhale_list, test_list, hierarchy_type):
            # Include the kind for error printing.
            n_e = len(exhale_list)
            e = set([(n.kind, n.name) for n in exhale_list])
            n_t = len(test_list)
            t = set([(n.kind, n.name) for n in test_list])
            self.assertEqual(
                n_e, n_t,
                f"Unable to recover corresponding {hierarchy_type} hierarchy, found "
                f"{n_e} exhale nodes and {n_t} test nodes: {e ^ t}")

            # Make sure we have unique names, otherwise refid matching is invalid.
            e_names = [
                n.name if n.kind != "file" else n.location for n in exhale_list
            ]
            t_names = [
                n.name if n.kind != "file" else n.location for n in test_list
            ]
            self.assertEqual(
                len(e_names), len(set(e_names)),
                f"Duplicate exhale names found, cannot match refids: {e_names}")
            self.assertEqual(
                len(t_names), len(set(t_names)),
                f"Duplicate test names found, cannot match refids: {t_names}")

            n_refids_assigned = 0
            for e_node in exhale_list:
                for t_node in test_list:
                    if e_node.kind == "file" and t_node.kind == "file":
                        if e_node.location == t_node.location:
                            t_node.refid = e_node.refid
                            n_refids_assigned += 1
                            break
                    elif e_node.kind != "file" and t_node.kind != "file":
                        if e_node.name == t_node.name:
                            t_node.refid = e_node.refid
                            n_refids_assigned += 1
                            break

            self.assertEqual(
                n_e, n_refids_assigned,
                f"Expected to assign {n_e} refids but {n_refids_assigned} were "
                "assigned.")

        _assign_refids(exhale_non_file_dir, test_classes.all_nodes, "class")
        _assign_refids(exhale_file_dir, test_file_dir, "file")

        # This is extremely dubious but it works.  Now that refid is available, we need
        # to generate the link names.
        proxy_root = ExhaleRoot()
        for node in itertools.chain(test_classes.all_nodes, test_file_dir):
            proxy_root.initializeNodeFilenameAndLink(node)

        # Now that the test nodes have refids, generate their hierarchies.  The order
        # in which the test case presents things may differ from how doxygen / exhale
        # present them, all we care about is that the lines generated are all there
        # (including correct indentation).
        test_class_hierarchy = StringIO()
        for node in test_classes.top_level:
            node.toHierarchy("class", 0, test_class_hierarchy)
        test_class_lines = test_class_hierarchy.getvalue().splitlines()
        test_class_hierarchy.close()

        test_file_hierarchy = StringIO()
        for node in test_files.top_level:
            node.toHierarchy("file", 0, test_file_hierarchy)
        test_file_lines = test_file_hierarchy.getvalue().splitlines()
        test_file_hierarchy.close()

        # Grab the actual generated hierarchies from exhale.  Only grab the bullets.
        exhale_class_view_raw, exhale_file_view_raw = self.raw_hierarchies()
        exhale_class_lines = [
            line for line in exhale_class_view_raw.splitlines() if "- :ref:" in line
        ]
        exhale_file_lines = [
            line for line in exhale_file_view_raw.splitlines() if "- :ref:" in line
        ]

        def _set_compare(exhale_list, test_list, hierarchy_type):
            e = set(exhale_list)
            t = set(test_list)
            self.assertEqual(
                len(exhale_list), len(e),
                f"Internal test failure, expected unique items: {exhale_list}")
            self.assertEqual(
                len(test_list), len(t),
                f"Internal test failure, expected unique items: {test_list}")
            self.assertEqual(e, t)

        _set_compare(exhale_class_lines, test_class_lines, "class")
        _set_compare(exhale_file_lines, test_file_lines, "file")

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
