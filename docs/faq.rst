FAQ
========================================================================================

Nothing is working, where did I go wrong?
----------------------------------------------------------------------------------------

Sorry to hear that.  Please try comparing how your documentation is set up with the
companion_ website.

If things look similar enough, or something isn't clear, raise an issue on GitHub.  I'll
do my best to support what I can, and if similar questions come up then I can add them
to this FAQ.

Why does it build locally, but not on Read the Docs?
----------------------------------------------------------------------------------------
Most likely Exhale is failing to build if you are getting this.

Make sure you have the *virtualenv* functionality available on the Admin page of your
website enabled, and provide a ``requirements.txt`` that has at the very least the line
``breathe`` (lower case, RTD will ``pip install`` every line in ``requirements.txt``).
Refer to the RTD docs here_.

.. _companion: http://my-favorite-documentation-test.readthedocs.io/en/latest/
.. _here: http://docs.readthedocs.io/en/latest/faq.html#my-project-isn-t-building-with-autodoc

Metaprogramming and full template specialization?
----------------------------------------------------------------------------------------
Nope.  Partial template specialization at best is supported by Breathe; not full
template specialization.  Furthermore, Doxygen can barely handle metaprogramming...YMMV.

For partial templates, see the breathe templates_ section for how you would specialize.
My understanding is the spacing is sensitive.  I have yet to be able to include any form
of template specialization in breathe, though, including their example code.

.. _templates: http://breathe.readthedocs.io/en/latest/class.html#template-specialisation-example
