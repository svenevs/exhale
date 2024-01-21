/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2024                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>

/* ================================================================================== */

#include <interface_alpha/alpha.hpp>
TEST_CASE( "interface_alpha/alpha", "[cpp-dir-underscores]" ) {
    interface_alpha::Alpha alpha;
    REQUIRE( alpha.id() == "alpha" );
}

/* ================================================================================== */

#include <interface_alpha/one_two_three/one_two_three.hpp>
TEST_CASE( "interface_alpha/one_two_three", "[cpp-dir-underscores]") {
    interface_alpha::one_two_three::OneTwoThree ott;
    REQUIRE( ott.id() == "one_two_three" );
}

/* ================================================================================== */

#include <interface_alpha/__four_five_six__/__four_five_six__.hpp>
TEST_CASE( "interface_alpha/four_five_six", "[cpp-dir-underscores]") {
    interface_alpha::four_five_six::FourFiveSix ffs;
    REQUIRE( ffs.id() == "four_five_six" );
}

/* ================================================================================== */

#include <interface_beta/beta.hpp>
TEST_CASE( "interface_beta/beta", "[cpp-dir-underscores]") {
    interface_beta::Beta beta;
    REQUIRE( beta.id() == "beta" );
}
