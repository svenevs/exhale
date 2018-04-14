import os
import shutil

TEST_PROJECTS_ROOT = os.path.abspath(os.path.join(
    os.path.dirname(__file__), "projects"
))
"""
The global ``projects`` folder that individual test cases use to index into with their
specified ``test_project``.  See also :data:`testing.base.ExhaleTestCase.test_root`.
"""

TEST_RESULTS_COPY_DIR = os.path.abspath(os.path.join(
    os.path.dirname(__file__), "generated_results"
))
"""
The location where generated test project results will be copied to when requested.
Results should only ever be copied using
:func:`testing.base.ExhaleTestCase.copyThisProject`.

.. todo:: There is a reason for this, which simply has not manifested yet.
"""

# Delete generated_results on every new invocation of the test suite
if os.path.exists(TEST_RESULTS_COPY_DIR):
    shutil.rmtree(TEST_RESULTS_COPY_DIR)
