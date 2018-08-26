/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2018                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>
#include <overload/overload.hpp>

/* ================================================================================== */

TEST_CASE( "void blargh()", "[cpp-func-overloads]" ) {
    overload::blargh();
    REQUIRE( true );// compilation is the test.
}

/* ================================================================================== */

TEST_CASE( "int blargh(int)", "[cpp-func-overloads]" ) {
    int x = overload::blargh(0);
    REQUIRE( x == 0 );
}

TEST_CASE( "int blargh(int, int)", "[cpp-func-overloads]" ) {
    int xy = overload::blargh(1, 2);
    REQUIRE( xy == 3 );
}

TEST_CASE( "int blargh(int, int, int)", "[cpp-func-overloads]" ) {
    int xyz = overload::blargh(1, 2, 3);
    REQUIRE( xyz == 6 );
}

/* ================================================================================== */

TEST_CASE( "float blargh(float)", "[cpp-func-overloads]" ) {
    float neg_x = overload::blargh(1.0f);
    REQUIRE( neg_x == -1.0f );
}

TEST_CASE( "float blargh(float, float)", "[cpp-func-overloads]" ) {
    float neg_xy = overload::blargh(1.0f, 2.0f);
    REQUIRE( neg_xy == -3.0f );
}

TEST_CASE( "float blargh(float, float, float)", "[cpp-func-overloads]" ) {
    float neg_xyz = overload::blargh(1.0f, 2.0f, 3.0f);
    REQUIRE( neg_xyz == -6.0f );
}

/* ================================================================================== */

TEST_CASE( "std::string blargh(const std::string &)", "[cpp-func-overloads]" ) {
    auto x = overload::blargh("blargh");
    REQUIRE( x == "blargh" );
}

TEST_CASE( "std::string blargh(const std::string &, const std::string &)", "[cpp-func-overloads]" ) {
    auto xy = overload::blargh("blargh ", "blargh");
    REQUIRE( xy == "blargh blargh" );
}

TEST_CASE( "std::string blargh(const std::string &, const std::string &, const std::string &)", "[cpp-func-overloads]" ) {
    auto xyz = overload::blargh("blargh ", "blargh ", "blargh");
    REQUIRE( xyz == "blargh blargh blargh" );
}

/* ================================================================================== */

TEST_CASE( "std::size_t blargh(std::size_t, const std::string &)", "[cpp-func-overloads]" ) {
    auto wtf = overload::blargh(std::size_t(5), "eleven");
    REQUIRE( wtf == std::size_t(11) );
}

TEST_CASE( "std::size_t blargh(std::size_t, const float &, double, const std::string &)", "[cpp-func-overloads]" ) {
    auto wtf = overload::blargh(std::size_t(2), 12.21f, 11.11, "luncheon");
    REQUIRE( wtf == std::size_t(33) );
}

/* ================================================================================== */

TEST_CASE( "void blargh(std::vector<std::string> &)", "[cpp-func-overloads]" ) {
    std::vector<std::string> v;
    REQUIRE( v.size() == 0);

    overload::blargh(v);
    REQUIRE( v.size() == 1    );
    REQUIRE( v[0] == "blargh" );

    v.emplace_back("narp");
    REQUIRE( v.size() == 2    );
    REQUIRE( v[0] == "blargh" );
    REQUIRE( v[1] == "narp"   );

    overload::blargh(v);
    REQUIRE( v.size() == 3    );
    REQUIRE( v[0] == "blargh" );
    REQUIRE( v[1] == "narp"   );
    REQUIRE( v[2] == "blargh" );

    v.emplace_back("yarp");
    REQUIRE( v.size() == 4    );
    REQUIRE( v[0] == "blargh" );
    REQUIRE( v[1] == "narp"   );
    REQUIRE( v[2] == "blargh" );
    REQUIRE( v[3] == "yarp"   );

    overload::blargh(v);
    REQUIRE( v.size() == 5    );
    REQUIRE( v[0] == "blargh" );
    REQUIRE( v[1] == "narp"   );
    REQUIRE( v[2] == "blargh" );
    REQUIRE( v[3] == "yarp"   );
    REQUIRE( v[4] == "blargh" );
}

