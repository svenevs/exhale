/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once

namespace concepts {

    /// See https://en.cppreference.com/w/cpp/language/constraints
    template <class T, class U>
    concept Derived = std::is_base_of<U, T>::value;

    /// A pure virtual base class that defines a useless interface.
    struct Base {
        /// The value of something.
        virtual int value() const = 0;
    };

    /// Constrained function example made concrete from
    /// https://en.cppreference.com/w/cpp/language/constraints
    template <Derived<Base> T>
    int get_value(const T& t) { return t.value(); }
}  // namespace concepts
