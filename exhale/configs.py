# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017, Stephen McDowell.                  #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                     https://github.com/svenevs/exhale/LICENSE.md                     #
########################################################################################
'''
The ``configs`` module exists to contain the Sphinx Application configurations specific
to this extension.  Almost every ``global`` variable defined in this file can be
modified using the ``exhale_args`` in ``conf.py``.  The convention for this file is as
follows:

1. Things that are **not** supposed to change, because their value is expected to be
   constant, are declared in ``ALL_CAPS``.  See

   - :data:`exhale.configs.SECTION_HEADING`
   - :data:`exhale.configs.SUB_SECTION_HEADING`
   - :data:`exhale.configs.SUB_SUB_SECTION_HEADING`
   - :data:`exhale.configs.DEFAULT_DOXYGEN_STDIN_BASE`

2. Internal / private variables that are **not** supposed to changed except for by this
   extension are declared as ``_lower_case_with_single_leading_underscore`` as is common
   in Python ;).

3. Every other variable is declared as ``camelCase``, indicating that it can be
   configured **indirectly** by using it as a key in the arguments to ``exhale_args``
   present in your ``conf.py``.  For example, one of the *required* arguments for this
   extension is :data:`exhale.configs.containmentFolder`.  This means that the key
   ``"containmentFolder"`` is *expected* to be present in ``exhale_args``.

   .. code-block:: py

      exhale_args = {
         "containmentFolder": "./api",
         # ...
      }

   Read the documentation for the various configs present to see what the various
   options are to modify the behavior of Exhale.
'''

import os
import textwrap
from sphinx.errors import ConfigError, ExtensionError

try:
    # Python 2 StringIO
    from cStringIO import StringIO
except ImportError:
    # Python 3 StringIO
    from io import StringIO

# __all__ = []

__name__ = "configs"
__docformat__ = "reStructuredText"

########################################################################################
##                                                                                     #
## Required configurations, these get set indirectly via the dictionary argument       #
## given to exhale in your conf.py.                                                    #
##                                                                                     #
########################################################################################
containmentFolder = None
'''
**Required**
    The location where Exhale is going to generate all of the reStructuredText documents.

**Value in** ``exhale_args`` (str)
    The value of key ``"containmentFolder"`` should be a string representing the
    (relative or absolute) path to the location where Exhale will be creating all of the
    files.  **Relative paths are relative to the Sphinx application source directory**,
    which is almost always wherever the file ``conf.py`` is.

    .. note::

       To better help you the user know what Exhale is generating (and therefore safe
       to delete), it is a **hard requirement** that ``containmentFolder`` is a
       **subdirectory** of the Sphinx Source Directory.  AKA the path ``"."`` will be
       rejected, but the path ``"./api"`` will be accepted.

       The suggested value for ``"containmentFolder"`` is ``"./api"``, or
       ``"./source/api"`` if you have separate source and build directories with Sphinx.
       When the html is eventually generated, this will make for a more human friendly
       url being generated.

    .. warning::

       The verbiage subdirectory means **direct** subdirectory.  So the path
       ``"./library/api"`` will be rejected.  This is because I make the assumption that
       ``containmentFolder`` is "owned" by Exhale / is safe to delete.
'''

rootFileName = None
'''
**Required**
    The name of the file that **you** will be linking to from your reStructuredText
    documents.  Do **not** include the ``containmentFolder`` path in this file name,
    Exhale will create the file ``"{contaimentFolder}/{rootFileName}"`` for you.

**Value in** ``exhale_args`` (str)
    The value of key ``"rootFileName"`` should be a string representing the name of
    the file you will be including in your top-level ``toctree`` directive.  In order
    for Sphinx to be happy, you should include a ``.rst`` suffix.  All of the generated
    API uses reStructuredText, and that will not ever change.

    For example, if you specify

    - ``"containmentFolder" = "./api"``, and
    - ``"rootFileName" = "library_root.rst"``

    Then exhale will generate the file ``./api/library_root.rst``.  You would then
    include this file in a ``toctree`` directive (say in ``index.rst``) with:

    .. code-block:: rst

       .. toctree:
          :maxdepth: 2

          api/library_root
'''

