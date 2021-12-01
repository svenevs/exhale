/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2021                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once

#include <string>

/// The ``interface_alpha`` namespace.
namespace interface_alpha {
    /// The Alpha struct.
    struct Alpha {
        /// Returns ``"alpha"``.
        std::string id() const { return "alpha"; }
    };
}
