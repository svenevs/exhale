Developer Reference Documentation
========================================================================================

.. todo::

   Exhale is being updated in waves as I have free time.  It was originally written to
   be tracked by the user next to ``conf.py``.  Keeping it in a single file made this
   as convenient as possible for users, but was ultimately inconvenient to maintain.

   Right now, the :mod:`~exhale.graph` module is largely the same as it was in the single
   file library version.  Eventually this will be whittled down into the other modules
   present in the library (e.g., modularizing writing nodes to file, parsing of xml).

Project Layout
----------------------------------------------------------------------------------------

The brief overview of what is where in this project:

**Configs**
    The :mod:`~exhale.configs` module contains everything related to what can be
    configured via ``conf.py``, plus a few constants and book-keeping variables.  At the
    bottom of this file is where you will find the bridge between Sphinx and Exhale (the
    function :func:`~exhale.configs.apply_sphinx_configurations`).

**Deploy**
    The :mod:`~exhale.deploy` module is responsible assisting in the creation of the
    Doxygen documentation (see :data:`~exhale.configs.exhaleExecutesDoxygen`) as well as
    "exploding" the documentation into all of the various reStructuredText documents.
    The :func:`~exhale.deploy.explode` is what triggers the creation of the graph, and is
    called by :func:`~exhale.configs.apply_sphinx_configurations`.

**Graph**
    The :mod:`~exhale.graph` module is the main representation of all the various items
    being documented.  This is by far the most important, and confusing, module.  The
    brief version is that the :func:`~exhale.deploy.explode` function will create an
    :class:`~exhale.graph.ExhaleRoot` object, which could be thought of as the equivalent
    of the ``index.xml`` produced by Doxygen.  The ``ExhaleRoot`` object will parse the
    Doxygen xml files and instantiate :class:`~exhale.graph.ExhaleNode` objects to
    represent the different items being documented.

**Parse**
    The :mod:`~exhale.parse` module does **not** currently do the parsing you would
    think.   It currently only parses the file level documentation from the xml
    documents and gives a best-faith effort to turn this into valid reStructuredText.

    The future intent is to have the parsing done in the :mod:`~exhale.graph` module
    get stripped out and placed in this module.

**Utils**
    The :mod:`~exhale.utils` module contains various helper methods for consistent
    formatting, colorized error reporting, and serialization of the Exhale
    configurations (Sphinx requires this in order to pickle the environment / identify
    what has changed, etc).

Execution Flow
----------------------------------------------------------------------------------------

There are quite a few different moving parts involved with this project, but when you
build your documentation with ``make html``, the Sphinx build process gets launched
and the following (simplified, read the Sphinx docs for the full story) occurs:

1. Sphinx reads ``conf.py`` and determines which ``extensions`` to find / load.  The
   user of Exhale should have both ``breathe`` and ``exhale`` in this list.

2. Each extension is ``setup``, whereby the extension declares what variables it is
   expecting (or can support) for customization that the user will be putting in their
   ``conf.py``.  During this phase is when extensions also request to be signaled when
   different stages of the Sphinx build process are triggered.

   - Exhale requests notification of the `builder-inited`__ event, which is the first
     event where the configuration variables have been populated.

     __ http://www.sphinx-doc.org/en/stable/extdev/appapi.html#event-builder-inited

   - It would be nice to one-day support incremental builds and a clean target, but at
     this time I have no idea how to do these.

   - As far as I understand it, the Exhale **must** complete generating all of the
     reStructuredText documents *before* the `env-get-outdated`__ event is triggered.

     .. note::

        If you have suggestions of a better way to hook into Sphinx, or ideas on how to
        only regenerate documents that need to be updated (hard), **please** `raise an
        issue on GitHub <https://github.com/svenevs/exhale/issues>`_.

        Even if you don't have a solution, it would be great to hear of ideas!

     __ http://www.sphinx-doc.org/en/stable/extdev/appapi.html#event-env-get-outdated

3. Now that the extensions have been setup, the rest of ``conf.py`` is processed.  For
   all intensive purposes, you can assume that as soon as this is complete is when
   Exhale is getting launched.

4. If requested, Exhale will first execute Doxygen.  Afterward, it will generate all of
   the various reStructuredText documents.

5. Control is passed back to Sphinx and then the source for the documentation is
   searched for / parsed from the Sphinx source directory (generally wherever your
   ``conf.py`` is, as well as all nested directories).


In picture form:

.. graphviz::
   :align: center

   digraph exe_flow {
       /* Global graph configurations, node and edge styling */
       nodesep=1;
       rankdir="LR";
       node [width=2, height=2, style=filled, fontname="Courier"];

       /* Rank declarations (e.g. keeps init and ext next to each other) */
       build;
       {rank=same; init; ext}
       {rank=same; apply_configs; cfg;}
       {rank=same; explode; rst; sphinx_parse; sphinx_gen}

       /* Edge declarations */
       build -> init;

       init -> ext [dir=back, style=dashed];
       init -> apply_configs;

       apply_configs -> cfg [dir=back, style=dashed];
       apply_configs -> explode;

       explode      -> rst;
       rst          -> sphinx_parse;
       sphinx_parse -> sphinx_gen;

       /* Node specific styling */
       build [
           shape=rectangle, style="rounded,filled", fillcolor="#c4c4c4",
           label="make html"
       ];

       init [
           shape=octagon, fillcolor="#90cc7f", label="exhale/__init__.py\nsetup(app)"
       ];
       ext [
           shape=rectangle, style="rounded,filled", fontname="Times New Roman",
           label="conf.py had 'exhale'\nin the 'extensions' list"
       ];

       apply_configs [
           shape=octagon, fillcolor="#a2ddf9",
           label="exhale/configs.py\napply_sphinx_configurations"
       ];
       cfg [
           shape=rectangle, style="rounded,filled", fontname="Times New Roman",
           label="Exhale reads configs in\n'exhale_args' dictionary from conf.py"
       ];

       explode [
           shape=octagon, fillcolor="#f7f389", label="exhale/deploy.py\nexplode"
       ];
       rst [
           shape=doubleoctagon, fillcolor="#f7f389", fontname="Times New Roman",
           label="Exhale generates the\nreStructuredText documents."
       ];
       sphinx_parse [
           shape=rectangle, style="rounded,filled", fontname="Times New Roman",
           label="Sphinx searches for / parses\nreStructuredText found in\nthe source directory."
       ];
       sphinx_gen [
           shape=rectangle, style="rounded,filled", fontname="Times New Roman",
           label="Sphinx generates your website!"
       ];
   }

Full Reference Documentation
----------------------------------------------------------------------------------------

.. toctree::
   :maxdepth: 5

   reference/configs
   reference/deploy
   reference/graph
   reference/parse
   reference/utils
