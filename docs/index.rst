Exhale
========================================================================================

.. danger::

   These documents are currently largely out of order and most of the documentation you
   will read pertaining to how it works are out of date.  While you are welcome to
   use the ``redux`` branch...it's a bad idea at this time.

Automatic C++ library API documentation generation using Doxygen, Sphinx, and Breathe.
This project attempts to revive the Doxygen style hierarchies in reStructuredText
documents to enable powerful documentation syntax and generate beautiful websites.

Exhale is a `Sphinx <http://www.sphinx-doc.org/en/stable/>`_ extension that depends on
the excellent `Breathe <http://breathe.readthedocs.io/en/latest/>`_ extension which
enables parsing Doxygen documentation into the Sphinx domain.  Exhale provides a layer
of automation, enabling launching Doxygen and generating the full website all from your
``conf.py``.  Exhale will execute these actions by way of ``sphinx-build`` being invoked,
allowing you to use it for hosting on `Read the Docs <https://readthedocs.org/>`_.

Getting Started
----------------------------------------------------------------------------------------

A :ref:`usage_quickstart_guide` guide gives the bare minimum needed to get things
working, please read the :ref:`overview` section if you are new to documenting code with
either Doxygen, Sphinx, or Breathe.

.. tip::

   Exhale might **not** be the tool you are looking for!  It was designed to be as
   intuitive and flexible as possible, but it does require more machinery to get
   everything started.

   **Why use it?**
        The motivation for writing it was to use Sphinx and Doxygen together.  It was
        largely inspired by Breathe, but I had a strong desire to have the Class and
        File hierarchies in an **html** format.  Doxygen can generate websites.  Sphinx
        can generate them better.

    **Why not use it?**
        It may be more involved than you need.  Check out the ``breathe-apidoc`` tool
        that comes with your installation of ``breathe``.  It is quite similar to the
        `Sphinx API doc tool <http://www.sphinx-doc.org/en/stable/man/sphinx-apidoc.html>`_,
        and that may be all you are looking for to get your documentation displayed.

A more comprehensive example repository (which was used for testing once upon a time) is
located at the companion_ site.

.. warning::

   Exhale is undergoing **significant** changes.  It was originally designed as a single
   file library that was tracked alongside of ``conf.py``.  This was overall more
   inconvenient and a burden to maintain for users.

   The

.. toctree::
   :maxdepth: 2

   overview
   usage
   reference
   faq

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

.. _companion: http://my-favorite-documentation-test.readthedocs.io/en/latest/

Legacy
========================================================================================

Legacy documentation is `available here <http://exhale.readthedocs.io/en/legacy_docs/>`_
for if you chanced upon this library when it was a single file.
