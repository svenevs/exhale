Exhale Configs Module
========================================================================================

.. contents:: Contents
   :local:
   :backlinks: none

.. automodule:: exhale.configs

.. _required_configs:

Required Configuration Arguments
----------------------------------------------------------------------------------------

.. begin_minimum_requirements_breathe_and_exhale

Both Breathe and Exhale require that you **already** have Doxygen ``xml`` documentation
generated **before** they are launched.  See the :ref:`usage_fully_automated` section
for more information.

There are **6** required arguments you must provide in your ``conf.py``.  **2** are for
Breathe, and **4** are for Exhale.

Required Arguments for Breathe
****************************************************************************************

Breathe is setup to allow for multiple projects being controlled by a **single**
``conf.py`` to rule them all.  Exhale only supports generating **one** "project" API at
a time.  The project that Exhale will generate is determined by what you signal to
Breathe as your *default* project.  The two arguments that must be present in your
``conf.py`` for Breathe are as follows:

.. _breathe_project:

**Mapping of Project Names to Doxygen XML Output Paths**
    ``breathe_projects`` (dict)
        - Keys: strings that are the name of a given project.
        - Values: strings that are (absolute or relative) paths to where the Doxygen XML
          output has been generated.

        So if the Doxygen documentation was generated to the path ``./doxyoutput/xml``,
        and your project was called ``"My Project"``, you would include the following in
        your ``conf.py``:

        .. code-block:: py

           breathe_projects = {
               "My Project": "./doxyoutput/xml"
           }

        .. tip::

           When specifying relative paths, they are all relative to ``conf.py``.

**Selecting the Project to Generate**
    ``breathe_default_project`` (str)
        Since Breathe can support multiple projects, specify the default project so that
        Exhale will know which one to use (when more than one project is available).

        Following from the example above, where the key in ``breathe_projects`` we want
        to generate is ``"My Project"``, you would include the following you your
        ``conf.py``:

        .. code-block:: py

           breathe_default_project = "My Project"

Required Arguments for Exhale
****************************************************************************************

Users must provide the following values to ``exhale_args`` in their ``conf.py``.

.. tip::

   Recall the variable name conventions from above.  If you want to specify the value
   for ``containmentFolder`` so that :data:`exhale.configs.containmentFolder` is
   populated, the name of the *key* is the string ``"containmentFolder"``.  Each entry
   below details what the ``type`` of the *value* of the key should be.  So in this case
   you might have

   .. code-block:: py

      exhale_args = {
          "containmentFolder": "./api",
          # other required entries here
      }

.. end_minimum_requirements_breathe_and_exhale

.. autodata:: exhale.configs.containmentFolder

.. autodata:: exhale.configs.rootFileName

.. autodata:: exhale.configs.rootFileTitle

.. autodata:: exhale.configs.doxygenStripFromPath

Optional Configuration Arguments
----------------------------------------------------------------------------------------

Build Process Logging, Colors, and Debugging
****************************************************************************************

.. autodata:: exhale.configs.verboseBuild

.. autodata:: exhale.configs.alwaysColorize

.. autodata:: exhale.configs.generateBreatheFileDirectives

Root API Document Customization
****************************************************************************************

.. begin_root_api_document_layout

The main library page (at the path given by ``"{containmentFolder}/{rootFileName}"``)
that you will link to from your documentation is laid out as follows:

    +------------+----------------------------------------------------+----------------+
    | **1**      | {{ rootFileTitle }}                                | Heading        |
    +============+====================================================+================+
    | **2**      | {{ afterTitleDescription }}                        | Section 1      |
    +------------+----------------------------------------------------+----------------+
    | **3**      | Class Hierarchy                                    | Section 2      |
    +------------+----------------------------------------------------+----------------+
    | **4**      | File Hierarchy                                     | Section 3      |
    +------------+----------------------------------------------------+----------------+
    | **5**      | {{ afterHierarchyDescription }}                    | Section 4      |
    +------------+----------------------------------------------------+----------------+
    | **6**      | {{ fullApiSubSectionTitle }}                       | Section 5      |
    +------------+----------------------------------------------------+----------------+
    | **7**      | Unabridged API                                     | Section 6      |
    +------------+----------------------------------------------------+----------------+
    | **8**      | {{ afterBodySummary }}                             | Section 7      |
    +------------+----------------------------------------------------+----------------+

