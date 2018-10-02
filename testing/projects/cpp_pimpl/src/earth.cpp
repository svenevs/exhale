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
#include <pimpl/earth.hpp>

namespace pimpl {
    class EarthImpl {
    public:
        double mass = 5.97237e24;
        double radius = 6'371.0;
        double eccentricity = 0.0167086;
        double surface_gravity = 9.807;
    };

    Earth::Earth() :
        Planet()
        , pimpl{std::make_unique<EarthImpl>()} { }

    Earth::~Earth() = default;
    Earth::Earth(Earth&&) = default;
    Earth& Earth::operator=(Earth&&) = default;

    double Earth::mass() const { return pimpl->mass; }
    double Earth::radius() const { return pimpl->radius; }
    double Earth::eccentricity() const { return pimpl->eccentricity; }
    double Earth::surface_gravity() const { return pimpl->surface_gravity; }

    namespace detail {
        class EarthImpl {
        public:
            double mass = 5.97237e24;
            double radius = 6'371.0;
            double eccentricity = 0.0167086;
            double surface_gravity = 9.807;
        };
    }

    Earth_v2::Earth_v2() :
        Planet()
        , pimpl{std::make_unique<detail::EarthImpl>()} { }

    Earth_v2::~Earth_v2() = default;
    Earth_v2::Earth_v2(Earth_v2&&) = default;
    Earth_v2& Earth_v2::operator=(Earth_v2&&) = default;

    double Earth_v2::mass() const { return pimpl->mass; }
    double Earth_v2::radius() const { return pimpl->radius; }
    double Earth_v2::eccentricity() const { return pimpl->eccentricity; }
    double Earth_v2::surface_gravity() const { return pimpl->surface_gravity; }
}
