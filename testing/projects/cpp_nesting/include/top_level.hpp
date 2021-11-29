/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2021                                           *
 * License:      CC0 1.0 Universal                                                     *
 * License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode           *
 **************************************************************************************/
/**
 * \file
 *
 * \brief This file should be at the top of the file hierarchy.
 */
#pragma once

#include <string>

/// A top level structure that should be at the root of the class hierarchy.
struct top_level {
    /**
     * \brief Creates a top_level structure.
     *
     * \param name
     *     The name of this top-level structure.  See \ref mName.
     */
    top_level(const std::string &name) : mName(name) { }

    /// The name of this top-level structure.
    std::string mName;
};
