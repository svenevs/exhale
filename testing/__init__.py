# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
The testing package for Exhale.
"""

from __future__ import unicode_literals
import os


TEST_PROJECTS_ROOT = os.path.abspath(os.path.join(
    os.path.dirname(__file__), "projects"
))
"""
The global ``projects`` folder that individual test cases use.

Each test case indexes into this folder with their specified ``test_project``.
See also :data:`testing.base.ExhaleTestCase.test_project`.
"""


def docs_dir(test_project, class_name, function_name):
    """
    Absolute path "docs" directory for a given test case.

    **Parameters**

    ``test_project`` (:class:`python:str`)
        The test project (nested directory in :data:`testing.TEST_PROJECTS_ROOT`).

    ``class_name`` (:class:`python:str`)
        The name of the test class being used.

    ``function_name`` (:class:`python:str`)
        The name of the test function (``"test_xxx"``).

    **Return** (:class:`python:str`)
        The absolute path to the "docs" directory where ``conf.py`` and friends will be
        generated.
    """
    return os.path.join(
        TEST_PROJECTS_ROOT,
        test_project,
        "docs_{class_name}_{function_name}".format(
            class_name=class_name, function_name=function_name
        )
    )


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
