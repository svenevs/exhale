########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

"""
Defines the core sphinx project based test case utilities.

All project based test cases should inherit from :class:`testing.base.ExhaleTestCase`.
"""

import os
import shutil
import unittest
from copy import deepcopy

import pytest

from six import with_metaclass

from .utils import deep_update


TEST_DOC_DIR = os.path.join(os.path.dirname(__file__), 'doc')
"""
The global testing directory.
"""


def make_default_config(project):
    """
    Return a default configuration for exhale.

    **Parameters**
        ``project`` (str)
            The name of the project that will be searched for in
            ``testing/projects/{project}``.

    **Return**
        ``dict``
            The global default testing configuration to supply to ``confoverrides``
            with ``@pytest.mark.sphinx``, these are values that would ordinarily be
            written in a ``conf.py``.
    """
    return {
        "breathe_projects": {
            project: "./_doxygen/xml"
        },
        "breathe_default_project": project,
        "exhale_args": {
            "containmentFolder": "./api",
            "rootFileName": "index.rst",
            "rootFileTitle": "API Documentation",
            "doxygenStripFromPath": "..",
            "exhaleExecutesDoxygen": True,
            "exhaleDoxygenStdin": "INPUT = ../projects/{0}/include".format(project)
        }
    }


class ExhaleTestCaseMetaclass(type):
    """
    Metaclass to enforce mandatory attributes on :class:`testing.base.ExhaleTestCase`.
    """

    def __new__(mcs, name, bases, attrs):
        """
        Return a new instance with the specified attributes.

        **Parameters**
            ``mcs`` (type)
                This metaclass (:class:`testing.base.ExhaleTestCaseMetaclass`).

            ``name`` (str)
                The name of the class being instantiated.

            ``bases`` (list)
                The list of base classes of ``name``.

            ``attrs`` (dict)
                The class-level attributes.  These will be inspected / modified as
                needed to produce a final class definition that can use sphinx test
                applications where desired.
        """
        if attrs['__module__'] != __name__ and attrs.get('test_project', None) is None:
            raise RuntimeError('ExhaleTestCase subclasses must define a "test_project" attribute')

        has_tests = False

        config = make_default_config(attrs['test_project'])
        deep_update(config, attrs.get('config', None))

        for n, attr in attrs.items():
            if callable(attr) and n.startswith('test_'):
                kwargs = dict(
                    testroot=TEST_DOC_DIR,
                    confoverrides=deepcopy(config)
                )

                try:
                    # if the method is already marked, we insert the default kwargs
                    # without overriding the specified ones (stored in attr.sphinx.kwargs

                    marker = attr.sphinx  # raises AttributeError if no existing marker

                    args = marker.args
                    deep_update(kwargs, marker.kwargs)
                    # we need to 'unmark' the method and then mark it again as the kwargs are not
                    # 'deep_update'ed within pytest's marking machinery

                    # first remove the sphinx marker info
                    delattr(attr, 'sphinx')

                    # then remove any marker with name 'sphinx'
                    # we need to pop in reverse otherwise it shifts the indexes
                    for i, m in zip(reversed(range(len(attr.pytestmark))), reversed(attr.pytestmark)):
                        if m.name == 'sphinx':
                            attr.pytestmark.pop(i)
                    if not attr.pytestmark:
                        delattr(attr, 'pytestmark')
                except AttributeError:
                    args = ()

                attrs[n], pytest.mark.sphinx(*args, **kwargs)(attr)

                has_tests = True

        if has_tests:
            def _set_app(self, app):
                self.app = app
                yield
                # cleanup
                dirs = [app.config.exhale_args['containmentFolder'], os.path.dirname(app.outdir)]
                for d in app.config.breathe_projects.values():
                    # get only first directory of breathe project directory relative to srcdir
                    dirs.append(os.path.relpath(os.path.join(app.srcdir, d), app.srcdir).split(os.sep)[0])
                for d in dirs:
                    if not os.path.isabs(d):
                        d = os.path.join(app.srcdir, d)
                    shutil.rmtree(d, ignore_errors=True)
            attrs['_set_app'] = pytest.fixture(autouse=True)(_set_app)

        return super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs)


class ExhaleTestCase(with_metaclass(ExhaleTestCaseMetaclass, unittest.TestCase)):
    """
    The primary project based test class to inherit from.

    The ``__metaclass__`` is set to :class:`testing.base.ExhaleTestCaseMetaclass`.
    Inherits from :class:`python:unittest.TestCase`.
    """

    test_project = None
    """
    The string representing the project to run Doxygen / exhale on.

    This value **must** be set in subclasses.
    """

    config = None
    """
    The dictionary of overrides to use for the whole class.

    This will be used to set and / or override configurations that would
    traditionally be included in a user's ``conf.py``.  Will override the defaults
    provided to the meta-class from :func:`testing.base.make_default_config`.
    """

    app = None
    """
    The Sphinx testing application.

    Will be automatically populated by the meta-class, in test-cases users may
    simply access the Sphinx application with ``self.app``.
    """
