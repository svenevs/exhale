"""
The ``cpp_fortran_mixed`` test project.
"""

from testing.hierarchies import directory, file, function, namespace, parameters, variable


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {}


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
        directory("include"): {
            directory("convert"): {
                file("convert.hpp"): {
                    namespace("convert"): {
                        function("T", "to_degrees", template=["typename T"]): parameters("T"),
                        function("T", "to_radians", template=["typename T"]): parameters("T")
                    }
                }
            }
        },
        directory("src"): {
            file("conversions.f90"): {
                namespace("conversions"): {
                    variable("real(c_float)", "pi_s"): {},
                    variable("real(c_double)", "pi_d"): {},
                    variable("real(c_float)", "s_180"): {},
                    variable("real(c_double)", "d_180"): {},
                    # NOTE: function parameters in fortran are a little weird.
                    # 1. <type> has 'function', e.g. 'real(c_float) function'
                    # 2. Parameters are names, not types?
                    function("real(c_float) function", "degrees_to_radians_s"): parameters("degrees_s"),
                    function("real(c_double) function", "degrees_to_radians_d"): parameters("degrees_d"),
                    function("real(c_float) function", "radians_to_degrees_s"): parameters("radians_s"),
                    function("real(c_double) function", "radians_to_degrees_d"): parameters("radians_d")
                }
            }
        }
    }
