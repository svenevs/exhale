/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>

/* ================================================================================== */

#include <top_level.hpp>
TEST_CASE( "top_level", "[cpp-nesting]" ) {
    top_level tl("hiya");
    REQUIRE( tl.mName == "hiya" );
}

/* ================================================================================== */

#include <nested/one/one.hpp>
TEST_CASE( "nested/one/one.hpp", "[cpp-nesting]" ) {
    nested::one one;
    REQUIRE( one.compiles() );

    nested::one::params one_params;
    REQUIRE( one_params.compiles() );

    REQUIRE( sizeof(nested::one::params::four_bytes) == 4 );
}

/* ================================================================================== */

#include <nested/two/two.hpp>
TEST_CASE( "nested/two/two.hpp", "[cpp-nesting]" ) {
    nested::two two;
    REQUIRE( two.compiles() );

    nested::two::params two_params;
    REQUIRE( two_params.compiles() );

    REQUIRE( sizeof(nested::four_bytes) == 4 );
    REQUIRE( sizeof(nested::two::params::four_bytes) == 4 );
}

/* ================================================================================== */

#include <nested/dual_nested/one/one.hpp>
TEST_CASE( "nested/dual_nested/one/one.hpp", "[cpp-nesting]" ) {
    nested::dual_nested::one one;
    REQUIRE( one.compiles() );

    nested::dual_nested::one::params one_params;
    REQUIRE( one_params.compiles() );

    REQUIRE( sizeof(nested::dual_nested::one::params::four_bytes) == 4 );
}

/* ================================================================================== */

#include <nested/dual_nested/two/two.hpp>
TEST_CASE( "nested/dual_nested/two/two.hpp", "[cpp-nesting]" ) {
    nested::dual_nested::two two;
    REQUIRE( two.compiles() );

    nested::dual_nested::two::params two_params;
    REQUIRE( two_params.compiles() );

    REQUIRE( sizeof(nested::dual_nested::two::params::four_bytes) == 4 );
}
