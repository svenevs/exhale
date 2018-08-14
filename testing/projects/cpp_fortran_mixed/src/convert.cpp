/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2018                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
#define CONVERT_IMPLEMENTATION
#include <convert/convert.hpp>
#include <convert/fortran_interface.h>

#if defined(__cplusplus)
    extern "C" {
#endif

#define EXPAND_FC(func) FC_MODULE(conversions, func, conversions, func)

#define degrees_to_radians_s EXPAND_FC(degrees_to_radians_s)
extern float degrees_to_radians_s(float *);

#define degrees_to_radians_d EXPAND_FC(degrees_to_radians_d)
extern double degrees_to_radians_d(double *);

#define radians_to_degrees_s EXPAND_FC(radians_to_degrees_s)
extern float radians_to_degrees_s(float *);

#define radians_to_degrees_d EXPAND_FC(radians_to_degrees_d)
extern double radians_to_degrees_d(double *);

#if defined(__cplusplus)
    }// extern "C"
#endif

namespace convert {
    template <>
    float to_radians<float>(float degrees) {
        return degrees_to_radians_s(&degrees);
    }

    template <>
    double to_radians<double>(double degrees) {
        return degrees_to_radians_d(&degrees);
    }

    template <>
    float to_degrees(float radians) {
        return radians_to_degrees_s(&radians);
    }

    template <>
    double to_degrees(double radians) {
        return radians_to_degrees_d(&radians);
    }
}
