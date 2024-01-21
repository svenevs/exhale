/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2024                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief Various operator overloads to ensure the right signature is parsed.
 */
#pragma once
#include <ostream>

namespace overload {
    /* NOTE: we need to test that signatures with these symbols work in exhale, so they
     * are not being defined in the class (where relevant).  This way they are showing
     * up as free-hanging functions.  Exhale does not deal with class definitions, but
     * the free-hanging functions are documented.  Primary issue is to make sure
     * treatment of operators with `<` and `>` are handled correctly:
     * https://github.com/svenevs/exhale/issues/168
     */

    /// A custom type to enable operator overloads with.
    class CustomType {
    public:
        /// Constructor
        CustomType(int v) : value_{v} {}
        /// Copy
        CustomType(const CustomType &other) : value_{other.value_} {}
        /// Move
        CustomType(const CustomType &&other) : value_{other.value_} {}

        /// Returns the value.
        int value() const { return value_; }

    protected:
        int value_;///< The value of the custom type.
    };

    /// Doing shenanigans to force a template so I can specialize it.
    template <typename Out, typename T>
    Out& operator<<(Out &out, const T &t) {
        return out << t;
    }

    /// Specialized operator << for CustomType
    template <>
    std::ostream& operator<< <std::ostream, CustomType>(std::ostream &out, const CustomType& ct);

    /// Operator ==
    bool operator==(const CustomType &lhs, const CustomType &rhs);

    /// Operator !=
    bool operator!=(const CustomType &lhs, const CustomType &rhs);

    /// Operator <
    bool operator<(const CustomType &lhs, const CustomType &rhs);

    /// Operator >
    bool operator>(const CustomType &lhs, const CustomType &rhs);

    /// Operator <=
    bool operator<=(const CustomType &lhs, const CustomType &rhs);

    /// Operator >=
    bool operator>=(const CustomType &lhs, const CustomType &rhs);

    // TODO: operator<=> when you can get proper C++20 support in CI...
}  // namespace overload
