Exhale
========================================================================================

Automatic C++ library api documentation generation: breathe doxygen in and exhale it out.
A :ref:`usage_quickstart_guide` guide gives the bare minimum needed to get things
working, please read the :ref:`usage_overview_guide` section above it if you are new to
Sphinx or Breathe.

This project revives the Doxygen style hierarchies in reStructuredText documents so that
you can keep using the beautiful Sphinx websites, but have a more human-readable Library
API without having to manually write it out yourself.  Exhale is self-contained and
easily portable to Read the Docs.  You should be able to use any Sphinx theme of your
choosing, though some of them likely work better than others.

The generated API has in the following order:

1. The class hierarchy (in namespaces) is generated.
   This includes any namespaces (or top-level) classes, structs, enums, and unions.
2. The folder / file hierarchy is generated.
   Anything defined in the file, as well as namespaces defined / used within.
3. The full API listing: namespaces, classes, structs, enums, defines, variables, asdfasdfasdfasdf

A more comprehensive example repository (which was used for testing once upon a time) is
located at the companion_ site.

.. toctree::
   :maxdepth: 2

   overview
   usage
   reference
   more_info

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

.. _companion: http://www.my-favorite-documentation-test.rtfd.io
