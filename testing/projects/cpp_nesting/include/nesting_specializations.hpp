/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This file tests struct nesting with template specializations.
 */
#pragma once

#include <string>
#include <type_traits>
#include <vector>

/** Specialized struct nesting for the joy and fun of all:
 * https://github.com/svenevs/exhale/issues/156 */
namespace special {
    /// Normal struct nesting.
    struct Normal {
        /// The id `"Normal"`.
        std::string id() const { return "Normal"; }

        /// Nested struct.
        struct Nested {
            /// The id `"Nested"`.
            std::string id() const { return "Nested"; }

            /// Deeper nesting like wow.
            struct Like {
                /// The id `"Like"`.
                std::string id() const { return "Like"; }

                /// Even deeper nesting `\o/`.
                struct Usual {
                    /// The id `"Usual"`.
                    std::string id() const { return "Usual"; }
                };
            };
        };
    };

    /** A dummy struct with template parameters to use for testing nesting
     * specialization name parsing with "template template parameters". */
    template <int Twidth, int Theight>
    struct Image {
        static constexpr int width = Twidth;///< Width of the image.
        static constexpr int height = Theight;///< Height of the image.
    };

    /// Unspecialized template class with nesting.
    template <class TImage, typename Tdata_t, int Tchannels>
    class ImageBuffer {
    public:
        using Image_t = TImage;///< Convenience typedef for template `TImage`.
        using data_t = Tdata_t;///< Convenience typedef for template `Tdata_t`.
        static constexpr int width = Image_t::width;///< The width of the image.
        static constexpr int height = Image_t::height;///< The height of the image.
        static constexpr int channels = Tchannels;///< The number of channels per pixel.

        /// Never do this in real life...
        struct Data {
            data_t vals[channels];///< The pixel data.
        };

        /// Checking nested specials too.
        template <int TNested>
        struct SomeThing {
            /// The identifier
            std::string id() const { return std::to_string(TNested); }
        };

        /// How much memory is used.
        constexpr int size() const {
            return width * height * sizeof(Data);
        }
    };

    /// Now lets specialize it partially and arbitrarily change behavior!
    template <class TImage, typename Tdata_t>
    class ImageBuffer<TImage, Tdata_t, 4> {
    public:
        using Image_t = TImage;///< Convenience typedef for template `TImage`.
        using data_t = Tdata_t;///< Convenience typedef for template `Tdata_t`.
        static constexpr int width = Image_t::width;///< The width of the image.
        static constexpr int height = Image_t::height;///< The height of the image.
        static constexpr int channels = 4;///< The number of channels per pixel.

        /// So really, don't change how things work like this in real life...
        struct Data {
            data_t r;///< Red.
            data_t g;///< Green.
            data_t b;///< Blue.
            data_t a;///< Alpha.
        };

        /// This one is not as special, right?
        struct SomeThing {
            /// The special identifier.
            std::string id() const { return "I AM SPECIAL!"; }
        };

        /// How much memory is used.
        constexpr int size() const {
            return width * height * 4 * sizeof(data_t);
        }
    };

    /// A fully specialized buffah.
    template <>
    class ImageBuffer<Image<1920, 1080>, float, 128> {
    public:
        using Image_t = Image<1920, 1080>;///< Convenience typedef for the Image class.
        using data_t = float;///< Convenience typedef for underlying data type `float`.
        static constexpr int width = 1920;///< The width of the image.
        static constexpr int height = 1080;///< The height of the image.
        static constexpr int channels = 128;///< The number of channels per pixel.

        /// Definitely don't do this.
        struct Data {
            std::vector<float> samples;///< so arbitrary
        };

        /// Super special.
        struct SomeThing {
            /// The spectral identifier.
            std::string id() const { return "Spectral"; }
        };

        /// This is a lie.
        constexpr int size() const { return 88; }
    };

    /** The original example expanded a bit. Thanks florian for making it
     * copy-pasteable :) */
    template <size_t N>
    struct Base {
        /// How big the base is.
        constexpr size_t size() const { return N; }
        struct A {};///< eeep
    };

    /// Specialized base.
    template <>
    struct Base<2> {
        /// It is bigger for no real reason.
        constexpr size_t size() const { return 42; }

        /// Inner struct 1.
        struct InnerStruct {
            /// returns 3
            int a() const { return 3; };
        };

