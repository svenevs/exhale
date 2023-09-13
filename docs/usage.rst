Usage
========================================================================================

Using exhale can be simple or involved, depending on how much you want to change and
how familiar you are with things like Sphinx, Breathe, Doxygen, etc.  At the top level,
what you need is:

1. Your C++ code you want to document, with "proper" Doxygen documentation.  Please
   read the :ref:`doxygen_documentation_specifics` for common documentation pitfalls,
   as well as features previously unavailable in standard Doxygen.
2. A sphinx documentation project ready to go.  See the
   `Sphinx Getting Started <https://www.sphinx-doc.org/en/master/usage/quickstart.html>`_
   tutorial for getting that off the ground.

.. contents:: Contents
   :local:
   :backlinks: none

.. tip::

    Don't know how to get started?  That's ok!  There's a lot of tools involved here,
    and it can be quite confusing to know what's what.  Please see the
    :ref:`quickstart_guide` for getting started with Sphinx, Breathe, and Exhale.

.. _usage_advanced_usage:

Additional Usage and Customization
----------------------------------------------------------------------------------------

Controlling the Layout of the Generated Root Library Document
****************************************************************************************

.. include:: reference/configs.rst
   :start-after: begin_root_api_document_layout
   :end-before:  end_root_api_document_layout

.. _usage_creating_the_treeview:

Clickable Hierarchies
****************************************************************************************

.. include:: reference/configs.rst
   :start-after: begin_clickable_hierarchies
   :end-before:  end_clickable_hierarchies

.. _usage_external_linkage:

Linking to a Generated File
****************************************************************************************

Using the linking strategies in this section is primarily for in your website's
documentation such as ``index.rst`` or ``usage.rst`` (since those are already
reStructuredText documents), or even in the supplemental arguments you supply to
``exhale_args`` such as :data:`~exhale.configs.afterTitleDescription` (since these
arguments get "pasted" directly onto a generated reStructuredText document).

In the actual code documentation, Breathe is typically able to infer links automatically
(which is really great!), as well as you can also use ``\ref`` from Doxygen if that is
not working.

**Where possible, you should prefer using the Doxygen** ``\ref`` **command**.

However, you can also use these in your code documentation **provided** that you enter a
verbatim reStructuredText.  See the :ref:`Doxygen ALIASES <doxygen_aliases>` section for
more information on that.

.. _usage_suggested_linking_strategy:

Suggested reStructuredText Linking Strategy
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Assuming you have set ``primary_domain = 'cpp'`` (as shown in the
:ref:`quickstart_guide`), you should be able to use the linking strategies
`provided by Sphinx itself`__ *without* needing to prefix everything with ``cpp:``.
Some examples:

__ https://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#cpp-domain

+--------------------------------+-----------------------------------------------------+
| Action                         | Syntax                                              |
+================================+=====================================================+
| Linking to a class             | ``:class:`namespace::ClassName```                   |
+--------------------------------+-----------------------------------------------------+
| Linking to a method of a class | ``:func:`namespace::ClassName::methodName```        |
+--------------------------------+-----------------------------------------------------+
| Linking to a member of a class | ``:member:`namespace::ClassName::mMemberName```     |
+--------------------------------+-----------------------------------------------------+
| Linking to a function          | ``:func:`namespace::funcName```                     |
+--------------------------------+-----------------------------------------------------+


.. tip::

   The value of ``primary_domain`` in ``conf.py`` is **very** important here!  If you do
   not set it, the default is ``py`` (python).  This means that instead of
   ``:class:`namespace::ClassName``` you would need to use
   ``:cpp:class:`namespace::ClassName``` to use a different *domain*.

   A much more thorough walk-through of how the different domains can be used together
   (e.g., how to link to a ``define`` or macro) is provided in the companion website's
   `Using Intersphinx`__ guide.

   __ https://my-favorite-documentation-test.readthedocs.io/en/latest/using_intersphinx.html


.. _using_exhale_internal_links:

Using Exhale's Internal Links
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

If the above are not working, you can try using the links that Exhale generates to
perform its own internal linkage.  These links are much harder to use directly.
**However, there are some documented compounds that can only be linked to using these
internal links.**  These are either because Exhale does not use the corresponding
Breathe directive (e.g., ``namespace``) **or** there does not exist an equivalent link
type in the Sphinx C++ domain (``file`` and ``dir``).

.. _usage_linking_to_the_root_api_document:

