Usage
========================================================================================

Using exhale can be simple or involved, depending on how much you want to change and
how familiar you are with things like Sphinx, Breathe, Doxygen, and Jinja.  At the top
level, what you need is:

1. Your C++ code you want to document, with "proper" Doxygen documentation.  Please
   read the :ref:`doxygen_documentaion_specifics` for common documentation pitfalls,
   as well as features previously unavailable in standard Doxygen.
2. Generating the API using Sphinx, Doxygen, Breathe already working.

.. _usage_quickstart_guide:

Quickstart
----------------------------------------------------------------------------------------

In your ``conf.py``

.. code-block:: py

    # setup is called auto-magically for you by Sphinx
    def setup(app):
        # create the dictionary to send to exhale
        exhaleArgs = {
            "doxygenIndexXMLPath" : "./doxyoutput/xml/index.xml",
            "containmentFolder"   : "./generated_api",
            "rootFileName"        : "library_root.rst",
            "rootFileTitle"       : "Library API"
        }

        # import the exhale module from the current directory and generate the api
        sys.path.append(os.path.abspath('.')) # exhale.py is in this directory
        from exhale import generate
        generate(exhaleArgs)

In your ``index.rst``, you might have something like

.. raw:: html

   <div class="highlight-rest">
     <div class="highlight">
       <pre>
   .. toctree::
      :maxdepth: 2

      about
      <b>generated_api/library_root</b></pre>
     </div>
   </div>

.. note::

   The above assumes that your Doxygen xml tree has already been created.  The
   :ref:`usage_fully_automated` section provides additional steps to do this all at once.

Lastly, you will likely want to add these two lines somewhere in ``conf.py`` as well:

.. code-block:: py

    # Tell sphinx what the primary language being documented is.
    primary_domain = 'cpp'

    # Tell sphinx what the pygments highlight language should be.
    highlight_language = 'cpp'

The full documentation for the only (official) entry point is: :func:`exhale.generate`.

.. _usage_advanced_usage:

Additional Usage and Customization
----------------------------------------------------------------------------------------

The main library page that you will link to from your documentation is laid out as
follows:

    +-------+------------------------------------------------+-----------+
    | **1** | {{ Library API Title }}                        | Heading   |
    +=======+================================================+===========+
    | **2** | {{ after title description }}                  | Section 1 |
    +-------+------------------------------------------------+-----------+
    | **3** | Class Hierarchy                                | Section 2 |
    +-------+------------------------------------------------+-----------+
    | **4** | File Hierarchy                                 | Section 3 |
    +-------+------------------------------------------------+-----------+
    | **5** | Full API Listing                               | Section 4 |
    +-------+------------------------------------------------+-----------+
    | **6** | {{ after body description }}                   | Section 5 |
    +-------+------------------------------------------------+-----------+


1. The dictionary key ``rootFileTitle`` passed to :func:`exhale.generate` function is what will
   be the Heading title.
2. Section 1 can optionally be provided by the dictionary key ``afterTitleDescription``
   in the argument to :func:`exhale.generate`.
3. The class view hierarchy (including namespaces with class-like children).
4. The file view hierarchy (including folders).
5. An ordered enumeration of every Breathe compound found, except for groups.
6. Section 5 can optionally be provided by the dictionary key ``afterBodySummary`` in
   the argument to :func:`exhale.generate`.

.. _usage_creating_the_treeview:

Clickable Hierarchies
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

While I would love to automate this for you, it is not possible to do so very easily.
If you would like to have a more interactive hierarchy view (instead of just bulleted
lists), you will need to add some extra files for it to work.  There are a lot of
different options available, but I rather enjoy Stephen Morley's collapsibleLists_: it's
effective, easily customizable if you know front-end, and has a generous license_.

You will need

1. The javascript library.
2. The css stylesheet and its associated images.
3. A sphinx template override.

