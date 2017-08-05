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

import os
import sys
import types

__all__       = [
    'AnsiColors', 'nodeCompoundXMLContents', 'exclaimError', 'qualifyKind', 'kindAsBreatheDirective', 'specificationsForKind'
]
__name__      = "utils"
__docformat__ = "reStructuredText"


AVAILABLE_KINDS = [
    "class",
    "struct",
    "function",
    "enum",
    "enumvalue",  # unused
    "namespace",
    "define",
    "typedef",
    "variable",
    "file",
    "dir",
    "group",  # unused
    "union"
]
''' A list of all potential input ``kind`` values coming from Doxygen. '''


def makeCustomSpecificationsMapping(func):
    # Make sure they gave us a function
    if not isinstance(func, types.FunctionType):
        raise ValueError(
            "The input to exhale.util.makeCustomSpecificationsMapping was *NOT* a function: {0}".format(
                type(func)
            )
        )

    # Stamp the return to ensure exhale created this function.
    ret = {configs._closure_map_sanity_check: configs._closure_map_sanity_check}
    try:
        # Because we cannot pickle a fully-fledged function object, we are going to go
        # through every kind and store its return value.
        for kind in AVAILABLE_KINDS:
            specs = func(kind)
            if type(specs) is not str:
                raise RuntimeError(
                    "The custom specifications function did not return a string for input `{kind}`".format(
                        kind=kind
                    )
                )
            ret[kind] = specs
    except Exception as e:
        raise RuntimeError("Unable to create custom specifications:\n{0}".format(e))

    # Everything went according to plan, send it back to `conf.py` :)
    return ret


def nodeCompoundXMLContents(node):
    node_xml_path = os.path.join(configs.doxygenOutputDirectory, "{0}.xml".format(node.refid))
    if os.path.isfile(node_xml_path):
        try:
            with open(node_xml_path, "r") as xml:
                node_xml_contents = xml.read()

            return node_xml_contents
        except:
            return None
    return None


########################################################################################
#
##
###
####
##### Utility / helper functions.
####
###
##
#
########################################################################################
def qualifyKind(kind):
    '''
    Qualifies the breathe ``kind`` and returns an qualifier string describing this
    to be used for the text output (e.g. in generated file headings and link names).

    The output for a given kind is as follows:

    +-------------+------------------+
    | Input Kind  | Output Qualifier |
    +=============+==================+
    | "class"     | "Class"          |
    +-------------+------------------+
    | "define"    | "Define"         |
    +-------------+------------------+
    | "enum"      | "Enum"           |
    +-------------+------------------+
    | "enumvalue" | "Enumvalue"      |
    +-------------+------------------+
    | "file"      | "File"           |
    +-------------+------------------+
    | "function"  | "Function"       |
    +-------------+------------------+
    | "group"     | "Group"          |
    +-------------+------------------+
    | "namespace" | "Namespace"      |
    +-------------+------------------+
    | "struct"    | "Struct"         |
    +-------------+------------------+
    | "typedef"   | "Typedef"        |
    +-------------+------------------+
    | "union"     | "Union"          |
    +-------------+------------------+
    | "variable"  | "Variable"       |
    +-------------+------------------+

    The following breathe kinds are ignored:

    - "autodoxygenfile"
    - "doxygenindex"
    - "autodoxygenindex"

    Note also that although a return value is generated, neither "enumvalue" nor
    "group" are actually used.

    :Parameters:
        ``kind`` (str)
            The return value of a Breathe ``compound`` object's ``get_kind()`` method.

    :Return (str):
        The qualifying string that will be used to build the reStructuredText titles and
        other qualifying names.  If the empty string is returned then it was not
        recognized.
    '''
    if kind == "dir":
        return "Directory"
    else:
        return kind.capitalize()


def kindAsBreatheDirective(kind):
    '''
    Returns the appropriate breathe restructured text directive for the specified kind.
    The output for a given kind is as follows:

    +-------------+--------------------+
    | Input Kind  | Output Directive   |
    +=============+====================+
    | "class"     | "doxygenclass"     |
    +-------------+--------------------+
    | "define"    | "doxygendefine"    |
    +-------------+--------------------+
    | "enum"      | "doxygenenum"      |
    +-------------+--------------------+
    | "enumvalue" | "doxygenenumvalue" |
    +-------------+--------------------+
    | "file"      | "doxygenfile"      |
    +-------------+--------------------+
    | "function"  | "doxygenfunction"  |
    +-------------+--------------------+
    | "group"     | "doxygengroup"     |
    +-------------+--------------------+
    | "namespace" | "doxygennamespace" |
    +-------------+--------------------+
    | "struct"    | "doxygenstruct"    |
    +-------------+--------------------+
    | "typedef"   | "doxygentypedef"   |
    +-------------+--------------------+
    | "union"     | "doxygenunion"     |
    +-------------+--------------------+
    | "variable"  | "doxygenvariable"  |
    +-------------+--------------------+

    The following breathe kinds are ignored:

    - "autodoxygenfile"
    - "doxygenindex"
    - "autodoxygenindex"

    Note also that although a return value is generated, neither "enumvalue" nor
    "group" are actually used.

    :Parameters:
        ``kind`` (str)
            The kind of the breathe compound / ExhaleNode object (same values).

    :Return (str):
        The directive to be used for the given ``kind``.  The empty string is returned
        for both unrecognized and ignored input values.
    '''
    return "doxygen{kind}".format(kind=kind)