rootFileTitle = None
'''
**Required**
    The title to be written at the top of ``rootFileName``, which will appear in your
    file including it in the ``toctree`` directive.

**Value in** ``exhale_args`` (str)
    The value of the key ``"rootFileTitle"`` should be a string that has the title of
    the main library root document folder Exhale will be generating.  The user is
    required to supply this value because its value directly affects the overall
    presentation of your documentation.  For example, if you are including the Exhale
    generated library root file in your ``index.rst`` top-level ``toctree`` directive,
    the title you supply here will show up on both your main page, as well as in the
    navigation menus.

    An example value could be ``"Library API"``.
'''

doxygenStripFromPath = None
'''
**Required**
    When building on Read the Docs, there seem to be issues regarding the Doxygen
    variable ``STRIP_FROM_PATH`` when built remotely.  That is, it isn't stripped at
    all.  This value enables Exhale to manually strip the path.

**Value in** ``exhale_args`` (str)
    The value of the key ``"doxygenStripFromPath"`` should be a string representing the
    (relative or absolute) path to be stripped from the final documentation.  As with
    :data:`exhale.configs.containmentFolder`, relative paths are relative to the Sphinx
    source directory (where ``conf.py`` is).  Consider the following directory structure::

        my_project/
        ├───docs/
        │       conf.py
        │
        └───include/
            └───my_project/
                    common.hpp

    In this scenario, if you supplied ``"doxygenStripFromPath" = ".."``, then the file
    page for ``common.hpp`` would list its declaration as
    ``include/my_project/common.hpp``.  If you instead set it to be ``"../include"``,
    then the file page for ``common.hpp`` would list its declaration as just
    ``my_project/common.hpp``.

    As a consequence, modification of this variable directly affects what shows up in
    the file view hierarchy.  In the previous example, the difference would really just
    be whether or not all files are nestled underneath a global ``include`` folder or
    not.

    .. warning::

       It is **your** responsibility to ensure that the value you provide for this
       configuration is valid.  The file view hierarchy will almost certainly break if
       you give nonsense.

    .. note::

       Depending on your project layout, some links may be broken in the above example
       if you use ``"../include"`` that work when you use ``".."``.  To get your docs
       working, revert to ``".."``.  If you're feeling nice, raise an issue on GitHub
       and let me know --- I haven't been able to track this one down yet :/

       Particularly, this seems to happen with projects that have duplicate filenames
       in different folders, e.g.::

           include/
           └───my_project/
               │    common.hpp
               │
               └───viewing/
                       common.hpp
'''

########################################################################################
##                                                                                     #
## Additional configurations available to further customize the output of exhale.      #
##                                                                                     #
########################################################################################
# Build Process Logging, Colors, and Debugging                                         #
########################################################################################
verboseBuild = False
'''
**Optional**
    If you are having a hard time getting documentation to build, or say hierarchies are
    not appearing as they should be, set this to ``True``.

**Value in** ``exhale_args`` (bool)
    Set the boolean value to be ``True`` to include colorized printing at various stages
    of the build process.

    .. warning::

       There is only one level of verbosity: excessively verbose.  **All logging is
       written to** ``sys.stderr``.  See :data:`exhale.configs.alwaysColorize`.

    .. tip::

       Looking at the actual code of Exhale trying to figure out what is going on?  All
       logging sections have a comment ``# << verboseBuild`` just before the logging
       section.  So you can ``grep -r '# << verboseBuild' exhale/`` if you're working
       with the code locally.
'''

alwaysColorize = True
'''
**Optional**
    Exhale prints various messages throughout the build process to both ``sys.stdout``
    and ``sys.stderr``.  The default behavior is to colorize output always, regardless
    of if the output is being directed to a file.  This is because you can simply use
    ``cat`` or ``less -R``.  By setting this to ``False``, when redirecting output to
    a file the color will not be included.

**Value in** ``exhale_args`` (bool)
    The default is ``True`` because I find color to be something developers should
    embrace.  Simply use ``less -R`` to view colorized output conveniently.  While I
    have a love of all things color, I understand you may not.  So just set this to
    ``False``.

    .. note::

       There is not and will never be a way to remove the colorized logging from the
       console.  This only controls when ``sys.stdout`` and ``sys.stderr`` are being
       redirected to a file.
'''

