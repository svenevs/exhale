import itertools
import os

__all__ = [
    "root", "node", "file_hierarchy", "class_hierarchy",
    "directory", "file", "function", "signature", "namespace", "enum", "clike", "union",
    "compare_file_hierarchy", "compare_class_hierarchy"
]

# from exhale.graph import ExhaleNode
# inherit from exhalenode
class node(object):
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
        self.location = None
        self.namespaces_used = []

    def __str__(self):
        return "{0}: {1}".format(self.kind, self.location)


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

class signature(object):
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

class union(node):
    def __init__(self, name):
        super(union, self).__init__("union", name)


class root(object):
    # def __init__(self, classHierarchy, fileHierarchy):
    def __init__(self, hierarchyType, hierarchy):
        if hierarchyType != "file" and hierarchyType != "class":
            raise ValueError("Hierarchy type must be either 'file' or 'class'.")
        self.hierarchy_type = hierarchyType
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
        self._reparent_all()


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

            self._visit_children(child, childSpec[child])

    def _init_from(self, hierarchy):
        if not isinstance(hierarchy, dict):
            raise ValueError("'hierarchy' must be a dictionary.")

        for node in hierarchy:
            # Make sure the top-level entities have their locations set before recursion
            if node.kind in ["dir", "file"]:
                node.location = node.name
            self._visit_children(node, hierarchy[node])
            self.top_level.append(node)

    def _reparent_all(self):
        # make sure directories are nested
        dir_removals = []
        for d in self.dirs:
            if d.parent:
                if d not in d.parent.children:
                    d.parent.children.append(d)
                dir_removals.append(d)

        for d in dir_removals:
            self.dirs.remove(d)

        # for the remainder, we basically do the opposite of what exhale is doing
        # exhale: inspect names and reparent
        # testing: parents specified directly, remove them from the top-level lists
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

        # chain = itertools.chain(
        #     self.class_like,
        #     self.defines,
        #     self.enums,
        #     self.functions,
        #     self.typedefs,
        #     self.unions,
        #     self.variables
        # )
        # for node in chain:
        #     if node.def_in_file and node not in node.def_in_file.children:
        #         node.def_in_file.children.append(node)

    def _init_class_hierarchy(self, classHierarchy):
        for node in classHierarchy:
            self._visit_children(node, classHierarchy[node])

    def _init_file_hierarchy(self, fileHierarchy):
        pass


class file_hierarchy(root):
    def __init__(self, hierarchy):
        super(file_hierarchy, self).__init__("file", hierarchy)


class class_hierarchy(root):
    def __init__(self, hierarchy):
        super(class_hierarchy, self).__init__("class", hierarchy)


def _compare_children(hierarchyType, test, testChild, exhaleChild):
    print("*" * 44)
    print("Comparing: {0} -- {1}".format(testChild.kind, testChild.name))
    print("*" * 44)
    if testChild.parent:
        test.assertTrue(exhaleChild.parent is not None)
        test.assertEqual(testChild.parent.name, exhaleChild.parent.name)
        test.assertEqual(testChild.parent.kind, exhaleChild.parent.kind)
    else:
        # namespaces are not represented in the file hierarchy, but in the Exhale graph
        # the parent will be the namespace
        if "::" in testChild.name and hierarchyType == "file":
            test.assertTrue(exhaleChild.parent is not None)
            test.assertTrue(exhaleChild.parent.kind == "namespace")
        else:
            test.assertTrue(exhaleChild.parent is None)

    if hierarchyType == "file":
        if testChild.def_in_file:
            # TODO: populate location variables for files
            test.assertEqual(testChild.def_in_file.name, exhaleChild.def_in_file.name)
            test.assertEqual(testChild.def_in_file.location, exhaleChild.def_in_file.location)
        else:
            test.assertTrue(exhaleChild.def_in_file is None)

    test.assertEqual(testChild.name, exhaleChild.name)
    test.assertEqual(testChild.kind, exhaleChild.kind)
    test.assertEqual(len(testChild.children), len(exhaleChild.children))

    for test_grand_child in testChild.children:
        exhale_grand_child = None
        for grand_child in exhaleChild.children:
            print("test: [{}] {} -- exhale: [{}] {}".format(
                test_grand_child.kind, test_grand_child.location if test_grand_child.kind == "file" else test_grand_child.name,
                grand_child.kind, grand_child.location if grand_child.kind == "file" else grand_child.name
            ))
            if grand_child.name == test_grand_child.name and \
                    grand_child.kind == test_grand_child.kind:
                exhale_grand_child = grand_child
                break
        if not exhale_grand_child:
            raise RuntimeError("Matching child for [{0}] '{1}' not found!".format(
                test_grand_child.kind, test_grand_child.name
            ))
        _compare_children(hierarchyType, test, test_grand_child, exhale_grand_child)


def compare_file_hierarchy(test, testRoot, exhaleRoot):
    if not isinstance(testRoot, file_hierarchy):
        raise ValueError("testRoot parameter must be an instance of `file_hierarchy`.")

    test.assertEqual(len(testRoot.dirs ), len(exhaleRoot.dirs ))
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
        _compare_children("file", test, test_obj, exhale_obj)


def compare_class_hierarchy(test, testRoot, exhaleRoot):
    if not isinstance(testRoot, class_hierarchy):
        raise ValueError("testRoot parameter must be an instance of `class_hierarchy`.")

    test.assertEqual(len(testRoot.class_like), len(exhaleRoot.class_like))
    test.assertEqual(len(testRoot.enums     ), len(exhaleRoot.enums     ))
    test.assertEqual(len(testRoot.namespaces), len(exhaleRoot.namespaces))
    test.assertEqual(len(testRoot.unions    ), len(exhaleRoot.unions    ))

    for test_obj in testRoot.top_level:
        exhale_obj = None
        if test_obj.kind in ["class", "struct"]:
            for cl in exhaleRoot.class_like:
                if cl.name == test_obj.name and cl.kind == test_obj.kind:
                    exhale_obj = cl
                    break
        elif test_obj.kind == "enum":
            for e in exhaleRoot.enums:
                if e.name == test_obj.name:
                    exhale_obj = e
                    break
        elif test_obj.kind == "namespace":
            for n in exhaleRoot.namespaces:
                if n.name == test_obj.name:
                    exhale_obj = n
                    break
        elif test_obj.kind == "union":
            for u in exhaleRoot.unions:
                if u.name == test_obj.name:
                    exhale_obj = u
                    break

        if exhale_obj is None:
            raise RuntimeError("Did not find match for [{0}] {1}".format(
                test_obj.kind, test_obj.name
            ))

        _compare_children("class", test, test_obj, exhale_obj)



if __name__ == "__main__":
    files = file_hierarchy({
        directory("include"): {
            file("top_level.hpp"): {
                clike("struct", "top_level"): {}
            },
            directory("nested"): {
                directory("one"): {
                    file("one.hpp"): {},
                },
                directory("two"): {
                    file("two.hpp"): {}
                },
                directory("dual_nested"): {
                    directory("one"): {
                        file("one.hpp"): {}
                    },
                    directory("two"): {
                        file("two.hpp"): {}
                    }
                }

            }
        }
    })
    files.toConsole()
    classes = class_hierarchy({
        clike("struct", "top_level"): {},
        namespace("nested"): {
            clike("struct", "one"): {},
            clike("struct", "two"): {},
            namespace("dual_nested"): {
                clike("struct", "one"): {},
                clike("struct", "two"): {}
            }
        },
    })
    classes.toConsole()
