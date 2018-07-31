# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_long_names`` project.
"""

from __future__ import unicode_literals
import hashlib
import os
import platform
import shutil
import textwrap

from exhale.configs import MAXIMUM_FILENAME_LENGTH

import pytest

from testing import TEST_PROJECTS_ROOT
from testing.base import ExhaleTestCase
from testing.hierarchies import                                                   \
    clike, compare_file_hierarchy, define, directory, enum, file, file_hierarchy, \
    function, namespace, signature, typedef, union, variable


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


def make_file_hierarchy_dict():
    """
    Return the :class:`python:dict` representing the file hierarchy.

    If :data:`RUN_ABSURD_TEST` is ``True``, :data:`ABSURD_DIRECTORY_PATH` will be
    incorporated in the returned dictionary.
    """
    absurdly_long_names_hpp_contents = {
        define("MAKE_IT_BIG"): {},
        clike("class", make_it_big("class")): {},
        clike("struct", make_it_big("struct")): {},
        function("std::string", make_it_big("function")): signature(),
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
                                                                                                directory("do"): {                                                                                                                                                                    # noqa: E501
                                                                                                    directory("and"): {                                                                                                                                                               # noqa: E501
                                                                                                        directory("if"): {                                                                                                                                                            # noqa: E501
                                                                                                            directory("you"): {                                                                                                                                                       # noqa: E501
                                                                                                                directory("did"): {                                                                                                                                                   # noqa: E501
                                                                                                                    directory("this"): {                                                                                                                                              # noqa: E501
                                                                                                                        directory("in"): {                                                                                                                                            # noqa: E501
                                                                                                                            directory("the"): {                                                                                                                                       # noqa: E501
                                                                                                                                directory("real"): {                                                                                                                                  # noqa: E501
                                                                                                                                    directory("world"): {                                                                                                                             # noqa: E501
                                                                                                                                        directory("you"): {                                                                                                                           # noqa: E501
                                                                                                                                            directory("put"): {                                                                                                                       # noqa: E501
                                                                                                                                                directory("yourself"): {                                                                                                              # noqa: E501
                                                                                                                                                    directory("comfortably"): {                                                                                                       # noqa: E501
                                                                                                                                                        directory("in"): {                                                                                                            # noqa: E501
                                                                                                                                                            directory("a"): {                                                                                                         # noqa: E501
                                                                                                                                                                directory("position"): {                                                                                              # noqa: E501
                                                                                                                                                                    directory("to"): {                                                                                                # noqa: E501
                                                                                                                                                                        directory("be"): {                                                                                            # noqa: E501
                                                                                                                                                                            directory("downsized"): {                                                                                 # noqa: E501
                                                                                                                                                                                directory("and"): {                                                                                   # noqa: E501
                                                                                                                                                                                    directory("outta"): {                                                                             # noqa: E501
                                                                                                                                                                                        directory("here"): {                                                                          # noqa: E501
                                                                                                                                                                                            directory("as"): {                                                                        # noqa: E501
                                                                                                                                                                                                directory("soul"): {                                                                  # noqa: E501
                                                                                                                                                                                                    directory("position"): {                                                          # noqa: E501
                                                                                                                                                                                                        directory("would"): {                                                         # noqa: E501
                                                                                                                                                                                                            directory("explain"): {                                                   # noqa: E501
                                                                                                                                                                                                                directory("to"): {                                                    # noqa: E501
                                                                                                                                                                                                                    directory("you"): {                                               # noqa: E501
                                                                                                                                                                                                                        file("a_file.hpp"): {                                         # noqa: E501
                                                                                                                                                                                                                            function("std::string", "extremely_nested"): signature()  # noqa: E501
                                                                                                                                                                                                                        }                                                             # noqa: E501
                                                                                                                                                                                                                    }                                                                 # noqa: E501
                                                                                                                                                                                                                }                                                                     # noqa: E501
                                                                                                                                                                                                            }                                                                         # noqa: E501
                                                                                                                                                                                                        }                                                                             # noqa: E501
                                                                                                                                                                                                    }                                                                                 # noqa: E501
                                                                                                                                                                                                }                                                                                     # noqa: E501
                                                                                                                                                                                            }                                                                                         # noqa: E501
                                                                                                                                                                                        }                                                                                             # noqa: E501
                                                                                                                                                                                    }                                                                                                 # noqa: E501
                                                                                                                                                                                }                                                                                                     # noqa: E501
                                                                                                                                                                            }                                                                                                         # noqa: E501
                                                                                                                                                                        }                                                                                                             # noqa: E501
                                                                                                                                                                    }                                                                                                                 # noqa: E501
                                                                                                                                                                }                                                                                                                     # noqa: E501
                                                                                                                                                            }                                                                                                                         # noqa: E501
                                                                                                                                                        }                                                                                                                             # noqa: E501
                                                                                                                                                    }                                                                                                                                 # noqa: E501
                                                                                                                                                }                                                                                                                                     # noqa: E501
                                                                                                                                            }                                                                                                                                         # noqa: E501
                                                                                                                                        }                                                                                                                                             # noqa: E501
                                                                                                                                    }                                                                                                                                                 # noqa: E501
                                                                                                                                }                                                                                                                                                     # noqa: E501
                                                                                                                            }                                                                                                                                                         # noqa: E501
                                                                                                                        }                                                                                                                                                             # noqa: E501
                                                                                                                    }                                                                                                                                                                 # noqa: E501
                                                                                                                }                                                                                                                                                                     # noqa: E501
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


def create_absurd_directory_structure():
    """
    Create the absurd directory structure when :data:`RUN_ABSURD_TEST` is ``True``.

    Helper function for the testing fixture :func:`potentially_with_insanity_fixture`.
    """
    if RUN_ABSURD_TEST:
        try:
            absurd_dir = ABSURD_DIRECTORY_PATH
            if not os.path.isdir(absurd_dir):
                os.makedirs(absurd_dir)
            with open(os.path.join(absurd_dir, "a_file.hpp"), "w") as a_file:
                a_file.write(textwrap.dedent(r'''
                    /** \file */
                    #pragma once

                    /// A function from an extremely nested file path.
                    inline std::string extremely_nested() { return "Extremely nested works!!!"; }
                '''))
        except Exception as e:
            raise RuntimeError(
                "Could not make the absurd directory structure: {0}".format(e)
            )


def remove_absurd_directory_structure():
    """
    Remove the absurd directory structure when :data:`RUN_ABSURD_TEST` is ``True``.

    Helper function for the testing fixture :func:`potentially_with_insanity_fixture`.
    """
    if RUN_ABSURD_TEST:
        try:
            absurd_dir_root = os.path.abspath(os.path.join(
                TEST_PROJECTS_ROOT,
                "cpp_long_names",
                "include",
                "directory"
            ))
            shutil.rmtree(absurd_dir_root)
        except Exception as e:
            raise RuntimeError("Could not remove the directory [{0}]: {1}".format(
                absurd_dir_root, e
            ))


@pytest.fixture(scope="class")
def potentially_with_insanity_fixture():
    """
    Class-level fixture that may create / remove the absurd directory.

    This will create the absurd directory structure before any tests are run, and
    remove it when all are finished when :data:`RUN_ABSURD_TEST` is ``True``.
    """
    create_absurd_directory_structure()
    yield
    remove_absurd_directory_structure()


def potentially_with_insanity(cls):
    """
    Mark ``cls`` to use the fixture :func:`potentially_with_insanity`.

    **Parameters**

        ``cls`` (:class:`~testing.tests.cpp_long_names.CPPLongNames`)

            Decorator designed **only** for :class:`~testing.tests.cpp_long_names.CPPLongNames`.

    **Return** (:class:`~testing.tests.cpp_long_names.CPPLongNames`)

        The input ``cls``, after executing ``pytest.mark.usefixtures``.
    """
    pytest.mark.usefixtures("potentially_with_insanity_fixture")(cls)
    return cls


@potentially_with_insanity
class CPPLongNames(ExhaleTestCase):
    """
    Primary test class for project ``cpp_long_names``.
    """

    test_project = "cpp_long_names"
    """.. testproject:: cpp_long_names"""

    file_hierarchy_dict = make_file_hierarchy_dict()
    """The (potentially absurd) file hierarchy for this project."""

    def test_app(self):
        """
        Check required configurations, that the app builds, and that long names get hashed correctly.
        """
        self.checkRequiredConfigs()

        # Make sure that the generated files and such _actually_ work via Sphinx.
        # NOTE: Sphinx actually crashes for the same reasons Exhale was on Windows
        #       because they do not prefix with \\?\ for >= 260 length paths x0
        if platform.system() != "Windows":
            self.app.build()

        # Define a testing function that will check either:
        #
        # 1. file_name does exist and hash_name does not, or
        # 2. file_name does not exist and hash_name does
        #
        # Which will depend on the length of file_name.
        containment_folder = self.getAbsContainmentFolder()

        def check_both(file_name, hash_name):
            # Setup for binding local functions.
            if len(file_name) >= MAXIMUM_FILENAME_LENGTH:
                file_name_exists = "assertFalse"
                file_name_notice = "[{path}] should *NOT* exist but did."
                hash_name_exists = "assertTrue"
                hash_name_notice = "[{path}] *SHOULD* exist but did not."
            else:
                file_name_exists = "assertTrue"
                file_name_notice = "[{path}] *SHOULD* exist but did not."
                hash_name_exists = "assertFalse"
                hash_name_notice = "[{path}] should *NOT* exist but did."

            # Bind some local functions (to this local function LOL).
            check_file_name = getattr(self, file_name_exists)
            check_hash_name = getattr(self, hash_name_exists)

            # Create the absolute paths to the files to check.
            file_path = os.path.join(containment_folder, file_name)
            hash_path = os.path.join(containment_folder, hash_name)

            # Verify that either the regular name exists and the hash does not, or vice-versa.
            check_file_name(
                os.path.isfile(file_path), file_name_notice.format(path=file_path)
            )
            check_hash_name(
                os.path.isfile(hash_path), hash_name_notice.format(path=hash_path)
            )

        if RUN_ABSURD_TEST:
            # Verify that the generated directories are correct, including getting a
            # sha1 sum once the full path is longer than 255 characters.
            long_dirs = make_it_big("include_directory_structure").split("_")
            curr_dir = "dir"
            for d in long_dirs:
                # Synthetic setup to graph.ExhaleRoot.initializeNodeFilenameAndLink
                curr_dir = "{curr_dir}_{d}".format(curr_dir=curr_dir, d=d)
                link_name = curr_dir

                # Set both names to check and make sure that only one exists.
                file_name = "{link_name}.rst".format(link_name=link_name)
                hash_name = "dir_{sha1}.rst".format(
                    sha1=hashlib.sha1(link_name.encode()).hexdigest()
                )

                check_both(file_name, hash_name)

            # Verify that the file a_file.hpp also uses the hashed name since it's full
            # path will be too long.
            long_dirs.append("a_file.hpp")
            link_name = "file_{path}".format(path="_".join(long_dirs))

            file_name = "{link_name}.rst".format(link_name=link_name)
            hash_name = "file_{sha1}.rst".format(
                sha1=hashlib.sha1(link_name.encode()).hexdigest()
            )

            check_both(file_name, hash_name)

            # Repeat for the program listing of a_file.hpp
            file_name = "program_listing_{file_name}".format(file_name=file_name)
            hash_name = "program_listing_{hash_name}".format(hash_name=hash_name)

            check_both(file_name, hash_name)

        # Besides files and directories, the only other compounds that do not use the
        # Doxygen refid's (Doxygen also uses hashing to shorten) in Exhale are
        # namespaces, so this is the last one to check.
        namespace = make_it_big("namespace")
        link_name = "namespace_{namespace}".format(namespace=namespace)

        file_name = "{link_name}.rst".format(link_name=link_name)
        hash_name = "namespace_{sha1}.rst".format(
            sha1=hashlib.sha1(link_name.encode()).hexdigest()
        )

        check_both(file_name, hash_name)

    def test_file_hierarchy(self):
        """
        Verify the file hierarchy.

        The class hierarchy is not validated for this test project simply because doing
        so is rather pointless, and the added complexity to do so given the
        conditionally created structure is not worth the effort.
        """
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict))
