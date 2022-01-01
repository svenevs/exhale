/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>
#include <c_maths.h>

/* ================================================================================== */

TEST_CASE( "cm_add", "[c-maths]" ) {
    SECTION( "Zero" ) {
        REQUIRE( cm_add(0, 0) == 0 );
    }

    SECTION( "Positive plus positive." ) {
        REQUIRE( cm_add(0, 1) == 1 );
        REQUIRE( cm_add(1, 0) == 1 );
        REQUIRE( cm_add(1, 2) == 3 );
        REQUIRE( cm_add(2, 1) == 3 );
    }

    SECTION( "Negative plus negative." ) {
        REQUIRE( cm_add( 0, -1) == -1 );
        REQUIRE( cm_add(-1,  0) == -1 );
        REQUIRE( cm_add(-1, -2) == -3 );
        REQUIRE( cm_add(-2, -1) == -3 );
    }

    SECTION( "Negative plus positive." ) {
        REQUIRE( cm_add(-1, 2) ==  1 );
        REQUIRE( cm_add(-2, 1) == -1 );
    }

    SECTION( "Positive plus negative." ) {
        REQUIRE( cm_add(1, -2) == -1 );
        REQUIRE( cm_add(2, -1) ==  1 );
    }
}

/* ================================================================================== */

TEST_CASE( "cm_sub", "[c-maths]" ) {
    SECTION( "Zero" ) {
        REQUIRE( cm_sub(0, 0) == 0 );
    }

    SECTION( "Positive minus positive." ) {
        REQUIRE( cm_sub(0, 1) == -1 );
        REQUIRE( cm_sub(1, 0) ==  1 );
        REQUIRE( cm_sub(1, 2) == -1 );
        REQUIRE( cm_sub(2, 1) ==  1 );
    }

    SECTION( "Negative minus negative." ) {
        REQUIRE( cm_sub( 0, -1) ==  1 );
        REQUIRE( cm_sub(-1,  0) == -1 );
        REQUIRE( cm_sub(-1, -2) ==  1 );
        REQUIRE( cm_sub(-2, -1) == -1 );
    }

    SECTION( "Negative minus positive." ) {
        REQUIRE( cm_sub(-1, 2) == -3 );
        REQUIRE( cm_sub(-2, 1) == -3 );
    }

    SECTION( "Positive minus negative." ) {
        REQUIRE( cm_sub(1, -2) == 3 );
        REQUIRE( cm_sub(2, -1) == 3 );
    }
}
