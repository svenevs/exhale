.. _mastering_doxygen:

Mastering Doxygen
========================================================================================

My hope for this document is that it will provide you with enough information if you are
just getting started with documenting a C++ project.  I make no claims to this being all
you will need, the information presented here comes from a **lot** of trial and error
and arriving at a workflow that seemed to work out.  Your mileage **will** vary, things
**will break**, but if you are patient (and belligerent) enough, the end result is
totally worth it.  With that, let's begin!

.. contents:: Contents
   :local:
   :backlinks: none

What is Doxygen, and How do I Approach it?
----------------------------------------------------------------------------------------

`Doxygen`__ is a documentation (doxy) generation (gen) system.  You should approach it
with fear, awe, and humility.  And remember to never look it in the eyes.

__ http://www.stack.nl/~dimitri/doxygen/

Doxygen on its own is a fascinating tool.  It's stupendously flexible, and immensely
powerful.  I mean let's think about what it's actually doing: it's parsing and
extracting documentation from C++ (among other possible languages), which in its own
right cannot even be parsed using pushdown automata.  Read this `amusing SO answer`__
for why it's so complex!

__ https://stackoverflow.com/a/14589567/3814202

With a little appreciation for **what** Doxygen is actually doing for you, don't take
for granted that it likely isn't going to work *perfectly* out-of-the-box.  It **will**
get **most** things right with almost no effort!  But if your code is complicated,
expect failure, taking solace in the fact that Doxygen's exceptional flexibility allows
for you to fix the errors.

**Recipe for Success**
    1. Start the documentation as early as you can.  Don't document it once you want to
       release.
    2. Since you're reading this page, I'd say the easiest thing to "just get the docs
       going" would be to use the STDIN approach provided by Exhale.
    3. When things aren't appearing correctly, add the **line** ``GENERATE_HTML = YES``
       to your input to :data:`~exhale.configs.exhaleDoxygenStdin` and look at the actual
       Doxygen HTML pages.

       - If it is broken there, there's no way it's going to work with Exhale.
       - If it is working there but not with Exhale, you at least have a starting point.

    4. **DO NOT IGNORE THE ERRORS FROM DOXYGEN**.  I've never understood why people
       think that it's ok for their documentation build to be emitting hundreds of
       warnings.  Fix them, or live with it.  The choice is yours.

**Recipe for Failure**
    1. Assume that you can just plug-and-play and never read any documentation on the
       documentation systems.
    2. Ignore the warnings and errors from Doxygen, Breathe, Exhale, and Sphinx.

Crash Course on Documentation with Doxygen
----------------------------------------------------------------------------------------

There is a lot to make sure you do in terms of the documentation you write in a C++ file
to make Doxygen work.  First and foremost, there is a comprehensive `Doxygen manual`__
that describes anything and everything.  Depending on the kind of person you are,
browsing the manual may be the best option.  I personally went the "hardcore" (aka
overwhelming) approach of just reading the entire generated ``Doxyfile``.  You can
acquire a shiny new ``Doxyfile`` by executing ``doxygen -g`` in your terminal in a
directory where there is no ``Doxyfile`` present.

__ http://www.stack.nl/~dimitri/doxygen/manual/index.html

.. tip::

   If you take this approach, open the ``Doxyfile`` in a text editor and view it with
   ``make`` syntax.  That will at least make it bearable.

The Core Variables
****************************************************************************************

Amidst all of the options, there are really only a handful that you need to get things
started.

``INPUT = ../some/path``
    You need to tell Doxygen where to look for your code!  This can be either a relative
    or absolute path.  Relative paths are preferred, because an absolute path means
    you will be the only person who can actually build the documentation.  Where
    relative paths are concerned, these are **relative to where Doxygen executes from**.

    In *pure* Doxygen, this is typically where the ``Doxyfile`` is.  In Exhale, these
    are relative to where ``conf.py`` is.

    .. note::

       Where Exhale is concerned, this is the **only** *required* Doxygen configuration
       when using :data:`~exhale.configs.exhaleDoxygenStdin`.

