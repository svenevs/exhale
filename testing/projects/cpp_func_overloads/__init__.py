"""
The ``cpp_func_overloads`` test project.
"""

from testing.hierarchies import directory, file, function, namespace, parameters


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {}


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
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
                        # NOTE: vvv not really a thing, but its for template specialization.
                        #       AKA broken
                        function("int", "blargh", template=["overload::SuperStruct"]): parameters("int"),
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
