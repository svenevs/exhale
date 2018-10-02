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
#include <pimpl/jupiter.hpp>

namespace pimpl {
    class JupiterImpl {
    public:
        double mass = 1.8982e27;
        double radius = 69'911.0;
        double eccentricity = 0.0489;
        double surface_gravity = 24.79;
    };

    Jupiter::Jupiter() :
        Planet()
        , pimpl{std::make_unique<JupiterImpl>()} { }

    Jupiter::~Jupiter() = default;
    Jupiter::Jupiter(Jupiter&&) = default;
    Jupiter& Jupiter::operator=(Jupiter&&) = default;

    double Jupiter::mass() const { return pimpl->mass; }
    double Jupiter::radius() const { return pimpl->radius; }
    double Jupiter::eccentricity() const { return pimpl->eccentricity; }
    double Jupiter::surface_gravity() const { return pimpl->surface_gravity; }

    namespace detail {
        class JupiterImpl {
        public:
            double mass = 1.8982e27;
            double radius = 69'911.0;
            double eccentricity = 0.0489;
            double surface_gravity = 24.79;
        };
    }

    Jupiter_v2::Jupiter_v2() :
        Planet()
        , pimpl{std::make_unique<detail::JupiterImpl>()} { }

    Jupiter_v2::~Jupiter_v2() = default;
    Jupiter_v2::Jupiter_v2(Jupiter_v2&&) = default;
    Jupiter_v2& Jupiter_v2::operator=(Jupiter_v2&&) = default;

    double Jupiter_v2::mass() const { return pimpl->mass; }
    double Jupiter_v2::radius() const { return pimpl->radius; }
    double Jupiter_v2::eccentricity() const { return pimpl->eccentricity; }
    double Jupiter_v2::surface_gravity() const { return pimpl->surface_gravity; }
}
