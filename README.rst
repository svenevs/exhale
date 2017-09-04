Exhale
========================================================================================
|docs|

.. |docs| image:: https://readthedocs.org/projects/exhale/badge/?version=latest
    :alt: Documentation Status
    :scale: 100%
    :target: https://exhale.readthedocs.io/en/latest/?badge=latest

.. begin_tmp_danger_warning

.. danger::

   These documents are currently largely out of order and most of the documentation you
   will read pertaining to how it works are out of date.  This code is currently
   unstable and under-tested.  This admonition will be removed when ready.

.. end_tmp_danger_warning

.. begin_exhale_brief_desc

Automatic C++ library API documentation generator using Doxygen, Sphinx, and Breathe.
Exhale revives Doxygen's class / file hierarchies using reStructuredText for superior
markup syntax / websites.

.. end_exhale_brief_desc

.. begin_exhale_long_desc

Exhale is a `Sphinx <http://www.sphinx-doc.org/en/stable/>`_ extension that depends on
the excellent `Breathe <http://breathe.readthedocs.io/en/latest/>`_ extension which
enables parsing Doxygen documentation into the Sphinx domain.  Exhale provides a layer
of automation, enabling launching Doxygen and generating the full website all from your
``conf.py``.  Exhale will execute these actions by way of ``sphinx-build`` being invoked,
allowing you to use it for hosting on `Read the Docs <https://readthedocs.org/>`_.
Exhale was designed for generating html output, and may not be appropriate for other
builders provided by Sphinx.

.. end_exhale_long_desc

Usage
----------------------------------------------------------------------------------------

See the `full documentation and usage guide <https://exhale.rtfd.io>`_.

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
    To be extra clear, I'm a **huge** fan of ``breathe``, and Exhale could never exist
    without it.  As it turns out, ``.. autodoxygenindex::`` is largely what inspired
    this library.  I loved the idea of being able to type ``make html``, and that's it.
    For larger frameworks, though, everything being generated on one page makes your
    documentation rather inconvenient to navigate.

    The ``breathe-apidoc`` is also an excellent resource to seriously consider.  The
    downside is that if you rename, remove, or add things, your documentation gets out
    of sync with the code.  Fixing isn't that difficult, but I personally always forget
    things like that.

    And of course, the Class and File hierarchies are only available in Sphinx via
    Exhale 😊

.. end_exhale_is_it_for_me

Participate
----------------------------------------------------------------------------------------

If you find a problem or think there is something that should change, please submit an
issue (or pull request!) explaining what should change.  I made this because it was
something I really wanted, and felt the community at large could benefit from as well.
I put a lot of effort into making it flexible, but it is by no means perfect.

Roadmap
****************************************************************************************

There are some features I need to / want to implement this summer.  I'm open to
suggestions / ideas / things you would want to see in this library.  I'll be revamping
`exhale` this summer when I have a little more time.

The proposed changes are in the project roadmap_.

.. _roadmap: https://github.com/svenevs/exhale/projects/1

Credit
----------------------------------------------------------------------------------------

This project could not exist without the already excellent tools available: Doxygen,
Sphinx, Breathe, and many others.  In particular, though, **all** files in the
``treeView/_static`` directory were scraped from Stephen Morley's collapsibleLists_
thanks to his generous license_.  I make no claims to these files, and only host them
here out of convenience for you.

.. _collapsibleLists: http://code.stephenmorley.org/javascript/collapsible-lists/
.. _license: http://code.stephenmorley.org/about-this-site/copyright/

License
----------------------------------------------------------------------------------------

This project uses a BSD 3-clause license, in hopes that it will be accessible to most
projects.  If you require a different license, please raise an issue and I will consider
a dual license.

The full license is `available here <https://github.com/svenevs/exhale/LICENSE.md>`_.
