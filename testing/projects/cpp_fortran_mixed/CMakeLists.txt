########################################################################################
# This file is dedicated to the public domain.  If your jurisdiction requires a        #
# specific license:                                                                    #
#                                                                                      #
# Copyright (c) Stephen McDowell, 2017-2018                                            #
# License:      CC0 1.0 Universal                                                      #
# License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            #
########################################################################################
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(cpp-fortran-mixed LANGUAGES C CXX Fortran)

if (WIN32 OR MSVC)
  message(FATAL_ERROR "The cpp-fortran-mixed library is not configured for windows support.")
endif()

# The extern "C" { ... } bit calling the fortran code is not to be run with
# coverage flags, because they break compilation...
set(NEW_CMAKE_C_FLAGS "")
foreach (flag ${CMAKE_C_FLAGS})
  if (NOT ${flag} MATCHES "--coverage" AND NOT ${flag} MATCHES "-fprofile-args" AND NOT ${flag} MATCHES "=ftest-coverage")
    list(APPEND NEW_CMAKE_C_FLAGS ${flag})
  endif()
endforeach()
set(CMAKE_C_FLAGS ${NEW_CMAKE_C_FLAGS}) # don't do PARENT_SCOPE here ;)

# Add the cpp-fortran-mixed library
add_library(cpp-fortran-mixed "")

# Generates the FC_MODULE macros for calling from extern "C" { ... } code.
include(FortranCInterface)
FortranCInterface_HEADER(
    ${CMAKE_CURRENT_BINARY_DIR}/include/convert/fortran_interface.h
    MACRO_NAMESPACE "FC_"
)

# Set the sources for the cpp-fortran-mixed library.
target_sources(cpp-fortran-mixed
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/convert/convert.hpp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/convert.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/conversions.f90
    ${CMAKE_CURRENT_BINARY_DIR}/include/convert/fortran_interface.h
)
# Include the default and generated include directories.
target_include_directories(cpp-fortran-mixed
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Add the tests and link against the cpp-fortran-mixed library.
target_sources(exhale-projects-unit-tests
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)
target_link_libraries(exhale-projects-tests-interface
  INTERFACE
    cpp-fortran-mixed
)
