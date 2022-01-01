########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2022                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(cpp-func-overloads LANGUAGES CXX)

# Add the cpp-func-overloads library
add_library(cpp-func-overloads "")
target_sources(cpp-func-overloads
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/overload/overload.hpp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/overload.cpp
)
target_include_directories(cpp-func-overloads
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add the tests and link against the cpp-func-overloads library.
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)
target_link_libraries(exhale-projects-tests-interface
  INTERFACE
    cpp-func-overloads
)

add_open_cpp_coverage_source_dirs(include src)
