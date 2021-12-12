Exhale
========================================================================================
|docs| |pypi| |coverage| |license|

.. begin_badges

.. |docs| image:: https://readthedocs.org/projects/exhale/badge/?version=latest
   :alt: Documentation Status
   :target: https://exhale.readthedocs.io/en/latest/?badge=latest

.. |pypi| image:: https://badge.fury.io/py/exhale.svg
   :alt: Latest Version
   :target: https://badge.fury.io/py/exhale

.. |coverage| image:: https://codecov.io/gh/svenevs/exhale/branch/master/graph/badge.svg
   :alt: Code Coverage Report
   :target: https://codecov.io/gh/svenevs/exhale

.. |license| image:: https://img.shields.io/github/license/svenevs/exhale.svg
   :alt: License BSD-3 Clause
   :target: https://github.com/svenevs/exhale/blob/master/LICENSE

.. end_badges

Automatic C++ library API documentation generator using Doxygen, Sphinx, and Breathe.
Exhale revives Doxygen's class, file, and page hierarchies in reStructuredText documents
to make these hierarchies available in Sphinx documented projects.

.. end_intro

.. contents:: Contents
   :local:
   :backlinks: none

.. _is_it_for_me:

Is it For Me?
----------------------------------------------------------------------------------------

Exhale might **not** be the tool you are looking for!  It was designed to be as
intuitive and flexible as possible, but it does require more machinery to get
everything started.

**Why use it?**
    You would use Exhale if you want to have beautiful Sphinx generated websites, but
    also see the value of the Class, File, and Page hierarchies provided by Doxygen.
    From running Doxygen for you, to organizing your full API every time, you won't need
    to worry about your documentation getting out of sync with the code --- it's
    regenerated on the fly every time.

**Why not use it?**
    It may be more involved than you need.  Check out the ``breathe-apidoc`` tool that
    comes with your installation of ``breathe``.  It is quite similar to the
    `Sphinx API doc tool <http://www.sphinx-doc.org/en/stable/man/sphinx-apidoc.html>`_,
    and that may be all you are looking for to get your documentation displayed.

    If you are working with a small enough framework, you may also be satisfied with
    just using the ``.. autodoxygenindex::`` directive from ``breathe``.  It works very
    well!

**The Main Difference**
    The Class, File, and Page hierarchies are only available in Sphinx via Exhale 😊

    Depending on the size and complexity of your project, ``breathe-apidoc`` or
    ``autodoxygenindex`` may be more appropriate.

**Important Consideration**
    Exhale is known to work well on small to medium sized projects.  Supporting larger
    projects in Sphinx is a much more involved process that may or may not be resolved
    over time -- this has to do with a lot more than just Exhale, but the nature of
    Exhale (generation of a large number of ``.rst`` files) definitely does not help.

Please see the `full documentation <https://exhale.readthedocs.io/en/latest>`_ for more
information on how to get started.

See it in Action
----------------------------------------------------------------------------------------

The `ExhaleCompanion <companion_>`_ repository has three builds to demonstrate the
different options with respect to creating a Tree View, as well as details of specific
HTML Theme choices:

+------------------------------+------------------+----------------------+
| HTML Theme Choice            | TreeView Created | ExhaleCompanion Docs |
+==============================+==================+======================+
| `RTD Theme <rtd_>`_          | Yes              | |rtd-docs|           |
+------------------------------+------------------+----------------------+
| `Bootstrap Theme <bstrap_>`_ | Yes              | |bootstrap-docs|     |
+------------------------------+------------------+----------------------+
| `Alabaster`_                 | No               | |alabaster-docs|     |
+------------------------------+------------------+----------------------+

.. _companion:  https://github.com/svenevs/exhale-companion

.. _rtd:       http://sphinx-rtd-theme.readthedocs.io/en/latest/
.. _bstrap:    https://ryan-roemer.github.io/sphinx-bootstrap-theme/
.. _alabaster: http://alabaster.readthedocs.io/en/latest/

.. |rtd-docs| image:: https://readthedocs.org/projects/my-favorite-documentation-test/badge/?version=latest
   :target: http://my-favorite-documentation-test.readthedocs.io/en/latest/

.. |bootstrap-docs| image:: https://readthedocs.org/projects/my-favorite-documentation-test/badge/?version=bootstrap
   :target: http://my-favorite-documentation-test.readthedocs.io/en/bootstrap