        /// Inner struct 2.
        struct AnotherNestedStruct {
            /// returns 4
            double b() const { return 4; }
        };


        char base_member{'!'};///< not used

        /// Unspecialized inner struct.
        template <size_t M, typename no_use_this = void>
        struct InnerTemplatedStruct {
            /// returns `{`
            char s() const { return '{'; }
        };

        /// Specialized inner struct.
        template <typename dont_use_this>
        struct InnerTemplatedStruct<4, dont_use_this>{
            /// returns `}`
            char s() const { return '}'; }
        };
    };

    /// unique snowflakes are unique
    namespace unique {
        /// very unique
        namespace snowflake {
            /// A wrapper struct in a namespace so I can have a final template parameter
            /// with some `::` in it.
            template <auto Epoch>
            struct Ontology {
                /// The current version of the simulation.
                static constexpr auto epoch() { return Epoch; }
                /// The dual of the epoch of the simulation.  Same as epoch.
                auto dual() const { return epoch(); }
            };

            /// A very special epoch with a dual meaning.
            template <>
            struct Ontology<11> {
                /// The current version of the simulation.
                static constexpr auto epoch() { return 11; }
                /// The dual of the epoch of the simulation, which is special. ?
                auto dual() const { return 22; }
            };
        }

        /// A nonsense class to specialize.
        template <int X, class T>
        struct Nonsense {
            /// Initializes the thing.
            Nonsense(const T &t) : thing{t} { }
            /// A T reference thing.
            const T &thing;

            /// Returns template parameter X.
            int x() const { return X; }
            /// Returns the tea.
            const T &t() const { return thing; }
        };

        /// Partially specialized nonsense.
        template <int X>
        struct Nonsense<X, snowflake::Ontology<X>> {
            /// Makes some nonsense.
            Nonsense(const snowflake::Ontology<X> &so) : thing{so} { }
            /// A snowflake thing.
            const snowflake::Ontology<X> &thing;

            /// Returns snowflake epoch plus dual plus X.
            int x() const {
                return snowflake::Ontology<X>::epoch() + thing.dual() + X;
            }
            /// Gives you a snowflake.
            const snowflake::Ontology<X> &t() const { return thing; }
        };

        /// Alias to partial nonsense.
        template <int X>
        using PartialNonsense = Nonsense<X, snowflake::Ontology<X>>;

        /// A fully specialized nonsense.
        template <>
        struct Nonsense<11, snowflake::Ontology<11>> {
            /// Fully special nonsense.
            Nonsense(const snowflake::Ontology<11> &so) : thing{so} { }
            /// A special snowflake thing.
            const snowflake::Ontology<11> &thing;

            /// Returns snowflake epoch plus dual.
            int x() const {
                return snowflake::Ontology<11>::epoch() + thing.dual();
            }
            /// Gives you a special snowflake.
            const snowflake::Ontology<11> &t() const { return thing; }
        };

        /// Alias to full nonsense.
        using FullNonsense = Nonsense<11, snowflake::Ontology<11>>;
    }

    /** More complicated templates with special characters, doing it on classes
     * intentionally (no functions allowed :p).  These are mostly here for help
     * testing limits on tokenize_template edge cases.  The tokenize_template
     * function may not even be called with these, but the python test cases
     * have these in there and this code is checked for compilation. */
    namespace complex {
        /// variadic folding stuff
        template <typename... Ts>
        struct Fold {
            /// make sure your types actually operator+...
            static auto sum(Ts... ts) { return (ts + ...); }
        };

        /// https://en.cppreference.com/w/cpp/types/void_t
        template <class...>
        using void_t = void;

        /// primary template handles types that have no nested `type` member:
        /// https://en.cppreference.com/w/cpp/types/void_t
        /// the equals sign yo
        template <class, class=void>
        struct has_type_member : std::false_type {
            /// returns `false`.
            bool meh() const { return false; }
        };

        /// specialization recognizes types that do have a nested `type` member:
        /// https://en.cppreference.com/w/cpp/types/void_t
        template <class T>
        struct has_type_member<T, void_t<typename T::type>> : std::true_type {
            /// returns `true`
            bool meh() const { return true; }
        };

        /// pure nonsense
        template <const int* I>
        struct IntPtr {
            /// gives back the I
            int i() { return *I; }
        };

        /// more nonsense
        template <const int& I>
        struct IntRef {
            /// gives back the I
            int i() { return I; }
        };
    }
}
