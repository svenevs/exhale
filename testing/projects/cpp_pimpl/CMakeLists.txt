########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2022                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(cpp-pimpl LANGUAGES CXX)

# Add the cpp-pimpl library
add_library(cpp-pimpl "")
target_sources(cpp-pimpl
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/pimpl/planet.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/pimpl/earth.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/pimpl/jupiter.hpp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/earth.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jupiter.cpp
)
target_include_directories(cpp-pimpl
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add the tests and link against the cpp-pimpl library.
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)
target_link_libraries(exhale-projects-tests-interface
  INTERFACE
    cpp-pimpl
)

add_open_cpp_coverage_source_dirs(include src)
