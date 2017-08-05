# This file is part of exhale: https://github.com/svenevs/exhale
#
# Copyright (c) 2017, Stephen McDowell
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
# * Neither the name of exhale nor the names of its
#   contributors may be used to endorse or promote products derived from
#   this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
from . import configs
from . import utils
from .graph import ExhaleRoot

import os
import sys
import re
import tempfile
import textwrap
from breathe.parser.index import parse as breathe_parse
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
                prefix = utils.info("", utils.AnsiColors.BOLD_YELLOW)
                tmp_err.seek(0)
                print(tmp_err.read().rstrip().replace("\n", "\n{0}".format(prefix)))
                # for line in tmp_err.read().splitlines():
                #     print("{prefix}{line}".format(prefix=prefix, line=line))

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

    return None


def _valid_config(config, required):
    re_template = r"\s*{config}\s*=.*".format(config=config)
    found = re.search(re_template, configs.exhaleDoxygenStdin)
    if required:
        return found is not None
    else:
        return found is None


def generateDoxygenXML():
    # If this happens, we really shouldn't be here...
    if not configs.exhaleExecutesDoxygen:
        return "`generateDoxygenXML` should *ONLY* be called internally, when `exhaleExecutesDoxygen=True`!"

    # Case 1: the user has their own `Doxyfile`.
    if configs.exhaleUseDoxyfile:
        return _generate_doxygen("Doxyfile")
    # Case 2: use stdin, with some defaults and potentially additional specs from user
    else:
        # There are two doxygen specs that we explicitly disallow
        #
        # 1. OUTPUT_DIRECTORY: this is *ALREADY* specified implicitly via breathe
        # 2. STRIP_FROM_PATH: this is a *REQUIRED* config for exhale (`exhaleDoxygenStripFromPath`)
        #
        # There is one doxygen spec that is REQUIRED to be given: INPUT (where doxygen should parse).
        # The below is a modest attempt to validate that these were / were not given.
        if type(configs.exhaleDoxygenStdin) is not str:
            return "`exhaleDoxygenStdin` config must be a string!"

        if not _valid_config("OUTPUT_DIRECTORY", False):
            return "`exhaleDoxygenStdin` may *NOT* specify `OUTPUT_DIRECTORY`.  Exhale does this internally."

        if not _valid_config("STRIP_FROM_PATH", False):
            return "`exhaleDoxygenStdin` may *NOT* specify `STRIP_FROM_PATH`.  Exhale does this internally."

        if not _valid_config("INPUT", True):
            return "`exhaleDoxygenStdin` *MUST* specify the `INPUT` doxygen config variable."

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
        The name of the file that **you** will be linking to from your reStructuredText
        documents.  Do not include the ``containmentFolder`` path in this file name,
        exhale will create the file ``"{}/{}".format(containmentFolder, rootFileName)``.

        In order for Sphinx to be happy, you should include a ``.rst`` suffix.  All of
        the generated API uses reStructuredText, and that will not ever change.

        For example, if you specify

        - ``"containmentFolder" = "./generated_api"``, and
        - ``"rootFileName" = "library_root.rst"``

        Then exhale will generate the file ``./generated_api/library_root.rst``.

        You could include this file in a toctree directive (say in ``index.rst``) with::

            .. toctree:
               :maxdepth: 2

               generated_api/library_root

        Since Sphinx allows for some flexibility (e.g. your primary domain may be using
        ``.txt`` files), **no error checking will be performed**.

    **key**: ``"rootFileTitle"`` --- value type: ``str``
        The title to be written at the top of ``rootFileName``, which will appear in
        your file including it in the ``toctree`` directive.

    **key**: ``"doxygenStripFromPath"`` --- value type: ``str``
        When building on Read the Docs, there seem to be issues regarding the Doxygen
        variable ``STRIP_FROM_PATH`` when built remotely.  That is, it isn't stripped at
        all.  Provide me with a string path (e.g. ``".."``), and I will strip this for
        you for the File nodes being generated.  I will use the exact value of
        ``os.path.abspath("..")`` in the example above, so you can supply either a
        relative or absolute path.  The File view hierarchy **will** break if you do
        not give me a value for this, and therefore I hesitantly require this argument.
        The value ``".."`` assumes that ``conf.py`` is in a ``docs/`` or similar folder
        exactly one level below the repository's root.

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

    **key**: ``"createTreeView"`` --- value type: ``bool``
        For portability, the default value if not specified is ``False``, which will
        generate reStructuredText bulleted lists for the Class View and File View
        hierarchies.  If ``True``, raw html unordered lists will be generated.  Please
        refer to the *Clickable Hierarchies* subsection of :ref:`usage_advanced_usage`
        for more details.

    **key**: ``"fullToctreeMaxDepth"`` --- value type: ``int``
        Beneath the Class View and File View hierarchies a Full API listing is generated
        as there are items that may not appear in the Class View hierarchy, as well as
        without this an obscene amount of warnings are generated from Sphinx because
        neither view actually uses a ``toctree``, they link directly.

        The default value is 5 if not specified, but you may want to give a smaller
        value depending on the framework being documented.  This value must be greater
        than or equal to 1 (this is the value of ``:maxdepth:``).

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

    textRoot.toConsole()
