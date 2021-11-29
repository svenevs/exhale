"""
The ``cpp_long_names`` test project.
"""

import os
import platform

from testing import TEST_PROJECTS_ROOT
from testing.hierarchies import                                                        \
    clike, define, directory, enum, file, function, namespace, parameters, typedef,    \
    union, variable


RUN_ABSURD_TEST = platform.system() != "Windows"
"""
When ``platform.system() != "Windows"``, :data:`ABSURD_DIRECTORY_PATH` is created.
"""


def make_it_big(prefix):
    """Mirrors the macro ``MAKE_IT_BIG`` in ``absurdly_long_names.hpp``."""
    big = [
        prefix, "that", "is", "longer", "than", "two", "hundred", "and", "fifty",
        "five", "characters", "long", "which", "is", "an", "absolutely", "and",
        "completely", "ridiculous", "thing", "to", "do", "and", "if", "you", "did",
        "this", "in", "the", "real", "world", "you", "put", "yourself", "comfortably",
        "in", "a", "position", "to", "be", "downsized", "and", "outta", "here", "as",
        "soul", "position", "would", "explain", "to", "you"
    ]
    return "_".join(big)


ABSURD_DIRECTORY_PATH = os.path.abspath(os.path.join(
    TEST_PROJECTS_ROOT,
    "cpp_long_names",
    "include",
    make_it_big("directory_structure").replace("_", os.sep)
))
"""
The absurd directory path that will be created depending on :data:`RUN_ABSURD_TEST`.
"""


def default_class_hierarchy_dict():
    """Return the default class hierarchy dictionary."""
    return {}


