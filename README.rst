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

.. begin_exhale_brief_desc

Automatic C++ library API documentation generator using Doxygen, Sphinx, and Breathe.
Exhale revives Doxygen's class / file hierarchies using reStructuredText for superior
markup syntax / websites.

.. end_exhale_brief_desc

.. contents:: Contents
   :local:
   :backlinks: none

.. begin_exhale_long_desc

Exhale is a `Sphinx <http://www.sphinx-doc.org/en/stable/>`_ extension that depends on
the excellent `Breathe`_ extension which enables parsing Doxygen documentation into the
Sphinx domain.  Exhale provides a layer of automation, enabling launching Doxygen and
generating the full website all from your ``conf.py``.  Exhale will execute these
actions by way of ``sphinx-build`` being invoked, allowing you to use it for hosting on
`Read the Docs <https://readthedocs.org/>`_.  Exhale was designed for generating html
output, and may not be appropriate for other builders provided by Sphinx.

.. _Breathe: http://breathe.readthedocs.io/en/latest

.. end_exhale_long_desc

See it in Action
----------------------------------------------------------------------------------------

.. begin_in_action

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

.. end_in_action

.. begin_installation

Installation
----------------------------------------------------------------------------------------

Exhale is a `Sphinx Extension`__ that depends on `Breathe`_ for access to the Doxygen
reStructuredText directives, and both `BeautifulSoup`_ and `lxml`_ for parsing the
generated Doxygen XML documentation.  Exhale also uses `six`_ help account for the
Python 2 unicode dilemma.  The easiest way to install Exhale is:

__ http://www.sphinx-doc.org/en/stable/extensions.html

.. _BeautifulSoup: https://www.crummy.com/software/BeautifulSoup/bs4/doc/
.. _lxml: http://lxml.de/
.. _six: https://six.readthedocs.io/

.. code-block:: bash

   # NOTE: see version compatibility notes below.
   $ pip install exhale

This will install Exhale, as well as all of its dependencies.

.. note::

   If you fail ``pip install exhale`` and it is failing on ``lxml``, you will likely
   need to install the proper development libraries.  See the
   `lxml installation instructions`__ for possible fixes.

   ``lxml`` **is readily available for Read The Docs** and generally installs
   seamlessly for Unix systems, but my understanding is Windows users may need to put a
   little more effort in to get it to install.

   __ http://lxml.de/installation.html

.. end_installation

.. begin_version_compatibility

.. _version_compatibility:

Exhale Version Compatibility with Python, Sphinx, and Breathe
----------------------------------------------------------------------------------------

+----------------+----------------+----------------+-----------------+
| Exhale Version | Python Version | Sphinx Version | Breathe Version |
+================+================+================+=================+
| 0.2.1-0.2.3    | 2.7, 3.3+      | >=1.6.1        | "Any"           |
+----------------+----------------+----------------+-----------------+
| <=0.2.0        | 2.7, 3.3+      | >=1.0          | "Any"           |
+----------------+----------------+----------------+-----------------+

Sphinx 2.0 requires Python 3.5+.  Breathe 4.13.0 drops support for Sphinx<2.0 in better
support of the Sphinx C++ domain.

Implications:

- **Unless you have a genuine need for Python 2.7**, you will be better served by
  pinning ``sphinx>=2.0`` and ``breathe>=4.13.0``.  It has many important improvements.

- For Python 3.5+, you should pin your documentation requirements to::

    sphinx>=2.0
    breathe>=4.13.0
    exhale

- For Python 2.7, you should pin your documentation requirements to::

    sphinx==1.8.5
    breathe==4.12.0
    exhale

**Order matters**, namely that ``sphinx`` and ``breathe`` appear / are installed before
``exhale``.  Exhale 0.* releases will continue support Python 2.7, but users need to be
aware of the dependencies between Python, Sphinx, and Breathe versions.

.. end_version_compatibility

Usage
----------------------------------------------------------------------------------------

See the `full documentation and usage guide`__.

__ http://exhale.readthedocs.io/en/latest

.. begin_exhale_is_it_for_me

Exhale might **not** be the tool you are looking for!  It was designed to be as
intuitive and flexible as possible, but it does require more machinery to get
everything started.

**Why use it?**
    You would use Exhale if you want to have beautiful Sphinx generated websites, but
    also see the value of the Class and File hierarchies provided by Doxygen.  From
    running Doxygen for you, to organizing your full API every time, you won't need to
    worry about your documentation getting out of sync with the code --- it's
    regenerated on the fly every time.

**Why not use it?**
    It may be more involved than you need.  Check out the ``breathe-apidoc`` tool
    that comes with your installation of ``breathe``.  It is quite similar to the
    `Sphinx API doc tool <http://www.sphinx-doc.org/en/stable/man/sphinx-apidoc.html>`_,
    and that may be all you are looking for to get your documentation displayed.

    If you are working with a small enough framework, you may also be satisfied with
    just using the ``.. autodoxygenindex::`` directive from ``breathe``.  It works very
    well!

**The Main Difference**
    The Class and File hierarchies are only available in Sphinx via Exhale 😊

    Depending on the size and complexity of your project, ``breathe-apidoc`` or
    ``autodoxygenindex`` may be more appropriate.

.. end_exhale_is_it_for_me

.. begin_quickstart_guide

Quickstart Guide
----------------------------------------------------------------------------------------

