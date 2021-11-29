"""
The ``cpp_pimpl`` test project.
"""

from testing.hierarchies import clike, directory, file, namespace


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {
        namespace("pimpl"): {
            clike("class", "Planet"): {},
            clike("class", "Earth"): {},
            clike("class", "EarthImpl"): {},
            clike("class", "Earth_v2"): {},
            clike("class", "Jupiter"): {},
            clike("class", "JupiterImpl"): {},
            clike("class", "Jupiter_v2"): {},
            namespace("detail"): {
                clike("class", "EarthImpl"): {},
                clike("class", "JupiterImpl"): {}
            }
        }
    }


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
        directory("include"): {
            directory("pimpl"): {
                file("planet.hpp"): {
                    namespace("pimpl"): {
                        clike("class", "Planet"): {}
                    }
                },
                file("earth.hpp"): {
                    namespace("pimpl"): {
                        clike("class", "Earth"): {},
                        clike("class", "EarthImpl"): {},
                        clike("class", "Earth_v2"): {},
                        namespace("detail"): {
                            clike("class", "EarthImpl"): {}
                        }
                    }
                },
                file("jupiter.hpp"): {
                    namespace("pimpl"): {
                        clike("class", "Jupiter"): {},
                        clike("class", "JupiterImpl"): {},
                        clike("class", "Jupiter_v2"): {},
                        namespace("detail"): {
                            clike("class", "JupiterImpl"): {}
                        }
                    }
                }
            }
        }
    }
