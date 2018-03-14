FAQ
========================================================================================

.. contents:: Contents
   :local:
   :backlinks: none

Nothing is working, where did I go wrong?
----------------------------------------------------------------------------------------

Sorry to hear that.  Please try comparing how your documentation is set up with the
companion_ website.

If things look similar enough, or something isn't clear, raise an issue on GitHub.  I'll
do my best to support what I can, and if similar questions come up then I can add them
to this FAQ.

Make sure you set the :data:`~exhale.configs.verboseBuild` to ``True``, there may be some
useful information being printed there.

.. _companion: http://my-favorite-documentation-test.readthedocs.io/en/latest/

Can I use the formidable Intersphinx extension?
----------------------------------------------------------------------------------------

Heck yes!  This has almost nothing to do with Exhale, and everything to do with Sphinx.
I've prepared a crash-course on how to get it up and running on the companion site's
`Using Intersphinx <using_intersphinx_>`_ page.

.. _using_intersphinx: http://my-favorite-documentation-test.readthedocs.io/en/latest/using_intersphinx.html

Why does it build locally, but not on Read the Docs?
----------------------------------------------------------------------------------------
Most likely Exhale is failing to build if you are getting this.

Make sure you have the *virtualenv* functionality available on the Admin page of your
website enabled, and provide a ``requirements.txt`` that has at the very least the line
``exhale`` (lower case, RTD will ``pip install`` every line in ``requirements.txt``).
Refer to the RTD docs here_.

.. _here: http://docs.readthedocs.io/en/latest/faq.html#my-project-isn-t-building-with-autodoc

Why are there build warnings about generated files not being included?
----------------------------------------------------------------------------------------

This means that you have changed your API in a way that the files being generated have
changed.  For example, you changed the template parameters on something, or you deleted
a class.  So now when you run ``make html``, the original generated files are still
floating around down there even though the current execution of Exhale will not use
them.

Solution: see the :ref:`quickstart_clean_target` section of the Quickstart guide.

Unicode support?
----------------------------------------------------------------------------------------

Every action Exhale performs with respect to strings is done using unicode strings.  Or
at least I tried my very best to make sure unicode support works.

1. At the top of every file:

   .. code-block:: py

      from __future__ import unicode_literals

   This is why all of the documentation on this site for strings has a leading ``u``.

2. Every file written to:

   .. code-block:: py

      with codecs.open(file_name, "w", "utf-8") as f:

3. When using Python **3**, ``bytes`` conversion is done as:

   .. code-block:: py

      doxygen_input = bytes(doxygen_input, "utf-8")

The last one may *potentially* cause problems, but in local testing it seems to be OK.
E.g., if you only specify **ASCII** in your ``conf.py``, everything should work out
in the end.

.. note::

   Sphinx / reStructuredText supports ``utf-8`` no problem.  The only potential concern
   is communicating with Doxygen on stdin like this, but it's worked without issue
   for me so I kept it.  Please speak up if you are experiencing encoding / decoding
   specific issues in Exhale!

Why does my documentation take so long to build?
----------------------------------------------------------------------------------------

This is a byproduct of what is actually being done by Exhale.  If you look at the
build output of Exhale when you execute ``make html``, parsing and generating the
documents takes on the order of seconds.

What takes long is Sphinx, and the time it takes is directly proportional to the size
of the API being documented.  The larger the API, the more individual reStructuredText
documents there are being created.  Meaning there are more documents that Sphinx has
to read *and* write.

.. note::

   The ``sphinx-bootstrap-theme`` is noticeably slower than others.  I have suspicions
   as to why, but have not actually investigated potential fixes.

Why are the Sphinx RTD theme "Edit on GitHub" links are invalid?
----------------------------------------------------------------------------------------

Because I haven't figured out how to implement this correctly yet.  Feel free to give
input `on the issue`__.  They point to nowhere because you aren't tracking the generated
API with ``git`` (nor should you be).

__ https://github.com/svenevs/exhale/issues/2

.. tip::

   There is an existing hack you can use to at least make the links go somewhere that
   exists.  Use the page-level metadata feature of Exhale and point it to the root of
   your repository:

   .. code-block:: py

      exhale_args = {
          # ... required / optional arguments ...
          "pageLevelConfigMeta": ":github_url: https://github.com/username/project"
      }