1. The title of the document will be the *required* key to ``"rootFileTitle"`` given to
   ``exhale_args`` in ``conf.py``.  See :data:`exhale.configs.rootFileTitle`.

2. If provided, the value of the key ``"afterTitleDescription"`` given to
   ``exhale_args`` will be included.  See :data:`exhale.configs.afterTitleDescription`.

3. The Class Hierarchy will be included next.  By default this is a bulleted list; see
   the :ref:`usage_creating_the_treeview` section.

   .. note::

      This is performed by an ``.. include::`` directive.  The file for this section
      is ``"{containmentFolder}/class_view_hierarchy.rst"``.

4. Next, the File Hierarchy is included.  By default this is a bulleted list; see the
   :ref:`usage_creating_the_treeview` section.

   .. note::

      This is performed by an ``.. include::`` directive.  The file for this section
      is ``"{containmentFolder}/file_view_hierarchy.rst"``.

5. If provided, the value of the key ``"afterHierarchyDescription"`` given to
   ``exhale_args`` will be included.  See
   :data:`exhale.configs.afterHierarchyDescription`.

6. After the Class and File Hierarchies, the unabridged API index is generated.  The
   default title for this section is ``"Full API"``, but can be changed using the key
   ``"fullApiSubSectionTitle"`` in ``exhale_args``.  See
   :data:`exhale.configs.fullApiSubSectionTitle`.

7. After the title or default value for (6), the full API is included.  This includes
   links to things such as defines, functions, typedefs, etc. that are not included in
   the hierarchies.

   .. note::

      This is performed by an ``.. include::`` directive.  The file for this section
      is ``"{containmentFolder}/unabridged_api.rst"``.

   .. tip::

      The ``unabridged_api.rst`` performs a large number of ``.. toctree::`` directives
      to link up all of the documents.  You can control the number of bullets shown for
      each section be setting the key ``"fullToctreeMaxDepth"`` (e.g. to a smaller
      number such as ``2``).  See :data:`exhale.configs.fullToctreeMaxDepth`.

8. If provided, the value of the key ``"afterBodySummary"`` will be included at the
   bottom of the document.  See :data:`exhale.configs.afterBodySummary`.

.. tip::

   Where numbers (3), (4), and (7) are concerned, you should be able to happily ignore
   that an ``.. include::`` is being performed.  The URL for the page is strictly
   determined by what you specified with the *required* arguments
   ``"containmentFolder"`` and ``"rootFileName"``.  However, if things are not working
   as expected it is useful to know where to look.  The hierarchies in particular,
   though, may be challenging to understand if you do not know HTML (or JavaScript) and
   you are generating the Tree View.

.. end_root_api_document_layout

.. autodata:: exhale.configs.afterTitleDescription

.. autodata:: exhale.configs.afterHierarchyDescription

.. autodata:: exhale.configs.fullApiSubSectionTitle

.. autodata:: exhale.configs.afterBodySummary

.. autodata:: exhale.configs.fullToctreeMaxDepth

Clickable Hierarchies
****************************************************************************************

.. begin_clickable_hierarchies

As stated elsewhere, the primary reason for writing Exhale is to revive the Doxygen
Class and File hierarchies.  **The default behavior of Exhale is to simply insert
bulleted lists for these**.  This was originally because I had hoped to support other
Sphinx writers besides HTML, but that ship has pretty much sailed.  Now, the reason is
primarily because more information is required by the user depending on their HTML
theme.  Basically

1. If you are using any theme **other than** the `Sphinx Bootstrap Theme`__, simply add
   the argument ``"createTreeView": True`` to your ``exhale_args`` dictionary in
   ``conf.py``.  This will use the lightweight and surprisingly compatible
   collapsibleLists_ library for your clickable hierarchies.

   __ https://ryan-roemer.github.io/sphinx-bootstrap-theme

   .. _collapsibleLists: http://code.stephenmorley.org/javascript/collapsible-lists/