generateBreatheFileDirectives = False
'''
**Optional**
    Append the ``.. doxygenfile::`` directive from Breathe for *every* file page
    generated in the API.

**Value in** ``exhale_args`` (bool)
    If True, then the breathe directive (``doxygenfile``) will be incorporated at the
    bottom of the file.

    .. warning::

       This feature is "deprecated" in lieu of minimal parsing of the input Doxygen xml
       for a given documented file.  This feature can be used to help determine if
       Exhale has made a mistake in parsing the file level documentation, but usage of
       this feature will create **many** duplicate id's and the Sphinx build process
       will be littered with complaints.

       **This feature is not intended for production release of pages, only debugging.**
'''

########################################################################################
# Root API Document Customization and Treeview                                         #
########################################################################################
afterTitleDescription = None
'''
**Optional**
    Provide a description to appear just after :data:`exhale.configs.rootFileTitle`.

**Value in** ``exhale_args`` (str)
    If you want to provide a brief summary of say the layout of the API, or call
    attention to specific classes, functions, etc, use this.  For example, if you had
    Python bindings but no explicit documentation for the Python side of the API, you
    could use something like

    .. code-block:: py

       exhale_args = {
           # ... other required arguments...
           "rootFileTitle": "Library API",
           "afterTitleDescription": textwrap.dedent(\'\'\'
              .. note::

              The following documentation presents the C++ API.  The Python API
              generally mirrors the C++ API, but some methods may not be available in
              Python or may perform different actions.
           \'\'\')
       }
'''

afterBodySummary = None
'''
**Optional**
    Provide a summary to be included at the bottom of the root library file.

**Value in** ``exhale_args`` (str)
    Similar to :data:`exhale.configs.afterTitleDescription`, only it is included at the
    bottom of the document.

    .. note::

       The root library document generated can be quite long, depending on your
       framework.  Important notes to developers should be included at the top of the
       file using :data:`exhale.configs.afterTitleDescription`.
'''

createTreeView = False
'''
**Optional**
    When set to ``True``, clickable hierarchies for the Class and File views will be
    generated.  **Set this variable to** ``True`` **if you are generating html** output
    for much more attractive websites!

**Value in** ``exhale_args`` (bool)
    When set to ``False``, the Class and File hierarches are just reStructuredText
    bullet lists.  This is rather unattractive, but the default of ``False`` is to
    hopefully enable non-html writers to still be able to use ``exhale``.

    .. tip::

       Using ``html_theme = "bootstrap"`` (the `Sphinx Bootstrap Theme`__)?  Make sure
       you set :data:`exhale.configs.treeViewIsBootstrap` to ``True``!

    __ https://ryan-roemer.github.io/sphinx-bootstrap-theme/
'''

treeViewIsBootstrap = False
'''
**Optional**
    If the generated html website is using ``bootstrap``, make sure to set this to
    ``True``.  The `Bootstrap Treeview`__ library will be used.

    __ http://jonmiles.github.io/bootstrap-treeview/

**Value in** ``exhale_args`` (bool)
    When set to ``True``, the clickable hierarchies will be generated using a Bootstrap
    friendly library.
'''

fullToctreeMaxDepth = 5
'''
**Optional**
    The generated library root document performs ``.. include:: unabridged_api.rst`` at
    the bottom, after the Class and File hierarchies.  Inside ``unabridged_api.rst``,
    every generated file is included using a ``toctree`` directive to prevent Sphinx
    from getting upset about documents not being included.  This value controls the
    ``:maxdepth:`` for all of these ``toctree`` directives.

**Value in** ``exhale_args`` (int)
    The default value is ``5``, but you may want to give a smaller value depending on
    the framework being documented.

    .. warning::

       This value must be greater than or equal to ``1``.  You are advised not to use
       a value greater than ``5``.
'''

########################################################################################
# Breathe Customization                                                                #
########################################################################################
customSpecificationsMapping = None

_closure_map_sanity_check = "blargh_BLARGH_blargh"
# See utils.makeCustomSpecificationsMapping, this is inserted to enforce exhale made the
# closures needed for pickling with sphinx.

########################################################################################
# Doxygen Execution and Customization                                                  #
########################################################################################
doxygenOutputDirectory = None
'''
The absolute path the the root level of the doxygen xml output.  If the path to the
``index.xml`` file created by doxygen was ``./doxyoutput/xml/index.xml``, then this
would simply be ``./doxyoutput/xml``.
'''

