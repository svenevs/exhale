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

import textwrap

__all__ = [
    "exhaleApiTocTreeMaxDepth",
    "setApiTocTreeMaxDepth",
    "setCustomSpecificationsForKind",
    "exhaleHasCustomSpecificationsFunction",
    "exhaleCallCustomSpecificationsForKind"
]

__name__ = "configs"
__docformat__ = "reStructuredText"

########################################################################################
# Required configurations, these get set indirectly via the dictionary argument given  #
# to exhale in your conf.py.                                                           #
########################################################################################
containmentFolder = None

rootFileName = None

rootFileTitle = None

doxygenStripFromPath = None

########################################################################################
# reStructuredText allows three types of section headings.                             #
########################################################################################
SECTION_HEADING = "=" * 88
''' The restructured text file heading separator (``"=" * 88``). '''

SUB_SECTION_HEADING = "-" * 88
''' The restructured text section heading separator (``"-" * 88``). '''

SUB_SUB_SECTION_HEADING = "*" * 88
''' The restructured text sub-section heading separator (``"*" * 88``).'''

########################################################################################
# Additional configurations available to further customize the output of exhale.       #
########################################################################################

afterTitleDescription = None

afterBodySummary = None

createTreeView = False

treeViewIsBootstrap = False

fullToctreeMaxDepth = 5

customSpecificationsMapping = None

_closure_map_sanity_check = "blargh_BLARGH_blargh"
# See utils.makeCustomSpecificationsMapping, this is inserted to enforce exhale made the
# closures needed for pickling with sphinx.

doxygenOutputDirectory = None
'''
The absolute path the the root level of the doxygen xml output.  If the path to the
``index.xml`` file created by doxygen was ``./doxyoutput/xml/index.xml``, then this
would simply be ``./doxyoutput/xml``.
'''

exhaleExecutesDoxygen = False

exhaleUseDoxyfile = False

exhaleDoxygenStdin = None

# # Make this the same as what you tell exhale.
#             OUTPUT_DIRECTORY       = doxyoutput
            # STRIP_FROM_PATH        = "%s/"
            # # Tell Doxygen where the source code is (yours may be different).
            # INPUT                  = ../include




DEFAULT_DOXYGEN_STDIN_BASE = textwrap.dedent(r'''
    # If you need this to be YES, exhale will probably break.
    CREATE_SUBDIRS         = NO
    # So that only include/ and subdirectories appear.
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

exhaleSilentDoxygen = False







exhaleApiTocTreeMaxDepth = 5
'''
The value used as ``:maxdepth:`` with restructured text ``.. toctree::`` directives.
The default value is 5, as any larger will likely produce errors with a LaTeX build.
Change this value by specifying the proper value to the dictionary passed to the
`generate` function.
'''


def setApiTocTreeMaxDepth(depth):
    global exhaleApiTocTreeMaxDepth
    exhaleApiTocTreeMaxDepth = depth

exhaleApiPageTocDepth = 5
def setApiPageTocDepth(depth):
    global exhaleApiPageTocDepth
    exhaleApiPageTocDepth = depth



exhaleCustomSpecificationsForKind = None  # DO NOT EXPOSE
'''
User specified override of `specificationsForKind`.  No safety checks are performed for
externally provided functions.  Change the functionality of `specificationsForKind` by
specifiying a function in the dictionary passed to `generate`.
'''


def setCustomSpecificationsForKind(func):
    global exhaleCustomSpecificationsForKind
    exhaleCustomSpecificationsForKind = func


def exhaleHasCustomSpecificationsFunction():
    return exhaleCustomSpecificationsForKind is not None


def exhaleCallCustomSpecificationsForKind(kind):
    return exhaleCustomSpecificationsForKind(kind)




exhaleDoxygenStripFromPath = None
'''
If not ``None``, this path is used to control deleting e.g. absolute paths from the
output generated.  This should be the same path specified to the doxygen build process,
but experience seems to reveal that the doxygen on read the docs is not performing this
(likely due to certain environment configurations or something as yet to be identified).
'''


def setExhaleDoxygenStripFromPath(path):
    global exhaleDoxygenStripFromPath
    exhaleDoxygenStripFromPath = path


generateBreatheFileDirectives = False
'''
If True, then the breathe directive (``doxygenfile``) will be incorporated at the bottom
of the file.

.. warning::

   This feature is "deprecated" in lieu of minimal parsing of the input Doxygen xml for
   a given documented file.  This feature can be used to help determine if ``exhale``
   has made a mistake in parsing the file level documentation, but usage of this feature
   will create **many** duplicate id's and the Sphinx build process will be littered
   with complaints.

   **This feature is not intended for production release of pages, only debugging.**
'''
