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
from .utils import exclaimError
from .graph import ExhaleRoot

import os
from breathe.parser.index import parse as breathe_parse


__all__       = ["generate"]
__name__      = "deploy"
__docformat__ = "reStructuredText"


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
def generate(exhaleArgs):
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
    if type(exhaleArgs) is not dict:
        raise ValueError("The type of 'exhaleArgs' must be a dictionary.")
    # Gather mandatory input
    if "doxygenIndexXMLPath" not in exhaleArgs:
        raise ValueError("'doxygenIndexXMLPath' must be present in the arguments to generate.")
    try:
        doxygenIndexXMLPath      = exhaleArgs["doxygenIndexXMLPath"]
        doxygenIndexXMLDirectory = doxygenIndexXMLPath.split("index.xml")[0]
        configs.setExhaleDoxyOutputDir(doxygenIndexXMLDirectory)
    except Exception as e:
        raise ValueError("Unable to utilize the provided 'doxygenIndexXMLPath'\n{}".format(e))

    if "containmentFolder" not in exhaleArgs:
        raise ValueError("'containmentFolder' must be present in the arguments to generate.")
    containmentFolder = exhaleArgs["containmentFolder"]
    if type(containmentFolder) is not str:
        raise ValueError("The type of the value for the key 'containmentFolder' must be a string.")

    if "rootFileName" not in exhaleArgs:
        raise ValueError("'rootFileName' must be present in the arguments passed to generate.")
    rootFileName = exhaleArgs["rootFileName"]
    if type(rootFileName) is not str:
        raise ValueError("The type of the value for the key 'rootFileName' must be a string.")

    if "rootFileTitle" not in exhaleArgs:
        raise ValueError("'rootFileTitle' must be present in the arguments passed to generate.")
    rootFileTitle = exhaleArgs["rootFileTitle"]
    if type(rootFileTitle) is not str:
        raise ValueError("The type of the value for the key 'rootFileTitle' must be a string.")

    if "doxygenStripFromPath" not in exhaleArgs:
        raise ValueError("'doxygenStripFromPath' must be present in the arguments passed to generate.")
    doxygenStripFromPath = exhaleArgs["doxygenStripFromPath"]
    if type(doxygenStripFromPath) is not str:
        raise ValueError("The type of the value for the key 'doxygenStripFromPath' must be a string.")
    try:
        strip = os.path.abspath(doxygenStripFromPath)
        if not os.path.isdir(strip):
            raise ValueError("The value for the key 'doxygenStripFromPath' does not appear to be a valid path")
        configs.setExhaleDoxygenStripFromPath(strip)
    except Exception as e:
        raise RuntimeError("Error coordinating the 'doxygenStripFromPath' variable: {}".format(e))

    # gather the optional configurations
    if "afterTitleDescription" in exhaleArgs:
        afterTitleDescription = exhaleArgs["afterTitleDescription"]
        if type(afterTitleDescription) is not str:
            raise ValueError("The type of the value for the key 'afterTitleDescription' must be a string.")
    else:
        afterTitleDescription = ""

    if "afterBodySummary" in exhaleArgs:
        afterBodySummary = exhaleArgs["afterBodySummary"]
        if type(afterBodySummary) is not str:
            raise ValueError("The type of the value for the key 'afterBodySummary' must be a string.")
    else:
        afterBodySummary = ""

    if "createTreeView" in exhaleArgs:
        createTreeView = exhaleArgs["createTreeView"]
        if type(createTreeView) is not bool:
            raise ValueError("The type of the value for the key 'createTreeView' must be a boolean.")
    else:
        createTreeView = False

    if "fullToctreeMaxDepth" in exhaleArgs:
        fullToctreeMaxDepth = exhaleArgs["fullToctreeMaxDepth"]
        if type(fullToctreeMaxDepth) is not int:
            raise ValueError("The type of the value for the key 'fullToctreeMaxDepth' must be an int.")
        configs.setApiTocTreeMaxDepth(fullToctreeMaxDepth)

    if "appendBreatheFileDirective" in exhaleArgs:
        appendBreatheFileDirective = exhaleArgs["appendBreatheFileDirective"]
        if type(appendBreatheFileDirective) is not bool:
            raise ValueError(
                "The type of the value for the key 'appendBreatheFileDirective' must be a boolean."
            )
        configs.setExhaleGenerateBreatheFileDirectives(appendBreatheFileDirective)

    if "customSpecificationFunction" in exhaleArgs:
        customSpecificationFunction = exhaleArgs["customSpecificationFunction"]
        try:
            ret = customSpecificationFunction("class")
        except:
            raise ValueError("Unable to call your custom specification function with 'class' as input...")
        if type(ret) is not str:
            raise ValueError("Your custom specification function did not return a string...")
        configs.setCustomSpecificationsForKind(customSpecificationFunction)

    # input gathered, try creating the breathe root compound
    try:
        breatheRoot = breathe_parse(doxygenIndexXMLPath)
    except Exception as e:
        raise RuntimeError("Unable to use Breathe to parse the specified doxygen index.xml: {}".format(e))

    exclaimError("The path is: {}".format(doxygenIndexXMLPath))

    if breatheRoot is not None:
        # split into multiple try-except blocks to make it a little easier to identify
        # where the error comes from
        try:
            textRoot = ExhaleRoot(breatheRoot, containmentFolder, rootFileName,
                                  rootFileTitle, afterTitleDescription,
                                  afterBodySummary, createTreeView)
        except Exception as e:
            raise RuntimeError("Exception caught creating the ExhaleRoot object: {}".format(e))
        try:
            textRoot.parse()
        except Exception as e:
            raise RuntimeError("Exception caught while parsing: {}".format(e))
        try:
            textRoot.generateFullAPI()
        except Exception as e:
            raise RuntimeError("Exception caught while generating: {}".format(e))
    else:
        raise RuntimeError("Critical error: the returned Breathe root is 'None'.")
