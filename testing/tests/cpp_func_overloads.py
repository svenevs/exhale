# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2019, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_func_overloads`` project.
"""

from __future__ import unicode_literals

from testing.base import ExhaleTestCase
from testing.decorators import no_cleanup
from testing.hierarchies import \
    compare_file_hierarchy, directory, file, file_hierarchy, function, namespace, parameters


class CPPFuncOverloads(ExhaleTestCase):
    """
    Primary test class for project ``cpp_func_overloads``.
    """

    test_project = "cpp_func_overloads"
    """.. testproject:: cpp_func_overloads"""

    file_hierarchy_dict = {
        directory("include"): {
            directory("overload"): {
                file("overload.hpp"): {
                    function("int", "blargh"): parameters("int"),
                    namespace("overload"): {
                        # No args
                        function("void", "blargh"): parameters(),
                        # "pure" int overloads
                        function("int", "blargh"): parameters("int"),
                        function("int", "blargh"): parameters("int", "int"),
                        function("int", "blargh"): parameters("int", "int", "int"),
                        # "pure" float overloads
                        function("float", "blargh"): parameters("float"),
                        function("float", "blargh"): parameters("float", "float"),
                        function("float", "blargh"): parameters("float", "float", "float"),
                        # "pure" std::string overloads
                        function("std::string", "blargh"): parameters("const std::string&"),
                        function("std::string", "blargh"): parameters(
                            "const std::string&", "const std::string&"
                        ),
                        function("std::string", "blargh"): parameters(
                            "const std::string&", "const std::string&", "const std::string&"
                        ),
                        # absurd mixtures
                        function("std::size_t", "blargh"): parameters("std::size_t", "const std::string&"),
                        function("std::size_t", "blargh"): parameters(
                            "std::size_t", "const float&", "double", "const std::string&"
                        ),
                        # vector overloads
                        function("void", "blargh"): parameters("std::vector<std::string>&"),
                        function("void", "blargh"): parameters("std::vector<std::vector<int>>&"),
                        # pointer style (spaces matter...)
                        function("void", "blargh"): parameters(
                            "const float *", "const float *", "float *", "std::size_t"
                        ),
                        # templates
                        function("C::type", "blargh", template=["class C"]): parameters("typename C::type"),
                        # SFINAE is really pretty yeah?
                        function(
                            "std::enable_if<std::is_convertible<typename C::type, T>::value, T>::type",
                            "blargh",
                            template=["class C", "typename T"]
                        ): parameters("typename C::type"),
                        function(
                            "std::enable_if<!std::is_convertible<typename C::type, T>::value, T>::type",
                            "blargh",
                            template=["class C", "typename T"]
                        ): parameters("typename C::type")
                    }
                }
            }
        }
    }

    @no_cleanup
    def test_builds(self):
        """Test deliberately kept to serve as a perpetual reminder this is still broken."""
        self.app.build()

    def test_file_hierarchy(self):
        """Verify the file hierarchy."""
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
