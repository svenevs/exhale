/***************************************************************************************
 * This file is dedicated to the public domain.  It is a minor modification of the     *
 * simple yet effective PIMPL article here:                                            *
 *                                                                                     *
 *     https://cpppatterns.com/patterns/pimpl.html                                     *
 *                                                                                     *
 * If your jurisdiction requires a specific license:                                   *
 *                                                                                     *
 * Copyright (c) Joseph Mansfield, Mehdi Amini, 2017                                   *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once

#include <pimpl/planet.hpp>
#include <memory>

namespace pimpl {
    /**
     * \class pimpl::JupiterImpl jupiter.hpp include/pimpl/jupiter.hpp
     * \brief The Jupiter PIMPL.
     */
    class JupiterImpl;

    /// A class that represents the planet Jupiter.
    class Jupiter : public Planet {
    public:
        Jupiter();                    ///< Constructs an Jupiter.
        ~Jupiter();                   ///< Destructs an Jupiter.
        Jupiter(Jupiter&&);           ///< Moves an Jupiter.
        Jupiter& operator=(Jupiter&&);///< Assigns an Jupiter.

        /// The mass of the Jupiter in kilograms.
        double mass() const;
        /// The mean radius of the Jupiter in kilometers.
        double radius() const;
        /// The orbital eccentricity of the Jupiter.
        double eccentricity() const;
        /// The gravity on the Jupiter surface in meters per second squared.
        double surface_gravity() const;
        /// A string description of the planet.
        std::string describe() const { return "Jupiter"; }

    protected:
        /// The Jupiter implementation details.
        std::unique_ptr<JupiterImpl> pimpl;
    };

    namespace detail {
        /**
         * \class pimpl::detail::JupiterImpl jupiter.hpp include/pimpl/jupiter.hpp
         * \brief The Jupiter_v2 PIMPL.
         */
        class JupiterImpl;
    }

    /// A class that represnts the planet Jupiter (version 2).
    class Jupiter_v2 : public Planet {
    public:
        Jupiter_v2();                       ///< Constructs an Jupiter_v2.
        ~Jupiter_v2();                      ///< Destructs an Jupiter_v2.
        Jupiter_v2(Jupiter_v2&&);           ///< Moves an Jupiter_v2.
        Jupiter_v2& operator=(Jupiter_v2&&);///< Assigns an Jupiter_v2.

        /// The mass of the Jupiter_v2 in kilograms.
        double mass() const;
        /// The mean radius of the Jupiter_v2 in kilometers.
        double radius() const;
        /// The orbital eccentricity of the Jupiter_v2.
        double eccentricity() const;
        /// The gravity on the Jupiter_v2 surface in meters per second squared.
        double surface_gravity() const;
        /// A string description of the planet.
        std::string describe() const { return "Jupiter_v2"; }

    protected:
        /// The Jupiter_v2 implementation details.
        std::unique_ptr<detail::JupiterImpl> pimpl;
    };
}
