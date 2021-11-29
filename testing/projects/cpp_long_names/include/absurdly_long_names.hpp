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
 * \brief Tests constructs with names longer than 255 characters.
 *
 * Tests the following kinds:
 *
 * - ``class``
 * - ``struct``
 * - ``function``
 * - ``enum``
 * - ``namespace``
 * - ``define``
 * - ``typedef``
 * - ``variable``
 * - ``union``
 *
 * Ignored kinds not explicitly tested (at least in this file):
 *
 * - ``enumvalue`` (unused in exhale)
 * - ``file`` (pointless to test directly)
 * - ``dir`` (pointless to test directly)
 * - ``group`` (unused in exhale)
 */
#pragma once

#include <string>

/// A macro for making the absurdly long names.
#define MAKE_IT_BIG(prefix) prefix##_that_is_longer_than_two_hundred_and_fifty_five_characters_long_which_is_an_absolutely_and_completely_ridiculous_thing_to_do_and_if_you_did_this_in_the_real_world_you_put_yourself_comfortably_in_a_position_to_be_downsized_and_outta_here_as_soul_position_would_explain_to_you

/// A class with an absurdly long name.
class MAKE_IT_BIG(class) {
public:
    static constexpr int value = 1;///< An absurd value ``1`` that means nothing.
};

/// A struct with an absurdly long name.
struct MAKE_IT_BIG(struct) {
    static constexpr int value = 2;///< An absurd value ``2`` that means nothing.
};

/// A function with an absurdly long name.  Returns a string describing the divergence number of the current world line.
inline std::string MAKE_IT_BIG(function)() {
    return "The divergence number: 0.999999999";// poor Mayuri...
}

/// An enum with an absurdly long name.
enum MAKE_IT_BIG(enum) {
    first = 1,///< The first value of the absurd enum.
    second,   ///< The second value of the absurd enum.
    third     ///< The third value of the absurd enum.
};

/// An absurdly long namespace.
namespace MAKE_IT_BIG(namespace) {
    static constexpr int value = 0;///< An absurd value ``0`` that means nothing.
}

/// A preprocessor ``define`` that has an absurdly long name.
#define DEFINE_THAT_IS_LONGER_THAN_TWO_HUNDRED_AND_FIFTY_FIVE_CHARACTERS_LONG_WHICH_IS_AN_ABSOLUTELY_AND_COMPLETELY_RIDICULOUS_THING_TO_DO_AND_IF_YOU_DID_THIS_IN_THE_REAL_WORLD_YOU_PUT_YOURSELF_COMFORTABLY_IN_A_POSITION_TO_BE_DOWNSIZED_AND_OUTTA_HERE_AS_SOUL_POSITION_WOULD_EXPLAIN_TO_YOU "Jajajaja"

/// A variable with an absurdly long value.
static constexpr int MAKE_IT_BIG(variable) = 929;

/// A typedef to an absurdly long name.
using MAKE_IT_BIG(typedef) = float;

// copy-pasted-ish: https://en.cppreference.com/w/cpp/language/union
/// A union with an absurdly long name which occupies 4 bytes total.
union MAKE_IT_BIG(union) {
    std::int32_t n;    ///< occupies 4 bytes
    std::uint16_t s[2];///< occupies 4 bytes
    std::uint8_t c;    ///< occupies 1 byte
};
