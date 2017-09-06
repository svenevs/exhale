.. _overview:

Overview
========================================================================================

Exhale is an automatic C++ library API generation utility.  It attempts to port the
Doxygen hierarchy view presentations for classes and files into the Sphinx domain.  See
the :ref:`usage_quickstart_guide` for the bare minimum you need to give to integrate it
into your project.

What does it do?
----------------------------------------------------------------------------------------

Exhale takes your Doxygen XML documentation and generates a large number of
reStructuredText for you automatically.  Most of the documents created are simply
wrapper pages to use the various directives made available by Breathe.

It begins by explicitly parsing the Doxygen XML, and re-constructing the graph of
relationships.  Things such as what file a given class was defined in, or what namespace
it belongs to.  Once the graph has been reconstructed and traversed, the API
reStructuredText documents are generated and linked to one another, as well as the root
library document.  The intent of the root library document is for you to just include it
in your top-level index ``toctree`` directive.  Refer to :ref:`usage_advanced_usage` for
how the root library document will be presented as well as how to customize it.

The individual and root library page are an attempt to emulate the output of what
Doxygen would for their html class and file hierarchies.  Many similarities exist, such
as the inclusion of ``struct`` before ``class`` in ranking over alphabetical.  However,
I took a few liberties to change the output to include things I felt were more useful,
such as including ``enum`` in the Class Hierarchy.

.. note::

   Every generated file has a reStructuredText label that you can use to highlight
   specific items such as an important class or a file.  Refer to
   :ref:`usage_external_linkage` for more information.


What does it need to do that?
----------------------------------------------------------------------------------------

First and foremost, if you do not have valid Doxygen documentation, Exhale may produce
false relationships, orphaned documents, etc.  Generally speaking, if your Doxygen
build is producing warnings, this is why Exhale is not creating what you expect.

.. tip::

   Doxygen is a complex and advanced tool!  In particular, you will likely need to
   finesse the Doxygen preprocessor for everything to work out as expected.  Refer to
   the :ref:`doxygen_documentaion_specifics` section for more information.

From there, Exhale needs the following information, all provided in ``conf.py``:

1. You need to configure the Breathe extension's ``breathe_projects`` variable.
2. You need to configure the Breathe extension's ``breathe_default_project`` variable.
3. The containment folder exhale is allowed to assume control over.  This is where
   all of the reStructuredText documents are being generated, and it must be a
   subdirectory of your Sphinx source directory (e.g., a subdirectory of the folder that
   your ``conf.py`` is in).
4. The name of the root library document you want generated, which **you** will be
   including in a ``toctree`` directive somewhere.
5. The title of the root library document, since it is part of a ``toctree``.
6. The path to strip from the Doxygen documentation.  This is required since without it
   the full paths of files are used.  Particularly for Read The Docs, this is rather
   unattractive.

This list sounds a lot more intimidating than it is.  The way you should think of this
list is more like this:

1. Exhale depends on the Breathe extension, so configure that correctly.
2. Exhale is generating a large number of documents for you, it needs to know where to
   put them.  Since the user needs to include one of these documents in their own
   documentation, Exhale requires you to make these arguments explicitly so you are
   conscious of where they are getting put.

See the :ref:`usage_quickstart_guide` for getting everything up and running.
