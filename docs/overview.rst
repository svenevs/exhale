.. _usage_overview_guide:

Overview
========================================================================================

Exhale is an automatic C++ library API generation utility.  It attempts to port the
Doxygen hierarchy view presentations for classes and files into the Sphinx domain.  See
the :ref:`usage_quickstart_guide` for the bare minimum you need to give to integrate it
into your project.

What does it do?
----------------------------------------------------------------------------------------

Exhale is completely dependent upon valid Doxygen documentation, and a working interface
with Breathe.  More specifically exhale explicitly parses the Doxygen xml using Breathe.
Once Breathe is done parsing everything, the problem basically becomes a graph traversal
except that parts of the graph have been lost somewhere and need to be rediscovered.

Once the graph has been reconstructed and traversed, the API reStructuredText documents
are generated and linked to one another, as well as the root library document.  The
intent of the root library document is for you to just include it in your top-level
index ``toctree`` directive.  Refer to :ref:`usage_advanced_usage` for how the root library document
will be presented as well as how to customize it.

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

Assuming you have Sphinx, Doxygen, and Breathe working with each other, exhale needs at
least the following information:

1. The location of the output of the Doxygen xml **index.xml** file.
2. The name of the **folder** you want the generated files to be put in.  You can give
   the current directory, but it will get *messy*.
3. The name of the root file **you** will be linking to from your reStructuredText.
   This file will be in the directory from 2.
4. The title of the document for 3, since this will appear in a ``.. toctree::`` directive.

.. warning::
   Order of execution matters: Doxygen must be executed / updated before exhale.  If you
   are calling exhale from ``conf.py``, then you must specify either an absolute path,
   or a path **relative to conf.py** for items 1 and 2 above.

I intentionally wrote exhale in one file
(`exhale <https://github.com/svenevs/exhale/blob/master/exhale.py>`_) so that you can
just drop that into your repository --- e.g. right next to ``conf.py``.  If you are
hosting on Read the Docs, make sure that ``exhale.py`` is being tracked by ``git``.

So if your documentation directory structure looked like::

    docs/
    │   conf.py     # created by sphinx-quickstart
    │   exhale.py   # placed here by you
    │   index.rst   # created by sphinx-quickstart
    │   about.rst   # created by you
    │   Makefile    # created by sphinx-quickstart
    │   Doxyfile    # created by you
    └───doxyoutput/ # output destination of Doxygen
        └───xml/
               index.xml
               ... other doxygen xml output ...

Then you could answer 1-4 above with

+---+--------------------------------------+----------------------------------+
| 1 | Doxygen xml index location           | ``"./doxyoutput/xml/index.xml"`` |
+---+--------------------------------------+----------------------------------+
| 2 | Generated library containment folder | ``"./generated_api"``            |
+---+--------------------------------------+----------------------------------+
| 3 | Generated library root file          | ``"library_root.rst"``           |
+---+--------------------------------------+----------------------------------+
| 4 | Generated library root file title    |``"Library API"``                 |
+---+--------------------------------------+----------------------------------+

and the following directory structure would be produced::

    docs/
    │   conf.py     # created by sphinx-quickstart
    │   exhale.py   # placed here by you
    │   index.rst   # created by sphinx-quickstart
    │   about.rst   # created by you
    │   Makefile    # created by sphinx-quickstart
    │   Doxyfile    # created by you
    ├───doxyoutput/ # output destination of Doxygen
    │   └───xml/
    │          index.xml
    │          ... other doxygen xml output ...
    └───generated_api/
           library_root.rst
           ... many other files ...

That is, all exhale is actually doing is creating a large number of independent
reStructuredText documents that link between each other.  Include the file from **3**
in a ``toctree`` somewhere, and that file will link to every possible generated file
in some way or another.  These are also all searchable, since Sphinx is given control
of the final setup and linking.

.. note::
   The file in **3** should not have the path from **2** preceding, exhale does that.