def default_file_hierarchy_dict():
    """
    Return the default file hierarchy dictionary.

    If :data:`RUN_ABSURD_TEST` is ``True``, :data:`ABSURD_DIRECTORY_PATH` will be
    incorporated in the returned dictionary.
    """
    absurdly_long_names_hpp_contents = {
        define("MAKE_IT_BIG"): {},
        clike("class", make_it_big("class")): {},
        clike("struct", make_it_big("struct")): {},
        function("std::string", make_it_big("function")): parameters(),
        enum(make_it_big("enum")): {},  # TODO: values("first", "second", "third"),
        namespace(make_it_big("namespace")): {
            variable("int", "value"): {}
        },
        define(make_it_big("define").upper()): {},
        variable("int", make_it_big("variable")): {},
        typedef(make_it_big("typedef"), "float"): {},
        union(make_it_big("union")): {}
    }

    if RUN_ABSURD_TEST:
        absurd_directory_structure = {
            directory("structure"): {
                directory("that"): {
                    directory("is"): {
                        directory("longer"): {
                            directory("than"): {
                                directory("two"): {
                                    directory("hundred"): {
                                        directory("and"): {
                                            directory("fifty"): {
                                                directory("five"): {
                                                    directory("characters"): {
                                                        directory("long"): {
                                                            directory("which"): {
                                                                directory("is"): {
                                                                    directory("an"): {
                                                                        directory("absolutely"): {
                                                                            directory("and"): {
                                                                                directory("completely"): {
                                                                                    directory("ridiculous"): {
                                                                                        directory("thing"): {
                                                                                            directory("to"): {
                                                                                                directory("do"): {                                                                                                                                                                     # noqa: E501
                                                                                                    directory("and"): {                                                                                                                                                                # noqa: E501
                                                                                                        directory("if"): {                                                                                                                                                             # noqa: E501
                                                                                                            directory("you"): {                                                                                                                                                        # noqa: E501
                                                                                                                directory("did"): {                                                                                                                                                    # noqa: E501
                                                                                                                    directory("this"): {                                                                                                                                               # noqa: E501
                                                                                                                        directory("in"): {                                                                                                                                             # noqa: E501
                                                                                                                            directory("the"): {                                                                                                                                        # noqa: E501
                                                                                                                                directory("real"): {                                                                                                                                   # noqa: E501
                                                                                                                                    directory("world"): {                                                                                                                              # noqa: E501
                                                                                                                                        directory("you"): {                                                                                                                            # noqa: E501
                                                                                                                                            directory("put"): {                                                                                                                        # noqa: E501
                                                                                                                                                directory("yourself"): {                                                                                                               # noqa: E501
                                                                                                                                                    directory("comfortably"): {                                                                                                        # noqa: E501
                                                                                                                                                        directory("in"): {                                                                                                             # noqa: E501
                                                                                                                                                            directory("a"): {                                                                                                          # noqa: E501
                                                                                                                                                                directory("position"): {                                                                                               # noqa: E501
                                                                                                                                                                    directory("to"): {                                                                                                 # noqa: E501
                                                                                                                                                                        directory("be"): {                                                                                             # noqa: E501
                                                                                                                                                                            directory("downsized"): {                                                                                  # noqa: E501
                                                                                                                                                                                directory("and"): {                                                                                    # noqa: E501
                                                                                                                                                                                    directory("outta"): {                                                                              # noqa: E501
                                                                                                                                                                                        directory("here"): {                                                                           # noqa: E501
                                                                                                                                                                                            directory("as"): {                                                                         # noqa: E501
                                                                                                                                                                                                directory("soul"): {                                                                   # noqa: E501
                                                                                                                                                                                                    directory("position"): {                                                           # noqa: E501
                                                                                                                                                                                                        directory("would"): {                                                          # noqa: E501
                                                                                                                                                                                                            directory("explain"): {                                                    # noqa: E501
                                                                                                                                                                                                                directory("to"): {                                                     # noqa: E501
                                                                                                                                                                                                                    directory("you"): {                                                # noqa: E501
                                                                                                                                                                                                                        file("a_file.hpp"): {                                          # noqa: E501
                                                                                                                                                                                                                            function("std::string", "extremely_nested"): parameters()  # noqa: E501
                                                                                                                                                                                                                        }                                                              # noqa: E501
                                                                                                                                                                                                                    }                                                                  # noqa: E501
                                                                                                                                                                                                                }                                                                      # noqa: E501
                                                                                                                                                                                                            }                                                                          # noqa: E501
                                                                                                                                                                                                        }                                                                              # noqa: E501
                                                                                                                                                                                                    }                                                                                  # noqa: E501
                                                                                                                                                                                                }                                                                                      # noqa: E501
                                                                                                                                                                                            }                                                                                          # noqa: E501
                                                                                                                                                                                        }                                                                                              # noqa: E501
                                                                                                                                                                                    }                                                                                                  # noqa: E501
                                                                                                                                                                                }                                                                                                      # noqa: E501
                                                                                                                                                                            }                                                                                                          # noqa: E501
                                                                                                                                                                        }                                                                                                              # noqa: E501
                                                                                                                                                                    }                                                                                                                  # noqa: E501
                                                                                                                                                                }                                                                                                                      # noqa: E501
                                                                                                                                                            }                                                                                                                          # noqa: E501
                                                                                                                                                        }                                                                                                                              # noqa: E501
                                                                                                                                                    }                                                                                                                                  # noqa: E501
                                                                                                                                                }                                                                                                                                      # noqa: E501
                                                                                                                                            }                                                                                                                                          # noqa: E501
                                                                                                                                        }                                                                                                                                              # noqa: E501
                                                                                                                                    }                                                                                                                                                  # noqa: E501
                                                                                                                                }                                                                                                                                                      # noqa: E501
                                                                                                                            }                                                                                                                                                          # noqa: E501
                                                                                                                        }                                                                                                                                                              # noqa: E501
                                                                                                                    }                                                                                                                                                                  # noqa: E501
                                                                                                                }                                                                                                                                                                      # noqa: E501
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return {
            directory("include"): {
                file("absurdly_long_names.hpp"): absurdly_long_names_hpp_contents,
                directory("directory"): absurd_directory_structure
            }
        }
    else:
        return {
            directory("include"): {
                file("absurdly_long_names.hpp"): absurdly_long_names_hpp_contents
            }
        }
