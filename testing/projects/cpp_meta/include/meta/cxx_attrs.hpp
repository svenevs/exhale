/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2021                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief Various signatures with c++ attributes involved.
 *
 * See: https://en.cppreference.com/w/cpp/language/attributes
 *
 * Skipped as irrelevant for documentation tests:
 *
 * - fallthrough
 * - likely
 * - unlikely
 */
#pragma once

/// The metaphysical nature of a namespace.
namespace meta {
    /// Encapsulates `[[ noreturn ]]`.
    namespace noreturn {
        /// From: https://en.cppreference.com/w/cpp/language/attributes/noreturn
        [[ noreturn ]] void f() {
            throw "f() must throw";
        }

        /// From: https://en.cppreference.com/w/cpp/language/attributes/noreturn
        /// Testing `[[ noreturn ]]`` on the other side.
        void q [[ noreturn ]] (int i) {
            throw "q() throws unconditionally.";
        }
    }// namespace noreturn

    /// Encapsulates `[[ carries_dependency ]]`.
    namespace carries_dependency {
        /// Option (1): on a parameter.
        int carry([[ carries_dependency ]] int *me) { return me[0]; }

        /// Option (2): on a function.
        [[ carries_dependency ]] int* pass_through(int *me) { return me; }
    }// namespace carries_dependency

    /// Encapsulates `[[ deprecated ]]`.
    namespace [[ deprecated ]] deprecated {
        /// The ground truth of all things.
        [[ deprecated ]] static constexpr int ground_truth = 0;

        /// A deprecated struct.
        struct [[ deprecated("this is fine") ]] ThisIs {
            bool fine = true;///< It is ok.
        };

        /// A deprecated function.
        [[ deprecated ]] bool this_is_fine() { return true; }
    }// namespace deprecated

    /// Encapsulates `[[ nodiscard ]]`.
    namespace nodiscard {
        /// A struct not to be discarded.
        struct [[ nodiscard ]] PleaseDontKillMe {
            int keep = 11;///< Keep it 11.
        };

        /// C++ 20 on a function.
        /// From: https://en.cppreference.com/w/cpp/language/attributes/nodiscard
        [[ nodiscard("PURE FUN") ]]
        int strategic_value(int x, int y) { return x^y; }

        /// On an enum.
        enum [[ nodiscard ]] Keeper {
            ForSomeTime = 0,///< Just for a little while.
            ForLife = 1,///< It's starting to get serious.
            ForEver = 2,///< You made a commitment.
            ForEverAndEver = 3///< And you aren't getting out of it.

        };
    }// namespace nodiscard

    /// Encapsulates `[[ maybe_unused ]]`.
    /// See: https://en.cppreference.com/w/cpp/language/attributes/maybe_unused
    namespace maybe_unused {
        /// A maybe unused struct.
        struct [[ maybe_unused ]] MayBe {
            int unused = 666;///< It May Be Unused.
        };

        /// A maybe unused typedef.
        [[ maybe_unused ]] typedef MayBe* MayBePtrTdef;

        /// A maybe unused typdef as using statement.
        using MayBePtrUsing = MayBe*;

        /// A static "variable".
        [[ maybe_unused ]] static constexpr int stat_var = 222;

        /// A union.
        union U {
            [[ maybe_unused]] int n;///< May be unused.
        };

        /// On a function.
        /// From: https://en.cppreference.com/w/cpp/language/attributes/maybe_unused
        [[ maybe_unused ]] bool f([[ maybe_unused ]] bool thing1,
                                  [[ maybe_unused ]] bool thing2) {
            [[ maybe_unused ]] bool b = thing1 && thing2 || !(thing1 && thing2);
            assert(b); // in release mode, assert is compiled out, and b is unused
                       // no warning because it is declared [[maybe_unused]]
            return true;
        } // parameters thing1 and thing2 are not used, no warning

        /// On an enum.
        enum [[ maybe_unused ]] MayBeNum {
            May [[ maybe_unused ]] = 0,///< May
            Be = 1,///< Be
            Num = 2///< Num
        };
    }// namespace maybe_unused
}// namespace meta
