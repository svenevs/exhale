import os
from inspect import isclass
from copy import deepcopy

import pytest
import shutil
import textwrap

from .utils import deep_update

__all__ = ['default_confoverrides', 'confoverrides', 'no_run']


def _apply_confoverride_to_class(cls, config, priority):
    """
    Apply a configuration override ``config`` to class ``cls`` with a given priority.

    We need the priority trick as the default configuration is applied before a possible
    class-wide decorator, which should supersede the default configuration.  We use
    ``pytest.mark.exhale`` as a store of ``kwargs`` to apply to ``pytest.mark.sphinx``,
    and we use the priority to combine these kwargs with respect to priorities.
    """

    # look for test methods in the class
    for name, meth in cls.__dict__.items():
        if not callable(meth) or not name.startswith('test_'):
            continue

        # meth is a test method, let's go and mark it!

        # create marker kwargs
        kwargs = dict(confoverrides=deepcopy(config))

        # apply the exhale marker to the method, so that priority is saved
        meth = pytest.mark.exhale(priority, **kwargs)(meth)

        # create a list of exhale markers kwargs
        markers_kwargs = []
        for m in meth.exhale._marks:
            markers_kwargs.append((m.args[0], m.kwargs))
        # sort that list according to priority
        markers_kwargs.sort(key=lambda m: m[0])

        # now we can generate the sphinx fixture kwargs by combining the above list of
        # kwargs depending on priority
        sphinx_kwargs = {'testroot': cls.testroot}
        for __, kw in markers_kwargs:
            deep_update(sphinx_kwargs, kw)

        ################################################################################
        # Automatically create docs/{conf.py,index.rst} for the test project.          #
        ################################################################################
        def _with_docs_dir(self):
            # Create the test project's 'docs' dir with a conf.py and index.rst.
            if os.path.isdir(self.testroot):
                shutil.rmtree(self.testroot)
            os.makedirs(self.testroot)
            # Sphinx demands a `conf.py` is present
            with open(os.path.join(self.testroot, "conf.py"), "w") as conf_py:
                conf_py.write(textwrap.dedent('''\
                    # -*- coding: utf-8 -*-
                    extensions = ["breathe", "exhale"]
                    master_doc = "index.rst"
                '''))

            # If a given test case needs to run app.build(), make sure index.rst
            # is available as well
            cls_exhale_args = sphinx_kwargs["confoverrides"]["exhale_args"]
            with open(os.path.join(self.testroot, "index.rst"), "w") as index_rst:
                index_rst.write(textwrap.dedent('''
                    Exhale Test Case
                    ================

                    .. toctree::
                       :maxdepth: 2

                       {containmentFolder}/{rootFileName}
                '''.format(
                    containmentFolder=cls_exhale_args["containmentFolder"],
                    rootFileName=cls_exhale_args["rootFileName"]
                )))

            # Let all of the tests run for this project
            yield

            # Delete the docs dir
            if os.path.isdir(self.testroot):
                shutil.rmtree(self.testroot)

        # Create the class-level fixture for creating / deleting the docs/ dir
        with_docs_dir_meth = pytest.fixture(scope="class", autouse=True)(_with_docs_dir)

        # and finally we set the sphinx markers with the combined kwargs, that override
        # the previous ones
        setattr(cls, name, pytest.mark.sphinx(**sphinx_kwargs)(with_docs_dir_meth))

    return cls


def default_confoverrides(cls, config):
    """
    Applies the default configuration config to test class cls
    This configuration is set with a priority of 1 so that it is overridden by the @confoverrides decorator
    applied to test classes and methods
    """
    return _apply_confoverride_to_class(cls, config, 1)


def confoverrides(**config):
    """
    Decorator that overrides the default sphinx configuration
    generated from :func:`testing.base.make_default_config`. It can
    be applied to a test method or a test class, which is equivalent
    to decorating every method in that class

    Usage::

       @confoverrides(var1=value1, var2=value2)
       def test_something(self):
           ...

    or::

       @confoverrides(var1=value1, var2=value2)
       class MyTestCase(ExhaleTestCase):
           test_project = 'my_project'
           ...
    """

    def actual_decorator(meth_or_cls):
        if not config:
            return meth_or_cls

        if isclass(meth_or_cls):
            return _apply_confoverride_to_class(meth_or_cls, config, 2)
        else:
            return pytest.mark.exhale(3, confoverrides=config)(meth_or_cls)

    return actual_decorator


def no_run(obj):
    """
    Decorator that disables the generation of ``*.rst`` files in a
    specific test method. It can be applied to a test class, which
    will be equivalent to decorating every method in that class

    Usage::

       @no_run
       def test_something(self):
           ...

    or::

       @no_run
       class MyTestCase(ExhaleTestCase):
           test_project = 'my_project'
           ...

    """
    return pytest.mark.usefixtures('no_run')(obj)