.. tip::

   Exhale sets all of these for you, they are described here for you to know what they
   are doing.

``OUTPUT_DIRECTORY = ./a/different/path``
    This tells Doxygen where to store the output of the documentation it is generating.
    Supposing you specified ``OUTPUT_DIRECTORY = ./doxyoutput``, and you specified to
    Doxygen ``GENERATE_HTML = YES``, ``GENERATE_LATEX = YES``, and
    ``GENERATE_XML = YES``, it would create the folder ``./doxyoutput``, with
    subdirectories such as ``html`` or ``xml``.

    For Exhale, since you already needed to supply the path to the ``xml`` output
    directory for Breathe, this configuration is inferred.  Or rather, Exhale searches
    for ``OUTPUT_DIRECTORY`` when using :data:`~exhale.configs.exhaleDoxygenStdin` and
    raises an exception if it is found.

``RECURSIVE = YES``
    Assuming your project has more than one directory, you specify ``INPUT`` to be the
    top-level of where your header files are, and setting this to ``YES`` tells Doxygen
    to recurse the directory structure.

``FULL_PATH_NAMES = YES``
    In *pure* Doxygen, you may not want this.  In Exhale, you always do.  When set to
    ``NO``, Doxygen performs some clever renaming, and discards all parts of paths that
    can be removed *while still keeping files unique*.  The consequence for Exhale is
    that when this is done, there is no way to know the original directory structure.

``STRIP_FROM_PATH = ../some/path``
    However, if you ask for ``FULL_PATH_NAMES``, you will be displeased by the results.
    This variable informs Doxygen to strip out a common prefix path from all the paths
    generated in the documentation.

    .. warning::

       Exhale requires that you specify this variable through ``exhale_args``.  If
       it is detected in the input to :data:`~exhale.configs.exhaleDoxygenStdin`, an
       exception is raised.  This is a detail specific to hosting on Read the Docs that
       in all honesty I've never found the cause of.  It likely has to do with the
       environment setup.

So in recap, really the only required variables you need to give are ``INPUT`` and
``OUTPUT_DIRECTORY``.  I highlight the above variables to indicate what the defaults
Exhale expects out of your configuration.

Additional Variables with Important Impacts
****************************************************************************************

.. _doxygen_aliases:

``ALIASES``
   In particular, the two aliases Exhale provides come from Breathe, and allow
   you to wield full-blown reStructuredText (including directives, grid tables,
   and more) in a "verbatim" environment.  The aliases as sent to Doxygen:

   .. code-block:: make

      # Allow for rst directives and advanced functions e.g. grid tables
      ALIASES  = "rst=\verbatim embed:rst:leading-asterisk"
      ALIASES += "endrst=\endverbatim"

   This allows you to do something like this in your code:

   .. code-block:: cpp

      /**
       * \file
       *
       * \brief This file does not even exist in the real world.
       *
       * \rst
       * There is a :math:`N^2` environment for reStructuredText!
       *
       * +-------------------+-------------------+
       * | Grid Tables       | Are Beautiful     |
       * +===================+===================+
       * | Easy to read      | In code and docs  |
       * +-------------------+-------------------+
       * | Exceptionally flexible and powerful   |
       * +-------+-------+-------+-------+-------+
       * | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 |
       * +-------+-------+-------+-------+-------+
       *
       * \endrst
       */

   .. note::

      This ``\rst`` environment is actually quite useful as an override.
      Doxygen by default enables Markdown.  For the most part, you can ignore
      this, but in the times where Markdown and reStructuredText create
      conflicts, being able to force reStructuredText is the **only** solution.

.. _doxygen_preprocessing:

``ENABLE_PREPROCESSING = YES``
   Its rather unlikely you will ever get a full C++ project to produce the
   expected documentation without using the preprocessor.

