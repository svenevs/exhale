/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2021                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#include <catch2/catch.hpp>
#include <meta/cxx_attrs.hpp>

/* ================================================================================== */

TEST_CASE( "[[ noreturn ]]", "[cpp-meta]" ) {
    using namespace meta::noreturn;
    REQUIRE_THROWS(f(), "f() must throw");
    REQUIRE_THROWS(q(11), "q() throws unconditionally.");
}

/* ================================================================================== */

TEST_CASE( "[[ carries_dependency ]]", "[cpp-meta]" ) {
    using namespace meta::carries_dependency;
    int me = 22;
    REQUIRE(carry(&me) == 22);
    me = 33;
    REQUIRE(*pass_through(&me) == 33);
}

/* ================================================================================== */

// TODO: probably should tell the compiler its OK we want to use it ;)
TEST_CASE( "[[ deprecated ]]", "[cpp-meta]" ) {
    using namespace meta::deprecated;
    REQUIRE(ground_truth == 0);
    ThisIs this_is;
    REQUIRE(this_is.fine == true);
    REQUIRE(this_is_fine() == true);
}

/* ================================================================================== */

TEST_CASE( "[[ nodiscard ]]", "[cpp-meta]" ) {
    using namespace meta::nodiscard;
    PleaseDontKillMe pdkm;
    REQUIRE(pdkm.keep == 11);
    int sv = strategic_value(11, 33);
    REQUIRE(sv == 42);
    REQUIRE(Keeper::ForSomeTime == 0);
    REQUIRE(Keeper::ForLife == 1);
    REQUIRE(Keeper::ForEver == 2);
    REQUIRE(Keeper::ForEverAndEver == 3);
}

/* ================================================================================== */

TEST_CASE( "[[ maybe_unused ]]", "[cpp-meta]" ) {
    using namespace meta::maybe_unused;
    MayBe may_be;
    REQUIRE(may_be.unused == 666);

    may_be.unused = 777;
    MayBePtrTdef mb_ptr_tdef = &may_be;
    REQUIRE(mb_ptr_tdef->unused == 777);
    may_be.unused = 1111;
    MayBePtrUsing mb_ptr_use = &may_be;
    REQUIRE(mb_ptr_use->unused == 1111);

    REQUIRE(stat_var == 222);

    U u{1221};
    REQUIRE(u.n == 1221);

    REQUIRE(f(true, true) == true);
    REQUIRE(f(true, false) == true);
    REQUIRE(f(false, true) == true);
    REQUIRE(f(false, false) == true);

    REQUIRE(MayBeNum::May == 0);
    REQUIRE(MayBeNum::Be == 1);
    REQUIRE(MayBeNum::Num == 2);
}