Linking to the Root API Document
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. todo::

   In Exhale v1.0.0 (when full-fledged projects are supported) each heading on
   this page will receive a formal reStructuredText label to ease the process
   of linking to this page.

   .. danger::

      This has an important consequence for **you**!  If you use the linking strategy
      described here, when formal reStructuredText labels are introduced, your links
      will likely break (because it changes the anchor point from the title to the
      generated label).

The link generated is entirely defined by what you specify to ``exhale_args`` with the
keys :data:`~exhale.configs.rootFileTitle`, :data:`~exhale.configs.rootFileName` and
:data:`~exhale.configs.containmentFolder`.  Consider the values

.. code-block:: py

   exhale_args = {
       "containmentFolder": "./api",
       "rootFileName": "library_root.rst",
       "rootFileTitle": "Library API"
       # ... other arguments ...
   }

Exhale will generate the file ``{containmentFolder}/{rootFileName}`` (so
``./api/library_root.rst``) with an H1 heading ``{rootFileTitle}`` like so:

.. code-block:: rst

   Library API
   ===========

   Other stuff generated by Exhale...

To link to the top of this generated document, you can use a reStructuredText link such
as

.. code-block:: rst

   ..                         html, not rst! ----------vv
   ..                                                 vvvv
   Please see the `full Library API <api/library_root.html#library-api>`_
   ..              |--------------|  |-------------------| |---------|  |
   ..                     1                    2                3       4

1. The hyperlink text generated will be what is **before** the ``<target>``.  In this
   example the hyperlink text will be ``full Library API``.
2. Inside of the ``<angle brackets>`` is the actual hyperlink target.  Note that this is
   a relative path here, so the above link would work for ``index.rst``, but would not
   work for say ``tutorials/getting_started.rst``.
3. Lastly, the anchor point is derived from what you specified as the root file title.
   The general scheme for how reStructuredText generates these links is basically
   ``target.lower().replace(" ", "-")``, but special symbols are treated differently.
4. The trailing ``_`` after ``#library-api>`` is **required**!  That's how
   reStructuredText hyperlinks work.

.. _usage_linking_to_special_cases:

Linking to "Special Cases": namespaces, files, and directories
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The work for generating these links takes place in
:func:`ExhaleRoot.initializeNodeFilenameAndLink <exhale.graph.ExhaleRoot.initializeNodeFilenameAndLink>`.
The relevant section of the code:

.. code-block:: py

   SPECIAL_CASES = ["dir", "file", "namespace"]
   if node.kind in SPECIAL_CASES:
       if node.kind == "file":
           unique_id = node.location
       else:
           unique_id = node.name

       unique_id = unique_id.replace(":", "_").replace(os.sep, "_").replace(" ", "_")

   # ... later on ...
   if node.kind in SPECIAL_CASES:
       node.link_name = "{kind}_{id}".format(kind=node.kind, id=unique_id)

Some examples of links you would use:

- ``namespace foo::bar::baz``:

  .. code-block:: rst

     ..    node.kind
     ..    |-------|
     :ref:`namespace_foo__bar__baz`
     ..                 ||   ||
     ..           Two underscores between namespaces!
     ..           from: replace(":", "_")

- ``file include/outer_dir/inner/file.hpp``:

  .. code-block:: rst

     ..  node.kind
     ..    |--|
     :ref:`file_include_outer_dir_inner_file.hpp`

  Note that unlike namespaces, ``replace(os.sep, "_")`` will only result in a single
  underscore between directories.  Note that spaces are not allowed in the generated
  links, so they are also replaced with underscores.

- ``dir include/outer_dir/inner``:

  .. code-block:: rst

     .. node.kind
     ..    |-|
     :ref:`dir_include_outer_dir_inner`

  Treatment is identical to files, with the same considerations for path separator
  and space replacement.


.. _usage_linking_to_any_other_generated_file:

Linking to Any Other Generated File
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. warning::

   Using these links directly may be an exercise in futility.  You should be able to use
   the links described in :ref:`usage_suggested_linking_strategy`.

The work for generating these links also takes place in
:func:`ExhaleRoot.initializeNodeFilenameAndLink <exhale.graph.ExhaleRoot.initializeNodeFilenameAndLink>`.
The relevant section for these constructs is:

.. code-block:: py

   unique_id = node.refid

   # ... later on ...
   node.link_name = "exhale_{kind}_{id}".format(kind=node.kind, id=unique_id)

