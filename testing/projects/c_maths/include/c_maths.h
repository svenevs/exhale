/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2021                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/*!
 * @file
 * Math functions declarations
 */

#ifndef C_MATHS_H
#define C_MATHS_H

#if defined(__cplusplus)
    extern "C" {
#endif

/*!
 * @brief Add two integers
 * @param a An integer
 * @param b Another integer
 */
int cm_add(int a, int b);

/*!
 * @brief Subtract one integer from another
 * @param a An integer
 * @param b An integer to subtract from \p a
 */
int cm_sub(int a, int b);

#if defined(__cplusplus)
    } // extern "C"
#endif

#endif // C_MATHS_H
