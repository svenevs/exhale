# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
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
    compare_file_hierarchy, directory, file, file_hierarchy, function, namespace, signature


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
                    function("int", "blargh"): signature("int"),
                    namespace("overload"): {
                        # No args
                        function("void", "blargh"): signature(),
                        # "pure" int overloads
                        function("int", "blargh"): signature("int"),
                        function("int", "blargh"): signature("int", "int"),
                        function("int", "blargh"): signature("int", "int", "int"),
                        # "pure" float overloads
                        function("float", "blargh"): signature("float"),
                        function("float", "blargh"): signature("float", "float"),
                        function("float", "blargh"): signature("float", "float", "float"),
                        # "pure" std::string overloads
                        function("std::string", "blargh"): signature("const std::string&"),
                        function("std::string", "blargh"): signature(
                            "const std::string&", "const std::string&"
                        ),
                        function("std::string", "blargh"): signature(
                            "const std::string&", "const std::string&", "const std::string&"
                        ),
                        # absurd mixtures
                        function("std::size_t", "blargh"): signature("std::size_t", "const std::string&"),
                        function("std::size_t", "blargh"): signature(
                            "std::size_t", "const float&", "double", "const std::string&"
                        ),
                        # vector overloads
                        function("void", "blargh"): signature("std::vector<std::string>&"),
                        function("void", "blargh"): signature("std::vector<std::vector<int>>&"),
                        # pointer style (spaces matter...)
                        function("void", "blargh"): signature(
                            "const float *", "const float *", "float *", "std::size_t"
                        ),
                        # templates
                        function("C::type", "blargh", template=["class C"]): signature("typename C::type"),
                        # SFINAE is really pretty yeah?
                        function(
                            "std::enable_if<std::is_convertible<typename C::type, T>::value, T>::type",
                            "blargh",
                            template=["class C", "typename T"]
                        ): signature("typename C::type"),
                        function(
                            "std::enable_if<!std::is_convertible<typename C::type, T>::value, T>::type",
                            "blargh",
                            template=["class C", "typename T"]
                        ): signature("typename C::type")
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