I have taken the liberty of adding these files to the exhale repository, just clone
exhale and move the files to where you need them to go.  Specifically, the exhale
repository looks like this::

    exhale/
        │   README.md
        │   exhale.py # put next to conf.py
        └───treeView/
            ├───_static/
            │       └───collapse/
            │              CollapsibleLists.compressed.js # (1) library
            │              tree_view.css                  # (2) stylesheet
            │              button-closed.png              #  v  associated images
            │              button-open.png
            │              button.png
            │              list-item-contents.png
            │              list-item-last-open.png
            │              list-item-last.png
            │              list-item-open.png
            │              list-item-root.png
            │              list-item.png
            └───_templates/
                    layout.html                           # (3) MUST be layout.html

You then just need to to move the folder ``collapse`` to your ``_static`` directory, and
move ``layout.html`` to your ``_templates`` directory.  So your ``docs`` folder might
look something like::

    docs/
        │   conf.py     # created by sphinx-quickstart
        │   exhale.py   # placed here by you
        │   index.rst   # created by sphinx-quickstart
        │   about.rst   # created by you
        │   Makefile    # created by sphinx-quickstart
        ├───_static/
        │   └───collapse/
        │          ... everything from above ...
        └───_templates/
               layout.html # copied from above

Sphinx will make everything else fall into place in the end.  If you already have your
own ``layout.html``, you know what you are doing --- just look at mine and add the
relevant lines to yours.

You can now add the key value pair ``createTreeView = True`` to the dictionary you are
passing to :func:`exhale.generate`.

.. warning::
   If you are hosting on Read the Docs, you will need to make sure you are tracking all
   of those files with git!

.. _collapsibleLists: http://code.stephenmorley.org/javascript/collapsible-lists/
.. _license: http://code.stephenmorley.org/about-this-site/copyright/

.. _usage_external_linkage:

Linking to a Generated File
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Every file created by exhale is given a reStructuredText label that you can use to link
to the API page.  It is easiest to just show how the labels are created.

.. code-block:: py

   def initializeNodeFilenameAndLink(self, node):
       html_safe_name = node.name.replace(":", "_").replace("/", "_")
       node.link_name = "{}_{}".format(qualifyKind(node.kind).lower(), html_safe_name)

The parameter ``node`` is an :class:`exhale.ExhaleNode` object.  So if the node being
represented is a ``struct some_thing`` in ``namespace arbitrary``, then

.. code-block:: py

   node.name      := "arbitrary::some_thing"
   node.link_name := "struct_arbitrary__some_thing"

Noting that there are **two** underscores between ``arbitrary`` and ``some``.  Refer to
the full documentation of :func:`exhale.qualifyKind` for the possible return values.

.. _usage_customizing_all_breathe_directives:

Customizing Breathe Output
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Breathe provides you with many excellent configurations for the various reStructuredText
directives it provides.  Your preferences will likely be different than mine for what
you do / do not want to show up.  The default behavior of exhale is to use all default
values for all Breathe directives except for classes and structs.  Classes and structs
will request documentation for ``:members:``, ``:protected-members:``, and
``:undoc-members:``.

To change the behavior of any of the breathe directives, you will need to implement your
own function and specify that as the ``customSpecificationFunction`` for
:func:`exhale.generate`.  Please make sure you read the documentation for
:func:`exhale.specificationsForKind` before implementing, the requirements are very
specific.  An example custom implementation could be included in ``conf.py`` as follows:

.. code-block:: py

   def customSpecificationsForKind(kind):
       if kind == "class" or kind == "struct":
           return "   :members:\n   :protected-members:\n   :no-link:\n"
       elif kind == "enum":
           return "   :outline:\n"
       return ""

and you would then change the declaration of the dictionary you are passing to
:func:`exhale.generate` to be:

.. code-block:: py

   exhaleArgs = {
       "doxygenIndexXMLPath"         : "./doxyoutput/xml/index.xml",
       "containmentFolder"           : "./generated_api",
       "rootFileName"                : "library_root.rst",
       "rootFileTitle"               : "Library API",
       "customSpecificationFunction" : customSpecificationsForKind
    }

.. note::
   The value of the key ``customSpecificationFunction`` is **not** a string, just the
   name of the function.  These are first class objects in Python, which makes the above exceptionally convenient :)

.. _usage_customizing_file_pages:

Customizing ``File`` Pages
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

