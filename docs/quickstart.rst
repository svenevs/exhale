.. _quickstart_guide:

Quickstart Guide
========================================================================================

You will need to edit **2** files: ``conf.py`` to configure the extensions, and
``index.rst`` (or whatever document you choose) to include the generated api in a
``toctree`` directive.  Both ``conf.py`` and ``index.rst`` are part of a default Sphinx
documentation project, the next section will walk you through how to create a new Sphinx
project and the subsequent sections explain the modifications required on each document.

.. contents:: Contents
   :local:
   :backlinks: none

Getting Started with Sphinx
----------------------------------------------------------------------------------------

To get a project started with Sphinx, we will want to run the ``sphinx-quickstart``
utility.  Assuming you are already working in a git repsoitory, the canonical location
to do this in would be ``{repo_root}/docs``.  So let's go ahead and make that folder
and get our Sphinx project started:

.. code-block:: console

    $ cd /path/to/my/repo
    $ mkdir docs
    $ cd docs

The output below is getting broken up into sections to explain what is happening, but
when you run this from your terminal you will need to of course complete it from start
to finish.

.. code-block:: console

    $ sphinx-quickstart
    Welcome to the Sphinx 4.3.1 quickstart utility.

    Please enter values for the following settings (just press Enter to
    accept a default value, if one is given in brackets).

    Selected root path: .

    You have two options for placing the build directory for Sphinx output.
    Either, you use a directory "_build" within the root path, or you separate
    "source" and "build" directories within the root path.
    > Separate source and build directories (y/n) [n]: n

The default choice ``n`` says "keep things together".  This is my personal preference,
but it is not overwhelmingly significant.

+-----------------------------+---------------------------+
| Choosing ``n``              | Choosing ``y``            |
+=============================+===========================+
| .. code-block:: text        | .. code-block:: text      |
|                             |                           |
|     docs/                   |     docs/                 |
|     ├── _build              |     ├── build             |
|     │       build artifacts |     │     build artifacts |
|     │       go here         |     │     go here         |
|     ├── conf.py             |     ├── make.bat          |
|     ├── index.rst           |     ├── Makefile          |
|     ├── make.bat            |     └── source            |
|     ├── Makefile            |         ├── conf.py       |
|     ├── _static             |         ├── index.rst     |
|     └── _templates          |         ├── _static       |
|                             |         └── _templates    |
+-----------------------------+---------------------------+

The main thing to understand is that where Exhale is concerned, **all relative paths
specified in any configuration variables are relative to wherever** ``conf.py``
**lives**.  The ``build artfiacts go here`` section is to just explain that if you do
``make html``, then in the ``n`` case a folder ``docs/_build/html`` will be created, and
in the ``y`` case it will be in ``docs/build/html``.  Repeat for ``make linkcheck``.
In either case, you will definitely want to add ``docs/_build`` or ``docs/build`` to
your ``.gitignore`` or related version control ignore file.

The only other thing worth pointing out here is that by default sphinx reates the
``_static`` and ``_templates`` directories for you.  At first start, you don't use those
but:

``_static``
    Where you would track things like a ``custom.css`` stylesheet, any logo icons,
    a ``custom.js`` javascript file, etc.  See :confval:`sphinx:html_static_path`.

``_templates``
    Where you would store custom jinja2 templates to override settings in your chosen
    :confval:`sphinx:html_theme`.  The templates are read from
    :confval:`sphinx:templates_path` which defaults to ``_templates``.  See also:
    `Sphinx Templating <https://www.sphinx-doc.org/en/master/templating.html>`_.


Finishing the ``sphinx-quickstart`` command output, we enter the relevant metadata about
our project so that sphinx can populate as much as possible of our ``conf.py`` for us:

.. code-block:: console

    $ sphinx-quickstart
    ...

    The project name will occur in several places in the built documentation.
    > Project name: Super Project
    > Author name(s): Myself ThePerson, Robotic Armistice
    > Project release []: 0.1.0

    If the documents are to be written in a language other than English,
    you can select a language here by its language code. Sphinx will then
    translate text that it generates into that language.

    For a list of supported codes, see
    https://www.sphinx-doc.org/en/master/usage/configuration.html#confval-language.
    > Project language [en]:

    Creating file /path/to/docs/conf.py.
    Creating file /path/to/docs/index.rst.
    Creating file /path/to/docs/Makefile.
    Creating file /path/to/docs/make.bat.

    Finished: An initial directory structure has been created.

    You should now populate your master file /path/to/docs/index.rst and create other documentation
    source files. Use the Makefile to build the docs, like so:
        make builder
    where "builder" is one of the supported builders, e.g. html, latex or linkcheck

There is also the official `Sphinx Quickstart Guide`__ with more information on builders
and whatnot.

__ https://www.sphinx-doc.org/en/master/usage/quickstart.html

Bonus: Sphinx Good-to-Know
****************************************************************************************

The ``conf.py`` file generated does not have a whole lot left in it anymore, but it's
worth pointing out a couple of important usage features of the ``conf.py`` file that are
not immediately obvious until you start working.

