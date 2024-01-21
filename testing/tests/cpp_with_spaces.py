########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_with_spaces`` project.
"""


from testing.base import ExhaleTestCase
from testing.decorators import no_cleanup
from testing.hierarchies import compare_file_hierarchy, file_hierarchy


class CPPWithSpaces(ExhaleTestCase):
    """
    Primary test class for project ``cpp with spaces``.
    """

    test_project = "cpp with spaces"
    """.. testproject:: cpp with spaces"""

    def test_hierarchies(self):
        """
        Verify the class and file hierarchies.

        .. todo::

            Class hierarchy not tested here, need to revisit that part of the testing
            framework **as well as** stop emitting a "Class Hierarchy" on the root api
            page when it is empty.
        """
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))

    @no_cleanup
    def test_build(self):
        """Verify that the sphinx build (with spaces in filenames) succeeds."""
        self.app.build()
