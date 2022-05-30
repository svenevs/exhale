/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>
#include <type_traits>
#include <vector>

/* ================================================================================== */

#include <top_level.hpp>
TEST_CASE( "top_level", "[cpp-nesting]" ) {
    top_level tl("hiya");
    REQUIRE( tl.mName == "hiya" );
}

/* ================================================================================== */

#include <nesting_specializations.hpp>
TEST_CASE( "nesting_specializations", "[cpp-nesting]" ) {
    REQUIRE(special::Normal().id() == "Normal");
    REQUIRE(special::Normal::Nested().id() == "Nested");
    REQUIRE(special::Normal::Nested::Like().id() == "Like");
    REQUIRE(special::Normal::Nested::Like::Usual().id() == "Usual");

    using VGA = special::Image<640, 480>;
    REQUIRE(VGA::width == 640);
    REQUIRE(VGA::height == 480);

    // 2 channels is just awkward.
    using WeirdBuffer = special::ImageBuffer<VGA, float, 2>;
    REQUIRE(std::is_same_v<WeirdBuffer::Image_t, VGA>);
    REQUIRE(WeirdBuffer::width == 640);
    REQUIRE(WeirdBuffer::height == 480);
    REQUIRE(std::is_same_v<WeirdBuffer::data_t, float>);
    REQUIRE(WeirdBuffer::channels == 2);
    WeirdBuffer::Data weird_data;// compilation test for changing Data
    weird_data.vals[0] = 111.111f;
    weird_data.vals[1] = 222.222f;
    REQUIRE(std::abs(weird_data.vals[0] - 111.111f) < 1e-6);
    REQUIRE(std::abs(weird_data.vals[1] - 222.222f) < 1e-6);
    REQUIRE(WeirdBuffer::SomeThing<3>().id() == "3");
    REQUIRE(WeirdBuffer().size() == 640 * 480 * 2 * sizeof(float));

    // what a name!
    using PngVgaRgba = special::ImageBuffer<VGA, uint8_t, 4>;
    REQUIRE(std::is_same_v<PngVgaRgba::Image_t, VGA>);
    REQUIRE(PngVgaRgba::width == 640);
    REQUIRE(PngVgaRgba::height == 480);
    REQUIRE(std::is_same_v<PngVgaRgba::data_t, uint8_t>);
    REQUIRE(PngVgaRgba::channels == 4);
    PngVgaRgba::Data pix{1, 2, 3, 4};// compilation test for changing Data
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 2);
    REQUIRE(pix.b == 3);
    REQUIRE(pix.a == 4);
    REQUIRE(PngVgaRgba::SomeThing().id() == "I AM SPECIAL!");
    REQUIRE(PngVgaRgba().size() == 640 * 480 * 4);

    // fully special
    using Wow = special::ImageBuffer<special::Image<1920, 1080>, float, 128>;
    REQUIRE(std::is_same_v<Wow::Image_t, special::Image<1920, 1080>>);
    REQUIRE(Wow::width == 1920);
    REQUIRE(Wow::height == 1080);
    REQUIRE(std::is_same_v<Wow::data_t, float>);
    Wow::Data wow_data;
    wow_data.samples.emplace_back(0.0f);
    REQUIRE(std::abs(wow_data.samples[0]) < 1e-6);
    REQUIRE(Wow::SomeThing().id() == "Spectral");
    REQUIRE(Wow().size() == 88);

    // Base without specialization.
    REQUIRE(special::Base<1>().size() == 1);

    // Base with specialization.
    using B2 = special::Base<2>;
    REQUIRE(B2().size() == 42);
    REQUIRE(B2::InnerStruct().a() == 3);
    REQUIRE(B2::AnotherNestedStruct().b() == 4);
    REQUIRE(B2::InnerTemplatedStruct<3>().s() == '{');
    REQUIRE(B2::InnerTemplatedStruct<4>().s() == '}');

    // special::unique::snowflake::Ontology
    using SSO1 = special::unique::snowflake::Ontology<1>;
    SSO1 onsies;
    REQUIRE(SSO1::epoch() == onsies.epoch());
    REQUIRE(SSO1::epoch() == 1);
    REQUIRE(onsies.dual() == 1);

    using SSO11 = special::unique::snowflake::Ontology<11>;
    SSO11 elevensies;
    REQUIRE(SSO11::epoch() == elevensies.epoch());
    REQUIRE(SSO11::epoch() == 11);
    REQUIRE(elevensies.dual() == 22);

    // special::unique::Nonsense
    using NonsenseVec = special::unique::Nonsense<11, std::vector<int>>;
    std::vector<int> mein_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    NonsenseVec n_vec{mein_vector};
    REQUIRE(n_vec.x() == 11);
    REQUIRE(n_vec.t().size() == 11);

    using SSO22 = special::unique::snowflake::Ontology<22>;
    using PartialNonsense = special::unique::PartialNonsense<22>;
    SSO22 ssdd;
    PartialNonsense pn{ssdd};
    REQUIRE(pn.x() == ssdd.epoch() + pn.t().dual() + 22);

    using FullNonsense = special::unique::FullNonsense;
    FullNonsense fn{elevensies};
    REQUIRE(fn.x() == elevensies.epoch() + fn.t().dual());
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