2. When using either the ``sphinx-bootstrap-theme``, or any other theme that
   incorporates Bootstrap, you will need to make sure to **also** set
   ``"treeViewIsBootstrap": True`` in your ``exhale_args`` dictionary in ``conf.py``
   **in addition to** ``"createTreeView": True``.  Exhale will then use the
   `Bootstrap Treeview`__ library to generate your clickable hierarchies.

   __ https://github.com/jonmiles/bootstrap-treeview

   .. note::

      See features available on ``bootstrap-treeview`` that you want access to?  Add
      your thoughts `on the issue <https://github.com/svenevs/exhale/issues/7>`_,
      explaining which feature you would want to be able to control.

      The currently available customizations :ref:`begin here <bootstrap_mods>`, but it
      shouldn't be too hard to add more.

   .. tip::

      You will see that many of the color, selection, and search options are **not**
      available to be customized for ``bootstrap-treeview``.  This is by design.
      See :data:`exhale.configs.treeViewBootstrapTextSpanClass`,
      :data:`exhale.configs.treeViewBootstrapIconMimicColor`, and
      :data:`exhale.configs.treeViewBootstrapOnhoverColor` for your color options.  The
      links are defined by your bootstrap theme's ``a`` tag color.

See the :ref:`index_credit` section for information on the licensing of these libraries.
Neither library should produce any legal gray areas for you, but I'm not a lawyer.

.. todo:: add some pictures of the different hierarchies once this is packaged

.. end_clickable_hierarchies

.. autodata:: exhale.configs.createTreeView

.. autodata:: exhale.configs.treeViewIsBootstrap

.. _bootstrap_mods:

.. autodata:: exhale.configs.treeViewBootstrapTextSpanClass

.. autodata:: exhale.configs.treeViewBootstrapIconMimicColor

.. autodata:: exhale.configs.treeViewBootstrapOnhoverColor

.. autodata:: exhale.configs.treeViewBootstrapUseBadgeTags

.. autodata:: exhale.configs.treeViewBootstrapExpandIcon

.. autodata:: exhale.configs.treeViewBootstrapCollapseIcon

.. autodata:: exhale.configs.treeViewBootstrapLevels

.. autodata:: exhale.configs._class_hierarchy_id

.. autodata:: exhale.configs._file_hierarchy_id

.. autodata:: exhale.configs._bstrap_class_hierarchy_fn_data_name

.. autodata:: exhale.configs._bstrap_file_hierarchy_fn_data_name


Page Level Customization
****************************************************************************************

.. begin_page_level_customization

Each page generated for a given "leaf-like" node (classes, structs, functions) will look
something like this, where special treatment is given to File pages specifically:

    +----------------------------------------------------------+-----------+
    | {{ pageLevelConfigMeta }}                                | Meta      |
    +----------------------------------------------------------+-----------+
    | {{ Node Title }}                                         | Heading   |
    +=======+==================================================+===========+
    | **1** | Definition {{ link to file or program listing }} | Section 1 |
    +-------+--------------------------------------------------+           |
    | **2** | {{ contentsDirectives }}                         |           |
    +-------+--------------------------------------------------+-----------+
    | {{ Kind Specific Exhale Links }}                         | Section 2 |
    +----------------------------------------------------------+-----------+
    | {{ Breathe Directive }}                                  | Section 3 |
    +----------------------------------------------------------+-----------+

**Meta**
    The page-level metadata is controlled by :data:`exhale.configs.pageLevelConfigMeta`.
    It is only included if provided.

**Heading**
    The internal reStructuredText link and page heading are included.  These are
    determined by the :class:`exhale.graph.ExhaleNode` object's ``link_name`` and
    ``title`` members, respectively.

**Section 1**
    **File Pages**
        1. If using Exhale to generate Doxygen on STDIN, the ``XML_PROGRAMLISTING``
           Doxygen variable is set to ``YES``, and an associated program listing page is generated for each file and linked to here.

           .. tip::

              The value of :data:`exhale.configs.doxygenStripFromPath` **directly**
              affects what path is displayed here.

           .. danger::

              If you override ``XML_PROGRAMLISTING = NO`` (or do not explicitly set it
              to ``YES`` if using alternative Doxygen generation methods),
              **significantly more** than just whether or not the program listing
              document is generated is affected.  There are numerous graph relationships
              that Exhale **cannot recover without the xml program listing**.

        2. See the :ref:`using_contents_directives` section.

        For File pages, the ``brief`` description of the File (if provided) is included
        in Section 1 underneath the title.

    **Other Pages**
        1. Assuming Exhale was able to infer which file defined a given node, a link to
           the file page that defined it is included here.

        2. See the :ref:`using_contents_directives` section.

