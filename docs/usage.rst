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
            "doxygenIndexXMLPath"  : "./doxyoutput/xml/index.xml",
            "containmentFolder"    : "./generated_api",
            "rootFileName"         : "library_root.rst",
            "rootFileTitle"        : "Library API",
            "doxygenStripFromPath" : ".."
        }

        # import the exhale module from the current directory and generate the api
        sys.path.insert(0, os.path.abspath('.')) # exhale.py is in this directory
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
If this is not working, simply generate the API once and look at the top of the file
generated for the thing you are trying to link to.  Copy the link (ignoring the leading
underscore) and use that.

These are reStructuredText links, so in the above example you would write

.. code-block:: rst

   I am linking to :ref:`struct_arbitrary__some_thing`.

Alternatively, you can link to a class with ``:class:`namespace::ClassName```, as well
as link to a method within that class using ``:func:`namespace::ClassName::method```.

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
    +-------+------------------------------------------------------------+
    | **3** | {{ appendBreatheFileDirective }}                           |
    +-------+------------------------------------------------------------+


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

3. If the value of ``"appendBreatheFileDirective" = True`` in the arguments passed to
   :func:`exhale.generate`, then the following section will be appended to the bottom
   of the file being generated:

   .. raw:: html

      <div class="highlight-rest">
        <div class="highlight">
          <pre>
      Full File Listing
      ----------------------------------------------------------------------------------

      .. doxygenfile:: {{ exhale_node.location }}</pre>
        </div>
      </div>

   This will hopefully be a temporary workaround until I can figure out how to robustly
   parse the xml for this, or figure out how to manipulate Breathe to give me this
   information (since it clearly exists...).  This workaround is unideal in that any
   errors you have in any of the documentation of the items in the file will be
   duplicated by the build, as well as a large number of DUPLICATE id's will be flagged.
   The generated links inside of the produced output by Breathe will now also link to
   items on this page first.  AKA this is a buggy feature that I hope to fix soon, but
   if you *really* need the file documentation in your project, this is currently the
   only way to include it.

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

    def generateDoxygenXML(stripPath):
        '''
        Generates the doxygen xml files used by breathe and exhale.
        Approach modified from:

        - https://github.com/fmtlib/fmt/blob/master/doc/build.py

        :param stripPath:
            The value you are sending to exhale.generate via the
            key 'doxygenStripFromPath'.  Usually, should be '..'.
        '''
        from subprocess import PIPE, Popen
        try:
            doxygen_cmd   = ["doxygen", "-"]# "-" tells Doxygen to read configs from stdin
            doxygen_proc  = Popen(doxygen_cmd, stdin=PIPE)
            doxygen_input = r'''
                # Make this the same as what you tell exhale.
                OUTPUT_DIRECTORY       = doxyoutput
                # If you need this to be YES, exhale will probably break.
                CREATE_SUBDIRS         = NO
                # So that only include/ and subdirectories appear.
                FULL_PATH_NAMES        = YES
                STRIP_FROM_PATH        = "%s/"
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
                # Allow for rst directives and advanced functions (e.g. grid tables)
                ALIASES                = "rst=\verbatim embed:rst:leading-asterisk"
                ALIASES               += "endrst=\endverbatim"
            ''' % stripPath)
            # In python 3 strings and bytes are no longer interchangeable
            if sys.version[0] == "3":
                doxygen_input = bytes(doxygen_input, 'ASCII')
            doxygen_proc.communicate(input=doxygen_input)
            doxygen_proc.stdin.close()
            if doxygen_proc.wait() != 0:
                raise RuntimeError("Non-zero return code from 'doxygen'...")
        except Exception as e:
            raise Exception("Unable to execute 'doxygen': {}".format(e))

