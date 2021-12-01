"""
The ``cpp_dir_underscores`` test project.

It primarily exists to make sure directories with underscores in their titles
get the correct link and title names (since exhale uses underscores internally).
"""

from testing.hierarchies import clike, directory, file, namespace


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionar."""
    return {
        namespace("interface_alpha"): {
            clike("struct", "Alpha"): {},
            namespace("one_two_three"): {
                clike("struct", "OneTwoThree"): {},
            },
            namespace("four_five_six"): {
                clike("struct", "FourFiveSix"): {}
            }
        },
        namespace("interface_beta"): {
            clike("struct", "Beta"): {}
        }
    }


def default_file_hierarchy_dict():
    """Return the default file hierarchy dictionary."""
    return {
        directory("include"): {
            directory("interface_alpha"): {
                file("alpha.hpp"): {
                    namespace("interface_alpha"): {
                        clike("struct", "Alpha"): {},
                    }
                },
                directory("one_two_three"): {
                    file("one_two_three.hpp"): {
                        namespace("interface_alpha"): {
                            namespace("one_two_three"): {
                                clike("struct", "OneTwoThree"): {},
                            }
                        }
                    },
                },
                directory("__four_five_six__"): {
                    file("__four_five_six__.hpp"): {
                        namespace("interface_alpha"): {
                            namespace("four_five_six"): {
                                clike("struct", "FourFiveSix"): {}
                            }
                        }
                    }
                }
            },
            directory("interface_beta"): {
                file("beta.hpp"): {
                    namespace("interface_beta"): {
                        clike("struct", "Beta"): {}
                    }
                }
            }
        }
    }
