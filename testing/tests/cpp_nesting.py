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

import os
import os.path as osp
from textwrap import dedent

import pytest

from testing import TEST_PROJECTS_ROOT
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


def with_page_hierarchy(f_path, page_hierarchy):
    """
    Return a function using a generated fixture creating a page hierarchy.

    The generated fixture generates a fixture that will create ``f_path`` prior to the
    test running (so Doxygen sees it) and then afterward deletes the file.  The comment
    generated will follow the provided ``page_hierarchy``.

    **Parameters**
    ``f_path`` (:class:`python:str`)
        The destination to generate the C++ documented file encoding the specified
        ``page_hierarchy``.

    ``page_hierarchy`` (:class:`python:dict`)
        A dictionary of :ref:`~testing.hierarchies.mainpage`,
        :ref:`~testing.hierarchies.page`, and/or :ref:`~testing.hierarchies.subpage`
        keys that either map to a :ref:`~testing.hierarchies.page_contents` node, or
        a subpage.

    **Return**
    The input ``func``, after executing ``pytest.mark.usefixtures``.
    """
    def actual_decorator(func):
        # NOTE: this is only supposed to be used on test functions, *BUT* controlling
        # order of fixtures is chaos and so I just cheat and force it to module scope
        # so that it actually runs before sphinx (and therefore doxygen).
        @pytest.fixture(scope="module")
        def page_town_rock_fixture():
            with open(f_path, "w") as f:
                f.write(dedent(r"""
                    /**
                     * \file page_town_rock.hpp
                     * yardy hardy har
                     */
                    /**
                    * \page super Super
                    * How interesting it is to be a page.  A super page.
                    *
                    * \section super_first First Things First
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
            globals()["active_page_hierarchy"] = {"page": "hierarchy"}

            yield

            del globals()["active_page_hierarchy"]
            if osp.isfile(f_path):
                os.remove(f_path)
            del globals()["page_town_rock_fixture"]

        globals()["page_town_rock_fixture"] = page_town_rock_fixture
        return pytest.mark.usefixtures("page_town_rock_fixture")(func)

    return actual_decorator


page_town_rock_hpp_path = osp.join(
    TEST_PROJECTS_ROOT, "cpp_nesting", "include", "page_town_rock.hpp")
r"""File path to generate for tests on ``\page`` / ``\subpage`` commands."""


class CPPNestingPages(ExhaleTestCase):
    """
    Primary test class for project ``doxygenpage``.
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    def get_page_hierarchy(self):
        """
        Return the ``page_hierarchy`` that was created in |with_page_hierarchy|.

        The decorator just stashes it in ``globals()["active_page_hierarchy"]``.
        """
        return globals()["active_page_hierarchy"]

    @with_page_hierarchy(page_town_rock_hpp_path, {})
    def test_hierarchies_without_pages(self):
        """Verify the class, file, and page hierarchies with pages excluded."""
        # import ipdb
        # ipdb.set_trace()
        self.app.build()
        page_hierarchy = self.get_page_hierarchy()
        print(page_hierarchy)
        # TODO: test that page hierarchy is not written (no pages included)
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
