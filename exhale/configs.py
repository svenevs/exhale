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

__all__ = [
    "exhaleApiTocTreeMaxDepth",
    "setApiTocTreeMaxDepth",
    "EXHALE_FILE_HEADING",
    "EXHALE_SECTION_HEADING",
    "EXHALE_SUBSECTION_HEADING",
    "setCustomSpecificationsForKind",
    "exhaleHasCustomSpecificationsFunction",
    "exhaleCallCustomSpecificationsForKind"
]

__name__ = "configs"
__docformat__ = "reStructuredText"

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

EXHALE_FILE_HEADING = "=" * 88
''' The restructured text file heading separator (``"=" * 88``). '''

EXHALE_SECTION_HEADING = "-" * 88
''' The restructured text section heading separator (``"-" * 88``). '''

EXHALE_SUBSECTION_HEADING = "*" * 88
''' The restructured text sub-section heading separator (``"*" * 88``).'''

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




exhaleDoxyOutputDir = ""
'''
The absolute path the the root level of the doxygen xml output.  If the path to the
``index.xml`` file created by doxygen was ``./doxyoutput/xml/index.xml``, then this
would simply be ``./doxyoutput/xml``.
'''


def setExhaleDoxyOutputDir(where):
    global exhaleDoxyOutputDir
    exhaleDoxyOutputDir = where


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


exhaleGenerateBreatheFileDirectives = False
'''
Currently, Exhale (I...) do not know how to extract the documentation string for a given
file being produced.  If True, then the breathe directive (``doxygenfile``) will be
incorporated at the bottom of the file.  This will duplicate a lot of information, but
will include the file's description at the beginning.  This feature will be removed in
future releases once files can be reliably paired with their documentation.
'''

def setExhaleGenerateBreatheFileDirectives(use):
    global exhaleGenerateBreatheFileDirectives
    exhaleGenerateBreatheFileDirectives = use
