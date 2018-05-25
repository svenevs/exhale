/**
 * \file
 *
 * \brief This file should be two levels down in the hierarchy.
 */

namespace nested {
    namespace dual_nested {
        /// The first class inside the ``nested::dual_nested`` namespace.
        struct one {
            /// Nesting even further: ``nested::dual_nested::one::params``.
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
}
