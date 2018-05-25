/**
 * \file
 *
 * \brief This file should be one level down in the hierarchy.
 */

namespace nested {
    /// The second class inside the ``nested`` namespace.
    struct two {
        /// Nesting even further: ``nested::two::params``.
        struct params {
            /// A union that occupies four bytes: http://en.cppreference.com/w/cpp/language/union
            union four_bytes {
                std::int32_t n;    ///< occupies 4 bytes
                std::uint16_t s[2];///< occupies 4 bytes
                std::uint8_t c;    ///< occupies 1 byte
            };
        };
    };
}
