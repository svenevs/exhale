import re
from subprocess import Popen, PIPE

github_base_url = None


# get a github specific URL to where the root of the project on current commit
def get_github_base_url():
    global github_base_url

    # just making sure this only needs to run once
    if github_base_url:
        return github_base_url

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
    ssh_re   = r"git@github\.com:(.*)/exhale(\.git)?"
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

    github_base_url = "https://github.com/{user}/exhale/tree/{sha}".format(
        user=user.strip(), sha=git_rev_parse_out.strip()
    )

    return github_base_url
