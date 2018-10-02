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
/** \file */
#pragma once

#include <pimpl/planet.hpp>
#include <memory>

namespace pimpl {
    /**
     * \class pimpl::EarthImpl earth.hpp include/pimpl/earth.hpp
     * \brief The Earth PIMPL.
     */
    class EarthImpl;

    /// A class that represents the planet Earth.
    class Earth : public Planet {
    public:
        Earth();                  ///< Constructs an Earth.
        ~Earth();                 ///< Destructs an Earth.
        Earth(Earth&&);           ///< Moves an Earth.
        Earth& operator=(Earth&&);///< Assigns an Earth.

        /// The mass of the Earth in kilograms.
        double mass() const;
        /// The mean radius of the Earth in kilometers.
        double radius() const;
        /// The orbital eccentricity of the Earth.
        double eccentricity() const;
        /// The gravity on the Earth surface in meters per second squared.
        double surface_gravity() const;
        /// A string description of the planet.
        std::string describe() const { return "Earth"; }

    protected:
        /// The Earth implementation details.
        std::unique_ptr<EarthImpl> pimpl;
    };

    /// The ``detail`` namespace contains items that should not be relied on in the public API.
    namespace detail {
        /**
         * \class pimpl::detail::EarthImpl earth.hpp include/pimpl/earth.hpp
         * \brief The Earth_v2 PIMPL.
         */
        class EarthImpl;
    }

    /// A class that represents the planet Earth_v2.
    class Earth_v2 : public Planet {
    public:
        Earth_v2();                     ///< Constructs an Earth_v2.
        ~Earth_v2();                    ///< Destructs an Earth_v2.
        Earth_v2(Earth_v2&&);           ///< Moves an Earth_v2.
        Earth_v2& operator=(Earth_v2&&);///< Assigns an Earth_v2.

        /// The mass of the Earth_v2 in kilograms.
        double mass() const;
        /// The mean radius of the Earth_v2 in kilometers.
        double radius() const;
        /// The orbital eccentricity of the Earth_v2.
        double eccentricity() const;
        /// The gravity on the Earth_v2 surface in meters per second squared.
        double surface_gravity() const;
        /// A string description of the planet.
        std::string describe() const { return "Earth_v2"; }

    protected:
        /// The Earth_v2 implementation details.
        std::unique_ptr<detail::EarthImpl> pimpl;
    };
}
