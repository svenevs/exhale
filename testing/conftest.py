# -*- coding: utf8 -*-
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

from __future__ import unicode_literals

import sys
import pytest

pytest_plugins = [
    'sphinx.testing.fixtures',
    'testing.fixtures'
]
"""Signals to ``pytest`` which plugins are needed for all tests."""


########################################################################################
# Below is a modification of the `pytest-raises` package to suit the needs of Exhale.  #
# When marking with `@pytest.mark.raises`, this is to test test exceptions raised by   #
# Exhale, which will actually happen during the test setup rather than the test body.  #
# See the full synopsis here: https://github.com/Authentise/pytest-raises/issues/9     #
########################################################################################
# The MIT License (MIT)                                                                #
#                                                                                      #
# Copyright (c) 2016 Scott Lemmon                                                      #
#                                                                                      #
# Permission is hereby granted, free of charge, to any person obtaining a copy         #
# of this software and associated documentation files (the "Software"), to deal        #
# in the Software without restriction, including without limitation the rights         #
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell            #
# copies of the Software, and to permit persons to whom the Software is                #
# furnished to do so, subject to the following conditions:                             #
#                                                                                      #
# The above copyright notice and this permission notice shall be included in           #
# all copies or substantial portions of the Software.                                  #
#                                                                                      #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR           #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,             #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE          #
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER               #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,        #
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN            #
# THE SOFTWARE.                                                                        #
########################################################################################
class ExpectedException(Exception):
    """
    Signal a test was expected to ``raise`` but did not, or wrong exception type raised.

    **See Also**
        :func:`pytest_runtest_setup <testing.conftest.pytest_runtest_setup>`
    """

    pass


class ExpectedMessage(Exception):
    """
    Signal a test raised an exception with a different message than expected.

    **See Also**
        :func:`pytest_runtest_setup <testing.conftest.pytest_runtest_setup>`
    """

    pass


@pytest.hookimpl(hookwrapper=True)
def pytest_runtest_setup(item):
    """
    Run test setup, taking special action when ``item`` is marked with ``raises``.

    When a test case for Exhale runs, exception tracking needs to happen during the test
    setup rather than the test call.  Modified from `pytest-raises`, the main change is
    that for Exhale the expected exceptions occur in the Sphinx fixtures, meaning we
    need to hook into ``pytest_runtest_setup`` rather than ``pytest_runtest_call`` (as
    the original does).

    .. _pytest-raises: https://github.com/Authentise/pytest-raises

    .. code-block:: py

       # In some subclass of testing.base.ExhaleTestCase.
       # Imported at top: from sphinx.errors import ConfigError
       @pytest.mark.raises(
           exception=ConfigError,
           message="The exact exception message."
       )
       @confoverrides(exhale_args={"someKey": "valueThatCausesException"})
       def test_some_thing(self):
           pass

    The above is a "complete" test case to test e.g. a user configuration error.

    .. note::

       In the case of Exhale, having a decorator ``@pytest.mark.raises`` is actually
       **required**  to properly test for exceptions (instead of using ``xfail``).  This
       means that if you need to test for an exception in a test function body, you must
       instead use the ``with`` statement:

       .. code-block:: py

          def test_some_internal_procedure(self):
              with pytest.raises(exception=RuntimeError, message="Assertion of death."):
                  exhale.function_being_tested()

       If you swap the ``with`` for the decorator, ``pytest`` will be halted by
       ``exhale.function_being_tested()`` since the decorator ``@pytest.mark.raises``
       checks for test *setup*, **not** test *execution*.

    **Parameters**
        ``item`` (:class:`pytest:_pytest.nodes.Item`)
            The test item.  If test setup raises an exception **and** the test was
            marked with ``raises``, the test will **fail** (since the test setup did not
            ``raise`` an exception).
    """
    outcome = yield
    raises_marker = item.get_marker('raises')
    if raises_marker:
        exception = raises_marker.kwargs.get('exception')
        exception = exception or Exception
        message = raises_marker.kwargs.get('message')

        raised_exception = outcome.excinfo[1] if outcome.excinfo else None
        traceback = outcome.excinfo[2] if outcome.excinfo else None
        if isinstance(raised_exception, exception):
            outcome.force_result(None)
            if message is not None:
                try:
                    raised_message = str(raised_exception)
                    if message not in raised_message:
                        raise ExpectedMessage('"{}" not in "{}"'.format(message, raised_message))
                except(ExpectedMessage):
                    excinfo = sys.exc_info()
                    if traceback:
                        outcome._excinfo = excinfo[:2] + (traceback, )
                    else:
                        outcome._excinfo = excinfo
        elif raised_exception:
            try:
                raise ExpectedException('Expected exception {}, but got {} with message: {}'.format(
                    exception, type(raised_exception), raised_exception
                ))
            except ExpectedException:
                excinfo = sys.exc_info()
                if traceback:
                    outcome._excinfo = excinfo[:2] + (traceback, )
                else:
                    outcome._excinfo = excinfo
        else:
            try:
                raise ExpectedException('Expected exception {}, but it did not raise'.format(exception))
            except ExpectedException:
                excinfo = sys.exc_info()
                if traceback:
                    outcome._excinfo = excinfo[:2] + (traceback, )
                else:
                    outcome._excinfo = excinfo