``MACRO_EXPANSION = YES``
   Similarly, if you use macros you'll want to make sure that Doxygen expands
   them.

``SKIP_FUNCTION_MACROS = NO``
   Though it is not always capable of actually doing the macros, try and let
   Doxygen's preprocessor do what it can.

``EXPAND_ONLY_PREDEF = NO``
   Unless you want to enumerate every single preprocessor constant / macro
   expansion, tell Doxygen to try and expand everything it can.

.. _doxygen_predefined:

``PREDEFINED``
   Exhale adds the following two predefined preprocessor symbols:

   .. code-block:: make

      # extra defs for to help with building the _right_ version of the docs
      PREDEFINED  = DOXYGEN_DOCUMENTATION_BUILD
      PREDEFINED += DOXYGEN_SHOULD_SKIP_THIS

   These are useful for when you either have code that is breaking the Doxygen
   documentation (e.g. heavy templating / metaprogramming), or need to control
   the compilation trajectory to where a docstring lives.  For example

   .. code-block:: cpp

      #if !defined(DOXYGEN_SHOULD_SKIP_THIS)
          // forward declarations in particular will make Doxygen think that the
          // class is defined in a different file!
          class Forward;
          struct Declaration;
      #endif // DOXYGEN_SHOULD_SKIP_THIS

      // platform specific code
      #if defined(__APPLE__) || defined(DOXYGEN_DOCUMENTATION_BUILD)
          /// This method is only needed on Apple
          void they_think_they_are_special();

          /**
           * This definition changes depending on the platform, but we can just
           * document it once.
           *
           * - Apple: ``12``
           * - Linux: ``21``
           * - Windows: ``0``
           */
          #define SOME_CONSTANT 12
      #elif defined(__linux__)
          #define SOME_CONSTANT 21
      #else
          #define SOME_CONSTANT 0
      #endif

   If / when the Doxygen preprocessor is not expanding things correctly, use
   this list to predefine what things should be expanding to.  For example, a
   macro I like to use originally taken from Wenzel Jakob's `NanoGUI`__ for
   making namespaces a little more readable looks like this:

   .. code-block:: cpp

      #define NAMESPACE_BEGIN(name) namespace name {
      #define NAMESPACE_END(name) }

   Doxygen gets confused by this, but for say ``namespace nanogui`` we can just
   predefine it for Doxygen:

   .. code-block:: make

      PREDEFINED += NAMESPACE_BEGIN(nanogui)="namespace nanogui {"
      PREDEFINED += NAMESPACE_END(nanogui)="}"

   __ http://nanogui.readthedocs.io/en/latest/

Adding Documentation to the Code
****************************************************************************************

See the `Doxygen docblocks documentation`__ for all of the different options you have
at your disposal.  I'll call attention to a couple of useful commands commonly used in
documenting specific aspects:

