# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2019, Stephen McDowell.             #
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

import pytest

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides, no_cleanup
from testing.hierarchies import                                                        \
    class_hierarchy, compare_class_hierarchy, compare_file_hierarchy, file_hierarchy


# NOTE: See setUp / tearDown in CPPNestingPages below.  That file is being
# generated to test the page hierarchy, but we don't want it included in the
# tests here which assert the page hierarchy being empty.
# TODO: assert that the page hierarchy is actually empty.
@confoverrides(exhale_args={
    "exhaleDoxygenStdin": dedent("""\
        INPUT            = ../include
        EXCLUDE_PATTERNS = */page_town_rock.hpp
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
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    def _page_town_rock_hpp_path(self):
        project_root = osp.abspath(osp.dirname(self.testroot))
        return osp.join(project_root, "include", "page_town_rock.hpp")

    def setUp(self):
        r"""
        Create ``page_town_rock.hpp`` with various ``\\page`` / ``\\subpage`` combos.
        """
        # TODO: this needs to be a fixture like the cpp_long_names one?
        # test_name = self.id().split(".")[-1]
        # test_func = getattr(self.__class__, test_name)
        # marks = getattr(test_func, "pytestmark", False)
        # if marks and any(m.name == "page_town_rock" for m in marks):
        #     import ipdb
        #     ipdb.set_trace()

        # project_root = osp.abspath(osp.dirname(self.testroot))
        with open(self._page_town_rock_hpp_path(), "w") as f:
            f.write(dedent(r"""\
                /**
                 * \\page super Super
                 * How interesting it is to be a page.  A super page.
                 *
                 * \\section super_first First Things First
                 * It is the first of times, it is the worst of times.
                 *
                 * \section super_second Second
                 * It is the second of times, it is the worst of times.
                 */
                /**
                 * \page super_super Super Super
                 * Super to be super.
                 *
                 * \subpage super_super_super Super Super Super
                 * Super super super.
                 */
            """))

    @pytest.mark.page_town_rock
    def test_hierarchies_without_pages(self):
        """Verify the class, file, and page hierarchies with pages excluded."""
        # TODO: test that page hierarchy is not written (no pages included)
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))

    # TODO: delete no_cleanup before merge.  Generated files go in
    # B = testing/projects/cpp_nesting/docs_CPPNestingPages_test_hierarchies_with_pages_dracula_is_mainpage/
    # - Doxygen XML: $B/_doxygen
    # - Sphinx html: $B/_build/html
    @pytest.mark.page_town_rock
    @confoverrides(exhale_args={
        "exhaleDoxygenStdin": dedent("""\
            INPUT       = ../include
            PREDEFINED += DOXYGEN_TEST_PAGES
            PREDEFINED += DRACULA_IS_MAINPAGE
            GENERATE_HTML = YES
        """),
        "verboseBuild": True})
    @no_cleanup
    def test_hierarchies_with_pages_dracula_is_mainpage(self):
        """Verify the class, file, and page hierarchies when pages included."""
        # TODO: test that page hierarchy is written and correct
        #
        # TODO: remove html build() call when the test is working to go back
        #       to using just XML validation, this is here to help the humans.
        self.app.build()
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))

    # TODO: delete no_cleanup before merge.  Generated files go in
    # B = testing/projects/cpp_nesting/docs_CPPNestingPages_test_hierarchies_with_pages_dracula_not_mainpage/
    # - Doxygen XML: $B/_doxygen
    # - Sphinx html: $B/_build/html
    @confoverrides(exhale_args={
        "exhaleDoxygenStdin": dedent("""\
            INPUT       = ../include
            PREDEFINED += DOXYGEN_TEST_PAGES
        """),
        "verboseBuild": True})
    @no_cleanup
    @pytest.mark.page_town_rock
    def test_hierarchies_with_pages_dracula_not_mainpage(self):
        """Verify the class, file, and page hierarchies when pages included."""
        # TODO: test that page hierarchy is written and correct
        #
        # TODO: remove html build() call when the test is working to go back
        #       to using just XML validation, this is here to help the humans.
        self.app.build()
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
