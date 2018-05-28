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
        regex=r"^`exhale_args` in `conf\.py` must be a dictionary, but was `<(class|type) 'int'>`\.$"
    )
    @confoverrides(exhale_args=11)
    def test_non_dict_exhale_args(self):
        """Validate non-dictionary ``exhale_args`` raises ``ConfigError``."""
        pass

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"^`exhale_projects` in `conf\.py` must be a dictionary, but was `<(class|type) 'float'>`\.$"
    )
    @confoverrides(exhale_projects=22.22)
    def test_non_dict_exhale_projects(self):
        """Validate non-dictionary ``exhale_projects`` raises ``ConfigError``."""
        pass

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"^`exhale_global_args` in `conf\.py` must be a dictionary, but was `<(class|type) 'bool'>`\.$"
    )
    @confoverrides(exhale_global_args=True)
    def test_non_dict_exhale_global_args(self):
        """Validate non-dictionary ``exhale_global_args`` raises ``ConfigError``."""
        pass

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"^`exhale_args` had key `11` of type `<(class|type) 'int'>`, but only strings are allowed\.$"
    )
    @confoverrides(exhale_args={11: "not valid"})
    def test_non_string_key_exhale_args(self):
        """Validate non-string key in ``exhale_args`` raises ``ConfigError``."""
        pass

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"^`exhale_projects` had key `22\.22` of type `<(class|type) 'float'>`, but only strings are allowed\.$"
    )
    @confoverrides(exhale_projects={22.22: "not valid"})
    def test_non_string_key_exhale_projects(self):
        """Validate non-string key in ``exhale_projects`` raises ``ConfigError``."""
        pass

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"^`exhale_global_args` had key `True` of type `<(class|type) 'bool'>`, but only strings are allowed\.$"
    )
    @confoverrides(exhale_global_args={True: "not valid"})
    def test_non_string_key_exhale_global_args(self):
        """Validate non-string key in ``exhale_global_args`` raises ``ConfigError``."""
        pass

    @pytest.mark.raises(
        exception=ConfigError,
        regex=r"^`exhale_projects\['defcon1'\]` had key `111` of type `<(class|type) 'int'>`, but only strings are allowed\.$"
    )
    @confoverrides(exhale_projects={"defcon1": {111: "not valid"}})
    def test_nested_non_string_key_exhale_projects(self):
        """Validate non-string key in nested ``exhale_projects['defcon1']`` raises ``ConfigError``."""
        pass

