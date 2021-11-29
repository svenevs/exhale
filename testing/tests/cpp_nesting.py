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

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides
from testing.hierarchies import                                                        \
    class_hierarchy, compare_class_hierarchy, compare_file_hierarchy, file_hierarchy


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