.. note::

   The consequence of fixing the link is that *locally* the "View Page Source" that
   would let you see the generated reStructuredText (e.g. to get the link name) is
   now gone.  You will have to open the file *manually* in a text editor.  Recall that
   the generated files get placed in the folder specified by
   :data:`~exhale.configs.containmentFolder`.

.. _faq_metaprogramming_and_template_specialization:

Metaprogramming and template (specialization)?
----------------------------------------------------------------------------------------

Yes and no.  Partial and full template specialization are supported, but not elegantly.

1.  Currently there are no links from partial and full specializations back to their
    original (unspecialized) type.  This may change in a future release.  Finding the
    unspecialized type is complicated due to how things are presented by Doxygen.

2. Template classes / structs were given the most attention.  Functions may or may not
   work.

3. **All** template classes, specialized or not, **produce build warnings**.  These
   warnings come from Breathe.  The documentation appears, but the layout is a little
   strange.  For specializations in particular, they seem to produce an extra
   ``template <>`` in the output.

   For example, with a ``template <typename T, unsigned int N> DerivedClass``,

   **Partial Specialization** ``template <unsigned int N> DerivedClass<int, N>``
       Produces ``template <unsigned int N> template<> DerivedClass<int, N>``.

   **Full Specialization** ``template <> DerivedClass<bool, 2>``
       Produces ``template <> template<> DerivedClass<bool, 2>``

4. Where metaprogramming is concerned, it is more likely that Doxygen's preprocessor
   needs to have everything ``PREDEFINED``.  YMMV.

.. tip::

   If all else fails, you can force Doxygen to skip things.  See the next FAQ entry.

How can I get Doxygen to skip code it cannot process?
----------------------------------------------------------------------------------------

It depends on what you need.  If it's something like a macro that isn't expanding
correctly, you can try pre-defining it.  Otherwise, you skip it with preprocessor
symbols that are only defined when the documentation is building.  See the
:ref:`Doxygen PREDEFINED <doxygen_predefined>` section.

I thought reStructuredText was supported, why does it look weird?
----------------------------------------------------------------------------------------

If you're using complicated syntax (e.g., more than ``**bold**`` or listings), you
will likely want to put that documentation in a raw reStructuredText verbatim block.
This basically tells Doxygen to skip it, allowing for Breathe / Exhale to then process
it directly.

See the :ref:`Doxygen ALIASES <doxygen_aliases>` section for how to do this.

The likely problem: Doxygen runs **first**.  It supports Markdown, and it is probably
transforming your documentation based off Markdown rules before Breathe / Sphinx /
Exhale even gain access to it.  Forcing a verbatim reStructuredText environment means
that Doxygen simply passes the raw docstring unadulterated forward.

You aren't including my ``enum``'s, ``defines``, etc.  Why Not?
----------------------------------------------------------------------------------------

This happens because Doxygen is not including them.  See the
:ref:`document_your_files_son` section.

Why aren't my Classes, Structs, Enums, or Unions associated with the right file?
----------------------------------------------------------------------------------------

I'm not entirely sure.  Fortunately, you can specify the path explicitly for these.  See
the :ref:`file_associations` section.  Personally, I tend to just default to always
specifying the path manually.

My documentation is setup using groups, how can I use Exhale?
----------------------------------------------------------------------------------------

I do not support ``groups`` with Doxygen, as I assume if you have gone through the
effort to group everything then you have a desire to manually control the output.
Breathe already has an excellent ``doxygengroup`` directive, and you should use that.

How do I modify the pygments highlighter for a program listing?
----------------------------------------------------------------------------------------

By default Exhale will use :data:`utils.LANG_TO_LEX <exhale.utils.LANG_TO_LEX>` to
choose the pygments syntax highlighter for ``.. code-block:: <lexer>``.  For most
projects the defaults here should work as expected.  If you need to change it, set
:data:`~exhale.configs.lexerMapping` in your ``conf.py``.

Ok seriously, why is there SO MUCH documentation on a documentation system?
----------------------------------------------------------------------------------------

It's your choice whether or not you read it.  Back when I was getting started on all of
this stuff it was **overwhelming**.  I did my best to recall where I got confused, as
well as highlight some of the tricks I've picked up over the years.

Basically, it's because I'm hopeful that I can save *at least one person* from falling
into some of the more confusing "traps" I've encountered.
