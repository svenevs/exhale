########################################################################################
# License: CC0 1.0                                                                     #
#                                                                                      #
# See full license text here: https://creativecommons.org/publicdomain/zero/1.0/       #
########################################################################################
# In the event that this code is useful to you, please feel free to use it without     #
# attribution.  The CC0 1.0 license is chosen in the event that you need a license.    #
#                                                                                      #
# Note that this code is basically just a bad modification of the Sphinx tutorial:     #
# https://www.sphinx-doc.org/en/latest/extdev/tutorial.html                            #
########################################################################################
import re
import textwrap

from docutils import nodes
from docutils.parsers.rst import Directive
from docutils.statemachine import StringList
from sphinx.locale import _

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.absolute()))
from github_url import get_github_base_url


def visit_exhaleversion_node(self, node):
    self.visit_admonition(node)


def depart_exhaleversion_node(self, node):
    self.depart_admonition(node)


class exhaleversion(nodes.Admonition, nodes.Element):
    pass


class ExhaleVersionDirective(Directive):
    has_content = True

    def run(self):
        if len(self.content) != 0:
            raise ValueError("`exhaleversion` directive does not allow any arguments.")
        # Seriously there _HAS_ to be a better way to do this...
        # Creating something of length 1 so that I can rage-replace it
        self.content = StringList("?")
        base = get_github_base_url()
        commit = base.split("/")[-1]
        self.content[0] = textwrap.dedent(f'''\
            This documentation was generated using exhale version |version|
            from `commit {commit} <{base}>`_.
        ''')
        exhaleversion_node = exhaleversion("\n".join(self.content))
        exhaleversion_node += nodes.title(_("Version"), _("Version"))
        self.state.nested_parse(self.content, self.content_offset, exhaleversion_node)

        return [exhaleversion_node]
