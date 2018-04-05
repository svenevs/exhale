import unittest
from importlib import reload
import subprocess

from six import with_metaclass

from .mocks import SphinxAppMock
from .utils import cd, deep_update


class ExhaleTestCaseMetaclass(type):
    """
    Metaclass to enforce mandatory attributes on ExhaleTestCase
    """

    def __new__(cls, name, bases, attrs):
        if attrs['__module__'] != 'testing.base' and attrs.get('test_project', None) is None:
            raise RuntimeError('ExhaleTestCase subclasses must define a "test_project" attribute')
        return super(ExhaleTestCaseMetaclass, cls).__new__(cls, name, bases, attrs)


class ExhaleTestCase(with_metaclass(ExhaleTestCaseMetaclass, unittest.TestCase)):

    test_project = None
    config = None

    def configure(self):
        if getattr(self, 'app', False):
            pass
        from exhale import configs

        config = {
            'breathe_projects': {
                self.test_project: './_doxml'
            },
            'breathe_default_project': self.test_project,
            'exhale_args': {
                'containmentFolder': './api',
                'rootFileName': 'index.rst',
                'rootFileTitle': 'API Documentation',
                'doxygenStripFromPath': '..',
                'exhaleExecutesDoxygen': True,
                'exhaleDoxygenStdin': 'INPUT = ../include'
            }
        }

        app = SphinxAppMock(self.test_project, config=deep_update(config, self.config or {}))

        with cd(app.srcdir):
            reload(configs).apply_sphinx_configurations(app)
        self.app = app

    def run_exhale(self):
        self.configure()

        from exhale import configs, deploy

        if configs.exhaleExecutesDoxygen:
            # test that doxygen is installed
            try:
                out = subprocess.check_output(['doxygen', '--version'])
            except OSError:
                raise RuntimeError(
                    'doxygen must be installed to run exhale with exhaleExecutesDoxygen = True'
                )

        with cd(self.app.srcdir):
            deploy.explode()

    def teardown_method(self, method):
        try:
            del self.app
        except AttributeError:
            pass
