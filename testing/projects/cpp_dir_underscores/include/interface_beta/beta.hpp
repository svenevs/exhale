/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2023                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once

#include <string>

/// The ``interface_beta`` namespace.
namespace interface_beta {
    /// The Beta struct.
    struct Beta {
        /// Returns ``"beta"``.
        std::string id() const { return "beta"; }
    };
}
