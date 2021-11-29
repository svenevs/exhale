"""
The ``cpp with spaces`` test project.
"""

from testing.hierarchies import directory, file, function, namespace, parameters


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {}


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
        directory("include"): {
            directory("with spaces"): {
                file("with spaces.hpp"): {
                    namespace("with_spaces"): {
                        function("int", "value"): parameters()
                    }
                }
            }
        }
    }
