# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Various helper classes and functions for validating the class and file hierarchies.

Every derived class of :class:`testing.base.ExhaleTestCase` should have at least one
test case validating the class and file hierarchies.  The class and file hierarchies
do not need to be validated in the same method.  In both cases, the recipe is:

1. Create a hierarchy that enumerates **all** of the documented code in the test
   project. This will either be an instance of
   :class:`hierarchies.class_hierarchy <testing.hierarchies.class_hierarchy>`, or of
   :class:`hierarchies.file_hierarchy <testing.hierarchies.file_hierarchy>`.

2. Call the comparison function for the created hierarchy:
   :func:`~testing.hierarchies.compare_class_hierarchy` or
   :func:`~testing.hierarchies.compare_file_hierarchy`.
"""

from __future__ import unicode_literals
import codecs
import os
import textwrap
from copy import deepcopy

from exhale.graph import ExhaleNode
from testing import get_exhale_root
from testing.base import ExhaleTestCase

__all__ = [
    "root", "file_hierarchy", "class_hierarchy",
    "node",
    "clike",
    "function", "parameters",
    "enum",
    "namespace",
    "define",
    "typedef",
    "variable",
    "file",
    "directory",
    "union",
    "compare_file_hierarchy", "compare_class_hierarchy"
]


########################################################################################
# Doxygen compound test classes (proxies to exhale.graph.ExhaleNode).                  #
########################################################################################
class node(ExhaleNode):  # noqa: N801
    """
    Testing hierarchy parent class for pass-through construction of |ExhaleNode|.

    Upon construction, the parent class's ``refid`` parameter is set as the empty string
    in the testing framework.  This item is the Doxygen hash value, which is not
    available until after Doxygen has been executed.

    .. |ExhaleNode| replace:: :class:`exhale.graph.ExhaleNode`

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the documented compound.

        ``kind`` (:class:`python:str`)
            Assumed to be one of the types in :data:`exhale.utils.AVAILABLE_KINDS`.
    """

    def __init__(self, name, kind):
        super(node, self).__init__(name, kind, "")  # no Doxygen refid available

    def __str__(self):
        """
        Return ``"{self.kind}: {self.name}"``.
        """
        return "{0}: {1}".format(self.kind, self.name)

    def toConsole(self, level):
        """
        Print this node to the console, and call ``toConsole`` for all children.

        Logging is done to ``sys.stdout``.

        **Parameters**
            ``level`` (:class:`python:int`)
                The recursion level, used as ``"  " * level`` to indent children.
        """
        print("{0}{1}".format("  " * level, self))
        for child in self.children:
            child.toConsole(level + 1)


class clike(node):  # noqa: N801
    """
    Represent a ``class`` or ``struct``.

    **Parameters**
        ``kind`` (:class:`python:str`)
            Assumed to be either ``"class"`` or ``"struct"``.

        ``name`` (:class:`python:str`)
            The un-qualified name of the class or struct being represented.

        ``template`` (???)
            .. todo:: template specification / creation TBD for classes / structs.
    """

    def __init__(self, kind, name, template=[]):
        super(clike, self).__init__(name, kind)
        self.template = template


class directory(node):  # noqa: N801
    """
    Represent a ``directory`` in a file hierarchy.

    .. note::

       This class may only appear in a file hierarchy, not a class hierarchy.

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the directory being represented.
    """

    def __init__(self, name):
        super(directory, self).__init__(name, "dir")


class define(node):  # noqa: N801
    """
    Represents a ``define``.

    **Parameters**

        ``name`` (:class:`python:str`)
            The name of the define / macro being representated

    .. todo:: Do macros (with parameters) need special treatment?
    """

    def __init__(self, name):
        super(define, self).__init__(name, "define")


class enum(node):  # noqa: N801
    """
    Represent an ``enum``.

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the enum being represented.

        ``values`` (???)
            .. todo:: enumvalues are not currently handled in Exhale proper.

    """

    def __init__(self, name, values=None):
        super(enum, self).__init__(name, "enum")
        self.values = values


class file(node):  # noqa: N801
    """
    Represent a ``file``.

    .. note::

       This class may only appear in a file hierarchy, not a class hierarchy.

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the file being represented.
    """

    def __init__(self, name):
        super(file, self).__init__(name, "file")
        self.location = None  # TODO: these should not be needed anymore
        self.namespaces_used = []

    def __str__(self):
        """
        Return ``"{self.kind}: {self.location}"``.
        """
        return "{0}: {1}".format(self.kind, self.location)


class function(node):  # noqa: N801
    """
    Represent a (partial) ``function``.

    .. note::

       This key must always map to a value of
       :class:`hierarchies.parameters <testing.hierarchies.parameters>`.

       .. code-block:: py

          function("int", "add"): parameters("int", "int")

       represents the function declaration

       .. code-block:: cpp

          int add(int a, int b);

       Note that parameter names (``a`` and ``b`` in this example) are not to be
       included, only parameter types.

    **Parameters**
        ``return_type`` (:class:`python:str`)
            The return type of the function, e.g. ``"void"`` or ``"int"``.

        ``name`` (:class:`python:str`)
            The name of the function.

        ``template`` (???)
            .. todo:: template specification / creation TBD for functions.
    """

    def __init__(self, return_type, name, template=None):
        super(function, self).__init__(name, "function")
        self.return_type = return_type
        self.parameters = []  # set later, required to let functions be keys in dict
        self.template = template
        # TODO: template specializations are *NOT* handled,
        # we're just hacking in one in cpp_func_overloads...
        if template is not None and len(template) == 1:
            if template[0] == "overload::SuperStruct":
                self.name = "blargh< SuperStruct >"
                self.parameters = ["int"]
                self.template = []
            elif template[0] == "overload::nested::SuperStruct":
                self.name = "blargh< nested::SuperStruct >"
                self.parameters = ["int"]
                self.template = []

    def __str__(self):
        """
        Pass-through method that will return |f_signature|.

        .. |f_signature| replace:: :func:`ExhaleNode.full_signature <exhale.graph.ExhaleNode.full_signature>`
        """
        return self.full_signature()

    def setParameters(self, parameters):
        """
        Set the parameters of this function.

        Since this class is to map to a value of type
        :class:`hierarchies.parameters <testing.hierarchies.parameters>`, when the
        dictionary is being parsed this method will be called.
        """
        self.parameters = parameters.args


class parameters(object):  # noqa: N801
    """
    Represent a |function| parameters.

    .. |function| replace:: :class:`hierarchies.function <testing.hierarchies.function>`

    **Parameters**
        ``*args`` (Parameter Pack)
            Arbitrary list, **assumed** to be all strings.  For example,

            .. code-block:: cpp

               int add(int a, int b);

            is represented by creating

            .. code-block:: py

               function("int", "add"): parameters("int", "int")

            whereas

            .. code-block:: cpp

               void serialize(Serializer &s, const std::string &name, int id);

            is represented by creating

            .. code-block:: py

               function("void", "serialize"): parameters(
                   "Serializer&",
                   "const std::string&",
                   "int"
               )

            Only parameter *types* are to be included, not declared names (``int, int``
            not ``int a, int b``).

    **Attributes**
        ``self.args`` (:class:`python:list` of :class:`python:str`)
            The in-order list of function arguments including types.

    """

    def __init__(self, *args):
        self.args = args

    def __str__(self):
        """
        Return ``", ".join(a for a in self.args)``.
        """
        return ", ".join(a for a in self.args)


class namespace(node):  # noqa: N801
    """
    Represent a ``namespace``.

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the namespace being represented.
    """

    def __init__(self, name):
        super(namespace, self).__init__(name, "namespace")


class page(node):  # noqa: N801
    """
    Represent a ``page`` (doxygen specific).

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the page (doxygen identifier, not the text).
    """

    def __init__(self, name):
        super(page, self).__init__(name, "page")


class typedef(node):  # noqa: N801
    """
    Represents a ``typedef``.

    **Parameters**
        ``new_name`` (:class:`python:str`)
            The new name to typedef *to*.  For example, if you had
            ``using my_float = float;`` the new name is ``"my_float"``.

        ``old_name`` (:class:`python:str`)
            The old name to typedef *from*.  For example, if you had
            ``using my_float = float;`` the old name is ``"float"``.

        ``template``
            .. todo:: e.g. ``template <typename X> using ...``.  Not implemented.
    """

    def __init__(self, new_name, old_name, template=None):
        super(typedef, self).__init__(new_name, "typedef")
        self.old_name = old_name
        self.template = template


class union(node):  # noqa: N801
    """
    Represent a ``union``.

    .. todo:: union members are not actually tested at this point.

    **Parameters**
        ``name`` (:class:`python:str`)
            The name of the union being represented.
    """

    def __init__(self, name):
        super(union, self).__init__(name, "union")


class variable(node):  # noqa: N801
    """
    Represent a ``variable``.

    **Parameters**
        ``_type`` (:class:`python:str`)
            The type of the variable (e.g., ``"int"`` or ``"std::string"``).

        ``name`` (:class:`python:str`)
            The name of the variable, e.g. ``int foo = 0;`` has a name of ``"foo"``.

    .. todo:: nothing is actually done for validating types at this time
    """

    def __init__(self, _type, name):
        super(variable, self).__init__(name, "variable")
        self.type = _type


########################################################################################
# Doxygen index test classes (proxies to exhale.graph.ExhaleRoot).                     #
########################################################################################
def deep_copy_hierarchy_dict(spec):
    """
    Produce a deep copy of the input specification of a hierarchy dictionary.

    **Parameters**
        ``spec`` (:class:`python:dict`)
            The input specification dictionary of the hierarchy.

    **Returns**
    A copy of the dictionary with new underlying objects.
    """
    def traverse_copy(t_spec):
        if isinstance(t_spec, dict):
            t_spec_copy = {}
            for s in t_spec:
                v = t_spec[s]
                s_copy = deepcopy(s)
                if isinstance(v, dict):
                    t_spec_copy[s_copy] = traverse_copy(v)
                else:
                    t_spec_copy[s_copy] = deepcopy(v)
            return t_spec_copy
        else:
            return deepcopy(t_spec)
    return traverse_copy(spec)


class root(object):  # noqa: N801
    """
    Represent a class or file hierarchy to simulate an :class:`exhale.graph.ExhaleRoot`.

    **Parameters**
        ``hierarchy_type`` (:class:`python:str`)
            May be either ``"class"`` or ``"file"``, indicating which type of hierarchy
            is being represented.

        ``hierarchy`` (:class:`python:dict`)
            The hierarchy dictionary, see reference documentation for
            :class:`class_hierarchy <testing.hierarchies.class_hierarchy>` and / or
            :class:`file_hierarchy <testing.hierarchies.file_hierarchy>` for examples.

    **Raises**
        :class:`python:ValueError`
            If ``hierarchy_type`` is neither ``"class"`` nor ``"file"``, or the specified
            ``hierarchy`` not a dictionary or malformed.
    """

    def __init__(self, hierarchy_type, hierarchy):
        if hierarchy_type != "file" and hierarchy_type != "class":
            raise ValueError("Hierarchy type must be either 'file' or 'class'.")
        self.hierarchy_type = hierarchy_type

        # Mimic exhale.graph.ExhaleRoot fields.
        self.class_like = []
        self.defines    = []
        self.enums      = []
        self.functions  = []
        self.dirs       = []
        self.files      = []
        self.groups     = []
        self.namespaces = []
        self.pages      = []
        self.typedefs   = []
        self.unions     = []
        self.variables  = []

        # The listing of top-level constructs.
        self.top_level  = []

        # Initialize from the specified hierarchy and construct the graph.
        # NOTE: a deep copy of hierarchy is needed so that if a test wants to
        # examine multiple tests against the same hierarchy dict (cpp_nesting)
        # the manipulations here do not alter the original nodes.
        self._init_from(deep_copy_hierarchy_dict(hierarchy))
        self._reparent_all()

    def _init_from(self, hierarchy):
        if not isinstance(hierarchy, dict):
            raise ValueError("'hierarchy' must be a dictionary.")

        for node in hierarchy:
            # Make sure top-level entities have their locations set before recursion.
            if node.kind in ["dir", "file"]:
                node.location = node.name
            self._visit_children(node, hierarchy[node])
            self.top_level.append(node)

    def _reparent_all(self):
        # Make sure directories are nested
        dir_removals = []
        for d in self.dirs:
            if d.parent:
                if d not in d.parent.children:
                    d.parent.children.append(d)
                dir_removals.append(d)

        for d in dir_removals:
            self.dirs.remove(d)

        # For the remainder, we basically do the opposite of what exhale is doing:
        #
        # Exhale:
        # Nodes are taken from the top-level listing and re-parented as the graph is
        # traversed.
        #
        # Testing:
        # Parents are specified directly, remove them from the top-level lists.
        cl_removals = []
        for cl in self.class_like:
            if cl.parent and cl.parent.kind in ["struct", "class"]:
                cl_removals.append(cl)

        for cl in cl_removals:
            self.class_like.remove(cl)

        nspace_removals = []
        for nspace in self.namespaces:
            if nspace.parent and nspace.parent.kind == "namespace":
                nspace_removals.append(nspace)

        for nspace in nspace_removals:
            self.namespaces.remove(nspace)

        union_removals = []
        for u in self.unions:
            if u.parent and u.parent.kind in ["class", "struct", "namespace", "union"]:
                union_removals.append(u)

        for u in union_removals:
            self.unions.remove(u)

    def _track_node(self, node):
        lst_name = "Mapping from node.kind={0} to internal list not found.".format(node.kind)
        kind = node.kind
        if kind in ["class", "struct"]:
            lst_name = "class_like"
        elif kind == "define":
            lst_name = "defines"
        elif kind == "enum":
            lst_name = "enums"
        elif kind == "function":
            lst_name = "functions"
        elif kind == "dir":
            lst_name = "dirs"
        elif kind == "file":
            lst_name = "files"
        elif kind == "namespace":
            lst_name = "namespaces"
        elif kind == "page":
            lst_name = "pages"
        elif kind == "typedef":
            lst_name = "typedefs"
        elif kind == "union":
            lst_name = "unions"
        elif kind == "variable":
            lst_name = "variables"

        if lst_name not in self.__dict__.keys():
            raise ValueError("Invalid internal list name: {0}".format(lst_name))

        if node not in self.__dict__[lst_name]:
            self.__dict__[lst_name].append(node)

    def _visit_children(self, parent, child_spec):
        self._track_node(parent)

        if not isinstance(child_spec, dict):
            if isinstance(parent, function):
                if not isinstance(child_spec, parameters):
                    raise ValueError(
                        "Specification of 'function' [{0}] must be of type 'parameters'".format(parent.name)
                    )
                else:
                    parent.setParameters(child_spec)
                    return
            else:
                raise ValueError(
                    "Specification of '{0}' [{1}] must be a dictionary.".format(parent.kind, parent.name)
                )

        for child in child_spec:
            # Special cases, make sure the hierarchy is acceptable
            if parent.kind == "dir":
                if child.kind not in ["dir", "file"]:
                    raise ValueError(
                        "Children of directories may only be directories or files."
                    )
            elif parent.kind == "file":
                if child.kind in ["dir", "file"]:
                    raise ValueError(
                        "Children of files may not be of type {dir,file}!"
                    )

            # make sure children of files have 'def_in_file' set
            if parent.kind == "file":
                if child.kind == "namespace":
                    parent.namespaces_used.append(child)

                # NOTE: exhale graph does *NOT* do this for namespaces, but testing
                #       dictionary-based hierarchies need namespaces to have file
                #       parents so that they can propagate to children
                child.def_in_file = parent
            else:
                # Exhale stores pages in a hierarchy, but they are all also
                # direct children of the file.
                # TODO: should nested pages be children of the file?  Doesn't seem to
                # matter...
                if child.kind == "page":
                    file_parent = parent.def_in_file
                    child.def_in_file = file_parent
                    file_parent.children.append(child)

                child.parent = parent

            if child not in parent.children:
                if not (parent.kind == "file" and child.kind == "namespace"):
                    parent.children.append(child)

            # update the fully qualified paths for children of directories
            if parent.kind == "dir":
                if child.kind == "file":
                    child.location = os.path.normpath(os.path.join(
                        parent.name, child.name
                    ))
                elif child.kind == "dir":
                    child.name = os.path.join(parent.name, child.name)
            # simulate how Doxygen will present fully qualified names
            if parent.kind in ["class", "struct", "namespace"]:
                child.name = "{0}::{1}".format(parent.name, child.name)
                if self.hierarchy_type == "file":
                    child.def_in_file = parent.def_in_file
                    if child.kind == "namespace":
                        parent.def_in_file.namespaces_used.append(child)
                    else:
                        parent.def_in_file.children.append(child)

            self._visit_children(child, child_spec[child])

    def toConsole(self):
        """
        Dump the hierarchy to the console.

        Calls |toConsole| for each |node| in ``self.top_level``.

        .. |toConsole| replace:: :func:`node.toConsole <testing.hierarchies.node.toConsole>`
        .. |node| replace:: :class:`hierarchies.node <testing.hierarchies.node>`
        """
        for node in self.top_level:
            node.toConsole(0)


class class_hierarchy(root):  # noqa: N801
    r"""
    Represent a name scope hierarchy.

    The class hierarchy represents things that in C++ would equate to using a ``::`` to
    gain access to.  This includes:

    - Classes and structs (:class:`hierarchies.clike <testing.hierarchies.clike>`).
    - Enums (:class:`hierarchies.enum <testing.hierarchies.enum>`).
    - Namespaces (:class:`hierarchies.namespace <testing.hierarchies.namespace>`).
    - Unions (:class:`hierarchies.union <testing.hierarchies.union>`).

    Consider the following C++ code:

    .. code-block:: cpp

       // in file: include/main.h
       #pragma once

       namespace detail {
           struct SomeStruct { /* ... */ };
       }

       struct SomeStruct {
           struct View { /* ... */ };
       };

    Then the testing code may look like:

    .. code-block:: py

       from testing.base import ExhaleTestCase
       from testing.hierarchies import class_hierarchy,         \
                                       clike,                   \
                                       compare_class_hierarchy, \
                                       namespace

       class SomeTest(ExhaleTestCase):
           test_project = "..." # specify the correct name...

           def test_class_hierarchy(self):
               class_hierarchy_dict = {
                   clike("struct", "SomeStruct"): {
                       clike("struct", "View"): {}
                   },
                   namespace("detail"): {
                       clike("struct", "SomeStruct"): {}
                   }
               }
               compare_class_hierarchy(self, class_hierarchy(class_hierarchy_dict))

    **Parameters**
        ``hierarchy`` (:class:`python:dict`)
            The hierarchy associated with the name scopes for the test project.
    """

    def __init__(self, hierarchy):
        super(class_hierarchy, self).__init__("class", hierarchy)


class file_hierarchy(root):  # noqa: N801
    r"""
    Represent a parsed directory structure, including which file defines which compound.

    .. note::

       The test case file hierarchies encompass **more** than just what should show up
       in the generated Exhale file hierarchy (which only includes directories and
       files).

       Specifically, the test file hierarchy is expected to encode **every documented
       object** in the project.  This means there will be duplicated constructs between
       the class and file hierarchy tests.

       This is done in order to help check that the file a construct was defined in is
       correctly parsed / generated by Exhale.

    Working with the same example code as above:

    .. code-block:: cpp

       // in file: include/main.h
       #pragma once

       namespace detail {
           struct SomeStruct { /* ... */ };
       }

       struct SomeStruct {
           struct View { /* ... */ };
       };

    The testing code is essentially the same dictionary, only we need to include directory
    and file information:

    .. code-block:: py

       from testing.base import ExhaleTestCase
       from testing.hierarchies import clike,                  \
                                       compare_file_hierarchy, \
                                       directory,              \
                                       file                    \
                                       file_hierarchy          \
                                       namespace

       class SomeTest(ExhaleTestCase):
           test_project = "..." # specify the correct name...

           def test_file_hierarchy(self):
               file_hierarchy_dict = {
                   directory("include"): {
                       file("main.h"): {
                           clike("struct", "SomeStruct"): {
                               clike("struct", "View"): {}
                           },
                           namespace("detail"): {
                               clike("struct", "SomeStruct"): {}
                           }
                       }
                   }
               }
               compare_file_hierarchy(self, file_hierarchy(file_hierarchy_dict))

    **Parameters**
        ``hierarchy`` (:class:`python:dict`)
            The hierarchy associated with the name scopes for the test project.
    """

    def __init__(self, hierarchy):
        super(file_hierarchy, self).__init__("file", hierarchy)


########################################################################################
# Test comparison functions.                                                           #
########################################################################################
def _compare_children(hierarchy_type, test, test_child, exhale_child):
    if test_child.parent:
        test.assertTrue(
            exhale_child.parent is not None,
            f"test_child of kind={test_child.kind} name={test_child.name} had a "
            f"parent of kind={test_child.parent.kind} name={test_child.parent.name} "
            "but exhale_child did *NOT* have a parent.  Likely invalid test hierarchy.")
        test.assertEqual(test_child.parent.name, exhale_child.parent.name)
        test.assertEqual(test_child.parent.kind, exhale_child.parent.kind)
    else:
        # namespaces are not represented in the file hierarchy, but in the Exhale graph
        # the parent will be the namespace
        if "::" in test_child.name and hierarchy_type == "file":
            test.assertTrue(exhale_child.parent is not None)
            test.assertTrue(exhale_child.parent.kind == "namespace")
        else:
            # Better error message when the test fails, but don't crash tests
            # that succeed by accessing `parent`.
            def err_message():
                if exhale_child.parent is None:
                    return ""
                return (
                    f"exhale_child of kind={exhale_child.kind} "
                    f"name={exhale_child.name} had a parent of "
                    f"kind={exhale_child.parent.kind} "
                    f"name={exhale_child.parent.name} but *NO* parent was expected."
                )

            test.assertTrue(exhale_child.parent is None, err_message())

    if hierarchy_type == "file":
        if test_child.def_in_file:
            # TODO: populate location variables for files
            test.assertEqual(test_child.def_in_file.name, exhale_child.def_in_file.name)
            test.assertEqual(test_child.def_in_file.location, exhale_child.def_in_file.location)
        else:
            test.assertTrue(exhale_child.def_in_file is None)

        # Make sure parent references for directory and file pages are included.
        if test_child.kind in {"dir", "file"}:
            # Load in the generated file contents.
            generated_rst_path = os.path.join(
                test.getAbsContainmentFolder(), exhale_child.file_name
            )
            with codecs.open(generated_rst_path, "r", "utf-8") as gen_file:
                generated_rst = gen_file.read()

            if test_child.kind == "dir":
                # Make sure full directory path is included (at least for now, may
                # put it back in the title at some point).
                path = "*Directory path:* ``{path}``".format(path=test_child.name)
                test.assertTrue(
                    path in generated_rst,
                    textwrap.dedent('''
                        The following full path listing:

                        {vsep}
                        {path}
                        {vsep}

                        was not found in '{generated_rst_path}' with full contents:

                        {vsep}
                        {generated_rst}
                        {vsep}
                    ''').format(
                        vsep=("*" * 77),
                        path=path,
                        generated_rst_path=generated_rst_path,
                        generated_rst=generated_rst
                    )
                )
            else:  # test_child.kind == "file"
                program_listing_path = os.path.join(
                    os.path.dirname(generated_rst_path),
                    exhale_child.program_file  # wtf did i do gerrymanderNodeFilenames for?!
                )
                program_listing_basename = os.path.basename(program_listing_path)

                # 1. Make sure link to program_listing file is generated.
                program_listing_toctree = textwrap.dedent('''
                    .. toctree::
                       :maxdepth: 1

                       {program_listing_basename}
                ''').format(
                    program_listing_basename=program_listing_basename
                )
                test.assertTrue(
                    program_listing_toctree in generated_rst,
                    textwrap.dedent('''
                        The following toctree directive:

                        {vsep}
                        {program_listing_toctree}
                        {vsep}

                        was not found in '{generated_rst_path}' with full contents:

                        {vsep}
                        {generated_rst}
                        {vsep}
                    ''').format(
                        vsep=("*" * 77),
                        program_listing_toctree=program_listing_toctree,
                        generated_rst_path=generated_rst_path,
                        generated_rst=generated_rst
                    )
                )

                # 2. Make sure link back to file page from program_listing file is generated.
                program_back_link = textwrap.dedent('''
                    |exhale_lsh| :ref:`Return to documentation for file <{file_link}>` (``{file_location}``)

                    .. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS
                ''').format(
                    file_link=exhale_child.link_name,
                    file_location=exhale_child.location
                )
                with codecs.open(program_listing_path, "r", "utf-8") as pl_file:
                    desired_lines = []
                    for line in pl_file:
                        if line.startswith(".. code-block::"):
                            break
                        desired_lines.append(line)
                    program_listing_header = "".join(desired_lines)

                test.assertTrue(
                    program_back_link in program_listing_header,
                    textwrap.dedent('''
                        The following back-link:

                        {vsep}
                        {program_back_link}
                        {vsep}

                        was not found in '{program_listing_path}' with header contents:

                        {vsep}
                        {program_listing_header}
                        {vsep}
                    ''').format(
                        vsep=("*" * 77),
                        program_back_link=program_back_link,
                        program_listing_path=program_listing_path,
                        program_listing_header=program_listing_header
                    )
                )

            # If parent exists, verify that a link to the parent is created.
            if test_child.parent:
                # Reconstruct expected parent directory reference rst.
                # TODO: un-copy-paste this from graph.py
                if test_child.parent.kind == "file":
                    parent_unique_id = test_child.parent.location
                else:
                    parent_unique_id = test_child.parent.name
                parent_unique_id = parent_unique_id.replace(":", "_").replace(os.sep, "_").replace(" ", "_")
                parent_link_name = "{kind}_{id}".format(kind=test_child.parent.kind, id=parent_unique_id)
                parent_name = test_child.parent.name
                parent_reference = textwrap.dedent('''
                    |exhale_lsh| :ref:`Parent directory <{parent_link}>` (``{parent_name}``)

                    .. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS
                '''.format(
                    parent_link=parent_link_name, parent_name=parent_name
                ))

                # Verify that both files and directories link to their directory parent
                test.assertTrue(
                    parent_reference in generated_rst,
                    textwrap.dedent('''
                        The following parent directory reference:

                        {vsep}
                        {parent_reference}
                        {vsep}

                        was not found in '{generated_rst_path}' with full contents:

                        {vsep}
                        {generated_rst}
                        {vsep}
                    ''').format(
                        vsep=("*" * 77),
                        parent_reference=parent_reference,
                        generated_rst_path=generated_rst_path,
                        generated_rst=generated_rst
                    )
                )

    # Make sure they have the same name.
    test.assertEqual(
        test_child.name,
        exhale_child.name,
        "test_child.name [{tc_name}] != exhale_child.name [{ec_name}]".format(
            tc_name=test_child.name, ec_name=exhale_child.name
        )
    )
    # Make sure they have the same kind.
    test.assertEqual(
        test_child.kind,
        exhale_child.kind,
        "test_child.kind [{tc_kind}] != exhale_child.kind [{ec_kind}]".format(
            tc_kind=test_child.kind, ec_kind=exhale_child.kind
        )
    )
    # Make sure they have the same number of children.
    CHILD_COUNT_IGNORE_KINDS = ["enumvalue", "group"]
    num_exhale_children = sum(child.kind not in CHILD_COUNT_IGNORE_KINDS for child in exhale_child.children)
    test.assertEqual(
        len(test_child.children),
        num_exhale_children,
        textwrap.dedent('''
            For child: {child_name}

            test_child.children names:

            {tc_names}

            exhale_child.children names:

            {ec_names}
        ''').format(
            child_name=test_child.breathe_identifier(),
            tc_names="\n".join([
                "- {breathe_identifier}".format(breathe_identifier=child.breathe_identifier())
                for child in test_child.children
            ]),
            ec_names="\n".join([
                "- {breathe_identifier}".format(breathe_identifier=child.breathe_identifier())
                for child in exhale_child.children if child.kind not in CHILD_COUNT_IGNORE_KINDS
            ])
        )
    )

    for test_grand_child in test_child.children:
        exhale_grand_child = None
        if test_grand_child.kind == "function":
            test_signature = test_grand_child.full_signature()
            for candidate in exhale_child.children:
                if candidate.kind == "function" and candidate.full_signature() == test_signature:
                    exhale_grand_child = candidate
                    break
        else:
            for candidate in exhale_child.children:
                if candidate.kind == test_grand_child.kind and candidate.name == test_grand_child.name:
                    exhale_grand_child = candidate
        if not exhale_grand_child:
            raise RuntimeError("Matching child for [{0}] '{1}' not found!".format(
                test_grand_child.kind, test_grand_child.name
            ))
        _compare_children(hierarchy_type, test, test_grand_child, exhale_grand_child)


def compare_class_hierarchy(test, test_root):
    """
    Compare the parsed and expected class hierarchy for the specified test.

    This method should only be called in a ``test_*`` method implemented in a
    |ExhaleTestCase| member function.

    **Parameters**
        ``test`` (|ExhaleTestCase|)
            The test instance.  This test will have its ``assert*`` methods called
            in this method.  The :class:`exhale.graph.ExhaleRoot` instance for the test
            project is acquired through this parameter.

        ``test_root`` (|class_hierarchy|)
            The class hierarchy to compare the parsed root with.

    **Raises**
        :class:`python:ValueError`
            When ``test`` is not an |ExhaleTestCase|, or ``test_root`` is not a
            |class_hierarchy|.

    .. |ExhaleTestCase| replace:: :class:`ExhaleTestCase <testing.base.ExhaleTestCase>`
    .. |class_hierarchy| replace:: :class:`class_hierarchy <testing.hierarchies.class_hierarchy>`
    """
    # Some simple sanity checks
    if not isinstance(test, ExhaleTestCase):
        raise ValueError(
            "'test' parameter was not an instance of 'testing.base.ExhaleTestCase'."
        )
    if not isinstance(test_root, class_hierarchy):
        raise ValueError("test_root parameter must be an instance of `class_hierarchy`.")

    # Run some preliminary tests
    exhale_root = get_exhale_root(test)
    test.assertEqual(len(test_root.class_like), len(exhale_root.class_like))
    test.assertEqual(len(test_root.enums), len(exhale_root.enums))
    test.assertEqual(len(test_root.namespaces), len(exhale_root.namespaces))
    test.assertEqual(len(test_root.unions), len(exhale_root.unions))

    for test_obj in test_root.top_level:
        exhale_obj = None
        if test_obj.kind in ["class", "struct"]:
            for cl in exhale_root.class_like:
                if cl.name == test_obj.name and cl.kind == test_obj.kind:
                    exhale_obj = cl
                    break
        elif test_obj.kind == "enum":
            for e in exhale_root.enums:
                if e.name == test_obj.name:
                    exhale_obj = e
                    break
        elif test_obj.kind == "namespace":
            for n in exhale_root.namespaces:
                if n.name == test_obj.name:
                    exhale_obj = n
                    break
        elif test_obj.kind == "union":
            for u in exhale_root.unions:
                if u.name == test_obj.name:
                    exhale_obj = u
                    break

        if exhale_obj is None:
            test.assertTrue(
                False,
                msg="Did not find match for [{0}] {1}".format(test_obj.kind, test_obj.name)
            )

        _compare_children("class", test, test_obj, exhale_obj)


def compare_file_hierarchy(test, test_root):
    """
    Compare the parsed and expected file hierarchy for the specified test.

    This method should only be called in a ``test_*`` method implemented in a
    |ExhaleTestCase| member function.

    **Parameters**
        ``test`` (|ExhaleTestCase|)
            The test instance.  This test will have its ``assert*`` methods called
            in this method.  The :class:`exhale.graph.ExhaleRoot` instance for the test
            project is acquired through this parameter.

        ``test_root`` (|file_hierarchy|)
            The class hierarchy to compare the parsed root with.

    **Raises**
        :class:`python:ValueError`
            When ``test`` is not an |ExhaleTestCase|, or ``test_root`` is not a
            |file_hierarchy|.

    .. |file_hierarchy| replace:: :class:`file_hierarchy <testing.hierarchies.file_hierarchy>`
    """
    # Some simple sanity checks
    if not isinstance(test, ExhaleTestCase):
        raise ValueError(
            "'test' parameter was not an instance of 'testing.base.ExhaleTestCase'."
        )
    if not isinstance(test_root, file_hierarchy):
        raise ValueError("test_root parameter must be an instance of `file_hierarchy`.")

    # Run some preliminary tests
    exhale_root = get_exhale_root(test)
    test.assertEqual(len(test_root.dirs), len(exhale_root.dirs))
    test.assertEqual(len(test_root.files), len(exhale_root.files))
    for test_obj in test_root.top_level:
        exhale_obj = None
        if test_obj.kind == "dir":
            for d in exhale_root.dirs:
                if d.name == test_obj.name:  # TODO: duplicate directory names (nested)?
                    exhale_obj = d
                    break
        elif test_obj.kind == "file":
            for f in exhale_root.files:
                if f.name == test_obj.name:  # TODO: duplicate file names (nested)?
                    exhale_obj = f
                    break

        if exhale_obj is None:
            raise RuntimeError("Did not find match for [{0}] {1}".format(
                test_obj.kind, test_obj.name
            ))
        _compare_children("file", test, test_obj, exhale_obj)

    # Functions needs to be checked explicitly (overloaded function names are same...)
    test.assertEqual(len(test_root.functions), len(exhale_root.functions))

    def find_overloads(root):
        # keys: string function names
        # values: list of nodes (length 2 or larger indicates overload)
        overloads = {}
        for func in root.functions:
            if func.name not in overloads:
                overloads[func.name] = [func]
            else:
                overloads[func.name].append(func)

        return overloads

    test_overloads   = find_overloads(test_root)
    exhale_overloads = find_overloads(exhale_root)

    # Create explicit sets to be able to use in error message.
    test_overloads_keys   = set(test_overloads.keys())
    exhale_overloads_keys = set(exhale_overloads.keys())

    # enumerate items in set on their own lines
    def set_error_string(s):
        if not s:
            return "{ /* empty */ }"
        ret = "{\n"
        for item in s:
            ret += "  {item}\n".format(item=item)
        ret += "}"
        return ret

    test.assertEqual(
        test_overloads_keys,
        exhale_overloads_keys,
        # Error messages for sets are quite nice locally, but on CI they are not as
        # helpful.  Probably a python 2 vs 3 thing?  The below information is enough to
        # figure out where the problem is.
        textwrap.dedent('''\
            Functions grouped by overload name not equivalent!

            ==> e (expected, as enumerated by test):
            {expected}

            ==> d (discovered by exhale):
            {discovered}

            ==> Intersection [ e & d ]:
            {intersection}

            ==> Difference [ e - d ]:
            {difference_e_min_d}

            ==> Difference [ d - e ]:
            {difference_d_min_e}

            ==> Symmetric Difference [ e ^ d ]:
            {symmetric_difference}
        ''').format(
            expected=set_error_string(test_overloads_keys),
            discovered=set_error_string(exhale_overloads_keys),
            intersection=set_error_string(test_overloads_keys & exhale_overloads_keys),
            difference_e_min_d=set_error_string(test_overloads_keys - exhale_overloads_keys),
            difference_d_min_e=set_error_string(exhale_overloads_keys - test_overloads_keys),
            symmetric_difference=set_error_string(test_overloads_keys ^ exhale_overloads_keys)
        )
    )

    for key in test_overloads:
        # Surface-level test: must be the same length.
        test.assertEqual(
            len(test_overloads[key]),
            len(exhale_overloads[key]),
            "Function overload group [{group}]:\nTest:\n{test_ids}\n\nExhale:\n{exhale_ids}\n".format(
                group=key,
                test_ids="".join(
                    "\n - {0}".format(f.full_signature()) for f in test_overloads[key]
                ),
                exhale_ids="".join(
                    "\n - {0}".format(f.full_signature()) for f in exhale_overloads[key]
                )
            )
        )

        # Validate the return type, name, and signatures.
        test_functions = set(f.full_signature() for f in test_overloads[key])
        # TODO: fix template specials
        if test_functions == {"template <> int blargh(int)"}:
            test_functions = {"int blargh(int)"}
        exhale_functions = set(f.full_signature() for f in exhale_overloads[key])
        # The error message when not equal is _beautiful_ <3
        test.assertEqual(test_functions, exhale_functions)
