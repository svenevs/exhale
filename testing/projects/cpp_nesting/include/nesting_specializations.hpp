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
        using Image_t = TImage;
        using data_t = Tdata_t;
        static constexpr int width = Image_t::width;
        static constexpr int height = Image_t::height;
        static constexpr int channels = Tchannels;

        /// Never do this in real life...
        struct Data {
            data_t vals[channels];///< The pixel data.
        };

        /// Checking nested specials too.
        template <int TNested>
        struct SomeThing {
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
        using Image_t = TImage;
        using data_t = Tdata_t;
        static constexpr int width = Image_t::width;
        static constexpr int height = Image_t::height;
        static constexpr int channels = 4;

        /// So really, don't change how things work like this in real life...
        struct Data {
            data_t r;///< Red.
            data_t g;///< Green.
            data_t b;///< Blue.
            data_t a;///< Alpha.
        };

        /// This one is not as special, right?
        struct SomeThing {
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
        using Image_t = Image<1920, 1080>;
        using data_t = float;
        static constexpr int width = 1920;
        static constexpr int height = 1080;
        static constexpr int channels = 128;

        /// Definitely don't do this.
        struct Data {
            std::vector<float> samples;///< so arbitrary
        };

        /// Super special.
        struct SomeThing {
            std::string id() const { return "Spectral"; }
        };

        /// This is a lie.
        constexpr int size() const { return 88; }
    };

#if 1
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
            int a() const { return 3; };
        };

        /// Inner struct 2.
        struct AnotherNestedStruct {
            double b() const { return 4; }
        };


        char base_member{'!'};/// < not used

        /// Unspecialized inner struct.
        template <size_t M, typename no_use_this = void>
        struct InnerTemplatedStruct {
            char s() const { return '{'; }
        };

        /// Specialized inner struct.
        template <typename dont_use_this>
        struct InnerTemplatedStruct<4, dont_use_this>{
            char s() const { return '}'; }
        };
    };
#endif // 0 the test discover is broken
}
