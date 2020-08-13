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
    compare_file_hierarchy, clike, directory, enum, file, file_hierarchy, function, namespace, parameters, typedef


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
                        # # SFINAE is really pretty yeah?
                        # function(
                        #     "std::enable_if<std::is_convertible<typename C::type, T>::value, T>::type",
                        #     "blargh",
                        #     template=["class C", "typename T"]
                        # ): parameters("typename C::type"),
                        # function(
                        #     "std::enable_if<!std::is_convertible<typename C::type, T>::value, T>::type",
                        #     "blargh",
                        #     template=["class C", "typename T"]
                        # ): parameters("typename C::type")
                    }
                }
            },
            directory("tt"): {
                file("tt.hpp"): {
                    namespace("tt"): {
                        clike("struct", "AudioDevice_state"): {},
                        clike("struct", "FontWeight"): {},
                        enum("KeyboardModifiers"): {},
                        clike("struct", "KeyboardVirtualKey"): {},
                        clike("struct", "TextDecoration"): {},
                        clike("struct", "ThemeMode"): {},
                        typedef("cell_address", "uint32_t"): {},
                        typedef("command", "uint16_t"): {},
                        clike("struct", "URL"): {},
                        typedef("datum_type_t", "uint8_t"): {},
                        typedef("glob_token_t", "int32_t"): {},
                        typedef("glob_token_type_t", "int16_t"): {},
                        typedef("source_code_ptr", "void *"): {},
                        typedef("tokenizer_name_t", "double"): {},
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "AudioDevice_state const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "FontWeight const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "KeyboardModifiers const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "KeyboardVirtualKey const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "TextDecoration const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "ThemeMode rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "cell_address const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "command const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "const URL &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "datum_type_t rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "glob_token_t const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "glob_token_type_t const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "source_code_ptr const &rhs"
                        ),
                        function("std::ostream&", "operator<<"): parameters(
                            "std::ostream &lhs", "tokenizer_name_t rhs"
                        )
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
