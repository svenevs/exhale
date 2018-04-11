
import os
import sys
import subprocess

# Make sure 'virtualenv' is available.
try:
    import virtualenv  # noqa F401
except ImportError:
    sys.stderr.write("Please install 'virtualenv', e.g. 'pip3 install virtualenv'\n")
    sys.exit(1)

# Make sure we can use relative paths as expected.
this_file_dir = os.path.abspath(os.path.dirname(__file__))
here = os.path.abspath(os.getcwd())
if this_file_dir != here:
    sys.stderr.write(
        "Please run this file from the same directory:\n\n"
        "    cd '{0}'\n".format(this_file_dir)
    )
    sys.exit(1)

# Import after location check so that local exhale source code is used
from exhale import utils  # noqa E402


def run_subprocess(args, exitOnFail=True):
    try:
        proc = subprocess.Popen(args)
        retcode = proc.wait()
        if retcode != 0 and exitOnFail:
            sys.stderr.write("Non-zero exit code of [{0}] from: {1}\n".format(
                retcode, " ".join(a for a in args)
            ))
            sys.exit(1)
        return retcode
    except Exception as e:
        sys.stderr.write(
            "Error running '{0}':\n{1}\n".format(" ".join(a for a in args), e)
        )
        sys.exit(1)


def create_virtualenv(name):
    # Only create the virtualenv if it is not already there
    pip_binary = os.path.join(this_file_dir, name, "bin", "pip")
    if not os.path.isfile(pip_binary):
        run_subprocess(["irtualenv", name])

    # We should now have access to a local virtualenv, install the testing requirements
    run_subprocess([
        pip_binary, "install",
        "-r", "requirements.txt",
        "-r", "requirements-dev.txt"
    ])


def run_pytest(venvName, extraArgs=[]):
    python_bin = os.path.join(this_file_dir, venvName, "bin", "python")
    args       = [python_bin, "-m", "pytest", this_file_dir] + extraArgs
    return run_subprocess(args, exitOnFail=False)


def run_flake8(venvName, extraArgs=[]):
    flake8   = os.path.join(this_file_dir, venvName, "bin", "flake8")
    specials = [os.path.join(this_file_dir, s) for s in ["setup.py", "run_tests.py"]]
    # dirs     = [os.path.join(this_file_dir, d) for d in ["exhale", "testing"]]
    # TODO: exhale intentionally has flake8 failures as markers right now!
    # dirs     = [os.path.join(this_file_dir, d) for d in ["testing"]]
    dirs = []
    args     = [flake8] + extraArgs + specials + dirs
    return run_subprocess(args, exitOnFail=False)


if __name__ == "__main__":
    # Create the virtualenv for testing
    testenv_name = "testenv"
    print(utils.info("Creating / validating virtualenv for testing."))
    create_virtualenv(testenv_name)
    print(utils.progress("Virtualenv ready for testing!"))

    # By default, just run pytest.  If single command-line argument 'flake8', run that.
    # In both cases, forward remaining sys.argv arguments.
    test_name = "pytest"
    extra_args = []
    argc = len(sys.argv)
    if argc > 1:
        if sys.argv[1] == "flake8":
            test_name = "flake8"
            if argc > 2:
                extra_args = sys.argv[2:]
        else:
            extra_args = sys.argv[1:]

    # Acquire a function object to be able to run
    test_func_name = "run_{0}".format(test_name)
    g = globals()
    if test_func_name not in g:
        print(utils.critical(
            "Internal error: function [{0}] not found!".format(test_func_name)
        ))
        sys.exit(1)

    # Make sure it is callable
    test_func = g[test_func_name]
    if not callable(test_func):
        print(utils.critical(
            "Internal error: [{0}] is not callable!".format(test_func_name)
        ))

    # Run the test!
    success = test_func(testenv_name, extra_args)
    if success == 0:
        print(utils.progress("{0} tests passed!".format(test_name)))
    else:
        print(utils.critical("{0} tests failed :/".format(test_name)))
        sys.exit(1)
