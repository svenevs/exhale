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

Automatic C++ library API documentation generation using Doxygen, Sphinx, and Breathe.
This project attempts to revive the Doxygen style hierarchies in reStructuredText
documents to enable powerful documentation syntax and generate beautiful websites.

.. end_exhale_brief_desc

.. begin_exhale_long_desc

Exhale is a `Sphinx <http://www.sphinx-doc.org/en/stable/>`_ extension that depends on
the excellent `Breathe <http://breathe.readthedocs.io/en/latest/>`_ extension which
enables parsing Doxygen documentation into the Sphinx domain.  Exhale provides a layer
of automation, enabling launching Doxygen and generating the full website all from your
``conf.py``.  Exhale will execute these actions by way of ``sphinx-build`` being invoked,
allowing you to use it for hosting on `Read the Docs <https://readthedocs.org/>`_.

.. end_exhale_long_desc

Usage
----------------------------------------------------------------------------------------

See the `full documentation and usage guide <https://exhale.rtfd.io>`_.

.. begin_exhale_is_it_for_me

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

.. _companion: http://my-favorite-documentation-test.readthedocs.io/en/latest/

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
