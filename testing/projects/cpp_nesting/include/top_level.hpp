/***************************************************************************************
 * This file is dedicated to the public domain.  If your jurisdiction requires a       *
 * specific license:                                                                   *
 *                                                                                     *
 * Copyright (c) Stephen McDowell, 2017-2019                                           *
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

#if defined(DOXYGEN_TEST_PAGES)
#if defined(DRACULA_IS_MAINPAGE)
/**
 * \mainpage Dracula
 *
 * Reuse of the project for testing page commands is a great idea.  An even
 * better idea is to not need to think of what to write, but lean on the greats.
 * Thanks to Project Gutenberg, the remaining items on the page are taken from
 * Bram Stoker's Dracula.
 *
 * \section dracula_foreword Foreword
 * The contents of these pages are gathered from Project Gutenberg.
 *
 * 1. Project Gutenberg Dracula: https://www.gutenberg.org/ebooks/345
 * 2. ASCII: https://www.gutenberg.org/files/345/old/345-8.txt
 *
 * \section dracula_lic Licensing
 * The Project Gutenberg EBook of Dracula, by Bram Stoker
 *
 * This eBook is for the use of anyone anywhere at no cost and with
 * almost no restrictions whatsoever.  You may copy it, give it away or
 * re-use it under the terms of the Project Gutenberg License included
 * with this eBook or online at www.gutenberg.org/license
 *
 * \subsection dracula_lic_title Title
 * Dracula
 *
 * \subsection dracula_lic_author Author
 * Bram Stoker
 *
 * \subsection dracula_lic_release_date Release Date
 * August 16, 2013 [EBook #345]
 *
 * \subsection dracula_lic_language Language
 * English
 *
 * \subsection dracula_lic_producers Producers
 * Produced by Chuck Greif and the Online Distributed
 * Proofreading Team at http://www.pgdp.net (This file was produced from images
 * generously made available by The Internet Archive).
 *
 * \section dracula_index Chapters
 *
 * \li \ref chapter_I
 * \li \ref chapter_II
 * \li \ref chapter_III
 * \li \ref chapter_IV
 * \li \ref chapter_V
 * \li \ref chapter_VI
 * \li \ref chapter_VII
 * \li \ref chapter_VIII
 * \li \ref chapter_IX
 * \li \ref chapter_X
 * \li \ref chapter_XI
 * \li \ref chapter_XII
 * \li \ref chapter_XIII
 * \li \ref chapter_XIV
 * \li \ref chapter_XV
 * \li \ref chapter_XVI
 * \li \ref chapter_XVII
 * \li \ref chapter_XVIII
 * \li \ref chapter_XIX
 * \li \ref chapter_XX
 * \li \ref chapter_XXI
 * \li \ref chapter_XXII
 * \li \ref chapter_XXIII
 * \li \ref chapter_XXIV
 * \li \ref chapter_XXV
 * \li \ref chapter_XXVI
 * \li \ref chapter_XXVII
 */
#else
/**
 * \page dracula Dracula
 *
 * Reuse of the project for testing page commands is a great idea.  An even
 * better idea is to not need to think of what to write, but lean on the greats.
 * Thanks to Project Gutenberg, the remaining items on the page are taken from
 * Bram Stoker's Dracula.
 *
 * \section dracula_foreword Foreword
 * The contents of these pages are gathered from Project Gutenberg.
 *
 * 1. Project Gutenberg Dracula: https://www.gutenberg.org/ebooks/345
 * 2. ASCII: https://www.gutenberg.org/files/345/old/345-8.txt
 *
 * \section dracula_lic Licensing
 * The Project Gutenberg EBook of Dracula, by Bram Stoker
 *
 * This eBook is for the use of anyone anywhere at no cost and with
 * almost no restrictions whatsoever.  You may copy it, give it away or
 * re-use it under the terms of the Project Gutenberg License included
 * with this eBook or online at www.gutenberg.org/license
 *
 * \subsection dracula_lic_title Title
 * Dracula
 *
 * \subsection dracula_lic_author Author
 * Bram Stoker
 *
 * \subsection dracula_lic_release_date Release Date
 * August 16, 2013 [EBook #345]
 *
 * \subsection dracula_lic_language Language
 * English
 *
 * \subsection dracula_lic_producers Producers
 * Produced by Chuck Greif and the Online Distributed
 * Proofreading Team at http://www.pgdp.net (This file was produced from images
 * generously made available by The Internet Archive).
 *
 * \section dracula_index Chapters
 *
 * \li \ref chapter_I
 * \li \ref chapter_II
 * \li \ref chapter_III
 * \li \ref chapter_IV
 * \li \ref chapter_V
 * \li \ref chapter_VI
 * \li \ref chapter_VII
 * \li \ref chapter_VIII
 * \li \ref chapter_IX
 * \li \ref chapter_X
 * \li \ref chapter_XI
 * \li \ref chapter_XII
 * \li \ref chapter_XIII
 * \li \ref chapter_XIV
 * \li \ref chapter_XV
 * \li \ref chapter_XVI
 * \li \ref chapter_XVII
 * \li \ref chapter_XVIII
 * \li \ref chapter_XIX
 * \li \ref chapter_XX
 * \li \ref chapter_XXI
 * \li \ref chapter_XXII
 * \li \ref chapter_XXIII
 * \li \ref chapter_XXIV
 * \li \ref chapter_XXV
 * \li \ref chapter_XXVI
 * \li \ref chapter_XXVII
 */
#endif // DRACULA_IS_MAINPAGE
#endif // DOXYGEN_TEST_PAGES
