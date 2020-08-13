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
 * \brief Overloaded function tests with operators, see issue #90.
 */
#pragma once

#include <iostream>

namespace tt {

    struct AudioDevice_state { };///< State of audio device.
    struct FontWeight { };///< Weight of font.
    enum class KeyboardModifiers : uint8_t { };///< Bitmasking modifiers to control keyboard.
    struct KeyboardVirtualKey { };///< Keyboard magic.
    struct TextDecoration { };///< For when bold isn't bold enough.
    struct ThemeMode { };///< Prefer dark themes.
    using cell_address = uint32_t;///< Cell indexing stuffs.
    using command = uint16_t;///< Command sequence `0x1111 ` is reserved.
    struct URL { };///< httpseverywhere
    using datum_type_t = uint8_t;///< Oh no our datum is so small :(
    using glob_token_t = int32_t;///< It is ok to mix with datum ;)
    using glob_token_type_t = int16_t;///< This doesn't get used often.
    using source_code_ptr = void *;///< Hehe.
    using tokenizer_name_t = double;///< Waste of precision.

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, AudioDevice_state const &rhs) {
        return lhs << "AudioDevice_state const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, FontWeight const &rhs) {
        return lhs << "FontWeight const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, KeyboardModifiers const &rhs) {
        return lhs << "KeyboardModifiers const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, KeyboardVirtualKey const &rhs) {
        return lhs << "KeyboardVirtualKey const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, TextDecoration const &rhs) {
        return lhs << "TextDecoration const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, ThemeMode rhs) {
        return lhs << "ThemeMode rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, cell_address const &rhs) {
        return lhs << "cell_address const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, command const &rhs) {
        return lhs << "command const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, const URL &rhs) {
        return lhs << "const URL &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, datum_type_t rhs) {
        return lhs << "datum_type_t rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, glob_token_t const &rhs) {
        return lhs << "glob_token_t const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, glob_token_type_t const &rhs) {
        return lhs << "glob_token_type_t const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, source_code_ptr const &rhs) {
        return lhs << "source_code_ptr const &rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

    /// \brief Adds `typeid(rhs).name()` to `lhs` with arbitrary formatting.
    inline std::ostream &operator<<(std::ostream &lhs, tokenizer_name_t rhs) {
        return lhs << "tokenizer_name_t rhs) {{{ " << typeid(rhs).name() << "}}}";
    }

/* TODO (untested TBD not now):
 * Template overloads may be more of a problem.  See also:
 * https://github.com/svenevs/exhale/blob/58c6c771fe021d7487644a30c2575b3fcf1ae94b/exhale/graph.py#L2372
 *
 * :(
 *
    template<typename T, int M> std::ostream &operator<<(std::ostream &lhs, fixed<T, M> const &rhs)
    template<typename T, int N> std::ostream &operator<<(std::ostream &os, results<T, N> const &r)
    template<typename Tag, typename ...InfoTags> std::ostream &operator<<(std::ostream &lhs, trace_data<Tag, InfoTags...> const &rhs)
 */

}// namespace tt
