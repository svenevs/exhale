/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2019                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This file should be one level down in the hierarchy.
 */
#pragma once

namespace nested {
    /// The first class inside the ``nested`` namespace.
    struct one {
        /// Nesting even further: ``nested::one::params``.
        struct params {
            /// A union that occupies four bytes: http://en.cppreference.com/w/cpp/language/union
            union four_bytes {
                std::int32_t n;    ///< occupies 4 bytes
                std::uint16_t s[2];///< occupies 4 bytes
                std::uint8_t c;    ///< occupies 1 byte
            };

            /// Returns ``true`` ;)
            bool compiles() { return true; }
        };

        /// Returns ``true`` ;)
        bool compiles() { return true; }
    };
}
