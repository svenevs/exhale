# from testing.base import ProjectTestCase
from testing.base import ExhaleTestCase

from exhale.utils import AVAILABLE_KINDS

__all__ = [
    "root", "node",
    "directory", "file", "function", "signature", "namespace", "enum", "clike",
    "compare_file_hierarchy"
]

# from exhale.graph import ExhaleNode
# inherit from exhalenode
class node:
    def __init__(self, kind, name):
        self.kind = kind
        self.name = name
        self.def_in_file = None
        self.children = []
        self.parent = None

    def toConsole(self, level):
        print("{0}{1}".format("  " * level, self))
        for child in self.children:
            child.toConsole(level + 1)

    def __lt__(self, other):
        return self.name < other.name

    def __str__(self):
        return "{0}: {1}".format(self.kind, self.name)

class directory(node):
    def __init__(self, name):
        super(directory, self).__init__("dir", name)


class file(node):
    def __init__(self, name):
        super(file, self).__init__("file", name)


class function(node):
    def __init__(self, returnType, name, template=None):
        super(function, self).__init__("function", name)
        self.return_type = returnType
        self.signature = None # set later, required to let functions be keys in dict
        self.template = None

    def setSignature(self, signature):
        self.signature = signature

    def __str__(self):
        if not self.signature:
            raise RuntimeError("{0}: no function signature!")
        return "{0} {1}({2})".format(
            self.return_type, self.name, self.signature
        )

class signature:
    def __init__(self, *args):
        self.args = args

    def __str__(self):
        return ", ".join(a for a in self.args)


class namespace(node):
    def __init__(self, name):
        super(namespace, self).__init__("namespace", name)


class enum(node):
    def __init__(self, name, values=None):
        super(enum, self).__init__("enum", name)
        self.values = values

# class-like entities (class and struct)
class clike(node):
    def __init__(self, kind, name, template=None):
        super(clike, self).__init__(kind, name)
        self.template = template

class root:
    # def __init__(self, classHierarchy, fileHierarchy):
    def __init__(self, hierarchy):
        self.class_like = []
        self.defines = []
        self.enums = []
        self.functions = []
        self.dirs = []
        self.files = []
        # self.groups = []
        self.namespaces = []
        self.typedefs = []
        self.unions = []
        self.variables = []

        self.top_level = []

        self._init_from(hierarchy)


        # self._init_class_hierarchy(classHierarchy)
        # self._init_file_hierarchy(fileHierarchy)

    def toConsole(self):
        for node in self.top_level:
            node.toConsole(0)


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
        elif kind == "union":
            lst_name = "unions"
        elif kind == "variable":
            lst_name = "variables"

        if lst_name not in self.__dict__.keys():
            raise ValueError("Invalid internal list name: {0}".format(lst_name))

        if node not in self.__dict__[lst_name]:
            self.__dict__[lst_name].append(node)

    def _visit_children(self, parent, childSpec):
        self._track_node(parent)

        if not isinstance(childSpec, dict):
            if isinstance(parent, function):
                if not isinstance(childSpec, signature):
                    raise ValueError(
                        "Specification of 'function' [{0}] must be of type 'signature'".format(parent.name)
                    )
                else:
                    parent.setSignature(childSpec)
                    return
            else:
                raise ValueError(
                    "Specification of '{0}' [{1}] must be a dictionary.".format(parent.kind, parent.name)
                )

        for child in childSpec:
            # Special cases, make sure the hierarchy is acceptable
            if parent.kind == "dir":
                if child.kind not in ["dir", "file"]:
                    raise ValueError(
                        "Children of directories may only be directories or files."
                    )
            elif parent.kind == "file":
                if child.kind in ["dir", "file", "namespace"]:
                    raise ValueError(
                        "Children of files may not be of type {dir,file,namespace}!"
                    )

            if parent.kind == "file":
                child.def_in_file = parent
            else:
                child.parent = parent
            if child not in parent.children:
                parent.children.append(child)
            self._visit_children(child, childSpec[child])

    def _init_from(self, hierarchy):
        if not isinstance(hierarchy, dict):
            raise ValueError("'hierarchy' must be a dictionary.")

        if len(hierarchy.keys()) < 1:
            raise ValueError("Specified 'hierarchy' is empty!")

        for node in hierarchy:
            if node.kind not in ["dir", "file"]:
                raise ValueError(
                    "Specified 'hierarchy' may only have directory and file nodes at "
                    "the root level."
                )
            self._visit_children(node, hierarchy[node])
            self.top_level.append(node)

    def _init_class_hierarchy(self, classHierarchy):
        for node in classHierarchy:
            self._visit_children(node, classHierarchy[node])

    def _init_file_hierarchy(self, fileHierarchy):
        pass

def _compare_children(test, testChild, exhaleChild):
    print("*" * 44)
    print("Comparing: {0} -- {1}".format(testChild.kind, testChild.name))
    print("*" * 44)
    if testChild.parent:
        test.assertTrue(exhaleChild.parent is not None)
        test.assertEqual(testChild.parent.name, exhaleChild.parent.name)
        test.assertEqual(testChild.parent.kind, exhaleChild.parent.kind)
    else:
        test.assertTrue(exhaleChild.parent is None)

    if testChild.def_in_file:
        # TODO: populate location variables for files
        test.assertEqual(testChild.def_in_file.name, exhaleChild.def_in_file.name)

    test.assertEqual(testChild.name, exhaleChild.name)
    test.assertEqual(testChild.kind, exhaleChild.kind)
    test.assertEqual(len(testChild.children), len(exhaleChild.children))

    for test_grand_child in testChild.children:
        exhale_grand_child = None
        for grand_child in exhaleChild.children:
            if grand_child.name == test_grand_child.name and \
                    grand_child.kind == test_grand_child.kind:
                exhale_grand_child = grand_child
                break
        if not exhale_grand_child:
            raise RuntimeError("Matching child for [{0}] '{1}' not found!".format(
                test_grand_child.kind, test_grand_child.name
            ))
        _compare_children(test, test_grand_child, exhale_grand_child)

def compare_file_hierarchy(test, testRoot, exhaleRoot):
    test.assertEqual(len(testRoot.dirs), len(exhaleRoot.dirs))
    test.assertEqual(len(testRoot.files), len(exhaleRoot.files))
    for test_obj in testRoot.top_level:
        exhale_obj = None
        if test_obj.kind == "dir":
            for d in exhaleRoot.dirs:
                if d.name == test_obj.name:  # TODO: duplicate directory names (nested)?
                    exhale_obj = d
                    break
        elif test_obj.kind == "file":
            for f in exhaleRoot.files:
                if f.name == test_obj.name:  # TODO: duplicate file names (nested)?
                    exhale_obj = f
                    break

        if exhale_obj is None:
            raise RuntimeError("Did not find match for [{0}] {1}".format(
                test_obj.kind, test_obj.name
            ))
        _compare_children(test, test_obj, exhale_obj)
