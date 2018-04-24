########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

"""
Global ``pytest`` configurations that are used / executed for every test.

See ``pytest`` documentation on `Package/Directory-level fixtures (setups)`__.

__ https://docs.pytest.org/en/latest/example/simple.html#package-directory-level-fixtures-setups
"""

pytest_plugins = [
    'sphinx.testing.fixtures',
    'testing.fixtures'
]
"""Signals to ``pytest`` which plugins are needed for all tests."""
