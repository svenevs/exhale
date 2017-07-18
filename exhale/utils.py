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

import sys

__all__       = [
    'exclaimError', 'qualifyKind', 'kindAsBreatheDirective', 'specificationsForKind'
]
__name__      = "utils"
__docformat__ = "reStructuredText"


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
    if kind == "class":
        qualifier = "Class"
    elif kind == "struct":
        qualifier = "Struct"
    elif kind == "function":
        qualifier = "Function"
    elif kind == "enum":
        qualifier = "Enum"
    elif kind == "enumvalue":  # unused
        qualifier = "Enumvalue"
    elif kind == "namespace":
        qualifier = "Namespace"
    elif kind == "define":
        qualifier = "Define"
    elif kind == "typedef":
        qualifier = "Typedef"
    elif kind == "variable":
        qualifier = "Variable"
    elif kind == "file":
        qualifier = "File"
    elif kind == "dir":
        qualifier = "Directory"
    elif kind == "group":  # unused
        qualifier = "Group"
    elif kind == "union":
        qualifier = "Union"
    else:
        qualifier = ""
    return qualifier


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
    if kind == "class":
        directive = "doxygenclass"
    elif kind == "struct":
        directive = "doxygenstruct"
    elif kind == "function":
        directive = "doxygenfunction"
    elif kind == "enum":
        directive = "doxygenenum"
    elif kind == "enumvalue":  # unused
        directive = "doxygenenumvalue"
    elif kind == "namespace":
        directive = "doxygennamespace"
    elif kind == "define":
        directive = "doxygendefine"
    elif kind == "typedef":
        directive = "doxygentypedef"
    elif kind == "variable":
        directive = "doxygenvariable"
    elif kind == "file":
        directive = "doxygenfile"
    elif kind == "union":
        directive = "doxygenunion"
    elif kind == "group":  # unused
        directive = "doxygengroup"
    else:
        directive = ""
    return directive


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
    if configs.exhaleHasCustomSpecificationsFunction():
        return configs.exhaleCallCustomSpecificationsForKind(kind)

    # otherwise, just provide class and struct
    if kind == "class" or kind == "struct":
        directive = "   :members:\n   :protected-members:\n   :undoc-members:"
    else:
        directive = ""
    return directive


def exclaimError(msg, ansi_fmt="34;1m"):
    '''
    Prints ``msg`` to the console in color with ``(!)`` prepended in color.

    Example (uncolorized) output of ``exclaimError("No leading space needed.")``::

        (!) No leading space needed.

    All messages are written to ``sys.stderr``, and are closed with ``[0m``.  The
    default color is blue, but can be changed using ``ansi_fmt``.

    Documentation building has a verbose output process, this just helps distinguish an
    error message coming from exhale.

    :Parameters:
        ``msg`` (str)
            The message you want printed to standard error.

        ``ansi_fmt`` (str)
            An ansi color format.  ``msg`` is printed as
            ``"\\033[" + ansi_fmt + msg + "\\033[0m\\n``, so you should specify both the
            color code and the format code (after the semicolon).  The default value is
            ``34;1m`` --- refer to
            http://misc.flogisoft.com/bash/tip_colors_and_formatting for alternatives.
    '''
    sys.stderr.write("\033[{}(!) {}\033[0m\n".format(ansi_fmt, msg))