TEST_CASE( "void blargh(std::vector<std::vector<int>>&)", "[cpp-func-overloads]" ) {
    std::vector<std::vector<int>> v;
    REQUIRE( v.size() == 0 );

    overload::blargh(v);
    REQUIRE( v.size()    == 1 );
    REQUIRE( v[0].size() == 1 );
    REQUIRE( v[0][0]     == 0 );

    v[0].emplace_back(1);
    REQUIRE( v.size()    == 1 );
    REQUIRE( v[0].size() == 2 );
    REQUIRE( v[0][0]     == 0 );
    REQUIRE( v[0][1]     == 1 );

    overload::blargh(v);
    REQUIRE( v.size()    == 2 );
    REQUIRE( v[0].size() == 2 );
    REQUIRE( v[0][0]     == 0 );
    REQUIRE( v[0][1]     == 1 );
    REQUIRE( v[1].size() == 1 );
    REQUIRE( v[1][0]     == 0 );

    v[1].emplace_back(2);
    REQUIRE( v.size()    == 2 );
    REQUIRE( v[0].size() == 2 );
    REQUIRE( v[0][0]     == 0 );
    REQUIRE( v[0][1]     == 1 );
    REQUIRE( v[1].size() == 2 );
    REQUIRE( v[1][0]     == 0 );
    REQUIRE( v[1][1]     == 2 );
}

/* ================================================================================== */

TEST_CASE( "void blargh(const float*, const float*, float*, std::size_t)", "[cpp-func-overloads]" ) {
    float x = 1.0f;
    float y = 2.0f;
    float z = 0.0f;
    overload::blargh(&x, &y, &z, 1);
    REQUIRE(z == 3.0f);

    static constexpr std::size_t N = 33;
    float *xs = (float *)malloc(N * sizeof(float));
    float *ys = (float *)malloc(N * sizeof(float));
    float *zs = (float *)malloc(N * sizeof(float));
    for (std::size_t i = 0; i < N; ++i) {
        xs[i] = static_cast<float>(i);
        ys[i] = static_cast<float>(N - i);
        zs[i] = 0.0f;
    }

    overload::blargh(xs, ys, zs, N);
    for (std::size_t i = 0; i < N; ++i) {
        CHECK( zs[i] == static_cast<float>(i + (N - i)) );
    }

    free(xs);
    free(ys);
    free(zs);
}

/* ================================================================================== */

TEST_CASE( "template <class C> typename C::type blargh(typename C::type)", "[cpp-func-overloads]" ) {
    struct C_float { using type = float; };
    auto v_f = overload::blargh<C_float>(11.11f);
    REQUIRE( v_f == 11.11f );

    struct C_int { using type = int; };
    auto v_i = overload::blargh<C_int>(12);
    REQUIRE( v_i == 12 );

    struct C_string { using type = std::string; };
    auto v_s = overload::blargh<C_string>("hiya");
    REQUIRE( v_s == "hiya" );

    struct Blargh { std::string name = "jajaja"; };
    struct C_Blargh { using type = Blargh; };

    auto b = Blargh();
    auto v_Blargh = overload::blargh<C_Blargh>(b);
    REQUIRE( v_Blargh.name == "jajaja" );
    REQUIRE( &v_Blargh != &b );

    b.name = "Snow, John";
    v_Blargh = overload::blargh<C_Blargh>(b);
    REQUIRE( v_Blargh.name == "Snow, John" );
    REQUIRE( &v_Blargh != &b );
}

TEST_CASE( "template <class C, typename T> T blargh(typename C::type)", "[cpp-func-overloads]" ) {
    struct C_float { using type = float; };

    double v_f2d = overload::blargh<C_float, double>(11.0f);
    REQUIRE( v_f2d == 11.0 );

    std::string v_f2s = overload::blargh<C_float, std::string>(11.0f);
    REQUIRE( v_f2s == "" );

    struct C_int { using type = int; };

    long v_i2l = overload::blargh<C_int, long>(12);
    REQUIRE( v_i2l == 12 );

    std::string v_i2s = overload::blargh<C_int, std::string>(12);
    REQUIRE( v_i2s == "" );

    struct C_string { using type = std::string; };

    std::basic_string<char> v_s2c = overload::blargh<C_string, std::basic_string<char>>("hiya");
    REQUIRE( v_s2c == "hiya" );

    int v_s2i = overload::blargh<C_string, int>("hiya");
    REQUIRE( v_s2i == 0 );
}

/* ================================================================================== */

TEST_CASE( "int ::blargh(int)", "[cpp-func-overloads]" ) {
    int x = blargh(0);
    REQUIRE( x == 0 );

    x = blargh(12);
    REQUIRE( x == 12 );
}
