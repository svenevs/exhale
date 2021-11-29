/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2021                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief Various function overloads to ensure the right signature is parsed.
 */
#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <type_traits>

namespace overload {
    /// This function does nothing.
    inline void blargh() { }

    /// Returns the integer ``x``.
    inline int blargh(int x) { return x; }

    /// Returns the integer ``x + y``.
    inline int blargh(int x, int y) { return x + y; }

    /// Returns the integer ``x + y + z``.
    inline int blargh(int x, int y, int z) { return x + y + z; }

    /// Returns the float ``-1.0f * x``.
    inline float blargh(float x) { return -1.0f * x; }

    /// Returns the float ``-1.0f * (x + y)``.
    inline float blargh(float x, float y) { return -1.0f * (x + y); }

    /// Returns the float ``-1.0f * (x + y + z)``.
    inline float blargh(float x, float y, float z) { return -1.0f * (x + y + z); }

    /// Returns a copy of the string ``x``.
    inline std::string blargh(const std::string &x) { return x; }

    /// Returns a concatenation of ``x + y``.
    inline std::string blargh(const std::string &x, const std::string &y) { return x + y; }

    /// Returns a concatenation of ``x + y + z``.
    inline std::string blargh(const std::string &x, const std::string &y, const std::string &z) {
        return x + y + z;
    }

    /// Returns ``x + s.length()``.
    inline std::size_t blargh(std::size_t x, const std::string &s) {
        return x + s.length();
    }

    /// Returns ``x + static_cast<std::size_t>(y) + static_cast<std::size_t>(z) + s.length()``.
    inline std::size_t blargh(std::size_t x, const float &y, double z, const std::string &s) {
        return x + static_cast<std::size_t>(y) + static_cast<std::size_t>(z) + s.length();
    }

    /// Adds ``"blargh"`` to the end of ``v``.
    inline void blargh(std::vector<std::string> &v) { v.emplace_back("blargh"); }

    /// Adds ``std::vector<int>({0})`` to the end of ``v``.
    inline void blargh(std::vector<std::vector<int>> &v){
        v.emplace_back(std::move(std::vector<int>({0})));
    }

    /// Sums: ``z_i = x_i + y_i`` for ``i`` in range ``[0, N)``.  No error checks performed.
    inline void blargh(const float *x, const float *y, float *z, std::size_t N) {
        for (std::size_t i = 0; i < N; ++i) {
            z[i] = x[i] + y[i];
        }
    }

    /// Returns (a copy of) input parameter ``t``.
    template <class C>
    typename C::type blargh(typename C::type t) {
        return t;
    }

    /// Returns parameter ``t`` converted to a ``T`` (enabled when ``std::is_convertible`` is ``true``).
    template <class C, typename T>
    typename std::enable_if<
        std::is_convertible<typename C::type, T>::value, T
    >::type blargh(typename C::type t) {
        return t;
    }

    /// Returns a default constructed ``T`` (enabled when ``std::is_convertible`` is ``false``).
    template <class C, typename T>
    typename std::enable_if<
        !std::is_convertible<typename C::type, T>::value, T
    >::type blargh(typename C::type t) {
        return T();
    }
}// namespace overload

/// A free hanging function shows up in the file XML page, the others are in the namespace XML.
inline int blargh(int x) { return x; }