+-----------------+--------------------------------------------------------------------+
| Doxygen Command | Doxygen Documentation Action                                       |
+=================+====================================================================+
| ``\ref``        | Add link to another item being documented.                         |
+-----------------+--------------------------------------------------------------------+
| ``\brief``      | Add brief documentation to a given construct.                      |
+-----------------+--------------------------------------------------------------------+
| ``\param``      | Add documentation for a specific parameter.                        |
+-----------------+--------------------------------------------------------------------+
| ``\tparam``     | Add documentation for a specific template parameter.               |
+-----------------+--------------------------------------------------------------------+
| ``\throw``      | Add documentation for a specific exception that can be thrown.     |
+-----------------+--------------------------------------------------------------------+
| ``\return``     | Add documentation for the return value.                            |
+-----------------+--------------------------------------------------------------------+
| Explicit Control Over Contstructs (e.g., Adding Documentation Apart from Definition )|
+-----------------+--------------------------------------------------------------------+
| ``\struct``     | To document a ``struct``.                                          |
+-----------------+--------------------------------------------------------------------+
| ``\union``      | To document a ``union``.                                           |
+-----------------+--------------------------------------------------------------------+
| ``\enum``       | To document an ``enum`` type.                                      |
+-----------------+--------------------------------------------------------------------+
| ``\fn``         | To document a function.                                            |
+-----------------+--------------------------------------------------------------------+
| ``\var``        | To document a variable or ``typedef`` or ``enum value``.           |
+-----------------+--------------------------------------------------------------------+
| ``\def``        | To document a ``#define``.                                         |
+-----------------+--------------------------------------------------------------------+
| ``\typedef``    | To document a ``typedef``.                                         |
+-----------------+--------------------------------------------------------------------+
| ``\file``       | To document a file.                                                |
+-----------------+--------------------------------------------------------------------+
| ``\namespace``  | To document a ``namespace``.                                       |
+-----------------+--------------------------------------------------------------------+
| Inline Formatting (see :ref:`file_and_namespace_level_documentation_in_exhale`)      |
+-----------------+--------------------------------------------------------------------+
| ``\b``          | Bold a single word (e.g. ``\b bold``).                             |
+-----------------+--------------------------------------------------------------------+
| ``\em``         | Emphasize a single word (e.g. ``\em emphasis``).                   |
+-----------------+--------------------------------------------------------------------+
| ``\c``          | Teletype a single word (e.g. ``\c computeroutput``).               |
+-----------------+--------------------------------------------------------------------+

__ http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html

Doxygen Documentation Pitfalls
----------------------------------------------------------------------------------------

.. _document_your_files_son:

File Documentation is Necessary for More than just Files!
****************************************************************************************

If you want a file documented, you **must** have ``\file`` somewhere in a documentation
string in the file.  **However**, if you want something like an ``enum`` or ``define``
to show up in the documentation, you **must document the file** (even if the file level
documentation is empty)!  From the Doxygen documentation reiteration_:

..

    Let's repeat that, because it is often overlooked: to document global objects
    (functions, typedefs, enum, macros, etc), you must document the file in which they
    are defined.

.. _reiteration: http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html

.. _file_associations:

Associating Documentation with the Right File
****************************************************************************************

Classes, Structs, Enums, and Unions typically need additional care in order for them to
appear in the hierarchy correctly.  If you have a file in a directory, the Doxygen FAQ_ explains that you need to specify this location:

..

    You can also document your class as follows:

    .. code-block:: cpp

        /**
         * \class MyClassName include.h path/include.h
         *
         *  Docs for MyClassName
         */

So a minimal working example of the file ``directory/file.h`` defining ``struct thing``
might look like:

.. code-block:: cpp

    #pragma once
    /** \file */

    /**
     * \struct thing file.h directory/file.h
     *
     * \brief The documentation about the thing.
     */
     struct thing {
        /// The thing that makes the thing.
        thing() {}
     };

.. _FAQ: http://www.stack.nl/~dimitri/doxygen/manual/faq.html#faq_code_inc

Features Available by Using Sphinx / Breathe / Exhale by way of reStructuredText
----------------------------------------------------------------------------------------

Especially if you already know Markdown, reStructuredText syntax can be a little
frustrating.  I love both equally for different reasons, but certain actions had to take
place in writing Exhale that necessitate using reStructuredText.  The following is a
mini-guide on the syntax, with links to more resources.

Basic Formatting
****************************************************************************************

**Bold Text**
    Bold text is done with **two** asterisks: ``**bold**``.

*Italic Text*
    Italic text is done with **one** asterisk: ``*italic*``.

    .. danger::

       Unlike most Markdown parsers, ``_italic_`` with underscores is **not** going to
       work.  It has to do with how hyperlinks work.

``Teletype Text``
    Teletype text is done with **two** backticks: ````teletype text````

    .. danger::

       Single backticks will **not** do teletype text!  This also has to do with how
       hyperlinks in reStructuredText work.