File pages are structured something like

    +--------------------------------------------------------+-----------+
    | File {{ filename of exhale node }}                     | Heading   |
    +=======+================================================+===========+
    | **1** | Definition ( {{ path to file with folders }} ) | Section 1 |
    +-------+------------------------------------------------+           |
    | **2** | - Program Listing for file (hyperlink)         |           |
    +-------+------------------------------------------------+-----------+
    |  ... other common information ...                                  |
    +--------------------------------------------------------------------+


**Heading**:
    Uses the file name without a path to it.  If the path was ``include/File.h``, then
    the line would be ``File File.h``.

**Section 1**:
    The following Doxygen variables control what this section looks like, as well as
    whether or not it is included at all.

1. Set the Doxygen variable ``STRIP_FROM_PATH`` to change the output inside of
   parentheses.

   If the file path is ``../include/arbitrary/File.h`` and ``STRIP_FROM_PATH = ..``, the
   parentheses line will be ``Definition ( include/arbitrary/File.h )``.  If you change
   ``STRIP_FROM_PATH`` to ``../include``, then line 1 will be
   ``Definition ( arbitrary/File.h )``.

   The appearance of this line will also be affected by whether or not you are using the
   Doxygen variable ``FULL_PATH_NAMES``.  In addition to leaving its default ``YES``
   value, I have had best success with setting the ``STRIP_FROM_PATH`` variable.

2. If you set ``XML_PROGRAMLISTING = YES``, then the code of the program (as Doxygen
   would display it) will be included as a bulleted hyperlink.  It is the full file
   including whitespace, with documentation strings removed.  Programming comments
   remain in the file.

   Unlike Doxygen, I do not link to anything in the code.  Maybe sometime in the future?

.. note::

   If you set ``XML_PROGRAMLISTING = NO``, then the file in which an
   ``enum``, ``class``, ``variable``, etc is declared may **not** be recovered.  To my
   experience, the missing items not recovered are only declared in the programlisting.
   See the :func:`exhale.ExhaleRoot.fileRefDiscovery` part of the parsing process.

.. _usage_fully_automated:

Fully Automated Building
----------------------------------------------------------------------------------------

It is preferable to have everything generated at once, e.g. if you wish to host your
documentation on Read the Docs.  I make the assumption that you already have a
``Makefile`` created by ``sphinx-quickstart``.  Instead of a Doxyfile, though, we're
going to take it one step further.  Your specific arguments to Doxygen may be more
involved than this, but the below should get you started in the right direction.

In ``conf.py`` we now define at the bottom

.. code-block:: py

    def generateDoxygenXML():
        '''
        Generates the doxygen xml files used by breathe and exhale.  Approach modified from:

        - https://github.com/fmtlib/fmt/blob/master/doc/build.py

        The differences are in some of the arguments to Doxygen.
        '''
        from subprocess import PIPE, Popen
        try:

            doxygen_cmd = ["doxygen", "-"]# "-" tells Doxygen to read configs from stdin
            doxygen_proc = Popen(doxygen_cmd, stdin=PIPE)
            doxygen_proc.communicate(input=r'''
                # Make this the same as what you tell exhale.
                OUTPUT_DIRECTORY       = doxyoutput
                # If you need this to be YES, exhale will probably break.
                CREATE_SUBDIRS         = NO
                # So that only include/ and subdirectories appear.
                STRIP_FROM_PATH        = ..
                # Tell Doxygen where the source code is (yours may be different).
                INPUT                  = ../include
                # Nested folders will be ignored without this.  You may not need it.
                RECURSIVE              = YES
                # Set to YES if you are debugging or want to compare.
                GENERATE_HTML          = NO
                # Unless you want it?
                GENERATE_LATEX         = NO
                # Both breathe and exhale need the xml.
                GENERATE_XML           = YES
                # Set to NO if you do not want the Doxygen program listing included.
                XML_PROGRAMLISTING     = YES
            ''')
            doxygen_proc.stdin.close()
            if doxygen_proc.wait() != 0:
                raise RuntimeError("Non-zero return code from 'doxygen'...")
        except Exception as e:
            raise Exception("Unable to execute 'doxygen': {}".format(e))

