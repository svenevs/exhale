# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017, Stephen McDowell.                  #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                     https://github.com/svenevs/exhale/LICENSE.md                     #
########################################################################################

from . import configs
from . import utils
from .graph import ExhaleRoot

import os
import sys
import re
import tempfile
import textwrap
from subprocess import PIPE, Popen


__all__       = ["explode"]
__name__      = "deploy"
__docformat__ = "reStructuredText"


def _generate_doxygen(doxygen_input):
    '''
    This method executes doxygen based off of the specified input.  Two versions of the
    doxygen command can be executed:

    1. If ``doxygen_input`` is exactly ``"Doxyfile"``, then it is assumed that a
       ``Doxyfile`` exists in the **current working directory**.  Meaning the command
       being executed is simply ``doxygen``.
    2. For all other values, ``doxygen_input`` represents the arguments as to be
       specified on ``stdin`` to the process.

    .. tip::

       This function is not intended to be used by external APIs.  If you are using
       ``exhale`` to generate the ``doxygen`` documentation, refer to the

       .. todo::

          WHERE IS THIS DOCUMENTED NOW?

    ``Parameters``
        ``doxygen_input`` (str)
            Either the string ``"Doxyfile"`` to run vanilla ``doxygen``, or the
            selection of doxygen inputs (that would ordinarily be in a ``Doxyfile``)
            that will be ``communicate``d to the ``doxygen`` process on ``stdin``.

    .. note::

       If using Python **3**, the input **must** still be a ``str``.  This method
       will convert the input to ``bytes`` as follows:

       .. code-block:: py

          if sys.version[0] == "3":
              doxygen_input = bytes(doxygen_input, "ASCII")

    ``Return``
        ``str`` or ``None``
            If an error occurs, a string describing the error is returned with the
            intention of the caller raising the exception.  If ``None`` is returned,
            then the process executed without error.  Example usage:

            .. code-block:: py

               status = _generate_doxygen("Doxygen")
               if status:
                   raise RuntimeError(status)

            Though a little awkward, this is done to enable the intended caller of this
            method to restore some state before exiting the program (namely, the working
            directory before propagating an exception to ``sphinx-build``).
    '''
    if type(doxygen_input) is not str:
        return "Error: the `doxygen_input` variable must be of type `str`."

    doxyfile = doxygen_input == "Doxyfile"
    try:
        # TL;DR: strictly enforce that (verbose) doxygen output doesn't cause the
        # `communicate` to hang due to buffer overflows.
        #
        # See excellent synopsis:
        # https://thraxil.org/users/anders/posts/2008/03/13/Subprocess-Hanging-PIPE-is-your-enemy/
        _, tmp_out_path = tempfile.mkstemp(prefix="exhale_launched_doxygen_buff")
        _, tmp_err_path = tempfile.mkstemp(prefix="exhale_launched_doxygen_buff")
        tmp_out         = open(tmp_out_path, "r+")  # read/write (read after communicate)
        tmp_err         = open(tmp_err_path, "r+")

        # Setup the arguments to launch doxygen
        if doxyfile:
            args   = ["doxygen"]
            kwargs = {}
        else:
            args   = ["doxygen", "-"]
            kwargs = {"stdin": PIPE}
        # Write to the tempfiles over PIPE to avoid buffer overflowing
        kwargs["stdout"] = tmp_out
        kwargs["stderr"] = tmp_err

        # Note: overload of args / kwargs, Popen is expecting a list as the first
        #       parameter (aka no *args, just args)!
        doxygen_proc = Popen(args, **kwargs)

        # Communicate can only be called once, arrange whether or not stdin has value
        if not doxyfile:
            # In Py3, make sure we are communicating a bytes-like object which is no
            # longer interchangeable with strings (as was the case in Py2).
            if sys.version[0] == "3":
                doxygen_input = bytes(doxygen_input, "ASCII")
            comm_kwargs = {"input": doxygen_input}
        else:
            comm_kwargs = {}

        # Waits until doxygen has completed
        doxygen_proc.communicate(**comm_kwargs)

        # Print out what was written to the tmpfiles by doxygen
        if not configs.exhaleSilentDoxygen:
            # Doxygen output (some useful information, mostly just enumeration of the
            # configurations you gave it {usefule for debugging...})
            if os.path.getsize(tmp_out_path) > 0:
                tmp_out.seek(0)
                print(tmp_out.read())
            # Doxygen error (e.g. any warnings, or invalid input)
            if os.path.getsize(tmp_err_path) > 0:
                # Making them stick out, ideally users would reduce this output to 0 ;)
                # This will print a yellow [~] before every line, but not make the
                # entire line yellow because it's definitively not helpful
                # Hack: empty string to utils.info will not give us anything, inserting
                #       a null character will xD
                prefix = utils.info("\0", utils.AnsiColors.BOLD_YELLOW, sys.stderr)
                tmp_err.seek(0)
                sys.stderr.write(utils.prefix(prefix, tmp_err.read()))

        # Delete the tmpfiles
        tmp_out.close()
        tmp_err.close()
        os.remove(tmp_out_path)
        os.remove(tmp_err_path)

        # Make sure we had a valid execution of doxygen
        exit_code = doxygen_proc.returncode
        if exit_code != 0:
            raise RuntimeError("Non-zero return code of [{0}] from 'doxygen'...".format(exit_code))
    except Exception as e:
        return "Unable to execute 'doxygen': {0}".format(e)

    # returning None signals _success_
    return None


