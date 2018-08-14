########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2018                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(cpp-nesting)

# "Header only library": add tests and include the directory
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)
target_include_directories(exhale-projects-tests-interface
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add to explicit list of sources for OpenCppCoverage
if (MSVC)
  foreach (dir include src)
    list(APPEND OPEN_CPP_COVERAGE_SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
  endforeach()
  set(OPEN_CPP_COVERAGE_SOURCE_LIST "${OPEN_CPP_COVERAGE_SOURCE_LIST}" PARENT_SCOPE)
endif()