.. note::

   Where Doxygen is concerned, you will likely need to give special attention to macros
   and preprocessor definitions.  Refer to the linked ``fmt`` docs in the above code
   snippet.  Of particular concern would be the following Doxygen config variables:

   - ``ENABLE_PREPROCESSING``
   - ``MACRO_EXPANSION``
   - ``EXPAND_ONLY_PREDEF``
   - ``PREDEFINED`` (very useful if the Doxygen preprocessor is choking on your macros)
   - ``SKIP_FUNCTION_MACROS``

If you are building on Read the Docs, you will need a few more items in ``conf.py``,
refer to the `RTD Theme GitHub Page <https://github.com/snide/sphinx_rtd_theme#using-this-theme-locally-then-building-on-read-the-docs>`_ for details.

.. _doxygen_documentaion_specifics:

Doxygen Documentation Specifics
----------------------------------------------------------------------------------------

If you have not used Doxygen before, the below may be helpful in getting things started.
To make sure you have Doxygen working, first try just using Doxygen and viewing the html
output by setting ``GENERATE_HTML = YES``.  This is the default value of the variable,
when you get Sphinx / Breathe / exhale going, just set this variable to ``NO`` to avoid
creating unnecessary files.

There is a lot to make sure you do in terms of the documentation you write in a C++ file
to make Doxygen work.  To get started, though, execute ``doxygen -g`` from your terminal
in a directory where there is no ``Doxyfile`` present and it will give you a large file
called ``Doxyfile`` with documentation on what all of the variables do.  You can leave
a large number of them to their default values.  To execute doxygen now, just enter
``doxygen`` in the same directory as the ``Doxyfile`` and it will generate the html
output for you so you can verify it is working.  Doxygen builds similarly to ``make``.

Later, you can just use ``conf.py`` and won't need to keep your ``Doxyfile``, but you
could also just keep the ``Doxyfile`` you have working for you and execute ``doxygen``
with no parameters in ``conf.py`` before calling :func:`exhale.generate`.

1. Files you want documented **must** have ``\file`` somewhere. From the Doxygen
   documentation reiteration_:

      Let's repeat that, because it is often overlooked: to document global objects
      (functions, typedefs, enum, macros, etc), you must document the file in which
      they are defined.

2. Classes, structs, and unions need additional care in order for them to appear in the
   hierarchy correctly.  If you have a file in a directory, the Doxygen FAQ_ explains
   that you need to specify this location:

      You can also document your class as follows:

      .. code-block:: cpp

          /*! \class MyClassName include.h path/include.h
           *
           *  Docs for MyClassName
           */

So a minimal working example of the file ``directory/file.h`` defining ``struct thing``
might look like:

.. code-block:: cpp

    /** \file */
    #ifndef _DIRECTORY_THING_H
    #define _DIRECTORY_THING_H

    /**
     * \struct thing file.h directory/file.h
     *
     * \brief The documentation about the thing.
     */
     struct thing {
        /// The thing that makes the thing.
        thing() {}
     };

    #endif // _DIRECTORY_THING_H


.. _reiteration: https://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
.. _FAQ: https://www.stack.nl/~dimitri/doxygen/manual/faq.html#faq_code_inc

3. Deviations from the norm.  The cool thing about using Sphinx in this context is that
   you have some flexibility inherent in the fact that we are using reStructuredText.
   For example, instead of using ``\ref``, you can just link to another documented item
   with ```item```.  This works across files as well, so you could link to class **A**
   in a different file from class **B** with ```A``` in the documentation string.  You
   could make a statement **bold** in your documentation with just ``**bold**``!

   I believe this includes the full range of reStructuredText syntax, but would not be
   surprised if there were directives or notation that break something.

.. note::
   I do not support ``groups`` with Doxygen, as I assume if you have gone through the
   effort to group everything then you have a desire to manually control the output.
   Breathe already has an excellent ``doxygengroup`` directive, and you should use that.

FAQ
----------------------------------------------------------------------------------------

Nothing is working, where did I go wrong?
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Sorry to hear that.  Please try comparing how your documentation is set up with the
companion_ website.

If things look similar enough, or something isn't clear, raise an issue on GitHub.  I'll
do my best to support what I can, and if similar questions come up then I can add them
to this FAQ.
