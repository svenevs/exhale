/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2024                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once

#include <string>

namespace interface_alpha {
    /// The ``four_five_six`` namespace.
    namespace four_five_six {
        /// The FourFiveSix struct.
        struct FourFiveSix {
            /// Returns ``"four_five_six"``.
            std::string id() const { return "four_five_six"; }
        };
    }
}
