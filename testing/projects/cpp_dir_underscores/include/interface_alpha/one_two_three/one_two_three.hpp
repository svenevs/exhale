/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once

#include <string>

namespace interface_alpha {
    /// The ``one_two_three`` namespace.
    namespace one_two_three {
        /// The OneTwoThree struct.
        struct OneTwoThree {
            /// Returns ``"one_two_three"``.
            std::string id() const { return "one_two_three"; }
        };
    }
}
