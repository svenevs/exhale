########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2019                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(cpp-with-spaces LANGUAGES CXX)

# Add the cpp-with-spaces library
add_library(cpp-with-spaces "")
target_sources(cpp-with-spaces
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/with spaces/with spaces.hpp"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/with spaces.cpp"
)
target_include_directories(cpp-with-spaces
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add the tests and link against the c-maths library.
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)
target_link_libraries(exhale-projects-tests-interface
  INTERFACE
    cpp-with-spaces
)

add_open_cpp_coverage_source_dirs(include src)
