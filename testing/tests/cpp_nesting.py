# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_nesting`` project.
"""

from __future__ import unicode_literals

import os.path as osp
from textwrap import dedent

from exhale.utils import heading_mark

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides, no_cleanup
from testing.hierarchies import                                                        \
    class_hierarchy, compare_class_hierarchy, compare_file_hierarchy, file,            \
    file_hierarchy, page


# NOTE: See setUp / tearDown in CPPNestingPages below.  That file is being
# generated to test the page hierarchy, but we don't want it included in the
# tests here which assert the page hierarchy being empty.
# TODO: assert that the page hierarchy is actually empty.
@confoverrides(exhale_args={
    "exhaleDoxygenStdin": dedent("""\
        INPUT            = ../include
        EXCLUDE_PATTERNS = */page_town_rock*.hpp
    """)})
class CPPNesting(ExhaleTestCase):
    """
    Primary test class for project ``cpp_nesting``.
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
        assert len(self.app.exhale_root.pages) == 0  # pages got excluded

    @confoverrides(exhale_args={"doxygenStripFromPath": "../include"})
    def test_hierarchies_stripped(self):
        """
        Verify the class and file hierarchies with ``doxygenStripFromPath=../include``.
        """
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
        # dirty hack to pop off the first include/ directory without needing to know
        # the actual object that is the first and only key
        file_hierarchy_dict = self.file_hierarchy_dict()
        for key in file_hierarchy_dict:
            no_include = file_hierarchy_dict[key]
            break
        compare_file_hierarchy(self, file_hierarchy(no_include))