You will need to edit **2** files: ``conf.py`` to configure the extensions, and
``index.rst`` (or whatever document you choose) to include the generated api in a
``toctree`` directive.

Setup the Extensions in ``conf.py``
****************************************************************************************

Assuming your Doxygen documentation is in order, and you already have your Sphinx
project ready to go, we need to configure the Breathe and Exhale extensions.  For this
guide I assume the following directory structure::

    my_project/
    │
    ├── docs/
    │   ├── conf.py
    │   └── index.rst
    │
    ├── include/
    │   └── common.hpp
    │
    └── src/
        └── common.cpp

This structure is not required, but you'll need to change values accordingly.

.. warning::

   When using *relative* paths, these are always relative to ``conf.py``.  In the above
   structure I do **not** have a "separate source and build directory" from Sphinx.  If
   you do, make sure you are using the correct paths.

.. code-block:: py

   # The `extensions` list should already be in here from `sphinx-quickstart`
   extensions = [
       # there may be others here already, e.g. 'sphinx.ext.mathjax'
       'breathe',
       'exhale'
   ]

   # Setup the breathe extension
   breathe_projects = {
       "My Project": "./doxyoutput/xml"
   }
   breathe_default_project = "My Project"

   # Setup the exhale extension
   exhale_args = {
       # These arguments are required
       "containmentFolder":     "./api",
       "rootFileName":          "library_root.rst",
       "doxygenStripFromPath":  "..",
       # Heavily encouraged optional argument (see docs)
       "rootFileTitle":         "Library API",
       # Suggested optional arguments
       "createTreeView":        True,
       # TIP: if using the sphinx-bootstrap-theme, you need
       # "treeViewIsBootstrap": True,
       "exhaleExecutesDoxygen": True,
       "exhaleDoxygenStdin":    "INPUT = ../include"
   }

   # Tell sphinx what the primary language being documented is.
   primary_domain = 'cpp'

   # Tell sphinx what the pygments highlight language should be.
   highlight_language = 'cpp'

With the above settings, Exhale would produce the ``docs/api`` folder, the file
``docs/api/library_root.rst`` (among many others), and it would use Doxygen to parse
``docs/../include`` and save the output in ``docs/doxyoutput``.  Meaning the following
structure would be created::

    my_project/
    ├── docs/
    │   ├── api/
    │   │   └── library_root.rst
    │   │
    │   ├── conf.py
    │   ├── index.rst
    │   │
    │   └── doxyoutput/
    │       └── xml/
    │           └── index.xml
    │
    ├── include/
    │   └── common.hpp
    │
    └── src/
        └── common.cpp

.. note::

   You are by no means required to use Exhale to generate Doxygen.  If you choose not to
   I assume you have the wherewithal to figure it out on your own.

Make Your Documentation Link to the Generated API
****************************************************************************************

So the final step is, in your ``index.rst`` or some other ``toctree`` directive, tell
Sphinx to link in the generated ``"{containmentFolder}/{rootFileName}"`` document:

.. begin_strip_raw_for_pypi:

.. raw:: html

   <div class="highlight-rest">
     <div class="highlight">
       <pre>
   .. toctree::
      :maxdepth: 2

      about
      <b>api/library_root</b></pre>
     </div>
   </div>

.. end_strip_raw_for_pypi:

.. _quickstart_clean_target:

Optional: Create a Proper Clean Target
****************************************************************************************

The ``sphinx-quickstart`` utility will create a ``Makefile`` for you, you are advised
to create an *explicit* ``clean`` target that removes the generated utilities.

1. You can just as easily specify to ``breathe_projects`` a path such as
   ``_build/doxyoutput/xml``, or ``../build/doxyoutput/xml`` if you have separate source
   and build directories.  This will ensure that a ``make clean`` will delete these.

   To avoid confusing users who are new to Sphinx, I encourage something in the same
   directory as ``conf.py`` for simplicity.

2. The generated API **must** appear in the Sphinx source directory.  If you put it
   under ``_build``, it will not get parsed.

So bust out the ``Makefile`` provided by Sphinx Quickstart and add ``clean`` to the
``.PHONY`` line, and the ``clean`` target as shown below (assuming you've been using
the paths specified above):

.. code-block:: make

   .PHONY: help Makefile clean

   clean:
       rm -rf doxyoutput/ api/
       @$(SPHINXBUILD) -M clean "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.. danger::

   ``make`` **requires** ``TAB`` characters!  If you just copy-pasted that, **you got
   space characters** (sorry).

.. note::

   The above code **must** appear **before** the ``%: Makefile`` "catch-all" target that
   Sphinx produced by default.  Otherwise...well the catch-all target catches all!

.. end_quickstart_guide

Participate
----------------------------------------------------------------------------------------

If you find a problem or think there is something that should change, please submit an
issue (or pull request!) explaining what should change.  I made this because it was
something I really wanted, and felt the community at large could benefit from as well.
I put a lot of effort into making it flexible, but it is by no means perfect.

Credit
----------------------------------------------------------------------------------------

.. begin_credit

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

.. end_credit

License
----------------------------------------------------------------------------------------

This project uses a BSD 3-clause license, in hopes that it will be accessible to most
projects.  If you require a different license, please raise an issue and I will consider
a dual license.

The full license is
`available here <https://github.com/svenevs/exhale/blob/master/LICENSE>`_.