**Section 2**
    **File Pages**
        At the beginning of section 2, the detailed description of the file is included
        if provided.

        Afterward, an enumeration of the files that this file ``#include`` s, as well as
        files that ``#include`` this file, is presented next.  Afterward, an enumeration
        by kind (namespaces, classes, functions, etc) that were defined in this file are
        included.

    **Other Pages**
        For many pages, section 2 will be blank.

        **Classes and Structs**
            Links to any nested classes (of this type, or the containing class if this
            is a nested type) are included.  Afterward, links to any base or derived
            classes are included.

            If :data:`exhale.configs.includeTemplateParamOrderList` is ``True``, the
            template parameter list enumeration is included next.

        **Namespaces**
            Namespaces will include an enumeration of everything that was determined to
            be a member of this namespace, listed by kind.  So things like nested
            namespaces, classes and structs, functions, etc.

**Section 3**
    **File Pages**
        If Exhale is producing unexpected output for file level documentation, you can
        set :data:`exhale.configs.generateBreatheFileDirectives` to ``True`` **as a
        debugging feature**.

        Please refer to the :ref:`doxygen_documentaion_specifics` section for potential
        causes, in particular the subsection describing
        :ref:`file_level_documentation_in_exhale`.

    **Namespaces**
        No Breathe directives for namespaces are used, as they will cause the same
        problems that the file directives do.

        .. todo::

           I have not explored acquiring namespace documentation from the Doxygen xml.
           This should be possible, but is currently not implemented.

    **Other Pages**
        For all other pages (except for directories, which simply link to subdirectories
        and files in that directory), this is where the Breathe directive is inserted.

        .. tip::

           See the :ref:`usage_customizing_breathe_output` section for how you can
           modify this section of a given document.

.. end_page_level_customization

.. autodata:: exhale.configs.includeTemplateParamOrderList

.. autodata:: exhale.configs.pageLevelConfigMeta

.. autodata:: exhale.configs.repoRedirectURL

Using Contents Directives
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

.. begin_page_level_customization_contents_directives

.. note::

   I put a lot of thought into the defaults for the ``.. contents::`` directive.  I
   believe the chosen defaults are optimal, but this is very much a personal decision.
   It also depends a lot on what ``html_theme`` you are using in ``conf.py``.  For
   example, the ``sphinx_rtd_theme`` (while classy) leaves a lot to the imagination
   where page-level navigation is concerned (and the page is long).

The `Contents Directive`__ can be used to display the table of contents on an individual
reStructuredText page.  This is **different** than the ``toctree`` directive in that
it is not specifying a list of documents to include next, it is simply informing the
reStructuredText parser (Sphinx in our case) that you would like a table of contents
displayed where this directive appears.

__ http://docutils.sourceforge.net/docs/ref/rst/directives.html#table-of-contents

By default, Exhale includes a ``.. contents::`` directive on all File and Namespace
pages.  This is particularly useful for making the Namespace and File pages navigable by
the reader of your documentation when the Namespace / File incorporates many parts of
the API.  Classes and structs have potential for a contents directive to be warranted
(e.g., complex inheritance relationships with nested types, core base types that every
class in the API inherits from).  If you have particular Classes or Structs that warrant
a ``.. contents::`` directive, you can enable this.  However, at this time, this is a
global setting for Exhale --- either all have it or none have it.  That said, the
presence of a ``.. contents::`` directive on simple class / struct pages doesn't seem to
be *too* distracting.

On the other hand, pages generated for things like Directories, Enums, Variables,
Defines, Typedefs, etc, are generally only as long as the documentation so they do
not receive a ``.. contents::`` directive by default.

The way Exhale is setup is to coordinate four variables:

1. :data:`exhale.configs.contentsDirectives` sets globally whether or not *any*
   ``.. contents::`` directives are generated.
2. :data:`exhale.configs.contentsTitle` determines the title of these directives.  The
   default is the reStructuredText default: ``Contents``.
3. :data:`exhale.configs.contentsSpecifiers` provides the specifications to apply to the
   ``.. contents::`` directives.  For stylistic reasons, the specifiers Exhale defaults
   to are ``:local:`` and ``:backlinks: none``.
4. :data:`exhale.configs.kindsWithContentsDirectives` specifies the kinds of compounds
   that will include a ``.. contents::`` directive.  The default is to only generate
   these for ``namespace`` and ``file``.

The implementation, if interested, is in :func:`exhale.utils.contentsDirectiveOrNone`.
Assuming you use all of the Exhale defaults, then every Namespace and File document will
include a directive like this:

.. code-block:: rst

   .. contents:: Contents
      :local:
      :backlinks: none

These defaults basically have two implications:

**The Effect of** ``:local:`` **on the Title**
    The ``:local:`` option states to only include the table of contents for the
    *remainder* of the page.  For Exhale, this means *do not include the title of the
    page*.

    When using ``:local:``, the title must be explicitly specified.  So if you set
    :data:`exhale.configs.contentsTitle` to the **empty string** (keeping all other
    defaults), the directive generated would be

    .. code-block:: rst

       .. contents::
          :local:
          :backlinks: none

    which results in a table of contents, without the word **Contents** before it.  This
    is likely a personal preference.

**The Effect of** ``:backlinks:``
    Traditional usage of a ``.. contents::`` directive, when ``:backlinks:`` is not
    explicitly specified, is to create circular links.  When considering writing a long
    document with many sections and subsections, this is exceptionally convenient.

    This means that when you click on a link in the generated table of contents, it
    takes you to the heading for that section.  The heading **is also a hyperlink**,
    which when clicked takes you back to the table of contents.

    I find this to be awkward for Exhale for two reasons:

    1. Section titles as hyperlinks, especially with Bootstrap, are quite unattractive.
    2. The circular linking is not exactly intuitive for code documentation.

Alas these are things that very much depend on *your personal preferences*, so I've done
my best to enable as much flexibility as possible.

.. end_page_level_customization_contents_directives

.. autodata:: exhale.configs.contentsDirectives

.. autodata:: exhale.configs.contentsTitle

.. autodata:: exhale.configs.contentsSpecifiers

.. autodata:: exhale.configs.kindsWithContentsDirectives

Breathe Customization
****************************************************************************************

.. begin_customizing_breathe_output

The directives for generating the documentation for a given node come from Breathe.
Exhale uses the Breathe defaults for all directives, **except** for Classes and Structs.
Suppose you are documenting a class ``namespace::ClassName``.  Exhale will produce
the following directive:

.. code-block:: rst

   .. doxygenclass:: namespace::ClassName
      :members:
      :protected-members:
      :undoc-members:

where the defaults being overridden are to include ``:protected-members:`` as well as
``:undoc-members:``.  You may, for example, want to also include ``:private-members:``
in your documentation, or override the `default settings for other Breathe directives`__
to control what is displayed.

__ http://breathe.readthedocs.io/en/latest/directives.html

In order to override these settings, a layer of indirection has to be added.  Because
Exhale is a Sphinx Extension, it needs to be possible to do something called "Pickle".
The short version of what this means is that you cannot give me a function directly
to call, because the Python function object cannot be pickled.  The solution is to use
the wrapper function I have created that takes your input function and stores all
possible inputs and outputs in a dictionary.  Details aside, it's easier than it sounds.

1. Define your custom specifications function in ``conf.py``.  In this example we'll be
   changing the specifications for the ``class``, ``struct``, and ``enum`` directives,
   and use the Breathe defaults for everything else:

   .. code-block:: py

      # somewhere in `conf.py`, *BERORE* declaring `exhale_args`
      def specificationsForKind(kind):
          '''
          For a given input ``kind``, return the list of reStructuredText specifications
          for the associated Breathe directive.
          '''
          # Change the defaults for .. doxygenclass:: and .. doxygenstruct::
          if kind == "class" or kind == "struct":
              return [
                ":members:",
                ":protected-members:",
                ":private-members:",
                ":undoc-members:"
              ]
          # Change the defaults for .. doxygenenum::
          elif kind == "enum":
              return [":no-link:"]
          # An empty list signals to Exhale to use the defaults
          else:
              return []

   .. tip::

      The full list of inputs your function will be called with are defined by
      :data:`exhale.utils.AVAILABLE_KINDS`.

2. Use Exhale's utility function to create the correct dictionary.  Below that function
   you can now do

   .. code-block:: py

      # Use exhale's utility function to transform `specificationsForKind`
      # defined above into something Exhale can use
      from exhale import utils
      exhale_args = {
          # ... required arguments / other configs ...
          "customSpecificationsMapping": utils.makeCustomSpecificationsMapping(
              specificationsForKind
          )
      }

   .. note::

      The parameter to :func:`exhale.utils.makeCustomSpecificationsMapping` is the
      **function** itself.

.. end_customizing_breathe_output