class CPPNestingPages(ExhaleTestCase):
    """
    Primary test class for project ``doxygenpage``.

    .. note::

        Setup for this test is particularly fickle.  There are only two test
        cases because there are only two file paths we generate.  Order of tests
        is not guaranteed, so each test needs to exclude it's alternate.  Eww.
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    def get_gen_page(self, page):
        """Return the generated node's rst document text as a string."""
        gen_file = osp.join(page.root_owner.root_directory, page.file_name)
        with open(gen_file, "r") as f:
            return f.read()

    def check_gen_page(self, page):
        """Verify expected link, title, and directive are on the page."""
        # NOTE: should *never* be called with p.refid == "indexpage", that is
        # not generated.
        page_contents = self.get_gen_page(page)
        link = "_page_{refid}".format(refid=page.refid)
        title = "{title}\n{underline}".format(
            title=page.title, underline=heading_mark(page.title, "="))
        directive = ".. doxygenpage:: {refid}".format(refid=page.refid)
        assert link in page_contents
        assert title in page_contents
        assert directive in page_contents

    def check_most_pages(self, uses_mainpage=True, main_refid="indexpage"):
        r"""Check the majority of the page generation.

        **Parameters**
            uses_mainpage (:class:`python:bool`)
                Whether or not ``\mainpage`` is used.

            main_refid (:class:`python:str`)
                If ``uses_mainpage`` is ``False``, then whatever ``\mainpage``
                was replaced to ``\page {main_refid}``.
        """
        # Checks that the right files are included or not included in the library
        # root document.  Specifically, whether these are found:
        #
        #     - .. include:: page_index.rst from doxygen \mainpage
        #     - .. include:: page_view_hierarchy.rst (from any \page not \mainpage)
        self.test_common()

        # Make sure nothing changed with the class / file hierarchies.
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
        file_hierarchy_dict = self.file_hierarchy_dict()
        include_dir = set(file_hierarchy_dict.keys()).pop()
        # TODO: make this a parameter if we add more than two tests...
        if uses_mainpage:
            f_name = "page_town_rock.hpp"
            outer_page = "index"
        else:
            f_name = "page_town_rock_alt.hpp"
            outer_page = "overview"

        file_hierarchy_dict[include_dir][file(f_name)] = {
            page(outer_page): {
                page("intro"): {
                    page("more_nesting"): {},
                    page("more_nesting_redux"): {
                        page("more_nesting_redux_again"): {},
                        page("more_nesting_redux_again_again"): {}
                    }
                },
                page("advanced"): {}
            },
        }
        compare_file_hierarchy(self, file_hierarchy(file_hierarchy_dict))

        # Validate the misc page hierarchy details.
        exhale_root = self.app.exhale_root
        all_pages = [p for p in exhale_root.all_nodes if p.kind == "page"]
        assert len(all_pages) == 7

        # \mainpage A simple manual
        # - \subpage intro
        # - \subpage advanced "Advanced usage"
        assert len(exhale_root.pages) == 1
        index = exhale_root.pages[0]
        assert index.refid == main_refid
        if not uses_mainpage:
            self.check_gen_page(index)
        assert len(index.children) == 2
        # NOTE: sort should keep intro in front of advanced.
        index_children = sorted(index.children)
        assert index_children[0].refid == "intro"
        assert index_children[1].refid == "advanced"

        # \page intro Introduction
        # - \subpage more_nesting
        # - \subpage more_nesting_redux
        intro = index_children[0]
        assert len(intro.children) == 2
        assert intro.children[0].refid == "more_nesting"
        assert intro.children[1].refid == "more_nesting_redux"
        self.check_gen_page(intro)

        # \page advanced Advanced Usage
        advanced = index_children[1]
        assert len(advanced.children) == 0
        self.check_gen_page(advanced)

        # \page more_nesting More Information
        mn = intro.children[0]
        assert len(mn.children) == 0
        self.check_gen_page(mn)

        # \page more_nesting_redux Even More Information
        mnr = intro.children[1]
        # - \subpage more_nesting_redux_again
        # - \subpage more_nesting_redux_again_again
        assert len(mnr.children) == 2
        assert mnr.children[0].refid == "more_nesting_redux_again"
        assert mnr.children[1].refid == "more_nesting_redux_again_again"
        self.check_gen_page(mnr)

        # \page more_nesting_redux_again Too Much Information
        mnra = mnr.children[0]
        assert len(mnra.children) == 0
        self.check_gen_page(mnra)

        # \page more_nesting_redux_again_again Way Too Much Information
        mnraa = mnr.children[1]
        assert len(mnraa.children) == 0
        self.check_gen_page(mnraa)

    @confoverrides(exhale_args={
        "rootFileTitle": "",
        "exhaleDoxygenStdin": dedent("""\
            INPUT            = ../include
            EXCLUDE_PATTERNS = */page_town_rock_alt.hpp
        """)})
    def test_hierarchies_primary_mainpage(self):
        """Verify the class, file, and page hierarchies."""
        self.check_most_pages(uses_mainpage=True)
        # Last but not least, we expect the hierarchy to *not* have indexpage.
        expected_page_hierarchy = dedent(r"""
            Page Hierarchy
            --------------

            - :ref:`page_intro`
                - :ref:`page_more_nesting`
                - :ref:`page_more_nesting_redux`
                    - :ref:`page_more_nesting_redux_again`
                    - :ref:`page_more_nesting_redux_again_again`
            - :ref:`page_advanced`
        """)
        with open(self.app.exhale_root.page_hierarchy_file, "r") as phf:
            assert expected_page_hierarchy in phf.read()

    @confoverrides(exhale_args={
        "exhaleDoxygenStdin": dedent("""\
            INPUT            = ../include
            EXCLUDE_PATTERNS = */page_town_rock.hpp
        """)})
    def test_hierarchies_primary_no_mainpage(self):
        """Verify the class, file, and page hierarchies."""
        self.check_most_pages(uses_mainpage=False, main_refid="overview")

        # Last but not least, we expect the hierarchy to *not* have indexpage.
        expected_page_hierarchy = dedent(r"""
            Page Hierarchy
            --------------

            - :ref:`page_overview`
                - :ref:`page_intro`
                    - :ref:`page_more_nesting`
                    - :ref:`page_more_nesting_redux`
                        - :ref:`page_more_nesting_redux_again`
                        - :ref:`page_more_nesting_redux_again_again`
                - :ref:`page_advanced`
        """)
        with open(self.app.exhale_root.page_hierarchy_file, "r") as phf:
            assert expected_page_hierarchy in phf.read()

    @no_cleanup
    @confoverrides(exhale_args={
        "rootFileTitle": "",
        "exhaleDoxygenStdin": dedent("""\
            INPUT            = ../include
            EXCLUDE_PATTERNS = */page_town_rock_alt.hpp
        """)})
    def test_html_output(self):
        """
        Verify exhale builds a project.

        This is not really a test.  But it can be helpful to view a test project build,
        in the ``testing/projects/cpp_nesting`` folder you can open
        ``docs_CPPNestingPages_test_html_output/_build/html/index.html`` to view.
        """
        self.app.build()
