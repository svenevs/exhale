/**
 * \file
 *
 * \brief This file should be at the top of the file hierarchy.
 */

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
