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


def visit_autotested_node(self, node):
    self.visit_admonition(node)


def depart_autotested_node(self, node):
    self.depart_admonition(node)


class autotested(nodes.Admonition, nodes.Element):
    pass


class AutoTestedDirective(Directive):
    has_content = True

    def run(self):
        if len(self.content) != 0:
            raise ValueError("`autotested` directive does not allow any arguments.")
        # Seriously there _HAS_ to be a better way to do this...
        # Creating something of length 1 so that I can rage-replace it
        self.content = StringList("?")
        self.content[0] = textwrap.dedent('''\
            This method is tested automatically for every derived type of
            :class:`~testing.base.ExhaleTestCase` that is not decorated with
            :func:`~testing.decorators.no_run`.  The metaclass
            :class:`~testing.base.ExhaleTestCaseMetaclass` generates a testing method
            ``test_common`` that invokes this method.
        ''')
        autotested_node = autotested("\n".join(self.content))
        autotested_node += nodes.title(_("Automatically Tested"), _("Automatically Tested"))
        self.state.nested_parse(self.content, self.content_offset, autotested_node)

        return [autotested_node]