def specificationsForKind(kind):
    '''
    Returns the relevant modifiers for the restructured text directive associated with
    the input kind.  The only considered values for the default implementation are
    ``class`` and ``struct``, for which the return value is exactly::

        "   :members:\\n   :protected-members:\\n   :undoc-members:\\n"

    Formatting of the return is fundamentally important, it must include both the prior
    indentation as well as newlines separating any relevant directive modifiers.  The
    way the framework uses this function is very specific; if you do not follow the
    conventions then sphinx will explode.

    Consider a ``struct thing`` being documented.  The file generated for this will be::

        .. _struct_thing:

        Struct thing
        ================================================================================

        .. doxygenstruct:: thing
           :members:
           :protected-members:
           :undoc-members:

    Assuming the first two lines will be in a variable called ``link_declaration``, and
    the next three lines are stored in ``header``, the following is performed::

        directive = ".. {}:: {}\\n".format(kindAsBreatheDirective(node.kind), node.name)
        specifications = "{}\\n\\n".format(specificationsForKind(node.kind))
        gen_file.write("{}{}{}{}".format(link_declaration, header, directive, specifications))

    That is, **no preceding newline** should be returned from your custom function, and
    **no trailing newline** is needed.  Your indentation for each specifier should be
    **exactly three spaces**, and if you want more than one you need a newline in between
    every specification you want to include.  Whitespace control is handled internally
    because many of the directives do not need anything added.  For a full listing of
    what your specifier options are, refer to the breathe documentation:

        http://breathe.readthedocs.io/en/latest/directives.html

    :Parameters:
        ``kind`` (str)
            The kind of the node we are generating the directive specifications for.

    :Return (str):
        The correctly formatted specifier(s) for the given ``kind``.  If no specifier(s)
        are necessary or desired, the empty string is returned.
    '''
    # use the custom directives function
    if configs.customSpecificationsMapping:
        return configs.customSpecificationsMapping[kind]

    # otherwise, just provide class and struct
    if kind == "class" or kind == "struct":
        directive = "   :members:\n   :protected-members:\n   :undoc-members:"
    else:
        directive = ""
    return directive


