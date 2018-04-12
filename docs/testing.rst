Testing Suite
========================================================================================
|travis| |appveyor| |coverage|

.. include:: ../README.rst
   :start-after: begin_badges
   :end-before:  end_badges

Exhale uses `pytest <https://docs.pytest.org/en/latest/>`_ for its testing suite.  To
run the tests, Exhale uses `tox <https://tox.readthedocs.io/en/latest/>`_.

.. code-block:: console

   $ pip3 install tox
   $ cd /path/to/exhale
   $ tox

.. note::

   See ``tox.ini`` in the root of the repository.  You only need to install ``tox`` to
   be able to run the tests, which will internally download the additional dependencies
   such as ``pytest``.  The tests will be run in a virtual environment.

Running Specific Tests
----------------------------------------------------------------------------------------

By default, ``tox`` will run the python tests and linting checks with
`flake8 <http://flake8.pycqa.org/en/latest/>`_.  More formally, the default environment
list is defined as:

.. code-block:: ini

   [testenv]
   envlist = py, flake8

This means that the version of python the tests are run with are the interpretor that
you installed ``tox`` for.  To run just one or the other, use

.. code-block:: console

   # Run just the python tests
   $ tox -e py

   # Run just the flake8 tests
   $ tox -e flake8

There is an additional testing suite available for the documentation, which you can
launch with ``tox -e docs``.  This will build the Exhale documentation using Sphinx with
both the ``html`` and ``linkcheck`` builders.

.. tip::

   If you need to debug a test case to discern why it is failing, the vibrantly colorful
   `ipdb <https://pypi.python.org/pypi/ipdb>`_ debugger is already installed in the
   environment running the tests.  It is nearly identical to ``pdb``, and although it
   is designed for IPython, it works just as well in "regular" code.  Just like with
   ``pdb``, set a trace in the test case you are debugging:

   .. code-block:: py

      import ipdb
      ipdb.set_trace()

   In order to be able to achieve the break-point, you would launch the tests with

   .. code-block:: console

      $ tox -e py -- -s

   The ``--`` signals that the command line arguments for ``tox`` are complete, and
   everything afterward should be forwarded to the specified environment (in this case
   to ``pytest`` since we launched ``-e py``).  The ``-s`` switch for ``pytest`` enables
   the debugger to stop the test, without this flag the test will fail at the
   break-point.

   The same goes for other test cases, if you need to specify a flag to ``flake8`` for
   some reason you would run ``tox -e flake8 -- --ignore XYYY`` where ``XYYY`` is the
   linter check you want to ignore.

Writing Project Test Cases
----------------------------------------------------------------------------------------

.. todo::

   Finalize these docs.

   1. Create the new test-case folder in ``testing/projects/{new project name}``.
   2. Inherit from :class:`testing.base.ExhaleTestCase`, setting the required
      class-level variables.
   3. ``pytest`` works by searching for all methods that start with ``test_`` or
      end with ``_test``.  For consistency with the other tests, please use a ``test_``
      prefix.

      - available decorators

Full Testing Suite Documentation
----------------------------------------------------------------------------------------

.. toctree::
   :maxdepth: 2

   testing/base
