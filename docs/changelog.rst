Changelog
========================================================================================

.. contents:: Release Notes
   :local:
   :backlinks: none

v0.3.3
----------------------------------------------------------------------------------------

- Fix sphinx-bootstrap-theme styling, the introduction of the page hierarchies broke
  the bootstrap tree for any project that does not use ``page``.  Solution is to only
  select / apply the ``treeview`` functions if the id anchors are found (:pr:`167`).

v0.3.2
----------------------------------------------------------------------------------------

- Exhale requires python 3.7+ (:pr:`163`).
- Development (local and CI) now support doxygen 1.9.x.  Additionally, fix parsing of
  function signatures where doxygen will erroneously create e.g.,
  ``template <typenameC>`` rather than ``template <typename C>`` with a space needed. It
  does not happen with all ``typename``, so the hack just replaces ``"typename"`` with
  ``"typename "`` and then replaces two spaces with one (:pr:`157`).
- Fix a bug where nested classes with specialized templates had the incorrect name being
  displayed (:issue:`156`, fix: :pr:`159`).  Nodes with ``<>`` in their name (doxygen
  presents specialized templates in the ``name`` attribute) get tokenized and the
  various parameters extracted.  As a result of fixing, exhale now has stronger
  capabilities to understand template parameters.  Substantive testing framework
  overhaul was required, exhale may still not handle all templates correctly.

  **Huge** thanks to `@florianhumblot <https://github.com/florianhumblot>`_ for devising
  the strategy and spending time helping flesh this out.

v0.3.1
----------------------------------------------------------------------------------------

- Fix regression introduced by :pr:`139` where custom ``"class"`` and ``"struct"``
  :data:`~exhale.configs.customSpecificationsMapping` were being overwritten
  (:pr:`154`).

v0.3.0
----------------------------------------------------------------------------------------

- Do not write source files for empty hierarchies (:pr:`134`, :pr:`147`).
- Support specialized template functions (:pr:`117`).
- Prevent sphinx from processing files that are incorporated via a ``.. include::``
  directive by renaming them to ``.rst.include`` suffix (:pr:`136`).
- Add ``:project: {app.config.breathe_default_project}`` to every breathe directive
  to make the monkeypatch (:issue:`27`) work (:pr:`139`, :pr:`148`).
- Do not require :data:`~exhale.configs.containmentFolder` to be a "direct"
  subdirectory of ``app.srcdir``, allow any arbitrary subdirectory (:pr:`144`).
- Update how css and js are added using a dubious check into the sphinx internals before
  adding css / js to avoid duplicates (:pr:`144`).

v0.2.4
----------------------------------------------------------------------------------------

- Use the correct PyPI name ``beautifulsoup4`` rather than ``bs4`` (:pr:`120`).
- Fix deprecated ``MutableMapping`` import for python 3.10 support (:pr:`124`).
- Enable parallel builds (use the right ``setup`` function...) (:pr:`126`).
- Add support for ``.. doxygenpage::`` (:pr:`114`).  **Huge** thanks to:
    - `@hidmic <https://github.com/hidmic>`_ for the initial implementiation, and
    - `@2bndy5 <https://github.com/2bndy5>`_ and
      `@clalancette <https://github.com/clalancette>`_ for their efforts in improving
      the doxygen-breathe-exhale-sphinx ecosystem (and consequently, encouraging me to
      resume work on this project).
- Escape ``*`` in template page titles (:pr:`118`).
- Fix titles / links for directories with underscores (:pr:`127`).

v0.2.3
----------------------------------------------------------------------------------------

- Allow unabridged API to exclude different kinds (:pr:`67`).
  :data:`~exhale.configs.unabridgedOrphanKinds` allows users to exclude a specific kind
  from getting dumped in the unabridged API beneath the hierarchies.

  By default, the unabridged API will exclude ``"file"`` and ``"dir"``, given that the
  file hierarchy already includes these.

v0.2.2
----------------------------------------------------------------------------------------

- Make sure spaces in directory / filenames are quoted when sent to Doxygen (:pr:`60`).

v0.2.1
----------------------------------------------------------------------------------------

- Fix bug where a ``union`` child of a ``namespace`` does not link correctly in the
  class hierarchy (:pr:`40`).
- Do not force pygments lexer to unconditionally use ``cpp`` for ``<programlisting>``
  pages.  Doxygen encodes a language, which is parsed and converted to the appropriate
  pygments lexer (:pr:`42`).

    - Added new configuration variable :data:`~exhale.configs.lexerMapping` for
      additional control over pygments language to use.
    - This marks the beginning of mixed-language support, but much more needs to be done
      for this!

- Most overloaded functions should now work.  See :pr:`45` for more information,
  including function overloads that do **not** currently work.

    - For consistency, the full api listing includes fully qualified function names
      (previously: ``Function foo``, now: ``Function namespace::foo(int)``).

- Stopped using deprecated sphinx API (:pr:`47`).
- Tree view hierarchies are minified by default (:pr:`48`).

    - Added new configuration variable :data:`~exhale.configs.minifyTreeView`.

- Parent directory links generated for ``directory`` and ``file`` pages (:pr:`49`).
- Tree view and namespace exclusion bypass configuration variable
  :data:`~exhale.configs.listingExclude` added (:pr:`50`).

    - Better logic for finding the file node that defined a given compound.
    - Doxygen produces inconsistencies with the paths, some are Windows paths and some
      are \*nix paths.  These should now all be corrected using ``os.path.normpath``.

v0.2.0
----------------------------------------------------------------------------------------

- Exhale no longer produces filenames that are longer than the operating system can
  handle (:pr:`35`).

    - Internal links have changed, more heavily discouraged in docs.  Ideally the
      internal link generation scheme will not need to change again, but they might.
    - Exhale can handle absurdly long file paths by using the ``\\?\`` prefix on
      Windows.  If you run into a situation where this affects you, Sphinx actually
      cannot handle this.  So try and build in a higher directory, e.g.
      ``C:\your_project`` (paths greater than ``260`` characters cause this issue).

- First *mostly* functional release for Windows (there were many locations where
  ``os.path.normpath`` needed to be used.
- **Bug**: bug introduced where a ``union`` child of a ``namespace`` does not link
  correctly in the class hierarchy.

v0.1.8
----------------------------------------------------------------------------------------

- Fix bug that prevents :ref:`usage_customizing_breathe_output` from working.  Was
  checking ``isinstance(val_t, six.string_types)``, but should have been checking
  ``isinstance(val, six.string_types)``.
- Fix / improve key guessing for when an invalid key is given in ``exhale_args``.

v0.1.7
----------------------------------------------------------------------------------------

- Colorized printing on Read The Docs is disabled, since their build logs online don't
  display the color.
- Doxygen ``stdout`` and ``stderr`` are directed to ``/dev/null`` on Read The Docs.  See
  :issue:`14`.

v0.1.6
----------------------------------------------------------------------------------------

- First release with manual namespace documentation parsing (same as files).

    - Limitations described in :ref:`file_and_namespace_level_documentation_in_exhale`.
    - Namespace documentation `example here <nspace_example_>`_.

- Fixed bad error message when multiple potential file parents are found, which produced
  an exception preventing the rest of the build. Full description can be found in
  :pr:`12`.

.. _nspace_example: https://my-favorite-documentation-test.readthedocs.io/en/latest/api/namespace_arbitrary.html#namespace-arbitrary

v0.1.5
----------------------------------------------------------------------------------------

- Page level configuration metadata added to all pages (rather than just leaf-like
  pages).
- Fixed ``textwrap.dedent`` inconsistencies when more than one nested type is
  enumerated.
