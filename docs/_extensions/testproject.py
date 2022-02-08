import textwrap

from docutils import nodes
from docutils.parsers.rst import Directive
from sphinx.locale import _

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.absolute()))
from github_url import get_github_base_url


def visit_testproject_node(self, node):
    self.visit_admonition(node)


def depart_testproject_node(self, node):
    self.depart_admonition(node)


class testproject(nodes.Admonition, nodes.Element):
    pass


class TestProjectDirective(Directive):
    has_content = True

    def run(self):
        if len(self.content) != 1:
            raise ValueError(
                "`testproject` directive needs exactly one argument (the name of the test folder).  "
                "Example: .. testproject:: c_maths"
            )
        self.content[0] = textwrap.dedent('''\
            The ``{project}`` test project.

            - Additional documentation: :mod:`testing.projects.{project_fixed}`.
            - Source code for `{project} available here <{baseurl}/{project_dir}>`_.

            See also: :data:`ExhaleTestCase.test_project <testing.base.ExhaleTestCase.test_project>`.
        '''.format(
            project=self.content[0],
            project_dir=self.content[0].replace(" ", "\\ "),
            project_fixed=self.content[0].replace(" ", "_"),  # cpp with spaces project
            baseurl=f"{get_github_base_url()}/testing/projects"
        ))
        project_node = testproject("\n".join(self.content))
        project_node += nodes.title(_("Test Project Source"), _("Test Project Source"))
        self.state.nested_parse(self.content, self.content_offset, project_node)

        return [project_node]