.. |alabaster-docs| image:: https://readthedocs.org/projects/my-favorite-documentation-test/badge/?version=alabaster
   :target: http://my-favorite-documentation-test.readthedocs.io/en/alabaster


Installation
----------------------------------------------------------------------------------------

Exhale is a `Sphinx Extension`__ that depends on `Breathe`_ for access to the Doxygen
reStructuredText directives, and both `BeautifulSoup`_ and `lxml`_ for parsing the
generated Doxygen XML documentation.  Exhale is `hosted on PyPI
<https://pypi.org/project/exhale/>`_, meaning you can install it through the normal
mechanisms, e.g.,

__ http://www.sphinx-doc.org/en/stable/extensions.html

.. _BeautifulSoup: https://www.crummy.com/software/BeautifulSoup/bs4/doc/
.. _lxml: http://lxml.de/
.. _Breathe: https://breathe.readthedocs.io/en/latest/

.. code-block:: console

   $ python -m pip install exhale

This will install Exhale, as well as all of its dependencies.

Exhale Version Compatibility with Python, Sphinx, and Breathe
----------------------------------------------------------------------------------------

+----------------+----------------+----------------+-----------------+
| Exhale Version | Python Version | Sphinx Version | Breathe Version |
+================+================+================+=================+
| 0.3.0          | >=3.6          | >=3.0,<5       | >=4.32.0        |
+----------------+----------------+----------------+-----------------+
| 0.2.1-0.2.4    | 2.7, 3.3+      | >=1.6.1        | "Any"           |
+----------------+----------------+----------------+-----------------+
| <=0.2.0        | 2.7, 3.3+      | >=1.0          | "Any"           |
+----------------+----------------+----------------+-----------------+

For your project's documentation requirements, adopting ``exhale@0.3.0`` means you just
need to specify directly that your ``docs/requirements.txt`` or similar express::

    exhale>=0.3.0

The ``exhale@0.3.0`` release uses the same dependencies required by ``breathe@4.32.0``.
If you need python 3.5 support, pin your documentation requirements to::

    sphinx>=2.0
    breathe>=4.13.0
    exhale<0.3.0

For Python 2.7, you should pin your documentation requirements to::

    sphinx==1.8.5
    breathe==4.12.0
    exhale<0.3.0

**Order matters**, namely that ``sphinx`` and ``breathe`` appear / are installed before
``exhale``.  Exhale 0.2.* releases support Python 2.7, but users need to be aware of the
dependencies between Python, Sphinx, and Breathe versions.

.. _credit:

Credit
----------------------------------------------------------------------------------------

This project could not exist without the already excellent tools available: Doxygen,
Sphinx, Breathe, and many others.  In particular, though, for the Tree View hierarchies
to be successful, I vendor copies of two excellent libraries that I make no claims to.
They are vendored with your installation of Exhale, in accordance with each project's
license:

1. For non-bootstrap, I used Kate Morley's excellent and lightweight collapsibleLists_
   including the sample CSS / images on that post.  She includes a generous
   `CC0 1.0 license <http://code.iamkate.com/>`_ for these files, as well as the rest of
   her website.

   For every HTML Theme I have tried, except for ones using bootstrap, this library
   works reliably and consistently.  It matches the Sphinx RTD theme quite well, too!

2. For bootstrap, I used Jon Miles' comprehensive `bootstrap-treeview`__ library.  Jon
   Miles hosts this library using the
   `Apache v2 license <https://github.com/jonmiles/bootstrap-treeview/blob/master/LICENSE>`_.

   This library is exceptionally well thought out and enables an impressive amount of
   customization.  At this time, Exhale does not expose any of the available
   customizations.  If there is a specific one you'd like to see, please join the
   `discussion here <https://github.com/svenevs/exhale/issues/7>`_.

Both of these libraries and copies of their licenses can be found in the
`data folder of the source code <https://github.com/svenevs/exhale/tree/master/exhale/data>`_.

.. _collapsibleLists: http://code.iamkate.com/javascript/collapsible-lists/

__ https://github.com/jonmiles/bootstrap-treeview

License
----------------------------------------------------------------------------------------

This project uses a BSD 3-clause license, in hopes that it will be accessible to most
projects.  If you require a different license, please raise an issue and I will consider
a dual license.

The full license is
`available here <https://github.com/svenevs/exhale/blob/master/LICENSE>`_.
