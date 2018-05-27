# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for validating error handling with configs set in ``conf.py``.
"""

from __future__ import unicode_literals
import pytest

from sphinx.errors import ConfigError

from testing.base import ExhaleTestCase
from testing.decorators import confoverrides, no_run


@no_run
class ConfigurationErrorTests(ExhaleTestCase):
    """
    Tests to ensure invalid user-input in ``conf.py`` is handled correctly.
    """

    test_project = "c_maths"
    """
    .. testproject:: c_maths

    .. note::

       The ``c_maths`` project is just being recycled, the tests for that project take
       place in :class:`CMathsTests <testing.tests.c_maths.CMathsTests>`.
    """

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"`exhale_args` in `conf\.py` must be a dictionary, but was `<(class|type) 'int'>`",
    )
    @confoverrides(exhale_args=11)
    def test_non_dict_exhale_args(self):
        """Validate non-dictionary ``exhale_args`` raises ``ConfigError``."""
        pass
