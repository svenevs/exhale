########################################################################################
# License: CC0 1.0                                                                     #
#                                                                                      #
# See full license text here: https://creativecommons.org/publicdomain/zero/1.0/       #
########################################################################################
# In the event that this code is useful to you, please feel free to use it without     #
# attribution.  The CC0 1.0 license is chosen in the event that you need a license.    #
########################################################################################
# NOTE: I may one day submit a PR to just allow ``:type:`` annotations for Sphinx, if  #
#       so this extension would then be irrelevant ;)                                  #
########################################################################################
"""
Defines two new directive classes that can be added to your ``conf.py``.

If the file this were saved in was in ``_extensions/attr_param.py``, then you might
do something like this in your ``conf.py``:

.. code-block:: py

   # called automagically for you by sphinx
   def setup(app):
       import os
       import sys
       # make sure you can import by modifying sys.path
       extensions_dir = os.path.join(
           os.path.abspath(os.path.dirname(__file__)),
           '_extensions'
       )
       sys.path.insert(0, extensions_dir)

       # import and add the new directives
       from attr_param import AttrDirective, ParamDirective
       app.add_directive('attr', AttrDirective)
       app.add_directive('param', ParamDirective)

Now you can use ``.. attr::`` and ``.. param::`` in your reStructuredText documents
and/or python documentation strings :)

.. note::

   ``AttrDirective`` is mapped as ``.. attr::`` and ``ParamDirective`` is mapped as
   ``.. param::`` in the above example.  ``attr`` is chosen to avoid conflicts with
   e.g. ``.. atribute::`` (which does not *currently* allow type annotations).
"""
from sphinx.domains.python import py_sig_re, PyClassmember
from sphinx import addnodes
from docutils import nodes
from docutils.parsers.rst import directives


class AttrDirective(PyClassmember):
    """
    Allow directive style member documentation (``:ivar:`` or ``:attribute:``) as
    ``.. attr::``. This is particularly useful with using ``setattr`` as opposed to
    something being defined in ``__init__``, but you still want to be able to have
    anchor links to refer to the documentation.

    .. code-block:: rst

       .. attr:: names
          :type: python:str

    Assuming you have an intersphinx_mapping with python.  Internal links such
    as ``:type: mypkg.mod.SuperClass`` will work too.

    .. code-block:: rst

       .. attr:: names
          :type: str
          :no-link:

    Unfortunately, ``:no-link:`` naively triggers a ``docutils.nodes.Text("str", "str")``
    meaning if you do ``:type: **str**`` to make it bold, you'll get asterisks
    in the final html output in standard face font...
    """
    option_spec = {
        'type': directives.unchanged,
        'no-link': directives.flag
    }

    def handle_signature(self, sig, signode):
        fullname, name_prefix = super(AttrDirective, self).handle_signature(sig, signode)
        typeref = self.options.get('type', None)
        if typeref:
            if 'no-link' in self.options:
                refnode = nodes.Text(typeref, typeref)
            else:
                refnode = addnodes.pending_xref(
                    typeref,
                    reftype='any',
                    refdomain='std',
                    reftarget=typeref
                )
                type_literal = typeref.split(':')[-1]
                refnode += nodes.literal(type_literal, type_literal, classes=['xref'])

            signode += nodes.Text(' (', ' (')
            signode += refnode
            signode += nodes.Text(')', ')')

        return fullname, name_prefix


class ParamDirective(AttrDirective):
    """
    Virtually the same as AttrDirective, only modifies the link URL to have param in
    it to prevent duplicate ids from being generated.

    .. code-block:: rst

       .. param:: name
          :type:  python:str

          The name of the thing we are creating.
    """
    def handle_signature(self, sig, signode):
        fullname, name_prefix = super(ParamDirective, self).handle_signature(sig, signode)
        # modifying fullname will change the link title, e.g. for documenting the
        # `app` parameter for class Config in the exhale.configs module, using
        # .. param:: app, the fullname will come in as `config.Config.app`.
        # This is just changing it to be `config.Config.param.app` so that
        # duplicate paramaters across modules / functions are "namespaced" under
        # their own name
        #
        # *hacks* ;)
        parts = fullname.split('.')
        fullname_front = '.'.join(parts[:-1])
        fullname = '.'.join([fullname_front, 'param', parts[-1]])
        return fullname, name_prefix
