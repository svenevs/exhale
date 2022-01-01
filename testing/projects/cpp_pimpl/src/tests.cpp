/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>

#include <pimpl/earth.hpp>
#include <pimpl/jupiter.hpp>

inline bool epsilon_equals(const double &a, const double &b) {
    return std::abs(a - b) < 1e-6;// so generous lol
}

TEST_CASE( "pimpl::Earth", "[cpp-pimpl]" ) {
    auto earth = pimpl::Earth();
    REQUIRE( epsilon_equals(earth.mass(), 5.97237e24) );
    REQUIRE( epsilon_equals(earth.radius(), 6'371.0) );
    REQUIRE( epsilon_equals(earth.eccentricity(), 0.0167086) );
    REQUIRE( epsilon_equals(earth.surface_gravity(), 9.807) );
    REQUIRE( earth.describe() == "Earth" );
}

TEST_CASE( "pimpl::Earth_v2", "[cpp-pimpl]" ) {
    auto earth_v2 = pimpl::Earth_v2();
    REQUIRE( epsilon_equals(earth_v2.mass(), 5.97237e24) );
    REQUIRE( epsilon_equals(earth_v2.radius(), 6'371.0) );
    REQUIRE( epsilon_equals(earth_v2.eccentricity(), 0.0167086) );
    REQUIRE( epsilon_equals(earth_v2.surface_gravity(), 9.807) );
    REQUIRE( earth_v2.describe() == "Earth_v2" );
}

TEST_CASE( "pimpl::Jupiter", "[cpp-pimpl]" ) {
    auto jupiter = pimpl::Jupiter();
    REQUIRE( epsilon_equals(jupiter.mass(), 1.8982e27) );
    REQUIRE( epsilon_equals(jupiter.radius(), 69'911.0) );
    REQUIRE( epsilon_equals(jupiter.eccentricity(), 0.0489) );
    REQUIRE( epsilon_equals(jupiter.surface_gravity(), 24.79) );
    REQUIRE( jupiter.describe() == "Jupiter" );
}

TEST_CASE( "pimpl::Jupiter_v2", "[cpp-pimpl]" ) {
    auto jupiter_v2 = pimpl::Jupiter_v2();
    REQUIRE( epsilon_equals(jupiter_v2.mass(), 1.8982e27) );
    REQUIRE( epsilon_equals(jupiter_v2.radius(), 69'911.0) );
    REQUIRE( epsilon_equals(jupiter_v2.eccentricity(), 0.0489) );
    REQUIRE( epsilon_equals(jupiter_v2.surface_gravity(), 24.79) );
    REQUIRE( jupiter_v2.describe() == "Jupiter_v2" );
}