.. note::
   The above code should work for Python 2 and 3, but be careful not to modify the
   somewhat delicate treatment of strings:

   - ``doxygen_input = r'''...``: the ``r`` is required to **prevent** the verbatim rst
     directives to expand into control sequences (``\v``)
   - In Python 3 you need to explicitly construct the bytes for communicating
     with the process.

Now that you have defined this at the bottom of ``conf.py``, we'll add a modified
``setup(app)`` method:

.. code-block:: py

    # setup is called auto-magically for you by Sphinx
    def setup(app):
        stripPath = ".."
        generateDoxygenXML(stripPath)

        # create the dictionary to send to exhale
        exhaleArgs = {
            "doxygenIndexXMLPath"  : "./doxyoutput/xml/index.xml",
            "containmentFolder"    : "./generated_api",
            "rootFileName"         : "library_root.rst",
            "rootFileTitle"        : "Library API",
            "doxygenStripFromPath" : stripPath
        }

        # import the exhale module from the current directory and generate the api
        sys.path.insert(0, os.path.abspath('.')) # exhale.py is in this directory
        from exhale import generate
        generate(exhaleArgs)

Now you can build the docs with ``make html`` and it will re-parse using Doxygen,
generate all relevant files, and give you an updated website.  While some may argue that
this is wasteful, ``exhale`` is not smart enough and never will be smart enough to
provide incremental updates.  The full api is regenerated.  Every time.  So you may as
well run Doxygen each time ;)

.. note::

   Where Doxygen is concerned, you will likely need to give special attention to macros
   and preprocessor definitions.  Refer to the linked ``fmt`` docs in the above code
   snippet.  Of particular concern would be the following Doxygen config variables:

   - ``ENABLE_PREPROCESSING``
   - ``MACRO_EXPANSION``
   - ``EXPAND_ONLY_PREDEF``
   - ``PREDEFINED`` (very useful if the Doxygen preprocessor is choking on your macros)
   - ``SKIP_FUNCTION_MACROS``

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

Start to finish for Read the Docs
----------------------------------------------------------------------------------------

Assuming you already had the code that you are generating the API for documented,
navigate to the top-level folder of your repository.  Read the Docs (RTD) will be
looking for a folder named either ``doc`` or ``docs`` at the root of your repository
by default::

    $ cd ~/my_repo/
    $ mkdir docs

Now we are ready to begin.

1. Generate your sphinx code by using the ``sphinx-quickstart`` utility.  It may look
   something like the following:

   .. code-block:: bash

      $ ~/my_repo/docs> sphinx-quickstart
      Welcome to the Sphinx 1.3.1 quickstart utility.

      Please enter values for the following settings (just press Enter to
      accept a default value, if one is given in brackets).

      Enter the root path for documentation.
      > Root path for the documentation [.]:

      You have two options for placing the build directory for Sphinx output.
      Either, you use a directory "_build" within the root path, or you separate
      "source" and "build" directories within the root path.
      > Separate source and build directories (y/n) [n]:

      Inside the root directory, two more directories will be created; "_templates"
      for custom HTML templates and "_static" for custom stylesheets and other static
      files. You can enter another prefix (such as ".") to replace the underscore.
      > Name prefix for templates and static dir [_]:

      ... and a whole lot more ...

  .. warning::
     The default value for ``> Create Makefile? (y/n) [y]:`` must be yes to work on RTD.
     They are giving you a unix virtual environment.

2. This will create the files ``conf.py``, ``index.rst``, ``Makefile``, and ``make.bat``
   if you are supporting Windows.  It will also create the directories ``_static`` and
   ``_templates`` for customizing the sphinx output.

3. Create a ``requirements.txt`` file with the line ``breathe`` so RTD will install it:

   .. code-block:: bash

      $ ~/my_repo/docs> echo 'breathe' > requirements.txt

   Alternatively, you can have RTD install via Git Tags.  At the time of writing this,
   the latest tag for ``breathe`` is ``4.3.1``, so in your ``requirements.txt`` you
   would have

   .. code-block:: bash

      git+git://github.com/michaeljones/breathe@v4.3.1#egg=breathe

4. Clone exhale and steal all of the files you will need:

   .. code-block:: bash

      $ ~/my_repo/docs> git clone https://github.com/svenevs/exhale.git
      $ ~/my_repo/docs> mv exhale/exhale.py .
      $ ~/my_repo/docs> mv exhale/treeView/_static/collapse/ ./_static/
      $ ~/my_repo/docs> mv exhale/treeView/_templates/layout.html _templates/
      $ ~/my_repo/docs> rm -rf exhale/

5. Uncomment the line ``sys.path.insert(0, os.path.abspath('.'))`` at the top of the
   generated ``conf.py`` so that Sphinx will know where to look for ``exhale.py``.

6. Two options below  (5) in ``conf.py``, add ``'breathe'`` to the ``extensions`` list
   so that the directives from Breathe can be used.

7. Just below the ``extensions`` list, configure breathe.  Adding the following should
   be sufficient:

   .. code-block:: py

      breathe_projects = { "yourProjectName": "./doxyoutput/xml" }
      breathe_default_project = "yourProjectName"

8. Edit ``conf.py`` to use the RTD Theme.  You are of course able to use a different
   Sphinx theme, but the RTD Theme is what this will enable.  Replace the ``html_theme``
   and ``html_theme_path`` lines (or comment them out) with:

   .. code-block:: py

      # on_rtd is whether we are on readthedocs.org, this line of code grabbed from docs.readthedocs.org
      on_rtd = os.environ.get('READTHEDOCS', None) == 'True'

      if not on_rtd:  # only import and set the theme if we're building docs locally
          import sphinx_rtd_theme
          html_theme = 'sphinx_rtd_theme'
          html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

9. Edit ``conf.py`` to include the ``generateDoxygenXML`` and ``setup`` methods provided
   in :ref:`usage_fully_automated` at the bottom of the file.

10. Add ``createTreeView = True`` to the dictionary arguments sent to :func:`exhale.generate`.

11. Go to the admin page of your RTD website and select the *Advanced Settings* tab.
    Make sure the *Install your project inside a virtualenv using* ``setup.py install``
    button is checked.  In the *Requirements file* box below, enter
    ``docs/requirements.txt`` assuming you followed the steps above.

    I personally prefer to keep the ``requirements.txt`` hidden in the ``docs`` folder
    so that it is implicit that those are only requirements for building the docs, and
    not the actual project itself.

And you are done.  Make sure you ``git add`` all of the files in your new ``docs``
directory, RTD will clone your repository / update when you push commits.  You can
build it locally using ``make html`` in the current directory, but make sure you do not
add the ``_build`` directory to your git repository.

I hope that the above is successful for you, it looks like a lot but it's not too bad...
right?