class AnsiColors:
    '''
    A simple wrapper class for convenience definitions of common ANSI formats to enable
    calling :func:`utils.exclaimError`.  The definitions below only affect the
    foreground color of the text, but you can easily change the background color too.
    See `ANSI color codes <http://misc.flogisoft.com/bash/tip_colors_and_formatting>`_
    for a concise overview of how to use the ANSI color codes.
    '''
    BOLD          = "1m"
    ''' The ANSI bold modifier, see :ref:`utils.AnsiColors.BOLD_RED` for an example. '''
    DIM           = "2m"
    ''' The ANSI dim modifier, see :ref:`utils.AnsiColors.DIM_RED` for an example. '''
    UNDER         = "4m"
    ''' The ANSI underline modifier, see :ref:`utils.AnsiColors.UNDER_RED` for an example. '''
    INV           = "7m"
    ''' The ANSI inverted modifier, see :ref:`utils.AnsiColors.INV_RED` for an example. '''
    ####################################################################################
    BLACK         = "30m"
    ''' The ANSI black color. '''
    BOLD_BLACK    = "30;{bold}".format(bold=BOLD)
    ''' The ANSI bold black color. '''
    DIM_BLACK     = "30;{dim}".format(dim=DIM)
    ''' The ANSI dim black color. '''
    UNDER_BLACK   = "30;{under}".format(under=UNDER)
    ''' The ANSI underline black color. '''
    INV_BLACK     = "30;{inv}".format(inv=INV)
    ''' The ANSI inverted black color. '''
    ####################################################################################
    RED           = "31m"
    ''' The ANSI red color. '''
    BOLD_RED      = "31;{bold}".format(bold=BOLD)
    ''' The ANSI bold red color. '''
    DIM_RED       = "31;{dim}".format(dim=DIM)
    ''' The ANSI dim red color. '''
    UNDER_RED     = "31;{under}".format(under=UNDER)
    ''' The ANSI underline red color. '''
    INV_RED       = "31;{inv}".format(inv=INV)
    ''' The ANSI inverted red color. '''
    ####################################################################################
    GREEN         = "32m"
    ''' The ANSI green color. '''
    BOLD_GREEN    = "32;{bold}".format(bold=BOLD)
    ''' The ANSI bold green color. '''
    DIM_GREEN     = "32;{dim}".format(dim=DIM)
    ''' The ANSI dim green color. '''
    UNDER_GREEN   = "32;{under}".format(under=UNDER)
    ''' The ANSI underline green color. '''
    INV_GREEN     = "32;{inv}".format(inv=INV)
    ''' The ANSI inverted green color. '''
    ####################################################################################
    YELLOW        = "33m"
    ''' The ANSI yellow color. '''
    BOLD_YELLOW   = "33;{bold}".format(bold=BOLD)
    ''' The ANSI bold yellow color. '''
    DIM_YELLOW    = "33;{dim}".format(dim=DIM)
    ''' The ANSI dim yellow color. '''
    UNDER_YELLOW  = "33;{under}".format(under=UNDER)
    ''' The ANSI underline yellow color. '''
    INV_YELLOW    = "33;{inv}".format(inv=INV)
    ''' The ANSI inverted yellow color. '''
    ####################################################################################
    BLUE          = "34m"
    ''' The ANSI blue color. '''
    BOLD_BLUE     = "34;{bold}".format(bold=BOLD)
    ''' The ANSI bold blue color. '''
    DIM_BLUE      = "34;{dim}".format(dim=DIM)
    ''' The ANSI dim blue color. '''
    UNDER_BLUE    = "34;{under}".format(under=UNDER)
    ''' The ANSI underline blue color. '''
    INV_BLUE      = "34;{inv}".format(inv=INV)
    ''' The ANSI inverted blue color. '''
    ####################################################################################
    MAGENTA       = "35m"
    ''' The ANSI magenta (purple) color. '''
    BOLD_MAGENTA  = "35;{bold}".format(bold=BOLD)
    ''' The ANSI bold magenta (purple) color. '''
    DIM_MAGENTA   = "35;{dim}".format(dim=DIM)
    ''' The ANSI dim magenta (purple) color. '''
    UNDER_MAGENTA = "35;{under}".format(under=UNDER)
    ''' The ANSI underlined magenta (purple) color. '''
    INV_MAGENTA   = "35;{inv}".format(inv=INV)
    ''' The ANSI inverted magenta (purple) color. '''
    ####################################################################################
    CYAN          = "36m"
    ''' The ANSI cyan color. '''
    BOLD_CYAN     = "36;{bold}".format(bold=BOLD)
    ''' The ANSI bold cyan color. '''
    DIM_CYAN      = "36;{dim}".format(dim=DIM)
    ''' The ANSI dim cyan color. '''
    UNDER_CYAN    = "36;{under}".format(under=UNDER)
    ''' The ANSI underline cyan color. '''
    INV_CYAN      = "36;{inv}".format(inv=INV)
    ''' The ANSI inverted cyan color. '''
    ####################################################################################
    WHITE         = "37m"
    ''' The ANSI white color. '''
    BOLD_WHITE    = "37;{bold}".format(bold=BOLD)
    ''' The ANSI bold white color. '''
    DIM_WHITE     = "37;{dim}".format(dim=DIM)
    ''' The ANSI dim white color. '''
    UNDER_WHITE   = "37;{under}".format(under=UNDER)
    ''' The ANSI underline white color. '''
    INV_WHITE     = "37;{inv}".format(inv=INV)
    ''' The ANSI inverted white color. '''

    @classmethod
    def printAllColorsToConsole(cls):
        ''' A simple enumeration of the colors to the console to help decide :) '''
        for elem in cls.__dict__:
            # ignore specials such as __class__ or __module__
            if not elem.startswith("__"):
                color_fmt = cls.__dict__[elem]
                if type(color_fmt) is str and color_fmt != "BOLD" and color_fmt != "DIM" and \
                        color_fmt != "UNDER" and color_fmt != "INV":
                    print("\033[{fmt}AnsiColors.{name}\033[0m".format(fmt=color_fmt, name=elem))


def colorize(msg, ansi_fmt):
    return "\033[{0}{1}\033[0m".format(ansi_fmt, msg)


def progress(msg, ansi_fmt=AnsiColors.BOLD_GREEN):
    return colorize("[+] {0}".format(msg), ansi_fmt)


def info(msg, ansi_fmt=AnsiColors.BOLD_BLUE):
    return colorize("[~] {0}".format(msg), ansi_fmt)


def exclaimError(msg, ansi_fmt=AnsiColors.BOLD_BLUE):
    '''
    Prints ``msg`` to the console in color with ``(!)`` prepended in color.

    Example (uncolorized) output of ``exclaimError("No leading space needed.")``::

        (!) No leading space needed.

    All messages are written to ``sys.stderr``, and are closed with ``[0m``.  The
    default color is bold blue, but can be changed using ``ansi_fmt``.  See the various
    constants defined in :class:`utils.AnsiColors`.

    Documentation building has a verbose output process, this just helps distinguish an
    error message coming from exhale.

    :Parameters:
        ``msg`` (str)
            The message you want printed to standard error.

        ``ansi_fmt`` (str)
            An ansi color format.  ``msg`` is printed as
            ``"\\033[" + ansi_fmt + msg + "\\033[0m\\n``, so you should specify both the
            color code and the format code (after the semicolon).  The default value is
            ``34;1m`` (bold blue).
    '''
    sys.stderr.write("\033[{}(!) {}\033[0m\n".format(ansi_fmt, msg))
