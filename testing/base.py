import os
import shutil
import unittest

from six import with_metaclass

import pytest

from .utils import deep_update


TEST_DOC_DIR = os.path.join(os.path.dirname(__file__), 'doc')


def make_default_config(project):
    """
    Creates a default configuration for exhale
    """
    return {
        'breathe_projects': {
            project: './_doxy/xml'
        },
        'breathe_default_project': project,
        'exhale_args': {
            'containmentFolder': './api',
            'rootFileName': 'index.rst',
            'rootFileTitle': 'API Documentation',
            'doxygenStripFromPath': '..',
            'exhaleExecutesDoxygen': True,
            'exhaleDoxygenStdin': 'INPUT = ../projects/%s/include' % project
        }
    }


class ExhaleTestCaseMetaclass(type):
    """
    Metaclass to enforce mandatory attributes on ExhaleTestCase
    """

    def __new__(mcs, name, bases, attrs):
        if attrs['__module__'] != __name__ and attrs.get('test_project', None) is None:
            raise RuntimeError('ExhaleTestCase subclasses must define a "test_project" attribute')

        has_tests = False

        config = make_default_config(attrs['test_project'])
        deep_update(config, attrs.get('config', None))

        for name, attr in attrs.items():
            if callable(attr) and name.startswith('test_'):
                attrs[name] = pytest.mark.sphinx(
                    testroot=TEST_DOC_DIR,
                    confoverrides=config
                )(attr)
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
                    shutil.rmtree(d)
            attrs['_set_app'] = pytest.fixture(autouse=True)(_set_app)

        return super(ExhaleTestCaseMetaclass, mcs).__new__(mcs, name, bases, attrs)


class ExhaleTestCase(with_metaclass(ExhaleTestCaseMetaclass, unittest.TestCase)):

    # the project that should be used to run doxygen/exhale on
    # must be set in subclasses
    test_project = None

    # configuration overrides for the whole class
    config = None

    # app will be populated by the metaclass with a Sphinx app before each test
    app = None
