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

import os
import shutil
import textwrap

from testing.base import ExhaleTestCase

pytest_plugins = [
    'sphinx.testing.fixtures',
    'testing.fixtures'
]
"""Signals to ``pytest`` which plugins are needed for all tests."""


def pytest_runtest_setup(item):
    """
    Create a "docs" directory for the given test case.

    When ``item.cls`` is available and is a subclass of
    :class:`testing.base.ExhaleTestCase`, this means that ``item.name`` is the
    test case function of the class that defined this.

    Consider the class

    .. code-block:: py

       class CMathsTests(ExhaleTestCase):
           test_project = 'c_maths'

           def test_app(self): pass

    Then when ``CMathsTests.test_app`` is being setup by ``pytest``:

    - ``item.cls`` will be ``CMathsTests``, which is a subclass of
      :class:`testing.base.ExhaleTestCase`.
    - ``item.name`` will be ``test_app``, which is assumed to be a key in
      :data:`testing.base.ExhaleTestCase.func_to_sphinx_map`.

    Using ``sphinx_kwargs = item.cls.func_to_sphinx_map[item.name]``, the values in this
    dictionary are the exact values specified to the sphinx backend, which will include
    ``"testroot"`` and ``"exhale_args"`` keys among others.  Using this information:

    1. The ``sphinx_kwargs["testroot"]`` directory will be created.

    2. The file ``{testroot}/conf.py`` will be created with the following contents:

       .. code-block:: py

          # -*- coding: utf-8 -*-
          extensions = ["breathe", "exhale"]
          master_doc = "index.rst"

       All remaining ``conf.py`` values are specified via
       ``sphinx_kwargs["confoverrides"]``, we just need a ``conf.py`` to be present.

    3. The file ``{testroot}/index.rst`` will be created with the following contents:

       .. code-block:: rst

          Exhale Test Case
          ================

          .. toctree::
             :maxdepth: 2

             {containmentFolder}/{rootFileName}

       Where ``{containmentFolder}`` and ``{rootFileName}`` are extracted from the final
       ``sphinx_kwargs["confoverrides"]["exhale_args"]`` for the given test.

    The ``conf.py`` is required to exist by the sphinx testing functions, and the
    ``index.rst`` is generated to allow for the event that a given test function wants
    to actually run the sphinx builder (e.g., via ``self.app.build()``).  However, the
    majority of the settings provided to sphinx are via the ``confoverrides``.

    **Parameters**
        ``item`` (:class:`pytest:_pytest.nodes.Item`)
            The test case to run setup for.
    """
    cls = getattr(item, "cls", None)
    if issubclass(cls, ExhaleTestCase):
        sphinx_kwargs = cls.func_to_sphinx_map[item.name]
        testroot = sphinx_kwargs["testroot"]
        item.add_report_section(
            "setup", "stdout", "Create: {0}/{{conf.py,index.rst}}".format(testroot)
        )
        if os.path.isdir(testroot):
            shutil.rmtree(testroot)
        os.makedirs(testroot)

        exhale_args = sphinx_kwargs["confoverrides"]["exhale_args"]
        containmentFolder = exhale_args["containmentFolder"]
        rootFileName = exhale_args["rootFileName"]
        # Sphinx demands a `conf.py` is present
        with open(os.path.join(testroot, "conf.py"), "w") as conf_py:
            conf_py.write(textwrap.dedent('''\
                # -*- coding: utf-8 -*-
                extensions = ["breathe", "exhale"]
                master_doc = "index.rst"
            '''))
        # If a given test case needs to run app.build(), make sure index.rst
        # is available as well
        with open(os.path.join(testroot, "index.rst"), "w") as index_rst:
            index_rst.write(textwrap.dedent('''
                Exhale Test Case
                ================

                .. toctree::
                   :maxdepth: 2

                   {containmentFolder}/{rootFileName}
            '''.format(
                containmentFolder=containmentFolder,
                rootFileName=rootFileName
            )))


def pytest_runtest_teardown(item, nextitem):
    """
    Remove the "docs" directory for a given test case.

    Similar to :func:`testing.conftest.pytest_runtest_setup`, when ``item.cls`` is a
    subclass of :class:`testing.base.ExhaleTestCase`, ``item.name`` is used to lookup in
    the class level mapping :data:`testing.base.ExhaleTestCase.func_to_sphinx_map`.  The
    ``"testroot"`` key in ``item.cls.func_to_sphinx_map[item.name]`` is the directory
    that will be deleted.

    **Parameters**
        ``item`` (:class:`pytest:_pytest.nodes.Item`)
            The test function to provide teardown for.

        ``nextitem`` (:class:`pytest:_pytest.nodes.Item`)
            Unused.  See :func:`pytest:_pytest.hookspec.pytest_runtest_teardown`.
    """
    cls = getattr(item, "cls", None)
    if issubclass(cls, ExhaleTestCase):
        sphinx_kwargs = cls.func_to_sphinx_map[item.name]
        testroot = sphinx_kwargs["testroot"]
        item.add_report_section("teardown", "stdout", "Delete: {0}".format(testroot))
        if os.path.isdir(testroot):
            shutil.rmtree(testroot)
