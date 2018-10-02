# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_nesting`` project.
"""

from __future__ import unicode_literals

from testing.base import ExhaleTestCase
from testing.hierarchies import                                              \
    class_hierarchy, clike, compare_class_hierarchy, compare_file_hierarchy, \
    directory, file, file_hierarchy, namespace


class CPPPimpl(ExhaleTestCase):
    """
    Primary test class for project ``cpp_pimpl``.
    """

    test_project = "cpp_pimpl"
    """.. testproject:: cpp_pimpl"""

    file_hierarchy_dict = {
        directory("include"): {
            directory("pimpl"): {
                file("planet.hpp"): {
                    namespace("pimpl"): {
                        clike("class", "Planet"): {}
                    }
                },
                file("earth.hpp"): {
                    namespace("pimpl"): {
                        clike("class", "Earth"): {},
                        clike("class", "EarthImpl"): {},
                        clike("class", "Earth_v2"): {},
                        namespace("detail"): {
                            clike("class", "EarthImpl"): {}
                        }
                    }
                },
                file("jupiter.hpp"): {
                    namespace("pimpl"): {
                        clike("class", "Jupiter"): {},
                        clike("class", "JupiterImpl"): {},
                        clike("class", "Jupiter_v2"): {},
                        namespace("detail"): {
                            clike("class", "JupiterImpl"): {}
                        }
                    }
                }
            }
        }
    }
    """The file hierarchy for this test."""

    class_hierarchy_dict = {
        namespace("pimpl"): {
            clike("class", "Planet"): {},
            clike("class", "Earth"): {},
            clike("class", "EarthImpl"): {},
            clike("class", "Earth_v2"): {},
            clike("class", "Jupiter"): {},
            clike("class", "JupiterImpl"): {},
            clike("class", "Jupiter_v2"): {},
            namespace("detail"): {
                clike("class", "EarthImpl"): {},
                clike("class", "JupiterImpl"): {}
            }
        }
    }
    """The class hierarchy for this test."""

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict))
