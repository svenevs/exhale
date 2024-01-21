########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_dir_underscores`` project.
"""

import os

from testing.base import ExhaleTestCase
from testing.hierarchies import                                                        \
    class_hierarchy, compare_class_hierarchy, compare_file_hierarchy, file_hierarchy


class CPPDirUnderscores(ExhaleTestCase):
    """
    Primary test class for project ``cpp_dir_underscores``.
    """

    test_project = "cpp_dir_underscores"
    """.. testproject:: cpp_dir_underscores"""

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))

    def check_title_link(self, name_map, node_map, t_type):
        """
        Verify the ``title`` and ``link_name`` of the specified nodes.

        .. note::

            It is assumed that the ``name_map`` and ``node_map`` parameters have the
            exact same set of keys.

        **Parameters**
            ``name_map`` : :class:`python:dict`
                Mapping of "dirname/filename" => expected [title, link_name].

            ``node_map`` : :class:`python:dict`
                Mapping of "dirname/filename" => ExhaleNode objects

            ``t_type`` : :class:`python:str`
                For formatting the error message.  Should be ``"file"`` or
                ``"directory"``.
        """
        for name, (title, link_name) in name_map.items():
            node = node_map[name]
            self.assertTrue(
                node.title == title,
                (
                    "Wrong title for {t_type} {name}!  Expected {title}, but got "
                    "{node_title}"
                ).format(
                    t_type=t_type,
                    name=node.name,
                    title=title,
                    node_title=node.title))
            self.assertTrue(
                node.link_name == link_name,
                (
                    "Wrong link_name for {t_type} {name}!  Expected {link_name}, but "
                    "got {node_link_name}"
                ).format(
                    t_type=t_type,
                    name=node.name,
                    link_name=link_name,
                    node_link_name=node.link_name))

    def test_files(self):
        """Verify that file nodes have correct title and link."""
        # include/
        # ├── interface_alpha
        # │   ├── alpha.hpp
        # │   ├── one_two_three
        # │   │   └── one_two_three.hpp
        # │   └── __four_five_six__
        # │       └── __four_five_six__.hpp
        # └── interface_beta
        #     └── beta.hpp
        # Map: filename => [title, link_name]
        f_map = {
            "alpha.hpp": [
                "File alpha.hpp",
                "file_include_interface_alpha_alpha.hpp"
            ],
            "one_two_three.hpp": [
                "File one_two_three.hpp",
                "file_include_interface_alpha_one_two_three_one_two_three.hpp"
            ],
            "__four_five_six__.hpp": [
                "File __four_five_six__.hpp",
                "file_include_interface_alpha___four_five_six_____four_five_six__.hpp"
            ],
            "beta.hpp": [
                "File beta.hpp",
                "file_include_interface_beta_beta.hpp"
            ]
        }
        node_map = {
            f.name: f for f in self.app.exhale_root.all_nodes if f.kind == "file"
        }
        self.check_title_link(f_map, node_map, "file")

    def test_directories(self):
        """Verify that file nodes have correct title and link."""
        # include/
        # ├── interface_alpha
        # │   ├── alpha.hpp
        # │   ├── one_two_three
        # │   │   └── one_two_three.hpp
        # │   └── __four_five_six__
        # │       └── __four_five_six__.hpp
        # └── interface_beta
        #     └── beta.hpp
        # Map: filename => [title, link_name]
        d_map = {
            "interface_alpha": [
                "Directory interface_alpha",
                "dir_include_interface_alpha"
            ],
            "one_two_three": [
                "Directory one_two_three",
                "dir_include_interface_alpha_one_two_three"
            ],
            "__four_five_six__": [
                "Directory __four_five_six__",
                "dir_include_interface_alpha___four_five_six__"
            ],
            "interface_beta": [
                "Directory interface_beta",
                "dir_include_interface_beta"
            ]
        }
        node_map = {
            # directory.name has the full path in it, just get the basename
            os.path.basename(d.name): d
            for d in self.app.exhale_root.all_nodes if d.kind == "dir"
        }
        self.check_title_link(d_map, node_map, "directory")
