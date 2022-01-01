/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2022                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#pragma once
#include <memory>
#include <string>

/// A namespace to contain everything in this test project ;)
namespace pimpl {
    /// The interface base class for all planets.
    class Planet {
    public:
        /// The mass of the planet in kilograms.
        virtual double mass() const = 0;
        /// The mean radius of the planet in kilometers.
        virtual double radius() const = 0;
        /// The orbital eccentricity of the planet.
        virtual double eccentricity() const = 0;
        /// The gravity on the planet surface in meters per second squared.
        virtual double surface_gravity() const = 0;
        /// A string description of the planet.
        virtual std::string describe() const = 0;
    };
}