This is prefixed with ``exhale_`` because there are potential collisions with using the
Doxygen ``refid`` (Doxygen's internal "unique identifier scheme", which is mostly
equivalent to compiler-like C++ name mangling with some potential hashing and
divergences).  The collisions come from the fact that Breathe will typically create an
anchor point that is exactly the Doxygen ``refid``.  The Breathe anchors are where the
links such as ``:class:`namespace::ClassName``` **as well as** your standard ``\ref``
calls will direct to.  This is ideal.

The Exhale links are anchor points to the top of the generated page that has the Breathe
directive in its body.  These anchor points are used for indexing the tree view.

.. tip::

   If for whatever reason you want to use the Exhale internal links, you can save
   yourself a lot of time trying to figure out what they might be and just generate the
   api once.  Open up the generated file for the desired node, and look at the top.

   .. code-block:: rst

      .. _exhale_class_somecrazy_thing:

      Class ``somecrazy_thing``
      =========================

   Copy-paste the thing at the top starting with ``.. _``, noting that in this
   particular (hypothetical) example, you would use
   ``:ref:`exhale_class_somecrazy_thing``` **without** the leading underscore.  The
   leading ``.. _`` is what tells reStructuredText "I want this to be the name of the
   link".

.. note::

   The internal links changed in a breaking way with Exhale v0.2.0.  Unless an
   exceptionally compelling reason comes up, I hope to never change the internal link
   generation again.

.. _usage_customizing_file_pages:

Page Level Customization
****************************************************************************************

.. include:: reference/configs.rst
   :start-after: begin_page_level_customization
   :end-before:  end_page_level_customization


.. _using_contents_directives:

Using Contents Directives
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

.. include:: reference/configs.rst
   :start-after: begin_page_level_customization_contents_directives
   :end-before:  end_page_level_customization_contents_directives

.. _usage_customizing_breathe_output:

Customizing Breathe Output
****************************************************************************************

.. include:: reference/configs.rst
   :start-after: begin_customizing_breathe_output
   :end-before:  end_customizing_breathe_output

.. _usage_fully_automated:

Fully Automated Building
----------------------------------------------------------------------------------------

It is preferable to have everything generated at once, e.g. if you wish to host your
documentation on Read the Docs.  Exhale is configured to enable this directly for you,
provided that you have the associated configuration variables setup.

.. _usage_exhale_executes_doxygen:

Using Exhale to Execute Doxygen
****************************************************************************************

.. include:: reference/configs.rst
   :start-after: begin_doxygen_execution_and_customization
   :end-before:  end_doxygen_execution_and_customization

Executing Doxygen Independently
****************************************************************************************

This is another option, just make sure that Doxygen is run **before** Exhale is.  See
the note at the bottom of the :ref:`quickstart_guide`.

.. _doxygen_documentation_specifics:

Doxygen Documentation Specifics
----------------------------------------------------------------------------------------

.. include:: reference/configs.rst
   :start-after: begin_doxygen_execution_and_customization
   :end-before:  end_doxygen_execution_and_customization

.. _file_and_namespace_level_documentation_in_exhale:

File and Namespace Level Documentation in Exhale
****************************************************************************************

Since the Breathe file / namespace directives cannot be used, Exhale implements a
"best-faith-effort" documentation parser.  It includes support for a few basic
block-level elements such as listings, but it is definitively not robust.  If the file
or namespace level documentation is rendering in unexpected ways, this is because your
documentation is "too advanced" for Exhale's mini-parser.

.. tip::

   See the :func:`~exhale.parse.walk` method for the currently supported Doxygen
   formatting being parsed.

However, the solution is easy: use a verbatim reStructuredText environment in the
documentation.  See how to do that in the :ref:`Doxygen ALIASES <doxygen_aliases>`
section.

.. note::

   By entering a verbatim RST environment, doxygen commands such as ``\ref`` are **no
   longer available**.  Or rather, they will be parsed as-is without actually generating
   a link to the desired target.  Since you've now entered a verbatim RST environment,
   you would instead use the Sphinx domain links.

   So if you were linking to ``class namespace::ClassName`` using
   ``\ref namespace::ClassName``, this would now change to be
   ``:class:`namespace::ClassName```.  See the `Sphinx Cross Referencing Guide <cross_>`_
   for some more examples.  There is also an `Intersphinx Guide <intersphinx_>`_
   available on the companion website with some examples of linking to macros.

.. _cross: https://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#cross-referencing-syntax

.. _intersphinx: https://my-favorite-documentation-test.readthedocs.io/en/latest/using_intersphinx.html
