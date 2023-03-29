/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2023                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This file should be two levels down in the hierarchy.
 */
#pragma once

namespace nested {
    namespace dual_nested {
        /// The first class inside the ``nested::dual_nested`` namespace.
        struct one {
            /// Nesting even further: ``nested::dual_nested::one::params``.
            struct params {
                /// A union that occupies four bytes: https://en.cppreference.com/w/cpp/language/union
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
}
