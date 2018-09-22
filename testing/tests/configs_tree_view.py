# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests specifically focused on the various tree view configurations.
"""
from __future__ import unicode_literals
import os
import re
import textwrap

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides


class_hierarchy_ground_truth = {
    "default_rst_list": textwrap.dedent(r'''
        - :ref:`namespace_nested`
            - :ref:`namespace_nested__dual_nested`
                - :ref:`exhale_struct_structnested_1_1dual__nested_1_1one`
                    - :ref:`exhale_struct_structnested_1_1dual__nested_1_1one_1_1params`
                        - :ref:`exhale_union_unionnested_1_1dual__nested_1_1one_1_1params_1_1four__bytes`
                - :ref:`exhale_struct_structnested_1_1dual__nested_1_1two`
                    - :ref:`exhale_struct_structnested_1_1dual__nested_1_1two_1_1params`
                        - :ref:`exhale_union_unionnested_1_1dual__nested_1_1two_1_1params_1_1four__bytes`
            - :ref:`exhale_struct_structnested_1_1one`
                - :ref:`exhale_struct_structnested_1_1one_1_1params`
                    - :ref:`exhale_union_unionnested_1_1one_1_1params_1_1four__bytes`
            - :ref:`exhale_struct_structnested_1_1two`
                - :ref:`exhale_struct_structnested_1_1two_1_1params`
                    - :ref:`exhale_union_unionnested_1_1two_1_1params_1_1four__bytes`
            - :ref:`exhale_union_unionnested_1_1four__bytes`
        - :ref:`exhale_struct_structtop__level`
    '''),
    "collapsible_lists": textwrap.dedent(r'''
        <ul class="treeView" id="class-treeView">
        <li>
            <ul class="collapsibleList">
            <li>
                Namespace <a href="namespace_nested.html#namespace-nested">nested</a>
                <ul>
                <li>
                    Namespace <a href="namespace_nested__dual_nested.html#namespace-nested-dual-nested">nested::dual_nested</a>
                    <ul>
                    <li>
                        Struct <a href="structnested_1_1dual__nested_1_1one.html#exhale-struct-structnested-1-1dual-nested-1-1one">one</a>
                        <ul>
                        <li class="lastChild">
                            Struct <a href="structnested_1_1dual__nested_1_1one_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1one-1-1params">one::params</a>
                            <ul>
                            <li class="lastChild">Union <a href="unionnested_1_1dual__nested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1one-1-1params-1-1four-bytes">params::four_bytes</a></li>
                            </ul>
                        </li>
                        </ul>
                    </li>
                    <li class="lastChild">
                        Struct <a href="structnested_1_1dual__nested_1_1two.html#exhale-struct-structnested-1-1dual-nested-1-1two">two</a>
                        <ul>
                        <li class="lastChild">
                            Struct <a href="structnested_1_1dual__nested_1_1two_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1two-1-1params">two::params</a>
                            <ul>
                            <li class="lastChild">Union <a href="unionnested_1_1dual__nested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1two-1-1params-1-1four-bytes">params::four_bytes</a></li>
                            </ul>
                        </li>
                        </ul>
                    </li>
                    </ul>
                </li>
                <li>
                    Struct <a href="structnested_1_1one.html#exhale-struct-structnested-1-1one">one</a>
                    <ul>
                    <li class="lastChild">
                        Struct <a href="structnested_1_1one_1_1params.html#exhale-struct-structnested-1-1one-1-1params">one::params</a>
                        <ul>
                        <li class="lastChild">Union <a href="unionnested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1one-1-1params-1-1four-bytes">params::four_bytes</a></li>
                        </ul>
                    </li>
                    </ul>
                </li>
                <li>
                    Struct <a href="structnested_1_1two.html#exhale-struct-structnested-1-1two">two</a>
                    <ul>
                    <li class="lastChild">
                        Struct <a href="structnested_1_1two_1_1params.html#exhale-struct-structnested-1-1two-1-1params">two::params</a>
                        <ul>
                        <li class="lastChild">Union <a href="unionnested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1two-1-1params-1-1four-bytes">params::four_bytes</a></li>
                        </ul>
                    </li>
                    </ul>
                </li>
                <li class="lastChild">Union <a href="unionnested_1_1four__bytes.html#exhale-union-unionnested-1-1four-bytes">four_bytes</a></li>
                </ul>
            </li>
            <li class="lastChild">Struct <a href="structtop__level.html#exhale-struct-structtop-level">top_level</a></li>

            </ul>
        </li><!-- only tree view element -->
        </ul><!-- /treeView class-treeView -->
    '''),  # noqa: E501
    "bootstrap": textwrap.dedent(r'''
        <div id="class-treeView"></div>
        <script type="text/javascript">
        function getClassHierarchyTree() {
            return [
            {
                text: "<span class=\"text-muted\">Namespace</span> nested",
                href: "namespace_nested.html#namespace-nested",
                selectable: false,
                tags: ['4'],

                nodes: [
                {
                    text: "<span class=\"text-muted\">Namespace</span> nested::dual_nested",
                    href: "namespace_nested__dual_nested.html#namespace-nested-dual-nested",
                    selectable: false,
                    tags: ['2'],

                    nodes: [
                    {
                        text: "<span class=\"text-muted\">Struct</span> one",
                        href: "structnested_1_1dual__nested_1_1one.html#exhale-struct-structnested-1-1dual-nested-1-1one",
                        selectable: false,
                        tags: ['1'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">Struct</span> one::params",
                            href: "structnested_1_1dual__nested_1_1one_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1one-1-1params",
                            selectable: false,
                            tags: ['1'],

                            nodes: [
                            {
                                text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                                href: "unionnested_1_1dual__nested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1one-1-1params-1-1four-bytes",
                                selectable: false,
                            },
                            ]
                        },
                        ]
                    },
                    {
                        text: "<span class=\"text-muted\">Struct</span> two",
                        href: "structnested_1_1dual__nested_1_1two.html#exhale-struct-structnested-1-1dual-nested-1-1two",
                        selectable: false,
                        tags: ['1'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">Struct</span> two::params",
                            href: "structnested_1_1dual__nested_1_1two_1_1params.html#exhale-struct-structnested-1-1dual-nested-1-1two-1-1params",
                            selectable: false,
                            tags: ['1'],

                            nodes: [
                            {
                                text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                                href: "unionnested_1_1dual__nested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1dual-nested-1-1two-1-1params-1-1four-bytes",
                                selectable: false,
                            },
                            ]
                        },
                        ]
                    },
                    ]
                },
                {
                    text: "<span class=\"text-muted\">Struct</span> one",
                    href: "structnested_1_1one.html#exhale-struct-structnested-1-1one",
                    selectable: false,
                    tags: ['1'],

                    nodes: [
                    {
                        text: "<span class=\"text-muted\">Struct</span> one::params",
                        href: "structnested_1_1one_1_1params.html#exhale-struct-structnested-1-1one-1-1params",
                        selectable: false,
                        tags: ['1'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                            href: "unionnested_1_1one_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1one-1-1params-1-1four-bytes",
                            selectable: false,
                        },
                        ]
                    },
                    ]
                },
                {
                    text: "<span class=\"text-muted\">Struct</span> two",
                    href: "structnested_1_1two.html#exhale-struct-structnested-1-1two",
                    selectable: false,
                    tags: ['1'],

                    nodes: [
                    {
                        text: "<span class=\"text-muted\">Struct</span> two::params",
                        href: "structnested_1_1two_1_1params.html#exhale-struct-structnested-1-1two-1-1params",
                        selectable: false,
                        tags: ['1'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">Union</span> params::four_bytes",
                            href: "unionnested_1_1two_1_1params_1_1four__bytes.html#exhale-union-unionnested-1-1two-1-1params-1-1four-bytes",
                            selectable: false,
                        },
                        ]
                    },
                    ]
                },
                {
                    text: "<span class=\"text-muted\">Union</span> four_bytes",
                    href: "unionnested_1_1four__bytes.html#exhale-union-unionnested-1-1four-bytes",
                    selectable: false,
                },
                ]
            },
            {
                text: "<span class=\"text-muted\">Struct</span> top_level",
                href: "structtop__level.html#exhale-struct-structtop-level",
                selectable: false,
            },

            ]
        }
        </script><!-- end getClassHierarchyTree() function -->
    ''')  # noqa: E501
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
    "default_rst_list": textwrap.dedent(r'''
        - :ref:`dir_include`
            - :ref:`dir_include_nested`
                - :ref:`dir_include_nested_dual_nested`
                    - :ref:`dir_include_nested_dual_nested_one`
                        - :ref:`file_include_nested_dual_nested_one_one.hpp`
                    - :ref:`dir_include_nested_dual_nested_two`
                        - :ref:`file_include_nested_dual_nested_two_two.hpp`
                - :ref:`dir_include_nested_one`
                    - :ref:`file_include_nested_one_one.hpp`
                - :ref:`dir_include_nested_two`
                    - :ref:`file_include_nested_two_two.hpp`
            - :ref:`file_include_top_level.hpp`
    '''),
    "collapsible_lists": textwrap.dedent(r'''
        <ul class="treeView" id="file-treeView">
        <li>
            <ul class="collapsibleList">
            <li class="lastChild">
                Directory <a href="dir_include.html#dir-include">include</a>
                <ul>
                <li>
                    Directory <a href="dir_include_nested.html#dir-include-nested">nested</a>
                    <ul>
                    <li>
                        Directory <a href="dir_include_nested_dual_nested.html#dir-include-nested-dual-nested">nested</a>
                        <ul>
                        <li>
                            Directory <a href="dir_include_nested_dual_nested_one.html#dir-include-nested-dual-nested-one">one</a>
                            <ul>
                            <li class="lastChild">File <a href="file_include_nested_dual_nested_one_one.hpp.html#file-include-nested-dual-nested-one-one.hpp">one.hpp</a></li>
                            </ul>
                        </li>
                        <li class="lastChild">
                            Directory <a href="dir_include_nested_dual_nested_two.html#dir-include-nested-dual-nested-two">two</a>
                            <ul>
                            <li class="lastChild">File <a href="file_include_nested_dual_nested_two_two.hpp.html#file-include-nested-dual-nested-two-two.hpp">two.hpp</a></li>
                            </ul>
                        </li>
                        </ul>
                    </li>
                    <li>
                        Directory <a href="dir_include_nested_one.html#dir-include-nested-one">one</a>
                        <ul>
                        <li class="lastChild">File <a href="file_include_nested_one_one.hpp.html#file-include-nested-one-one.hpp">one.hpp</a></li>
                        </ul>
                    </li>
                    <li class="lastChild">
                        Directory <a href="dir_include_nested_two.html#dir-include-nested-two">two</a>
                        <ul>
                        <li class="lastChild">File <a href="file_include_nested_two_two.hpp.html#file-include-nested-two-two.hpp">two.hpp</a></li>
                        </ul>
                    </li>
                    </ul>
                </li>
                <li class="lastChild">File <a href="file_include_top_level.hpp.html#file-include-top-level.hpp">top_level.hpp</a></li>
                </ul>
            </li>

            </ul>
        </li><!-- only tree view element -->
        </ul><!-- /treeView file-treeView -->
    '''),  # noqa: E501
    "bootstrap": textwrap.dedent(r'''
        <div id="file-treeView"></div>
        <script type="text/javascript">
        function getFileHierarchyTree() {
            return [
            {
                text: "<span class=\"text-muted\">Directory</span> include",
                href: "dir_include.html#dir-include",
                selectable: false,
                tags: ['2'],

                nodes: [
                {
                    text: "<span class=\"text-muted\">Directory</span> nested",
                    href: "dir_include_nested.html#dir-include-nested",
                    selectable: false,
                    tags: ['3'],

                    nodes: [
                    {
                        text: "<span class=\"text-muted\">Directory</span> nested",
                        href: "dir_include_nested_dual_nested.html#dir-include-nested-dual-nested",
                        selectable: false,
                        tags: ['2'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">Directory</span> one",
                            href: "dir_include_nested_dual_nested_one.html#dir-include-nested-dual-nested-one",
                            selectable: false,
                            tags: ['1'],

                            nodes: [
                            {
                                text: "<span class=\"text-muted\">File</span> one.hpp",
                                href: "file_include_nested_dual_nested_one_one.hpp.html#file-include-nested-dual-nested-one-one.hpp",
                                selectable: false,
                            },
                            ]
                        },
                        {
                            text: "<span class=\"text-muted\">Directory</span> two",
                            href: "dir_include_nested_dual_nested_two.html#dir-include-nested-dual-nested-two",
                            selectable: false,
                            tags: ['1'],

                            nodes: [
                            {
                                text: "<span class=\"text-muted\">File</span> two.hpp",
                                href: "file_include_nested_dual_nested_two_two.hpp.html#file-include-nested-dual-nested-two-two.hpp",
                                selectable: false,
                            },
                            ]
                        },
                        ]
                    },
                    {
                        text: "<span class=\"text-muted\">Directory</span> one",
                        href: "dir_include_nested_one.html#dir-include-nested-one",
                        selectable: false,
                        tags: ['1'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">File</span> one.hpp",
                            href: "file_include_nested_one_one.hpp.html#file-include-nested-one-one.hpp",
                            selectable: false,
                        },
                        ]
                    },
                    {
                        text: "<span class=\"text-muted\">Directory</span> two",
                        href: "dir_include_nested_two.html#dir-include-nested-two",
                        selectable: false,
                        tags: ['1'],

                        nodes: [
                        {
                            text: "<span class=\"text-muted\">File</span> two.hpp",
                            href: "file_include_nested_two_two.hpp.html#file-include-nested-two-two.hpp",
                            selectable: false,
                        },
                        ]
                    },
                    ]
                },
                {
                    text: "<span class=\"text-muted\">File</span> top_level.hpp",
                    href: "file_include_top_level.hpp.html#file-include-top-level.hpp",
                    selectable: false,
                },
                ]
            },

            ]
        }
        </script><!-- end getFileHierarchyTree() function -->
    ''')  # noqa: E501
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
        """Path to ``class_view_hierarchy.rst`` for this test."""
        return os.path.join(self.getAbsContainmentFolder(), "class_view_hierarchy.rst")

    def file_view_hierarchy_file(self):
        """Path to ``file_view_hierarchy.rst`` for this test."""
        return os.path.join(self.getAbsContainmentFolder(), "file_view_hierarchy.rst")

    def raw_hierarchies(self):
        """
        Raw contents of ``class_view_hierarchy.rst`` and ``file_view_hierarchy.rst``.

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
        empty = re.compile(r"^$")
        only_whitespace = re.compile(r"^\s+$")
        return [
            line for line in lst
            if not empty.match(line) and not only_whitespace.match(line)
        ]

    def html_hierarchies(self):
        """
        Hierarchy text from ``class_view_hierarchy.rst`` and ``file_view_hierarchy.rst``.

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
        class_view, file_view = self.raw_hierarchies()
        self.assertTrue(
            class_hierarchy_ground_truth["default_rst_list"] in class_view
        )
        self.assertTrue(
            file_hierarchy_ground_truth["default_rst_list"] in file_view
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
        class_view_lines, file_view_lines = self.html_hierarchies()
        class_ground_truth_lines = self.html_ground_truth_list("class", "collapsible_lists")
        file_ground_truth_lines = self.html_ground_truth_list("file", "collapsible_lists")

        self.line_compare(class_ground_truth_lines, class_view_lines)
        self.line_compare(file_ground_truth_lines, file_view_lines)

    @confoverrides(exhale_args={
        "createTreeView": True,
        "minifyTreeView": False,
        "treeViewIsBootstrap": True
    })
    def test_bootstrap(self):
        """
        Verify the *un-minified* bootstrap json data list appears as expected.
        """
        class_view_lines, file_view_lines = self.html_hierarchies()
        class_ground_truth_lines = self.html_ground_truth_list("class", "bootstrap")
        file_ground_truth_lines = self.html_ground_truth_list("file", "bootstrap")

        self.line_compare(class_ground_truth_lines, class_view_lines)
        self.line_compare(file_ground_truth_lines, file_view_lines)
