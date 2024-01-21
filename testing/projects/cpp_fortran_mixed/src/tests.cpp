/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2024                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>
#include <convert/convert.hpp>
#include <limits>

namespace gold {
    template <typename T>
    T Pi() {
        return static_cast<T>(3.14159265358979323846264338327950288);// shouldn't actually be used
    }

    template <>
    float Pi<float>() {
        return 3.14159265358979323846f;
    }

    template <>
    double Pi<double>() {
        return 3.14159265358979323846264338327950288;
    }

    template <typename T>
    T to_radians(T degrees) {
        return degrees * Pi<T>() / static_cast<T>(180.0);
    }

    template <typename T>
    T to_degrees(T radians) {
        return radians * static_cast<T>(180.0) / Pi<T>();
    }
}

template <typename T>
inline bool epsilon_equals(T a, T b) {
    return std::abs(a - b) < std::numeric_limits<T>::round_error();
}

template <typename T> inline T num_tests() { return T(512.0); }

// T should only be `float` or `double`!
template <typename T>
void test_to_radians() {
    auto min     = T(-720.0);
    auto max     = T(720.0);
    auto incr    = (max - min) / num_tests<T>();
    auto degrees = min;
    while (degrees <= max) {
        REQUIRE(epsilon_equals<T>(
            convert::to_radians<T>(degrees), gold::to_radians<T>(degrees)
        ));
        degrees += incr;
    }
}

// T should only be `float` or `double`!
template <typename T>
void test_to_degrees() {
    auto min     = T(-2.0) * gold::Pi<T>();
    auto max     = T( 2.0) * gold::Pi<T>();
    auto incr    = (max - min) / num_tests<T>();
    auto radians = min;
    while (radians <= max) {
        REQUIRE(epsilon_equals<T>(
            convert::to_degrees<T>(radians), gold::to_degrees<T>(radians)
        ));
        radians += incr;
    }
}

TEST_CASE( "convert::to_radians" , "[cpp-fortran-mixed]") {
    SECTION( "convert::to_radians< float >") {
        test_to_radians<float>();
    }
    SECTION( "convert::to_radians< double >") {
        test_to_radians<double>();
    }
    SECTION( "convert::to_radians< int >" ) {
        REQUIRE_THROWS_WITH(
            convert::to_radians<int>(0),
            "convert::to_radians<T>: T may only be `float` or `double`."
        );
    }
}

TEST_CASE( "convert::to_degrees", "[cpp-fortran-mixed]" ) {
    SECTION( "convert::to_degrees< float >" ) {
        test_to_degrees<float>();
    }
    SECTION( "convert::to_degrees< double >" ) {
        test_to_degrees<double>();
    }
    SECTION( "convert::to_degrees< int >" ) {
        REQUIRE_THROWS_WITH(
            convert::to_degrees<int>(0),
            "convert::to_degrees<T>: T may only be `float` or `double`."
        );
    }
}