exhaleExecutesDoxygen = False

exhaleUseDoxyfile = False

exhaleDoxygenStdin = None

DEFAULT_DOXYGEN_STDIN_BASE = textwrap.dedent(r'''
    # If you need this to be YES, exhale will probably break.
    CREATE_SUBDIRS         = NO
    # So that only Doxygen does not trim paths, which affects the File hierarchy
    FULL_PATH_NAMES        = YES
    # Nested folders will be ignored without this.  You may not need it.
    RECURSIVE              = YES
    # Set to YES if you are debugging or want to compare.
    GENERATE_HTML          = NO
    # Unless you want it...
    GENERATE_LATEX         = NO
    # Both breathe and exhale need the xml.
    GENERATE_XML           = YES
    # Set to NO if you do not want the Doxygen program listing included.
    XML_PROGRAMLISTING     = YES
    # Allow for rst directives and advanced functions e.g. grid tables
    ALIASES                = "rst=\verbatim embed:rst:leading-asterisk"
    ALIASES               += "endrst=\endverbatim"
    # Enable preprocessing and related preprocessor necessities
    ENABLE_PREPROCESSING   = YES
    MACRO_EXPANSION        = YES
    EXPAND_ONLY_PREDEF     = NO
    SKIP_FUNCTION_MACROS   = NO
    # extra defs for to help with building the _right_ version of the docs
    PREDEFINED             = DOXYGEN_DOCUMENTATION_BUILD
    PREDEFINED            += DOXYGEN_SHOULD_SKIP_THIS
''')
'''
These are the default values sent to Doxygen along stdin when
:data:`exhale.configs.exhaleExecutesDoxygen` is ``True``.  This is sent to Doxygen
immediately **before** the :data:`exhale.configs.exhaleDoxygenStdin` provided to
``exhale_args`` in your ``conf.py``.  In this way, you can override any of the specific
defaults shown here.

.. tip::

   See the documentation for :data:`exhale.configs.exhaleDoxygenStdin`, as well as
   :data:`exhale.configs.exhaleUseDoxyfile`.  Only **one** may be provided to the
   ``exhale_args`` in your ``conf.py``.

.. include:: DEFAULT_DOXYGEN_STDIN_BASE_value.rst
'''

exhaleSilentDoxygen = False
'''
**Optional**
    When set to ``True``, the Doxygen output is omitted from the build.

**Value in** ``exhale_args`` (bool)
    Documentation generation can be quite verbose, especially when running both Sphinx
    and Doxygen in the same process.  Use this to silence Doxygen.

    .. danger::

       You are **heavily** discouraged from setting this to ``True``.  Many problems
       that may arise through either Exhale or Breathe are because the Doxygen
       documentation itself has errors.  It will be much more difficult to find these
       when you squelch the Doxygen output.

       The reason you would do this is for actual limitations on your specific
       ``stdout`` (e.g. you are getting a buffer maxed out).  The likelihood of this
       being a problem for you is exceptionally small.
'''

########################################################################################
##                                                                                     #
## Utility variables.                                                                  #
##                                                                                     #
########################################################################################
SECTION_HEADING = "=" * 88
''' The restructured text file heading separator (``"=" * 88``). '''

SUB_SECTION_HEADING = "-" * 88
''' The restructured text section heading separator (``"-" * 88``). '''

SUB_SUB_SECTION_HEADING = "*" * 88
''' The restructured text sub-section heading separator (``"*" * 88``).'''

_the_app = None
''' The Sphinx ``app`` object.  Currently unused, saved for availability in future. '''

_app_src_dir = None
'''
**Do not modify**.  The location of ``app.srcdir`` of the Sphinx application, once the
build process has begun to execute.  Saved to be able to run a few different sanity
checks in different places.
'''