Listings
****************************************************************************************

See the `official documentation`__.

__ http://docutils.sourceforge.net/docs/user/rst/quickref.html#bullet-lists

Tables
****************************************************************************************

.. tip::

   Everything from here on may cause issues with Doxygen.  Use the ``\rst`` verbatim
   environment described in the :ref:`Doxygen Aliases <doxygen_aliases>` section.

Use `grid tables`__!!!

__ http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html#grid-tables

Hyperlinks
****************************************************************************************

I'll confess that reStructuredText hyperlinks are probably the most confusing.  Best to
leave the explaining to the `official documentation`__.

__ http://docutils.sourceforge.net/docs/user/rst/quickref.html#hyperlink-targets

Useful Directives
****************************************************************************************

reStructuredText is particularly sensitive to whitespace.  Where directives are
concerned, it may be uncomfortable for you but you actually indent by **three** spaces.
The reason is simple: it lines up visually.

Every directive starts with two ``.``, followed by a single space, then the directive,
followed by **two** ``:``.  So it looks like this:

.. code-block:: rst

   .. directive:: primary argument
      :specifications:

      There is exactly *ONE* blank line between the specifications and the text that is
      a part of the directive.

1. Not every directive requires (or supports) a primary argument.
2. Not every directive requires (or supports) specifications.

- :ref:`Admonitions <admonitions>`
- :ref:`Indexing / Including Other Files <indexing_and_including>`
- :ref:`Code Listings <code_listings>`

.. _admonitions:

**Admonitions**
   Sphinx enables you to include a few different admonitions.  Note that which
   ``html_theme`` you choose in ``conf.py`` determines how they are displayed.  With the
   admonitions, there are no arguments or specifications.  If it is a short note you can
   specify it all on one line.  If it is longer, make sure you keep the blank line
   between the directive and the text.

   .. note::

      .. code-block:: rst

         .. note::

            This is a note!

   .. tip::

      .. code-block:: rst

         .. tip::

            This is a tip!

   .. warning::

      .. code-block:: rst

         .. warning::

            This is a warning!

   .. danger::

      .. code-block:: rst

         .. danger::

            This is a danger (aka super-warning)!

.. _indexing_and_including:

**Indexing / Including Other Files**
    The two directives you will use for this will be ``.. toctree::`` and
    ``.. include::``.

    ``toctree``
        Toctrees are "Table of Contents" trees.  See the `Sphinx Toctree Docs`__.

        __ http://www.sphinx-doc.org/en/latest/usage/restructuredtext/directives.html#directive-toctree

    ``include``
        I learned of the ``include`` directive by way of writing Exhale, and call
        attention to it because of the ``:start-after:`` and ``:end-before:``
        specifiers.  It's particularly nice to use in order to have a shared
        ``README.rst`` for your code and documentation.

        View the source code of `exhale/docs/index.rst`__ to see how that works.

        __ https://raw.githubusercontent.com/svenevs/exhale/master/docs/index.rst

.. _code_listings:

**Code Listings**
    If you hail from Markdown, keep in mind that it's actually very similar. Instead of
    using fenced code blocks, you're using a directive.

    .. code-block:: rst

        .. code-block:: cpp

           // This code is highlighted using the cpp lexer
           void foo() { /* ... */ }

    results in

    .. code-block:: cpp

       // This code is highlighted using the cpp lexer
       void foo() { /* ... */ }

    You have another option, which is to use **two** colons after a paragraph and then
    indent by **four** spaces.  This is also similar to Markdown, only the two colons
    are required.  The downside to this approach is you are at the disposal of Sphinx to
    determine what the language is.

    .. code-block:: rst

       This is a paragraph::

           def foo():
               pass

    This is a paragraph::

        def foo():
            pass

    Noting that in the above output there **is** a **single** ``:`` after ``paragraph``.
