FAQ
========================================================================================

.. contents::

Nothing is working, where did I go wrong?
----------------------------------------------------------------------------------------

Sorry to hear that.  Please try comparing how your documentation is set up with the
companion_ website.

If things look similar enough, or something isn't clear, raise an issue on GitHub.  I'll
do my best to support what I can, and if similar questions come up then I can add them
to this FAQ.

Make sure you set the :data:`exhale.configs.verboseBuild` to ``True``, there may be some
useful information being printed there.

.. _companion: http://my-favorite-documentation-test.readthedocs.io/en/latest/

Why does it build locally, but not on Read the Docs?
----------------------------------------------------------------------------------------
Most likely Exhale is failing to build if you are getting this.

Make sure you have the *virtualenv* functionality available on the Admin page of your
website enabled, and provide a ``requirements.txt`` that has at the very least the line
``exhale`` (lower case, RTD will ``pip install`` every line in ``requirements.txt``).
Refer to the RTD docs here_.

.. _here: http://docs.readthedocs.io/en/latest/faq.html#my-project-isn-t-building-with-autodoc

Metaprogramming and full template specialization?
----------------------------------------------------------------------------------------
Nope.  Partial template specialization at best is supported by Breathe; not full
template specialization.  Furthermore, Doxygen can barely handle metaprogramming...YMMV.

For partial templates, see the breathe templates_ section for how you would specialize.
My understanding is the spacing is sensitive.  I have yet to be able to include any form
of template specialization in breathe, though, including their example code.

.. _templates: http://breathe.readthedocs.io/en/latest/class.html#template-specialisation-example

Support of this is in progress, but for now just force Doxygen to skip it.

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
