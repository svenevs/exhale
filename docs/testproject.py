
import re
import textwrap

from subprocess import Popen, PIPE
from docutils import nodes
from docutils.parsers.rst import Directive
from sphinx.locale import _


def visit_testproject_node(self, node):
    self.visit_admonition(node)


def depart_testproject_node(self, node):
    self.depart_admonition(node)


class testproject(nodes.Admonition, nodes.Element):
    pass


projects_baseurl = None

# get a github specific URL to where the test projects live using the current commit
def get_projects_baseurl():
    global projects_baseurl

    # just making sure this only needs to run once
    if projects_baseurl:
        return projects_baseurl

    # otherwise, first execution so grab it, set it, and return it

    git_remote_proc = Popen(
        ["git", "remote", "get-url", "origin"], stdout=PIPE, stderr=PIPE
    )
    git_remote_out, git_remote_err = git_remote_proc.communicate()
    if git_remote_proc.returncode != 0:
        raise RuntimeError(
            "Non-zero exit code [{0}] from git remote.  STDERR: {1}".format(
                git_remote_proc.returncode, git_remote_err.decode("ascii")
            )
        )

    # extract user so that pull requests don't fail the docs linkcheck test
    git_remote_out = git_remote_out.decode("ascii")
    user = None

    # HTTPS url: https://github.com/svenevs/exhale.git
    https_re = r"https://github\.com/(.*)/exhale\.git"
    https_match = re.match(https_re, git_remote_out)
    if https_match:
        user = https_match.groups()[0]

    # HTTPS url as done by GitHub Actions.
    https_re = r"https://github\.com/(.*)/exhale"  # no .git
    https_match = re.match(https_re, git_remote_out)
    if https_match:
        user = https_match.groups()[0]

    # SSH url:   git@github.com:svenevs/exhale.git
    ssh_re   = r"git@github\.com:(.*)/exhale\.git"
    ssh_match = re.match(ssh_re, git_remote_out)
    if ssh_match:
        user = ssh_match.groups()[0]

    if not user:
        raise RuntimeError(
            "Could not parse GitHub user information from remote: {}".format(git_remote_out)
        )

    # Get the commit hash
    git_rev_parse_proc = Popen(
        ["git", "rev-parse", "HEAD"], stdout=PIPE, stderr=PIPE
    )
    git_rev_parse_out, git_rev_parse_err = git_rev_parse_proc.communicate()
    if git_rev_parse_proc.returncode != 0:
        raise RuntimeError(
            "Non-zero exit code [{0}] from git rev-parse.  STDERR: {1}".format(
                git_rev_parse_proc.returncode, git_rev_parse_err.decode("ascii")
            )
        )

    git_rev_parse_out = git_rev_parse_out.decode("ascii")

    projects_baseurl = "https://github.com/{user}/exhale/tree/{sha}/testing/projects".format(
        user=user.strip(), sha=git_rev_parse_out.strip()
    )

    return projects_baseurl


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
            baseurl=get_projects_baseurl()
        ))
        project_node = testproject("\n".join(self.content))
        project_node += nodes.title(_("Test Project Source"), _("Test Project Source"))
        self.state.nested_parse(self.content, self.content_offset, project_node)

        return [project_node]
