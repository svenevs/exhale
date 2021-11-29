"""
The ``c_maths`` test project.
"""

from testing.hierarchies import directory, file, function, parameters


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {}


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
        directory("include"): {
            file("c_maths.h"): {
                function("int", "cm_add"): parameters("int", "int"),
                function("int", "cm_sub"): parameters("int", "int")
            }
        }
    }
