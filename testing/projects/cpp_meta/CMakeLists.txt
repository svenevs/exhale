########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2021                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(cpp-meta LANGUAGES CXX)

# "Header only library": add tests and include the directory
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)

# Ignore some warnings e.g. intentional use of [[ deprecated ]] things.
# TODO: not sure how to disable... flag isn't found.
# warning: ‘bool meta::deprecated::this_is_fine()’ is deprecated [-Wdeprecated-declarations]
# include(CheckCXXCompilerFlag)
# check_cxx_compiler_flag("-Wdeprecated-declarations" no_deprecated)

target_include_directories(exhale-projects-tests-interface
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_open_cpp_coverage_source_dirs(include src)
