Exhale
========================================================================================

Automatic C++ library API documentation generation using Doxygen, Sphinx, and Breathe.
This project attempts to revive the Doxygen style hierarchies in reStructuredText
documents to enable powerful documentation syntax and generate beautiful websites.

Exhale is a `Sphinx <http://www.sphinx-doc.org/en/stable/>`_ extension that depends on
the excellent `Breathe <http://breathe.readthedocs.io/en/latest/>`_ extension which
enables parsing Doxygen documentation into the Sphinx domain.  Exhale provides a layer
of automation, enabling launching Doxygen and generating the full website all from your
``conf.py``.  Exhale will execute these actions by way of ``sphinx-build`` being invoked,
allowing you to use it for hosting on `Read the Docs <https://readthedocs.org/>`_.

A :ref:`usage_quickstart_guide` guide gives the bare minimum needed to get things
working, please read the :ref:`overview` section if you are new to documenting code with
either Doxygen, Sphinx, or Breathe.

This project revives the Doxygen style hierarchies in reStructuredText documents so that
you can keep using the beautiful Sphinx websites, but have a more human-readable Library
API without having to manually write it out yourself.  Exhale is self-contained and
easily portable to Read the Docs.  You should be able to use any Sphinx theme of your
choosing, though some of them likely work better than others.

A more comprehensive example repository (which was used for testing once upon a time) is
located at the companion_ site.

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
