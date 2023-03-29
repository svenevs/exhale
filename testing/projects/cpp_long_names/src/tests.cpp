/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2023                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>
#include <type_traits>
#include <sstream>

#include <absurdly_long_names.hpp>

TEST_CASE( "MAKE_IT_BIG(class)", "[cpp-long-names]" ) {
    MAKE_IT_BIG(class) cls;
    int value = cls.value;
    REQUIRE( value == 1 );
}

TEST_CASE( "MAKE_IT_BIG(struct)", "[cpp-long-names]" ) {
    MAKE_IT_BIG(struct) s;
    int value = s.value;
    REQUIRE( value == 2 );
}

TEST_CASE( "MAKE_IT_BIG(function)", "[cpp-long-names]" ) {
    auto divergence = MAKE_IT_BIG(function)();
    REQUIRE( divergence == "The divergence number: 0.999999999" );
}

TEST_CASE( "MAKE_IT_BIG(enum)", "[cpp-long-names]" ) {
    REQUIRE( MAKE_IT_BIG(enum)::first  == 1 );
    REQUIRE( MAKE_IT_BIG(enum)::second == 2 );
    REQUIRE( MAKE_IT_BIG(enum)::third  == 3 );
}

TEST_CASE( "MAKE_IT_BIG(namespace)", "[cpp-long-names]" ) {
    int value = MAKE_IT_BIG(namespace)::value;
    REQUIRE( value == 0 );
}

TEST_CASE( "#define longer than 255", "[cpp-long-names]" ) {
    auto Jajajaja = std::string(DEFINE_THAT_IS_LONGER_THAN_TWO_HUNDRED_AND_FIFTY_FIVE_CHARACTERS_LONG_WHICH_IS_AN_ABSOLUTELY_AND_COMPLETELY_RIDICULOUS_THING_TO_DO_AND_IF_YOU_DID_THIS_IN_THE_REAL_WORLD_YOU_PUT_YOURSELF_COMFORTABLY_IN_A_POSITION_TO_BE_DOWNSIZED_AND_OUTTA_HERE_AS_SOUL_POSITION_WOULD_EXPLAIN_TO_YOU);
    REQUIRE( Jajajaja == "Jajajaja" );
}

TEST_CASE( "MAKE_IT_BIG(variable)", "[cpp-long-names]" ) {
    int var = MAKE_IT_BIG(variable);
    REQUIRE( var == 929 );
}

TEST_CASE( "MAKE_IT_BIG(typedef)", "[cpp-long-names]" ) {
    // sigh, std::is_same_v introduced in C++17, i'm compiling in C++14.
    bool is_float = std::is_same<MAKE_IT_BIG(typedef), float>::value;
    REQUIRE( is_float );
}

TEST_CASE( "MAKE_IT_BIG(union)", "[cpp-long-names]" ) {
    // from the docs: https://en.cppreference.com/w/cpp/language/union
    MAKE_IT_BIG(union) u = {0x12345678}; // initializes the first member, s.n is now the active member
    std::ostringstream n_stream;
    n_stream << std::hex << "u.n = 0x" << u.n;
    std::string n_str = n_stream.str();
    REQUIRE( n_str == "u.n = 0x12345678" );
}

#if !defined(_WIN32)
  #include <directory/structure/that/is/longer/than/two/hundred/and/fifty/five/characters/long/which/is/an/absolutely/and/completely/ridiculous/thing/to/do/and/if/you/did/this/in/the/real/world/you/put/yourself/comfortably/in/a/position/to/be/downsized/and/outta/here/as/soul/position/would/explain/to/you/a_file.hpp>
  TEST_CASE( "absurd directory structure", "[cpp-long-names]" ) {
      auto nested = extremely_nested();
      REQUIRE( nested == "Extremely nested works!!!" );
  }
#endif