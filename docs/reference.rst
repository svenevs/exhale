Developer Reference Documentation
========================================================================================

Primary Entry Point
----------------------------------------------------------------------------------------

The main entry point to exhale is through the generate function.  This method internally
calls breathe, reparses / rebuilds the hierarchies, and then generates the API.

.. autofunction:: exhale.generate

Helper Functions
----------------------------------------------------------------------------------------

There are a few helper functions used throughout the framework that effectively just
reformat the input into a specific kind of output for incorporating into
reStructuredText documents, and the directives used in those documents.  The last
function is largely unrelated to exhale, and just prints something to the console in a
way that makes it stick out a little more.

.. autofunction:: exhale.qualifyKind

.. autofunction:: exhale.kindAsBreatheDirective

.. autofunction:: exhale.specificationsForKind

.. autofunction:: exhale.exclaimError

Ownership Graph Representation
----------------------------------------------------------------------------------------

A graph representing what classes belong to what namespaces, what file defines what, etc
is built with a single ``ExhaleRoot``.  This root node contains multiple different lists
of ``ExhaleNode`` objects that it parses from both Breathe and the Doxygen xml output.

If you are reading this, then you are likely trying to make changes.  To avoid having
such a huge reference page, and enable viewing the reference documentation for the two
primary classes at the same time, they are on separate pages.

.. toctree::
   :maxdepth: 1

   reference_exhale_root
   reference_exhale_node
