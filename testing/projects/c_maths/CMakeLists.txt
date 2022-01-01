########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2022                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(c-maths LANGUAGES C)

# Add the c-maths library
add_library(c-maths "")
target_sources(c-maths
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/c_maths.h
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/c_maths.c
)
target_include_directories(c-maths
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
    c-maths
)

add_open_cpp_coverage_source_dirs(include src)
