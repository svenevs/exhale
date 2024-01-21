########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2024                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(cpp-long-names LANGUAGES CXX)

# Windows cannot handle the full test case because of its antiquated filesystem.
if (NOT WIN32)
  # Will re-use the methods defined in testing/tests/cpp_long_names.py to generate the
  # full test case directory paths.
  find_program(PYTHON_EXECUTABLE python)
  if (PYTHON_EXECUTABLE STREQUAL PYTHON_EXECUTABLE-NOTFOUND)
    message(FATAL_ERROR "This project requires python in order to generate the full test case.")
  endif()

  # Using git rev-parse to make life easier to find the cpp_long_names.py test case.
  find_program(GIT_EXECUTABLE git)
  if (GIT_EXECUTABLE STREQUAL GIT_EXECUTABLE-NOTFOUND)
    message(FATAL_ERROR "This project requires git in order to generate the full test case.")
  endif()

  # Acquire the full path to the repository root and create the path to where the
  # cpp_long_names.py file lives.
  execute_process(
    COMMAND         ${GIT_EXECUTABLE} rev-parse --show-toplevel
    RESULT_VARIABLE GIT_EXIT_CODE
    OUTPUT_VARIABLE REPOSITORY_ROOT
    ERROR_VARIABLE  GIT_FAILURE_MESSAGE
  )
  if (GIT_EXIT_CODE)
    message(FATAL_ERROR "Non-zero exit code of [${GIT_EXIT_CODE}] executing 'git rev-parse --show-toplevel'. ${GIT_FAILURE_MESSAGE}")
  elseif (REPOSITORY_ROOT MATCHES "^$")
    message(FATAL_ERROR "Impossible empty string result of 'git rev-parse --show-toplevel'...")
  endif()
  # Remove trailing newline from command-line output.
  string(REGEX REPLACE "\n" "" REPOSITORY_ROOT "${REPOSITORY_ROOT}")
  set(CPP_LONG_NAMES_PY "${REPOSITORY_ROOT}/testing/tests/cpp_long_names.py")
  if (NOT EXISTS "${CPP_LONG_NAMES_PY}")
    message(FATAL_ERROR "Could not find the file [${CPP_LONG_NAMES_PY}]!")
  endif()

  # Create a script to call the function to make directories.  If only there was
  # textwrap.dedent(...) in CMake x0
  string(CONCAT GENERATE_ABSURD_SCRIPT_CONTENTS
    "import os\n"
    "import sys\n"
    "\n"
    "\n"
    "if __name__ == '__main__':\n"
    "    try:\n"
    "        # Make it so we can import 'exhale' and 'testing'\n"
    "        repository_root = os.path.abspath('${REPOSITORY_ROOT}')\n"
    "        sys.path.insert(0, repository_root)\n"
    "\n"
    "        from testing.tests import cpp_long_names\n"
    "        cpp_long_names.create_absurd_directory_structure()\n"
    "\n"
    "        # Print out what we just made verify it was created in CMake.\n"
    "        sys.stdout.write(os.path.join(\n"
    "            cpp_long_names.ABSURD_DIRECTORY_PATH, 'a_file.hpp'\n"
    "        ))\n"
    "        sys.exit(0)\n"
    "    except Exception as e:\n"
    "        sys.stderr.write('Critical error trying to make the absurd path: {}'.format(e))\n"
    "        sys.exit(1)\n"
  )
  set(GENERATE_ABSURD_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/prepare_cpp_long_names.py")

  # Only generate this once to prevent re-builds.
  if (NOT EXISTS ${GENERATE_ABSURD_SCRIPT})
    file(WRITE "${GENERATE_ABSURD_SCRIPT}" "${GENERATE_ABSURD_SCRIPT_CONTENTS}")

    # Call the script to generate the absurd path.
    execute_process(
      COMMAND ${PYTHON_EXECUTABLE} ${GENERATE_ABSURD_SCRIPT}
      RESULT_VARIABLE GENERATE_ABSURD_SCRIPT_EXIT_CODE
      OUTPUT_VARIABLE ABSURD_FILE_PATH
      ERROR_VARIABLE  GENERATE_ABSURD_SCRIPT_FAILURE_MESSAGE
    )
    if (GENERATE_ABSURD_SCRIPT_EXIT_CODE)
      message(FATAL_ERROR "Could not generate the absurd file path. ${GENERATE_ABSURD_SCRIPT_FAILURE_MESSAGE}")
    endif()
  endif()
endif()


# "Header only library": add tests and include the directory
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)
target_include_directories(exhale-projects-tests-interface
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_open_cpp_coverage_source_dirs(include src)
