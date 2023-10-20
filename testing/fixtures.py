########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2023, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Provides fixtures to be available for all test cases.
"""
from __future__ import unicode_literals
from exhale import deploy
import pytest


@pytest.fixture(scope="class")
def no_run():
    """
    Disable :func:`exhale.deploy.explode` using a class-level ``pytest`` `fixture`__.

    __ https://docs.pytest.org/en/latest/explanation/fixtures.html

    The fixture will temporarily assign ``lambda: None`` to ``deploy.explode``,
    restoring the original function after the test case has completed.  A class-scoped
    fixture is used so that this fixture is generated **before** others.

    .. See :func:`pytest:_pytest.FixtureManager.getfixtureclosure`.

    Search for ``def getfixtureclosure`` on `this page`__.

    __ https://docs.pytest.org/en/latest/_modules/_pytest/fixtures.html
    """
    explode = deploy.explode
    deploy.explode = lambda: None
    yield
    deploy.explode = explode