def _valid_config(config, required):
    '''
    .. todo:: add documentation of this method

    ``config``: doxygen input we're looking for
    ``required``: if ``True``, must be present.  if ``False``, NOT ALLOWED to be present
    '''
    re_template = r"\s*{config}\s*=.*".format(config=config)
    found = re.search(re_template, configs.exhaleDoxygenStdin)
    if required:
        return found is not None
    else:
        return found is None


def generateDoxygenXML():
    # If this happens, we really shouldn't be here...
    if not configs.exhaleExecutesDoxygen:
        return textwrap.dedent('''
            `generateDoxygenXML` should *ONLY* be called internally.  You should
            set `exhaleExecutesDoxygen=True` in `exhale_args` in `conf.py`.
        ''')

    # Case 1: the user has their own `Doxyfile`.
    if configs.exhaleUseDoxyfile:
        return _generate_doxygen("Doxyfile")
    # Case 2: use stdin, with some defaults and potentially additional specs from user
    else:
        # There are two doxygen specs that we explicitly disallow
        #
        # 1. OUTPUT_DIRECTORY: this is *ALREADY* specified implicitly via breathe
        # 2. STRIP_FROM_PATH: this is a *REQUIRED* config (`doxygenStripFromPath`)
        #
        # There is one doxygen spec that is REQUIRED to be given:
        #
        # 1. INPUT (where doxygen should parse).
        #
        # The below is a modest attempt to validate that these were / were not given.
        if type(configs.exhaleDoxygenStdin) is not str:
            return "`exhaleDoxygenStdin` config must be a string!"

        if not _valid_config("OUTPUT_DIRECTORY", False):
            # If we are hitting this code, these should both exist and be configured
            # since this method is called **AFTER** the configuration verification code
            # performed in configs.apply_sphinx_configurations
            breathe_projects = configs._the_app.config.breathe_projects
            breathe_default_project = configs._the_app.config.breathe_default_project
            return textwrap.dedent('''
                `exhaleDoxygenStdin` may *NOT* specify `OUTPUT_DIRECTORY`.  Exhale does
                this internally by reading what you provided to `breathe_projects` in
                your `conf.py`.

                Based on what you had in `conf.py`, Exhale will be using

                - The `breathe_default_project`:

                      {default}

                - The output path specfied (`breathe_projects[breathe_default_project]`):

                      {path}

                  NOTE: the above path has the `xml` portion removed from what you
                        provided.  This path is what is sent to Doxygen, Breathe
                        requires you include the `xml` directory path; so Exhale simply
                        re-uses this variable and adapts the value for our needs.
            '''.format(
                default=breathe_default_project,
                path=breathe_projects[breathe_default_project].rsplit("{sep}xml".format(sep=os.sep), 1)[0]
            ))

        if not _valid_config("STRIP_FROM_PATH", False):
            return textwrap.dedent('''
                `exhaleDoxygenStdin` may *NOT* specify `STRIP_FROM_PATH`.  Exhale does
                this internally by using the value you provided to `exhale_args` in
                your `conf.py` for the key `doxygenStripFromPath`.

                Based on what you had in `conf.py`, Exhale will be using:

                    {strip}

                NOTE: the above is what you specified directly in `exhale_args`.  Exhale
                      will be using an absolute path to send to Doxygen.  It is:

                    {absolute}
            '''.format(
                strip=configs._the_app.config.exhale_args["doxygenStripFromPath"],
                absolute=configs.doxygenStripFromPath
            ))

        if not _valid_config("INPUT", True):
            return textwrap.dedent('''
                `exhaleDoxygenStdin` *MUST* specify the `INPUT` doxygen config variable.
                The INPUT variable is what tells Doxygen where to look for code to
                extract documentation from.  For example, if you had a directory layout

                    project_root/
                        docs/
                            conf.py
                            Makefile
                            ... etc ...
                        include/
                            my_header.hpp
                        src/
                            my_header.cpp

                Then you would include the line

                    INPUT = ../include

                in the string provided to `exhale_args["exhaleDoxygenStdin"]`.
            ''')

        # For these, we just want to warn them of the impact but still allow an override
        re_template = r"\s*{config}\s*=\s*(.*)"
        for cfg in ("ALIASES", "PREDEFINED"):
            found = re.search(re_template.format(config=cfg), configs.exhaleDoxygenStdin)
            if found:
                sys.stderr.write(utils.info(textwrap.dedent('''
                    You have supplied to `exhaleDoxygenStdin` a configuration of:

                        {cfg}   =   {theirs}

                    This has an important impact, as it overrides a default setting that
                    Exhale is using.

                    1. If you are intentionally overriding this configuration, simply
                       ignore this message --- what you intended will happen.

                    2. If you meant to _continue_ adding to the defaults Exhale provides,
                       you need to use a `+=` instead of a raw `=`.  So do instead

                           {cfg}   +=   {theirs}

                '''.format(cfg=cfg, theirs=found.groups()[0])), utils.AnsiColors.BOLD_YELLOW))

        # Include their custom doxygen definitions after the defaults so that they can
        # override anything they want to.  Populate the necessary output dir and strip path.
        doxy_dir = configs.doxygenOutputDirectory.rsplit("{sep}xml".format(sep=os.sep), 1)[0]
        internal_configs = textwrap.dedent('''
            # Tell doxygen to output wherever breathe is expecting things
            OUTPUT_DIRECTORY       = {out}
            # Tell doxygen to strip the path names (RTD builds produce long abs paths...)
            STRIP_FROM_PATH        = {strip}
        '''.format(out=doxy_dir, strip=configs.doxygenStripFromPath))
        external_configs = textwrap.dedent(configs.exhaleDoxygenStdin)
        # Place external configs last so that if the _valid_config method isn't actually
        # catching what it should be, the internal configs will override theirs
        full_input = "{base}\n{external}\n{internal}\n\n".format(base=configs.DEFAULT_DOXYGEN_STDIN_BASE,
                                                                 external=external_configs,
                                                                 internal=internal_configs)

        # << verboseBuild
        if configs.verboseBuild:
            msg = "[*] The following input will be sent to Doxygen:\n"
            if not configs.alwaysColorize and not sys.stderr.isatty():
                sys.stderr.write(msg)
                sys.stderr.write(full_input)
            else:
                sys.stderr.write(utils.colorize(msg, utils.AnsiColors.BOLD_CYAN))
                sys.stderr.write(utils.__fancy(full_input, "make", "console"))

        return _generate_doxygen(full_input)


