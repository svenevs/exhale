########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_long_names`` project.
"""

import hashlib
import os
import platform
import shutil
import textwrap

from exhale.configs import MAXIMUM_FILENAME_LENGTH

import pytest

from testing import TEST_PROJECTS_ROOT
from testing.base import ExhaleTestCase
from testing.hierarchies import compare_file_hierarchy, file_hierarchy
from testing.projects.cpp_long_names import \
    ABSURD_DIRECTORY_PATH, RUN_ABSURD_TEST, make_it_big


def create_absurd_directory_structure():
    """
    Create the absurd directory structure when |RUN_ABSURD_TEST| is ``True``.

    Helper function for the testing fixture :func:`potentially_with_insanity_fixture`.

    .. |RUN_ABSURD_TEST| replace:: :data:`testing.projects.cpp_long_names.RUN_ABSURD_TEST`
    """
    if RUN_ABSURD_TEST:
        try:
            absurd_dir = ABSURD_DIRECTORY_PATH
            if not os.path.isdir(absurd_dir):
                os.makedirs(absurd_dir)
            with open(os.path.join(absurd_dir, "a_file.hpp"), "w") as a_file:
                a_file.write(textwrap.dedent(r'''
                    /***************************************************************************************
                     * This file is dedicated to the public domain.  If your jurisdiction requires a       *
                     * specific license:                                                                   *
                     *                                                                                     *
                     * Copyright (c) Stephen McDowell, 2017-2024                                           *
                     * License:      CC0 1.0 Universal                                                     *
                     * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
                     **************************************************************************************/
                    /** \file */
                    #pragma once

                    #include <string>

                    /// A function from an extremely nested file path.
                    inline std::string extremely_nested() {
                        return "Extremely nested works!!!";
                    }
                '''))
        except Exception as e:
            raise RuntimeError(
                "Could not make the absurd directory structure: {0}".format(e)
            )


def remove_absurd_directory_structure():
    """
    Remove the absurd directory structure when |RUN_ABSURD_TEST| is ``True``.

    Helper function for the testing fixture :func:`potentially_with_insanity_fixture`.
    """
    if RUN_ABSURD_TEST:
        absurd_dir_root = os.path.abspath(os.path.join(
            TEST_PROJECTS_ROOT,
            "cpp_long_names",
            "include",
            "directory"
        ))
        try:
            if os.path.isdir(absurd_dir_root):
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
    remove it when all are finished when |RUN_ABSURD_TEST| is ``True``.
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

    def test_hashes(self):
        """Verify the long names get hashed to the expected values."""
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
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))