.. autodata:: exhale.configs.customSpecificationsMapping

.. autodata:: exhale.configs._closure_map_sanity_check

.. _configs_doxygen_execution_and_customization:

Doxygen Execution and Customization
****************************************************************************************

.. begin_doxygen_execution_and_customization

To have Exhale launch Doxygen when you run ``make html``, you will need to set
:data:`exhale.configs.exhaleExecutesDoxygen` to ``True``.  After setting that, you will
need to choose how Exhale is executing Doxygen.  If you already know what you are doing,
continue on.  If you've *never* used Doxygen before, skim this, but refer to the
:ref:`Mastering Doxygen <mastering_doxygen>` for more information on areas that you may
get confused by.

**Suggested Approach**
    Provide a (multiline) string to :data:`exhale.configs.exhaleDoxygenStdin`.  In the
    :ref:`usage_quickstart_guide`, the bare minimum needed to get things off the ground
    was used: ``INPUT`` must be set to tell Doxygen where to look.

    .. tip::

       If you set :data:`exhale.configs.verboseBuild` to ``True``, Exhale will print out
       exactly what it sends to Doxygen.

    Presumably just specifying ``INPUT`` will not be enough, particularly if the Doxygen
    preprocessor is not understanding your code.  Exhale uses a number of defaults
    to send to Doxygen as specified by :data:`exhale.configs.DEFAULT_DOXYGEN_STDIN_BASE`.
    The way these are used with your argument are as follows:

    .. code-block:: py

       # doxy_dir is the parent directory of what you specified in
       # `breathe_projects[breathe_default_project]` in `conf.py`
       internal_configs = textwrap.dedent('''
           # Tell doxygen to output wherever breathe is expecting things
           OUTPUT_DIRECTORY       = {out}
           # Tell doxygen to strip the path names (RTD builds produce long abs paths...)
           STRIP_FROM_PATH        = {strip}
       '''.format(out=doxy_dir, strip=configs.doxygenStripFromPath))

       # The configurations you specified
       external_configs = textwrap.dedent(configs.exhaleDoxygenStdin)

       # The full input being sent
       full_input = "{base}\n{external}\n{internal}\n\n".format(
           base=configs.DEFAULT_DOXYGEN_STDIN_BASE,
           external=external_configs,
           internal=internal_configs
       )

    In words, first the Exhale defaults are sent in.  Then your configurations, allowing
    you to override anything you need.  Last, the output directory and strip from path
    (specified elsewhere) are sent in.

    The error checking and warning logic seems pretty robust.  For example, suppose you
    need to add to the ``PREDEFINED`` to add a definition.  If you did something like

    .. code-block:: py

       import textwrap
       exhale_args = {
           # ... required args ...
           "exhaleExecutesDoxygen": True,
           "exhaleDoxygenStdin": textwrap.dedent('''
               INPUT      = ../include
               # Using `=` instead of `+=` overrides
               PREDEFINED = FOO="12"
           ''')
       }

    This will **override** the ``PREDEFINED`` section in the default configurations.
    Exhale will produce a warning encouraging you to ``+=``, but still continue.

**Using a Doxyfile**
    If you have your own customized ``Doxyfile``, just make sure it is in the same
    directory as ``conf.py``.  See the documentation for
    :data:`exhale.configs.exhaleUseDoxyfile` for items you need to make sure agree with
    the configurations you have applied elsewhere to Breathe / Exhale.

.. end_doxygen_execution_and_customization

.. autodata:: exhale.configs._doxygen_xml_output_directory

.. autodata:: exhale.configs.exhaleExecutesDoxygen

.. autodata:: exhale.configs.exhaleUseDoxyfile

.. autodata:: exhale.configs.exhaleDoxygenStdin

.. autodata:: exhale.configs.DEFAULT_DOXYGEN_STDIN_BASE

.. autodata:: exhale.configs.exhaleSilentDoxygen

Utility Variables
----------------------------------------------------------------------------------------

.. autodata:: exhale.configs.SECTION_HEADING

.. autodata:: exhale.configs.SUB_SECTION_HEADING

.. autodata:: exhale.configs.SUB_SUB_SECTION_HEADING

.. autodata:: exhale.configs._the_app

.. autodata:: exhale.configs._app_src_dir

Secondary Sphinx Entry Point
----------------------------------------------------------------------------------------

.. autofunction:: exhale.configs.apply_sphinx_configurations
