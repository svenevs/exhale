########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2018                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
#                                                                                      #
# WARNING:                                                                             #
# What you find below as well as in other CMakeLists.txt in nested directories should  #
# *NOT* be regarded as holistically good CMake practice.  I have deliberately chosen   #
# to set, modify, configure, or alter certain behaviors that should ordinarily be left #
# up to the user to configure.  This is done primarily for two reasons:                #
#                                                                                      #
# 1. It makes my life easier for getting code coverage for the non-python files.       #
# 2. This is *NOT* a "real" CMake project!!!                                           #
#                                                                                      #
# You have been warned.  If you choose to continue reading, I cannot guarantee your    #
# safety as your eyes may bleed, or you may spontaneously combust.                     #
#                                                                                      #
########################################################################################
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(exhale-projects)

# Forcibly setting this to make CI easier.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE "Debug") # required for code coverage

# Download the test suite utilities (Catch2 <3)
file(
  DOWNLOAD
    https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp
    ${CMAKE_CURRENT_BINARY_DIR}/include/catch2/catch.hpp
)

# Download the C++ code coverage utilities for non-Windows.
if (NOT WIN32)
  file(
    DOWNLOAD
      https://raw.githubusercontent.com/bilke/cmake-modules/master/CodeCoverage.cmake
      ${CMAKE_CURRENT_BINARY_DIR}/cmake/CodeCoverage.cmake
  )
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR}/cmake)
endif()

# The "main" testing executable, only write once so as not to force a re-build every time
if (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/src/main.cpp)
  file(
    WRITE ${CMAKE_CURRENT_BINARY_DIR}/src/main.cpp
    "#define CATCH_CONFIG_MAIN\n#include <catch2/catch.hpp>\n"
  )
endif()

# Add an interface library for sub-projects to add dependencies to.
# Subdirectories will modify the interface include directories / link libraries etc so
# that the final testing executable depends on the respective libraries built by
# sub-projects (via add_subdirectory).
add_library(exhale-projects-tests-interface INTERFACE)
target_include_directories(exhale-projects-tests-interface
  INTERFACE
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# The main testing executable target.
# Subdirectories will modify the target_sources() of this executable to append their
# respective tests.
add_executable(exhale-projects-unit-tests
  ${CMAKE_CURRENT_BINARY_DIR}/src/main.cpp
)
target_link_libraries(exhale-projects-unit-tests
  PRIVATE
    exhale-projects-tests-interface
)

# Setup code coverage (changes CMAKE_<LANG>_FLAGS, must be done before add_subdirectory calls).
if (NOT WIN32)
  # See ${CMAKE_BINARY_DIR}/cmake/CodeCoverage.cmake, this trims the local genhtml report
  set(COVERAGE_GCOVR_EXCLUDES
    "'/usr/*'"
    "'${CMAKE_BINARY_DIR}/*'"
  )
  include(CodeCoverage)
  append_coverage_compiler_flags()
endif()

# List of projects to validate have code that actually compiles xD
set(EXHALE_PROJECTS
  cpp_nesting
)
foreach (proj ${EXHALE_PROJECTS})
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${proj})
endforeach()

# NOTE: must be done *AFTER* all add_subdirectory are finished so that the target
#       exhale-projects-unit-tests has all of the correct sources.
if (UNIX)
  setup_target_for_coverage_gcovr_xml(
    NAME coverage-xml
    EXECUTABLE $<TARGET_FILE:exhale-projects-unit-tests>
    DEPENDENCIES exhale-projects-unit-tests
  )
  setup_target_for_coverage_gcovr_html(
    NAME coverage-html
    EXECUTABLE $<TARGET_FILE:exhale-projects-unit-tests>
    DEPENDENCIES exhale-projects-unit-tests cpp-fortran-mixed
  )
endif()