########################################################################################
#
##
###
####
##### Primary entry point.
####
###
##
#
########################################################################################
def explode():
    '''
    The main entry point to exhale, which parses and generates the full API.

    :Parameters:
        ``exhaleArgs`` (dict)
            The dictionary of arguments to configure exhale with.  All keys are strings,
            and most values should also be strings.  See below.

    **Required Entries:**

    **key**: ``"doxygenIndexXMLPath"`` --- value type: ``str``
        The absolute or relative path to where the Doxygen index.xml is.  A relative
        path must be relative to the file **calling** exhale.

    **key**: ``"containmentFolder"`` --- value type: ``str``
        The folder the generated API will be created in.  If the folder does not exist,
        exhale will create the folder.  The path can be absolute, or relative to the
        file that is **calling** exhale.  For example, ``"./generated_api"``.

    **key**: ``"rootFileName"`` --- value type: ``str``


    **key**: ``"rootFileTitle"`` --- value type: ``str``


    **key**: ``"doxygenStripFromPath"`` --- value type: ``str``


    **Additional Options:**

    **key**: ``"afterTitleDescription"`` --- value type: ``str``
        Properly formatted reStructuredText with **no indentation** to be included
        directly after the title.  You can use any rst directives or formatting you wish
        in this string.  I suggest using the ``textwrap`` module, e.g.::

            description = textwrap.dedent(\'\'\'
            This is a description of the functionality of the library being documented.

            .. warning::

               Please be advised that this library does not do anything.
            \'\'\')

        Then you can add ``"afterTitleDescription" = description`` to your dictionary.

    **key**: ``"afterBodySummary"`` --- value type: ``str``
        Similar to ``afterTitleDescription``, this is a string with reStructuredText
        formatting.  This will be inserted after the generated API body.  The layout
        looks something like this::

            rootFileTitle
            ============================================================================

            afterTitleDescription (if provided)

            [[[ GENERATED API BODY ]]]

            afterBodySummary (if provided)

    **key**: ``"appendBreatheFileDirective"`` --- value type: ``bool``
        Currently, I do not know how to reliably extract the brief / detailed file
        descriptions for a given file node.  Therefore, if you have file level
        documentation in your project that has meaning, it would otherwise be omitted.
        As a temporary patch, if you specify this value as ``True`` then at the bottom
        of the file page the full ``doxygenfile`` directive output from Breathe will
        be appended to the file documentiation.  File level brief and detailed
        descriptions will be included, followed by a large amount of duplication.  I
        hope to remove this value soon, in place of either parsing the xml more
        carefully or finding out how to extract this information directly from Breathe.

        The default value of this behavior is ``False`` if it is not specified in the
        dictionary passed as input for this method.  Please refer to the *Customizing
        File Pages* subsection of :ref:`usage_customizing_file_pages` for more
        information on what the impact of this variable is.

    **key**: ``"customSpecificationFunction"`` --- value type: ``function``
        The custom specification function to override the default behavior of exhale.
        Please refer to the :func:`exhale.specificationsForKind` documentation.

    :raises ValueError:
        If the required dictionary arguments are not present, or any of the (key, value)
        pairs are invalid.

    :raises RuntimeError:
        If any **fatal** error is caught during the generation of the API.
    '''
    # Quick sanity check to make sure the bare minimum have been set in the configs
    err_msg = "`configs.{config}` was `None`.  Do not call `deploy.explode` directly."
    if configs.containmentFolder is None:
        raise RuntimeError(err_msg.format(config="containmentFolder"))
    if configs.rootFileName is None:
        raise RuntimeError(err_msg.format(config="rootFileName"))
    if configs.rootFileTitle is None:
        raise RuntimeError(err_msg.format(config="rootFileTitle"))
    if configs.doxygenStripFromPath is None:
        raise RuntimeError(err_msg.format(config="doxygenStripFromPath"))

    # From here on, we assume that everything else has been checked / configured.
    try:
        textRoot = ExhaleRoot()
    except Exception as e:
        raise RuntimeError("Unable to create an `ExhaleRoot` object:\n{0}".format(e))
    try:
        textRoot.parse()
    except Exception as e:
        raise RuntimeError("Exception caught while parsing:\n{0}".format(e))
    try:
        textRoot.generateFullAPI()
    except Exception as e:
        raise RuntimeError("Exception caught while generating:\n{0}".format(e))

    # << verboseBuild
    #   toConsole only prints if verbose mode is enabled
    textRoot.toConsole()