########################################################################################
##                                                                                     #
## Secondary Sphinx Entry Point                                                        #
## Called from exhale/__init__.py:environment_ready during the sphinx build process.   #
##                                                                                     #
########################################################################################
def apply_sphinx_configurations(app):
    '''
    This method applies the various configurations users place in their ``conf.py``, in
    the dictionary ``exhale_args``.  The error checking seems to be robust, and
    borderline obsessive, but there may very well be some glaring flaws.

    When the user requests for the ``treeView`` to be created, this method is also
    responsible for adding the various CSS / JavaScript to the Sphinx Application
    to support the hierarchical views.

    .. danger::

       This method is **not** supposed to be called directly.  See
       ``exhale/__init__.py`` for how this function is called indirectly via the Sphinx
       API.

    **Parameters**
        ``app`` (:class:`sphinx.application.Sphinx`)
            The Sphinx Application running the documentation build.
    '''
    # Import local to function to prevent circular imports elsewhere in the framework.
    from . import deploy
    from . import utils
    ####################################################################################
    # Make sure they have the `breathe` configs setup in a way that we can use them.   #
    ####################################################################################
    # Breathe allows users to have multiple projects to configure in one `conf.py`
    # A dictionary of keys := project names, values := path to Doxygen xml output dir
    breathe_projects = app.config.breathe_projects
    if not breathe_projects:
        raise ConfigError("You must set the `breathe_projects` in `conf.py`.")
    elif type(breathe_projects) is not dict:
        raise ConfigError("The type of `breathe_projects` in `conf.py` must be a dictionary.")
    # The breathe_default_project is required by `exhale` to determine where to look for
    # the doxygen xml.
    #
    # TODO: figure out how to allow multiple breathe projects?
    breathe_default_project = app.config.breathe_default_project
    if not breathe_default_project:
        raise ConfigError("You must set the `breathe_default_project` in `conf.py`.")
    elif type(breathe_default_project) is not str:
        raise ConfigError("The type of `breathe_default_project` must be a string.")

    if breathe_default_project not in breathe_projects:
        raise ConfigError(
            "The given breathe_default_project='{0}' was not a valid key in `breathe_projects`:\n{1}".format(
                breathe_default_project, breathe_projects
            )
        )

    # Grab where the Doxygen xml output is supposed to go, make sure it is a string,
    # defer validation of existence until after potentially running Doxygen based on
    # the configs given to exhale
    doxy_xml_dir = breathe_projects[breathe_default_project]
    if type(doxy_xml_dir) is not str:
        raise ConfigError(
            "The type of `breathe_projects[breathe_default_project]` from `conf.py` was not a string."
        )

    ####################################################################################
    # Initial sanity-check that we have the arguments needed.                          #
    ####################################################################################
    exhale_args = app.config.exhale_args
    if not exhale_args:
        raise ConfigError("You must set the `exhale_args` dictionary in `conf.py`.")
    elif type(exhale_args) is not dict:
        raise ConfigError("The type of `exhale_args` in `conf.py` must be a dictionary.")

    ####################################################################################
    # In order to be able to loop through things below, we want to grab the globals    #
    # dictionary (rather than needing to do `global containmentFolder` etc for every   #
    # setting that is being changed).                                                  #
    ####################################################################################
    configs_globals = globals()
    # At the end of input processing, fail out if unrecognized keys were found.
    keys_processed = []

    ####################################################################################
    # Gather the mandatory input for exhale.                                           #
    ####################################################################################
    key_error = "Did not find required key `{key}` in `exhale_args`."
    val_error = "The type of the value for key `{key}` must be `{exp}`, but was `{got}`."

    req_kv = [
        ("containmentFolder",    str,  True),
        ("rootFileName",         str, False),
        ("rootFileTitle",        str, False),
        ("doxygenStripFromPath", str,  True)
    ]
    for key, expected_type, make_absolute in req_kv:
        # Make sure we have the key
        if key not in exhale_args:
            raise ConfigError(key_error.format(key=key))
        # Make sure the value is at the very least the correct type
        val   = exhale_args[key]
        val_t = type(val)
        if val_t is not expected_type:
            raise ConfigError(val_error.format(key=key, exp=expected_type, got=val_t))
        # Make sure that a value was provided (e.g. no empty strings)
        if not val:
            raise ConfigError("Non-empty value for key [{0}] required.".format(key))
        # If the string represents a path, make it absolute
        if make_absolute:
            val = os.path.abspath(val)
        # Set the config for use later
        try:
            configs_globals[key] = val
            keys_processed.append(key)
        except Exception as e:
            raise ExtensionError(
                "Critical error: unable to set `global {0}` to `{1}` in exhale.configs:\n{2}".format(
                    key, val, e
                )
            )

    ####################################################################################
    # Validate what can be checked from the required arguments at this time.           #
    ####################################################################################
    global _the_app
    _the_app = app

    # Make sure they know this is a bad idea.  The order of these checks is important.
    # This assumes the path given was not the empty string (3 will break if it is).
    #
    # 1. If containmentFolder and app.srcdir are the same, problem.
    # 2. If app.srcdir is not at the beginning of containmentFolder, problem.
    # 3. If the first two checks have not raised a problem, the final check is to make
    #    sure that a subdirectory was actually used, as opposed to something that just
    #    starts with the same path.
    #
    #    Note for the third check lazy evaluation is the only thing that makes checking
    #    _parts[1] acceptable ;)
    _one     = containmentFolder == app.srcdir
    _two     = not containmentFolder.startswith(app.srcdir)
    _abs_rel = os.path.abspath(os.path.relpath(containmentFolder, app.srcdir))
    _parts   = _abs_rel.split(app.srcdir)
    _three   = _parts[0] != "" or len(_parts[1].split(os.path.sep)) > 2 or \
                   os.path.join(app.srcdir, _parts[1].replace(os.path.sep, "", 1)) != containmentFolder  # noqa
    # If they are equal, containmentFolder points somewhere entirely differently, or the
    # relative path (made absolute again) does not have the srcdir
    if _one or _two or _three:
        raise ConfigError(
            "The given `containmentFolder` must be a *SUBDIRECTORY* of [{0}].".format(
                app.srcdir
            )
        )

    global _app_src_dir
    _app_src_dir = os.path.abspath(app.srcdir)

    # We *ONLY* generate reStructuredText, make sure Sphinx is expecting this as well as
    # the to-be-generated library root file is correctly suffixed.
    if not rootFileName.endswith(".rst"):
        raise ConfigError(
            "The given `rootFileName` ({0}) did not end with '.rst'; Exhale is reStructuredText only.".format(
                rootFileName
            )
        )
    if ".rst" not in app.config.source_suffix:
        raise ConfigError(
            "Exhale is reStructuredText only, but '.rst' was not found in `source_suffix` list of `conf.py`."
        )

    # Make sure the doxygen strip path is an exclude-able path
    if not os.path.exists(doxygenStripFromPath):
        raise ConfigError(
            "The path given as `doxygenStripFromPath` ({0}) does not exist!".format(doxygenStripFromPath)
        )

    ####################################################################################
    # Gather the optional input for exhale.                                            #
    ####################################################################################
    opt_kv = [
        ("verboseBuild",                  bool),
        ("alwaysColorize",                bool),
        ("afterTitleDescription",         str),
        ("createTreeView",                bool),
        ("treeViewIsBootstrap",           bool),
        ("fullToctreeMaxDepth",           int),
        ("customSpecificationsMapping",   dict),
        ("exhaleExecutesDoxygen",         bool),
        ("exhaleUseDoxyfile",             bool),
        ("exhaleDoxygenStdin",            str),
        ("exhaleSilentDoxygen",           bool),
        ("generateBreatheFileDirectives", bool)
    ]
    for key, expected_type in opt_kv:
        # Override the default settings if the key was provided
        if key in exhale_args:
            # Make sure the value is at the very least the correct type
            val   = exhale_args[key]
            val_t = type(val)
            if val_t is not expected_type:
                raise ConfigError(val_error.format(key=key, exp=expected_type, got=val_t))
            # Set the config for use later
            try:
                configs_globals[key] = val
                keys_processed.append(key)
            except Exception as e:
                raise ExtensionError(
                    "Critical error: unable to set `global {0}` to `{1}` in exhale.configs:\n{2}".format(
                        key, val, e
                    )
                )

    ####################################################################################
    # See if unexpected keys were presented.                                           #
    ####################################################################################
    all_keys = set(exhale_args.keys())
    keys_processed = set(keys_processed)
    if all_keys != keys_processed:
        # Much love: https://stackoverflow.com/a/17388505/3814202
        from difflib import SequenceMatcher

        def similar(a, b):
            return SequenceMatcher(None, a, b).ratio() * 100.0

        # If there are keys left over after taking the differences of keys_processed
        # (which is all keys Exhale expects to see), inform the user of keys they might
        # have been trying to provide.
        extras = all_keys - keys_processed
        extra_error = StringIO()
        extra_error.write("Exhale found unexpected keys in `exhale_args`:\n")
        for key in extras:
            extra_error.write("  - Extra key: {0}\n".format(key))
            potentials = []
            for mate in keys_processed:
                similarity = similar(key, mate)
                if similarity > 40.0:
                    potentials.append((similarity, mate))
            if potentials:
                potentials = reversed(sorted(potentials))
                for rank, mate in potentials:
                    extra_error.write("    - {0:2.2f}% match with: {1}\n".format(rank, mate))

        extra_error_str = extra_error.getvalue()
        extra_error.close()
        raise ConfigError(extra_error_str)

    ####################################################################################
    # Verify some potentially inconsistent or ignored settings.                        #
    ####################################################################################
    # treeViewIsBootstrap only takes meaning when createTreeView is True
    if not createTreeView and treeViewIsBootstrap:
        app.warn("Exhale: `treeViewIsBootstrap=True` ignored since `createTreeView=False`")

    # fullToctreeMaxDepth > 5 may produce other sphinx issues unrelated to exhale
    if fullToctreeMaxDepth > 5:
        app.warn(
            "Exhale: `fullToctreeMaxDepth={0}` is greater than 5 and may build errors for non-html.".format(
                fullToctreeMaxDepth
            )
        )

    # Make sure that we received a valid mapping created by utils.makeCustomSpecificationsMapping
    sanity = _closure_map_sanity_check
    insane = "`customSpecificationsMapping` *MUST* be made using  exhale.utils.makeCustomSpecificationsMapping"
    if customSpecificationsMapping:
        # Sanity check to make sure exhale made this mapping
        if sanity not in customSpecificationsMapping:
            raise ConfigError(insane)
        elif customSpecificationsMapping[sanity] != sanity:  # LOL
            raise ConfigError(insane)
        # Sanity check #2: enforce no new additions were made
        expected_keys = set([sanity]) | set(utils.AVAILABLE_KINDS)
        provided_keys = set(customSpecificationsMapping.keys())
        diff = provided_keys - expected_keys
        if diff:
            raise ConfigError("Found extra keys in `customSpecificationsMapping`: {0}".format(diff))
        # Sanity check #3: make sure the return values are all strings
        for key in customSpecificationsMapping:
            val_t = type(customSpecificationsMapping[key])
            if val_t is not str:
                raise ConfigError(
                    "`customSpecificationsMapping` key `{key}` gave value type `{val_t}` (need `str`).".format(
                        key=key, val_t=val_t
                    )
                )

    # Specify where the doxygen output should be going
    global doxygenOutputDirectory
    doxygenOutputDirectory = doxy_xml_dir

    # If requested, the time is nigh for executing doxygen.  The strategy:
    # 1. Execute doxygen if requested
    # 2. Verify that the expected doxy_xml_dir (specified to `breathe`) was created
    # 3. Assuming everything went to plan, let exhale take over and create all of the .rst docs
    if exhaleExecutesDoxygen:
        # Cannot use both, only one or the other
        if exhaleUseDoxyfile and (exhaleDoxygenStdin is not None):
            raise ConfigError("You must choose one of `exhaleUseDoxyfile` or `exhaleDoxygenStdin`, not both.")

        # The Doxyfile *must* be at the same level as conf.py
        # This is done so that when separate source / build directories are being used,
        # we can guarantee where the Doxyfile is.
        if exhaleUseDoxyfile:
            doxyfile_path = os.path.abspath(os.path.join(app.confdir, "Doxyfile"))
            if not os.path.exists(doxyfile_path):
                raise ConfigError("The file [{0}] does not exist".format(doxyfile_path))

        here = os.path.abspath(os.curdir)
        if here == app.confdir:
            returnPath = None
        else:
            returnPath = here

        # All necessary information ready, go to where the Doxyfile is, run Doxygen
        # and then return back (where applicable) so sphinx can continue
        if returnPath:
            app.info(utils.info(
                "Exhale: changing directories to [{0}] to execute Doxygen.".format(app.confdir)
            ))
            os.chdir(app.confdir)
        app.info(utils.info("Exhale: executing doxygen."))
        status = deploy.generateDoxygenXML()
        # Being overly-careful to put sphinx back where it was before potentially erroring out
        if returnPath:
            app.info(utils.info(
                "Exhale: changing directories back to [{0}] after Doxygen.".format(returnPath)
            ))
            os.chdir(returnPath)
        if status:
            raise ExtensionError(status)
        else:
            app.info(utils.progress("Exhale: doxygen ran successfully!"))
    else:
        if exhaleUseDoxyfile:
            app.warn("Exhale: `exhaleUseDoxyfile` ignored since `exhaleExecutesDoxygen=False`")
        if exhaleDoxygenStdin is not None:
            app.warn("Exhale: `exhaleDoxygenStdin` ignored since `exhaleExecutesDoxygen=False`")
        if exhaleSilentDoxygen:
            app.warn("Exhale: `exhaleSilentDoxygen=True` ignored since `exhaleExecutesDoxygen=False`")

    # Either Doxygen was run prior to this being called, or we just finished running it.
    # Make sure that the files we need are actually there.
    if not os.path.isdir(doxy_xml_dir):
        raise ConfigError(
            "Exhale: the specified folder [{0}] does not exist.  Has Doxygen been run?".format(doxy_xml_dir)
        )
    index = os.path.join(doxy_xml_dir, "index.xml")
    if not os.path.isfile(index):
        raise ConfigError("Exhale: the file [{0}] does not exist.  Has Doxygen been run?".format(index))

    # Legacy / debugging feature, warn of its purpose
    if generateBreatheFileDirectives:
        app.warn("Exhale: `generateBreatheFileDirectives` is a debugging feature not intended for production.")

    ####################################################################################
    # If using a fancy treeView, add the necessary frontend files.                     #
    ####################################################################################
    if createTreeView:
        if treeViewIsBootstrap:
            tree_data_static_base = "treeView-bootstrap"
            tree_data_css = [os.path.join("bootstrap-treeview", "bootstrap-treeview.min.css")]
            tree_data_js  = [
                os.path.join("bootstrap-treeview", "bootstrap-treeview.min.js"),
                # os.path.join("bootstrap-treeview", "apply-bootstrap-treview.js")
            ]
            tree_data_ext = []
        else:
            tree_data_static_base = "treeView"
            tree_data_css = [os.path.join("collapsible-lists", "css", "tree_view.css")]
            tree_data_js  = [
                os.path.join("collapsible-lists", "js", "CollapsibleLists.compressed.js"),
                os.path.join("collapsible-lists", "js", "apply-collapsible-lists.js")
            ]
            # The tree_view.css file uses these
            tree_data_ext = [
                os.path.join("collapsible-lists", "css", "button-closed.png"),
                os.path.join("collapsible-lists", "css", "button-open.png"),
                os.path.join("collapsible-lists", "css", "button.png"),
                os.path.join("collapsible-lists", "css", "list-item-contents.png"),
                os.path.join("collapsible-lists", "css", "list-item-last-open.png"),
                os.path.join("collapsible-lists", "css", "list-item-last.png"),
                os.path.join("collapsible-lists", "css", "list-item-open.png"),
                os.path.join("collapsible-lists", "css", "list-item.png"),
                os.path.join("collapsible-lists", "css", "list-item-root.png"),
            ]

        # Make sure we have everything we need
        collapse_data = os.path.join(os.path.abspath(os.path.dirname(__file__)), "data", tree_data_static_base)
        if not os.path.isdir(collapse_data):
            raise ExtensionError(
                "Exhale: the path to [{0}] was not found, possible installation error.".format(collapse_data)
            )
        else:
            all_files = tree_data_css + tree_data_js + tree_data_ext
            missing   = []
            for file in all_files:
                path = os.path.join(collapse_data, file)
                if not os.path.isfile(path):
                    missing.append(path)
            if missing:
                raise ExtensionError(
                    "Exhale: the path(s) {0} were not found, possible installation error.".format(missing)
                )

        # We have all the files we need, the extra files will be copied automatically by
        # sphinx to the correct _static/ location, but stylesheets and javascript need
        # to be added explicitly
        app.info(utils.info("Exhale: adding tree view css / javascript."))
        app.config.html_static_path.append(collapse_data)

        # Add the stylesheets
        for css in tree_data_css:
            app.add_stylesheet(css)

        # Add the javascript
        for js in tree_data_js:
            app.add_javascript(js)
