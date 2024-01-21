########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
The decorators module defines useful class / function decorators for test cases.
"""

from copy import deepcopy
from inspect import isclass

import pytest

from .utils import deep_update


__all__ = ["default_confoverrides", "confoverrides", "no_run"]


def _apply_confoverride_to_class(cls, config, priority):
    """
    Apply a configuration override ``config`` to class ``cls`` with a given priority.

    We need the priority trick as the default configuration is applied before a possible
    class-wide decorator, which should supersede the default configuration.  We use
    ``pytest.mark.exhale`` as a store of ``kwargs`` to apply to ``pytest.mark.sphinx``,
    and we use the priority to combine these kwargs with respect to priorities.

    This method performs the ultimate ``pytest.mark.sphinx``.

    **Parameters**
        ``cls`` (Subclass of :class:`testing.base.ExhaleTestCase`)
            The class to apply the ``confoverride`` to.

        ``config`` (:class:`python:dict`)
            The dictionary of ``confoverrides`` as would be supplied to
            ``pytest.mark.sphinx``.  These are the overrides to ``conf.py``.

        ``priority`` (:class:`python:int`)
            The positive integer indicating the priority of the new ``config`` updates,
            higher values take precedence over lower values.

            For example, when :func:`testing.decorators.default_confoverrides` calls
            this function, the priority is ``1``.  When the decorator
            :func:`testing.decorators.confoverrides` is applied to a class, the priority
            is ``2``.  Finally, when :func:`testing.decorators.confoverrides` is applied
            to a test function, its priority is ``3``.  Thus the function-level override
            has the highest priority, meaning any conflicting values with lower level
            priorities will lose out to the function-level override.

    **Return**
        Subclass of :class:`testing.base.ExhaleTestCase`
            The input ``cls`` is returned.
    """
    # look for test methods in the class
    for name, meth in cls.__dict__.items():
        if not callable(meth) or not name.startswith("test_"):
            continue

        # meth is a test method, let's go and mark it!

        # create marker kwargs
        kwargs = dict(confoverrides=deepcopy(config))

        # apply the exhale marker to the method, so that priority is saved
        meth = pytest.mark.exhale(priority, **kwargs)(meth)

        # create a list of exhale markers kwargs
        markers_kwargs = []
        if getattr(meth, "pytestmark", False):
            for mark in meth.pytestmark:
                if mark.name == "exhale":
                    # mark.args[0]: the priority from pytest.mark.exhale
                    # mark.kwargs: the kwargs to override with said priority
                    markers_kwargs.append((mark.args[0], mark.kwargs))

        # sort that list according to priority
        markers_kwargs.sort(key=lambda m: m[0])

        # now we can generate the sphinx fixture kwargs by combining the above list of
        # kwargs depending on priority
        sphinx_kwargs = {}
        for __, kw in markers_kwargs:
            deep_update(sphinx_kwargs, kw)

        # and finally we set the sphinx markers with the combined kwargs, that override
        # the previous ones
        setattr(cls, name, pytest.mark.sphinx(**sphinx_kwargs)(meth))

    return cls


def default_confoverrides(cls, config):
    """
    Apply the default configuration config to test class ``cls``.

    This configuration is set with a priority of ``1`` so that it may be overridden by
    the :func:`testing.decorators.confoverrides` decorator applied to test classes and
    functions.

    **Parameters**
        ``cls`` (Subclass of :class:`testing.base.ExhaleTestCase`)
            The class to apply the ``config`` dictionary as ``confoverrides`` to.

        ``config`` (:class:`python:dict`)
            The dictionary of ``confoverrides`` as would be supplied to
            ``pytest.mark.sphinx``.  These are the overrides to ``conf.py``.

    **Return**
        Subclass of :class:`testing.base.ExhaleTestCase`
            The input ``cls`` is returned.
    """
    return _apply_confoverride_to_class(cls, config, 1)


def confoverrides(**config):
    """
    Override the defaults of |make_default_config| to supply to ``pytest.mark.sphinx``.

    .. |make_default_config| replace:: :func:`testing.base.make_default_config`

    It can be applied to a test method or a test class, which is equivalent to
    decorating every method in that class.

    Usage:

    .. code-block:: py

       @confoverrides(var1=value1, var2=value2)
       def test_something(self):
           ...

    or:

    .. code-block:: py

       @confoverrides(var1=value1, var2=value2)
       class MyTestCase(ExhaleTestCase):
           test_project = 'my_project'
           ...

    Typical usage of this decorator is to modify a value in ``exhale_args``, such as

    .. code-block:: py

       @confoverrides(exhale_args={"containmentFolder": "./alt_api"})
       def test_alt_out(self):
          ...

    However, this decorator can be used to change or set any value you would typically
    find in a ``conf.py`` file.

    **Parameters**
        ``**config`` (:class:`python:dict`)
            The dictionary of ``confoverrides`` as would be supplied to
            ``pytest.mark.sphinx``.  These are the overrides to ``conf.py``.

    **Return**
        (``class`` or :data:`python:types.FunctionType`)
            The decorated class or function.
    """
    def actual_decorator(meth_or_cls):
        if not config:
            return meth_or_cls

        if isclass(meth_or_cls):
            return _apply_confoverride_to_class(meth_or_cls, config, 2)
        else:
            return pytest.mark.exhale(3, confoverrides=config)(meth_or_cls)

    return actual_decorator


def no_cleanup(method):
    """
    Prevent the "docs" directory and generated Doxygen / API from being deleted.

    Usage:

    .. code-block:: py

       class CMathsTests(ExhaleTestCase):
           # docs dir, generated API, and Doxygen will not be deleted so that you can
           # inspect what may be causing your test to fail
           @no_cleanup
           def test_being_developed(self):
               pass

    .. danger::

       This decorator performs ``self.testroot = [self.testroot]`` as an internal bypass
       to the fixtures created in ``__new__`` for the metaclass.  Specifically, the
       fixtures generated check ``if isinstance(self.testroot, six.string_types)``.

       As such, since ``self.testroot`` may be desired in the given ``@no_cleanup``
       function, you must acquire it with ``testroot = self.testroot[0]``.  This is a
       hacky solution, but should be sufficient.  You have been warned.

    **Parameters**
        ``method`` (:data:`python:types.FunctionType`)
            **Must** be an instance-level testing function of a derived type of
            :class:`testing.base.ExhaleTestCase`.  The function should have only a
            single parameter ``self``.

    **Return**
        (:data:`python:types.FunctionType`)
            The decorated function, which simply calls the provided function and sets
            ``self.testroot = None``.  Click on ``[source]`` link for
            :func:`ExhaleTestCaseMetaclass.__new__ <testing.base.ExhaleTestCaseMetaclass.__new__>`
            and search for ``@no_cleanup`` to see how this prevents cleanup.
    """
    def actual_no_cleanup(self):
        self.testroot = [self.testroot]
        method(self)
    return actual_no_cleanup


def no_run(obj):
    """
    Disable the generation of ``*.rst`` files in a specific test method.

    It can be applied to a test class, which will be equivalent to decorating every
    method in that class.

    Usage:

    .. code-block:: py

       @no_run
       def test_something(self):
           ...

    or:

    .. code-block:: py

       @no_run
       class MyTestCase(ExhaleTestCase):
           test_project = 'my_project'
           ...

    Internally this will use the :func:`testing.fixtures.no_run` fixture.

    **Parameters**
        ``obj`` (``class`` or :data:`python:types.FunctionType`)
            The class or function to disable exhale from generating reStructuredText
            documents for.

    **Return**
        ``class`` or :data:`python:types.FunctionType`
            The decorated ``obj``.
    """
    return pytest.mark.usefixtures("no_run")(obj)
