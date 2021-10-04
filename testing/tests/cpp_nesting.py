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

from textwrap import dedent

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides, no_cleanup
from testing.hierarchies import                                              \
    class_hierarchy, clike, compare_class_hierarchy, compare_file_hierarchy, \
    directory, file, file_hierarchy, namespace, union


class CPPNesting(ExhaleTestCase):
    """
    Primary test class for project ``cpp_nesting``.
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    file_hierarchy_dict = {
        directory("include"): {
            file("top_level.hpp"): {
                clike("struct", "top_level"): {}
            },
            directory("nested"): {
                directory("one"): {
                    file("one.hpp"): {
                        namespace("nested"): {
                            clike("struct", "one"): {
                                clike("struct", "params"): {
                                    union("four_bytes"): {}
                                }
                            }
                        }
                    },
                },
                directory("two"): {
                    file("two.hpp"): {
                        namespace("nested"): {
                            clike("struct", "two"): {
                                clike("struct", "params"): {
                                    union("four_bytes"): {}
                                }
                            },
                            union("four_bytes"): {}
                        }
                    }
                },
                directory("dual_nested"): {
                    directory("one"): {
                        file("one.hpp"): {
                            namespace("nested"): {
                                namespace("dual_nested"): {
                                    clike("struct", "one"): {
                                        clike("struct", "params"): {
                                            union("four_bytes"): {}
                                        }
                                    }
                                }
                            }
                        }
                    },
                    directory("two"): {
                        file("two.hpp"): {
                            namespace("nested"): {
                                namespace("dual_nested"): {
                                    clike("struct", "two"): {
                                        clike("struct", "params"): {
                                            union("four_bytes"): {}
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }

    class_hierarchy_dict = {
        clike("struct", "top_level"): {},
        namespace("nested"): {
            clike("struct", "one"): {
                clike("struct", "params"): {
                    union("four_bytes"): {}
                }
            },
            clike("struct", "two"): {
                clike("struct", "params"): {
                    union("four_bytes"): {}
                }
            },
            union("four_bytes"): {},
            namespace("dual_nested"): {
                clike("struct", "one"): {
                    clike("struct", "params"): {
                        union("four_bytes"): {}
                    }
                },
                clike("struct", "two"): {
                    clike("struct", "params"): {
                        union("four_bytes"): {}
                    }
                }
            }
        }
    }

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))

    @confoverrides(exhale_args={"doxygenStripFromPath": "../include"})
    def test_hierarchies_stripped(self):
        """
        Verify the class and file hierarchies with ``doxygenStripFromPath=../include``.

        .. todo:: this test is not supported yet
        """
        # dirty hack to pop off the first include/ directory without needing to know
        # the actual object that is the first and only key
        for key in self.file_hierarchy_dict:
            no_include = self.file_hierarchy_dict[key]
            break
        compare_file_hierarchy(self, file_hierarchy(no_include))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))


class CPPNestingPages(ExhaleTestCase):
    """
    Primary test class for project ``doxygenpage``.
    """

    test_project = "cpp_nesting"
    """.. testproject:: cpp_nesting"""

    class_hierarchy_dict = CPPNesting.class_hierarchy_dict

    file_hierarchy_dict = CPPNesting.file_hierarchy_dict

    def test_hierarchies_without_pages(self):
        """Verify the class, file, and page hierarchies with pages excluded."""
        # TODO: test that page hierarchy is not written (no pages included)
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))

    # TODO: delete no_cleanup before merge.  Generated files go in
    # B = testing/projects/cpp_nesting/docs_CPPNestingPages_test_hierarchies_with_pages_dracula_is_mainpage/
    # - Doxygen XML: $B/_doxygen
    # - Sphinx html: $B/_build/html
    @confoverrides(exhale_args={
        "exhaleDoxygenStdin": dedent("""\
            INPUT       = ../include
            PREDEFINED += DOXYGEN_TEST_PAGES
            PREDEFINED += DRACULA_IS_MAINPAGE
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
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))

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
    def test_hierarchies_with_pages_dracula_not_mainpage(self):
        """Verify the class, file, and page hierarchies when pages included."""
        # TODO: test that page hierarchy is written and correct
        #
        # TODO: remove html build() call when the test is working to go back
        #       to using just XML validation, this is here to help the humans.
        self.app.build()
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))

