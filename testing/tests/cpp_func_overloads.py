########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_func_overloads`` project.
"""


from testing.base import ExhaleTestCase
from testing.decorators import no_cleanup
from testing.hierarchies import class_hierarchy, compare_class_hierarchy, \
    compare_file_hierarchy, file_hierarchy


class CPPFuncOverloads(ExhaleTestCase):
    """
    Primary test class for project ``cpp_func_overloads``.
    """

    test_project = "cpp_func_overloads"
    """.. testproject:: cpp_func_overloads"""

    @no_cleanup
    def test_builds(self):
        """Test deliberately kept to serve as a perpetual reminder this is still broken."""
        self.app.build()
        if False:  # set to True, and run: tox -e py -- -k cpp_func_overloads -s
            import ipdb  # then you can view the results
            ipdb.set_trace()
            print("hi there")

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
