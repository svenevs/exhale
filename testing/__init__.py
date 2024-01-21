########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
The testing package for Exhale.
"""

import os


TEST_PROJECTS_ROOT = os.path.abspath(os.path.join(
    os.path.dirname(__file__), "projects"
))
"""
The global ``projects`` folder that individual test cases use.

Each test case indexes into this folder with their specified ``test_project``.
See also :data:`testing.base.ExhaleTestCase.test_project`.
"""


def get_exhale_root(test):
    """
    Return the finalized :class:`exhale.graph.ExhaleRoot` object for the specified test.

    .. todo:: document better / this gets updated in v1.0.0
    """
    # Get the finalized exhale.graph.ExhaleRoot object
    # TODO: in future this app.exhale_root will *NOT* be set, but instead it will be
    # something else depending on how the multi-project setup works, AKA if you are
    # reading this `app.exhale_root` is *NOT* a feature you can rely on!!!
    app = getattr(test, "app", None)
    if app is None:
        raise RuntimeError("Critical failure: the test_root.app was 'None'.")
    return app.exhale_root
