# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``with spaces`` project.

This test is mostly the same as the ``c_maths`` projects, but it contains spaces in
both the directory structure and file names to make sure everything is still generated
and working as expected.
"""

from __future__ import unicode_literals

from testing.base import ExhaleTestCase
from testing.decorators import no_cleanup
from testing.hierarchies import                                       \
    class_hierarchy, compare_class_hierarchy, compare_file_hierarchy, \
    directory, file, file_hierarchy, function, signature


class WithSpacesTests(ExhaleTestCase):
    """
    Primary test class for project ``with spaces``.
    """

    test_project = "with spaces"
    """.. testproject:: with spaces"""

    @no_cleanup
    def test_app(self):
        """Simply checks :func:`testing.base.ExhaleTestCase.checkRequiredConfigs`."""
        self.checkRequiredConfigs()
        self.app.build()

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        # verify the file hierarchy and file declaration relationships
        file_hierarchy_dict = {
            directory("include"): {
                directory("with spaces"): {
                    file("with spaces.h"): {
                        function("int", "add"): signature("int a", "int b"),
                        function("int", "sub"): signature("int a", "int b")
                    }
                }
            }
        }
        compare_file_hierarchy(self, file_hierarchy(file_hierarchy_dict))
        compare_class_hierarchy(self, class_hierarchy({}))
