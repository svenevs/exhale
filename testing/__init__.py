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
