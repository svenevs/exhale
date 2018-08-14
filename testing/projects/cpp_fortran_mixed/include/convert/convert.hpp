/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2018                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This is a file that does things.
 */
#pragma once

#include <stdexcept>

/**
 * \brief The C++ namespace containing everything else.
 *
 * The convert namespace, named differently than the fortran module because
 * otherwise  Doxygen will merge the documentation (lol).
 */
namespace convert {
    /**
     * \brief Convert the input degrees to radians.
     *
     * \tparam T
     *     Should only be ``float`` or ``double``.
     *
     * \param degrees
     *     The input number representing degrees to be converted.
     *
     * \return
     *     The input ``degrees`` converted to radians.
     *
     * \throws std::runtime_error
     *     When template parameter ``T`` is neither ``float`` nor ``double``.  This code
     *     is deliberately obtuse, because the goal of this code is to enforce that the
     *     (extremely simple) fortran code is actually called.  I added in some explicit
     *     function template instantiations just for shiggles.
     */
    template <typename T>
    T to_radians(T degrees) {
        throw std::runtime_error(
            "convert::to_radians<T>: T may only be `float` or `double`."
        );
    }

    /**
     * \brief Convert the input radians to degrees.
     *
     * \tparam T
     *     Should only be ``float`` or ``double``.
     *
     * \param radians
     *     The input number representing radians to be converted.
     *
     * \return
     *     The input ``radians`` converted to degrees.
     *
     * \throws std::runtime_error
     *     When template parameter ``T`` is neither ``float`` nor ``doubl``.  This code
     *     is deliberately obtuse, because the goal of this code is to enforce that the
     *     (extremely simple) fortran code is actually called.  I added in some explicit
     *     function template instantiations just for shiggles.
     */
    template <typename T>
    T to_degrees(T radians) {
        throw std::runtime_error(
            "convert::to_degrees<T>: T may only be `float` or `double`."
        );
    }

    // yes, i am doing this in the header file, what are you gonna do about it?
    #if !defined(CONVERT_IMPLEMENTATION) && !defined(DOXYGEN_SHOULD_SKIP_THIS)
        extern template float  to_radians<float>(float);
        extern template double to_radians<double>(double);
        extern template float  to_degrees<float>(float);
        extern template double to_degrees<double>(double);
    #endif // CONVERT_IMPLEMENTATION
}// namespace convert
