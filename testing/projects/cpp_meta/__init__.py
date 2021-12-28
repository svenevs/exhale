"""
The ``cpp_meta`` test project.
"""

from testing.hierarchies import directory, file, function, parameters, namespace


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {}


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    raise NotImplementedError("TODO... match the cxx tests when completed.")
    return {
        directory("include"): {
            directory("meta"): {
                file("cxx_attrs.hpp"): {
                    namespace("meta"): {
                        function(): parameters(),
                    }
                },
                file("tfuncs.hpp"): {
                    namespace("meta"): {
                        function(): parameters(),
                    }
                }
            }
        }
    }
