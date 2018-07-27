# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
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
import os

from exhale.graph import ExhaleNode
from testing.base import ExhaleTestCase

__all__ = [
    "root", "file_hierarchy", "class_hierarchy",
    "node",
    "clike",
    "function", "signature",
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

    def __init__(self, kind, name, template=None):
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
       :class:`hierarchies.signature <testing.hierarchies.signature>`.

       .. code-block:: py

          function("int", "add"): signature("int a", "int b")

       represents the function declaration

       .. code-block:: cpp

          int add(int a, int b);

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
        self.signature = None  # set later, required to let functions be keys in dict
        self.template = None

    def __str__(self):
        """
        Return the full declaration and signature of this function.

        **Raises**
            :class:`python:RuntimeError`
                If ``self.signature`` is ``None``, meaning the hierarchy was not
                correctly parsed from the json-like dictionary.
        """
        if not self.signature:
            raise RuntimeError("{0}: no function signature!".format(self.name))
        return "{0} {1}({2})".format(
            self.return_type, self.name, self.signature
        )

    def setSignature(self, signature):
        """
        Set the signature of this function.

        Since this class is to map to a value of type
        :class:`hierarchies.signature <testing.hierarchies.signature>`, when the
        dictionary is being parsed this method will be called.
        """
        self.signature = signature


class signature(object):  # noqa: N801
    """
    Represent a |function| signature.

    .. |function| replace:: :class:`hierarchies.function <testing.hierarchies.function>`

    **Parameters**
        ``*args`` (Parameter Pack)
            Arbitrary list, **assumed** to be all strings.  Must also include types.
            For example,

            .. code-block:: cpp

               int add(int a, int b);

            is represented by creating

            .. code-block:: py

               function("int", "add"): signature("int a", "int b")

            whereas

            .. code-block:: cpp

               void serialize(Serializer &s, const std::string &name, int id);

            is represented by creating

            .. code-block:: py

               function("void", "serialize"): signature(
                   "Serializer &s",
                   "const std::string &name",
                   "int id"
               )

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
        self.typedefs   = []
        self.unions     = []
        self.variables  = []

        # The listing of top-level constructs.
        self.top_level  = []

        # Initialize from the specified hierarchy and construct the graph.
        self._init_from(hierarchy)
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
            if u.parent and u.parent.kind in ["class", "struct", "union"]:
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
                if not isinstance(child_spec, signature):
                    raise ValueError(
                        "Specification of 'function' [{0}] must be of type 'signature'".format(parent.name)
                    )
                else:
                    parent.setSignature(child_spec)
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
                child.parent = parent

            if child not in parent.children:
                if not (parent.kind == "file" and child.kind == "namespace"):
                    parent.children.append(child)

            # update the fully qualified paths for children of directories
            if parent.kind == "dir":
                if child.kind == "file":
                    child.location = os.path.join(parent.name, child.name)
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
        test.assertTrue(exhale_child.parent is not None)
        test.assertEqual(test_child.parent.name, exhale_child.parent.name)
        test.assertEqual(test_child.parent.kind, exhale_child.parent.kind)
    else:
        # namespaces are not represented in the file hierarchy, but in the Exhale graph
        # the parent will be the namespace
        if "::" in test_child.name and hierarchy_type == "file":
            test.assertTrue(exhale_child.parent is not None)
            test.assertTrue(exhale_child.parent.kind == "namespace")
        else:
            test.assertTrue(exhale_child.parent is None)

    if hierarchy_type == "file":
        if test_child.def_in_file:
            # TODO: populate location variables for files
            test.assertEqual(test_child.def_in_file.name, exhale_child.def_in_file.name)
            test.assertEqual(test_child.def_in_file.location, exhale_child.def_in_file.location)
        else:
            test.assertTrue(exhale_child.def_in_file is None)

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
        "\ntest_child.children names:\n\n{tc_names}\n\nexhale_child.children names:\n\n{ec_names}\n".format(
            tc_names="\n- ".join(["{name}".format(name=child.name) for child in test_child.children]),
            ec_names="\n- ".join([
                "{name}".format(name=child.name)
                for child in exhale_child.children if child.kind not in CHILD_COUNT_IGNORE_KINDS
            ])
        )
    )

    for test_grand_child in test_child.children:
        exhale_grand_child = None
        for grand_child in exhale_child.children:
            if grand_child.name == test_grand_child.name and \
                    grand_child.kind == test_grand_child.kind:
                exhale_grand_child = grand_child
                break
        if not exhale_grand_child:
            raise RuntimeError("Matching child for [{0}] '{1}' not found!".format(
                test_grand_child.kind, test_grand_child.name
            ))
        _compare_children(hierarchy_type, test, test_grand_child, exhale_grand_child)


def _get_exhale_root(test):
    # Get the finalized exhale.graph.ExhaleRoot object
    # TODO: in future this app.exhale_root will *NOT* be set, but instead it will be
    # something else depending on how the multi-project setup works, AKA if you are
    # reading this `app.exhale_root` is *NOT* a feature you can rely on!!!
    app = getattr(test, "app", None)
    if app is None:
        raise RuntimeError("Critical failure: the test_root.app was 'None'.")
    return app.exhale_root


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
    exhale_root = _get_exhale_root(test)
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
    exhale_root = _get_exhale_root(test)
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
