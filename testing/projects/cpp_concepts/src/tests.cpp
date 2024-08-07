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

#include <concepts/concepts.hpp>
TEST_CASE( "concepts.hpp", "[cpp-concepts]" ) {
    struct Concrete : public concepts::Base {
        int value() const { return 11; }
    };
    Concrete c;

    REQUIRE(concepts::get_value(c) == 11);
}