Where do Magic Variables Come From?
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Any variable listed on :py:mod:`Sphinx Configurations Module <sphinx:conf>` can be added
to this ``conf.py`` file.  There are a **lot** of options available to you, it's worth
taking a scroll through to see what kind of customization can be done!  For example, see
the docs on :confval:`sphinx:rst_epilog` -- that makes it so that you could inject your
own custom (and even programmatically defined) substitutions to make life easy.

Do I have to Write reStructuredText?
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

**No**, this is not a requirement.  However, it needs to be enabled in your project
since Exhale generates ``.rst`` documents.  You will want to modify the
:confval:`sphinx:source_suffix` value in ``conf.py`` to include markdown, if that is
what you want to write in.  You may also be interested in looking at
`MyST <https://myst-parser.readthedocs.io/en/latest/sphinx/intro.html>`_ if you want to
write in markdown, but need to call "directives".  These -- directives -- are what
Exhale needs to do its thing.

.. _setup_app:

WTF is ``setup(app)``?!
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

One of my most favorite, but not very well documented, features of ``conf.py`` is that
effectively **every** sphinx project is a Sphinx Extension of sorts.  At the bottom of
your ``conf.py`` file, if you add a magic ``def setup(app):`` method then you will be
able to do all sorts of things like adding custom `"roles"`__ or "directives".  The main
point is that ``app`` is going to be a :class:`~sphinx:sphinx.application.Sphinx`
instance so any method there is fair game.

__ https://www.sphinx-doc.org/en/master/usage/restructuredtext/roles.html

Noting that in recent times, adding a custom ``_static/custom.css`` file or
``_static/super_hack.js`` file has become easier via the
:confval:`sphinx:html_css_files` and :confval:`sphinx:html_js_files`, this example is
just to demonstrate that using those configuration values could also be accomplished
like this:

.. code-block:: py

    # See discussion above about html_static_path, let's assume that the files
    # docs/_static/custom.css and docs/_static/super_hack.js exist.
    html_static_path = ["_static"]

    # ... other configurations ...

    def setup(app):
        app.add_css_file("custom.css")
        app.add_js_file("super_hack.js", async="async")

In most cases, you won't really have a need for the ``setup(app)`` method, but as soon
as you want to do anything beyond what the default configurations in Sphinx allow,
you'll be able to do it in this method.

Setup the Extensions in ``conf.py``
----------------------------------------------------------------------------------------

Assuming your Doxygen documentation is in order, and you already have your Sphinx
project ready to go, we need to configure the Breathe and Exhale extensions.  For this
guide I assume the following directory structure::

    my_project/
    │
    ├── docs/
    │   ├── conf.py
    │   └── index.rst
    │
    ├── include/
    │   └── common.hpp
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
       "My Project": "./_doxygen/xml"
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
``docs/../include`` and save the output in ``docs/_doxygen``.  Meaning the following
structure would be created::

    my_project/
    ├── docs/
    │   ├── api/
    │   │   └── library_root.rst
    │   │
    │   ├── conf.py
    │   ├── index.rst
    │   │
    │   └── _doxygen/
    │       └── xml/
    │           └── index.xml
    │
    ├── include/
    │   └── common.hpp
    │
    └── src/
        └── common.cpp

.. note::

   You are by no means required to use Exhale to generate Doxygen.  If you choose not to
   I assume you have the wherewithal to figure it out on your own.  See also the
   :ref:`setup_app` section, in that method would be a good place to invoke doxygen.
   Or use CMake.  Or whatever.

Make Your Documentation Link to the Generated API
----------------------------------------------------------------------------------------

So the final step is, in your ``index.rst`` or some other ``toctree`` directive, tell
Sphinx to link in the generated ``"{containmentFolder}/{rootFileName}"`` document:


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

.. _quickstart_clean_target:

Optional: Create a Proper Clean Target
----------------------------------------------------------------------------------------

The ``sphinx-quickstart`` utility will create a ``Makefile`` for you, you are advised
to create an *explicit* ``clean`` target that removes the generated utilities.

1. You can just as easily specify to ``breathe_projects`` a path such as
   ``_build/_doxygen/xml``, or ``../build/_doxygen/xml`` if you have separate source
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
   	rm -rf _doxygen/ api/
   	@$(SPHINXBUILD) -M clean "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.. danger::

   ``make`` **requires** ``TAB`` characters!  If you just copy-pasted that, **you got
   space characters** (sorry).

.. note::

   The above code **must** appear **before** the ``%: Makefile`` "catch-all" target that
   Sphinx produced by default.  Otherwise...well the catch-all target catches all!

Hosting your Documentation Online
----------------------------------------------------------------------------------------

Now that you have a sphinx project able to build your documentation, you will want to
find a home to host your project online.  If you just want to get documentation out
the door, try `Read the Docs <https://docs.readthedocs.io/en/stable/tutorial/>`_.  You
can also do something like `GitHub Pages <https://pages.github.com/>`_, but that process
is a little bit more involved since you'll need to deploy to a ``gh-pages`` branch.
Search online for ``sphinx github pages``, hopefully over time somebody will create a
better GitHub action that allows e.g., versioned hosting of docs.
