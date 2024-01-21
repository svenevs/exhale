# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_fortran_mixed`` project.
"""

from __future__ import unicode_literals
import os
import platform
import re

from testing import get_exhale_root
from testing.base import ExhaleTestCase
from testing.decorators import confoverrides
from testing.hierarchies import compare_file_hierarchy, file_hierarchy


@confoverrides(exhale_args={
    "exhaleDoxygenStdin": "INPUT = ../include ../src/conversions.f90"
})
class CPPFortranMixed(ExhaleTestCase):
    """
    Primary test class for project ``cpp_fortran_mixed``.

    This test class exists to test explicit language lexer mappings via
    :data:`~exhale.configs.lexerMapping`.  Note that the C++ code and namespace
    ``convert`` is definitively chosen to be different than the name of the fortran
    module name (``conversions``).  If they are the same, some interesting things
    happen on the Doxygen side, because Doxygen will combine the namespaces.

    .. todo::

        These tests are incomplete (``from __future__ import config_objects``).  The
        module level storage creates conflicts between the test cases when specifying
        the regular expressions :/

        Currently there is only one test for a custom lexer mapping, and it only
        actually works because the name is alphabetically sorted after the default
        test (meaning pytest will run it after).

    .. todo::

        The full function validation does not support templates (yet).  Templates at
        large in the testing framework need to be reworked, currently it is all boiler
        plate code with no actual validation...

    """

    test_project = "cpp_fortran_mixed"
    """.. testproject:: cpp_fortran_mixed"""

    def test_hierarchies(self):
        """
        Validate the class and file hierarchies.

        **Not tested on Windows**, maybe I'll care to fix it one day.
        `But it is not this day`__!

        __ https://youtu.be/EXGUNvIFTQw

        .. todo::

            Too much shared code in hierarchy comparisons, the class hierarchy for this
            project should be **empty**.  Need to enable asserting this fact (same for
            the ``cpp_nesting`` project).
        """
        if platform.system() != "Windows":
            # compare_class_hierarchy(self, class_hierarchy({}))
            compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))

    def validate_pygments_lexers(self, exhale_root, node_map):
        """
        Validate nodes have the expected pygments lexer in their program listing file.

        **Parameters**

            ``exhale_root`` (:class:`exhale.graph.ExhaleRoot`)
                The graph root object for this project.

            ``node_map`` (:class:`python:dict`)
                A map of :class:`exhale.graph.ExhaleNode` objects to string values.  The
                keys must be the nodes extracted from the ``exhale_root`` (as opposed
                to a testing type).  Each value should be a pygments lexer, such as
                ``"cpp"`` or ``"fortran"``.

                The generated program listing file will be parsed and an assert
                statement performed for equality to these specified values.
        """
        lexer_regex = re.compile(r"^.. code-block:: (.*)$")

        for file_node in node_map:
            expected_lexer = node_map[file_node]
            program_listing_file_path = os.path.join(
                exhale_root.root_directory,
                file_node.program_file
            )

            lexer_was_asserted = False
            with open(program_listing_file_path) as program_listing_file:
                for line in program_listing_file:
                    lexer_match = lexer_regex.match(line)
                    if lexer_match:
                        lexer = lexer_match.groups()[0]
                        self.assertTrue(
                            lexer == expected_lexer,
                            "{}: expected '{}' but got '{}' language lexer.".format(
                                file_node.location, expected_lexer, lexer
                            )
                        )
                        lexer_was_asserted = True
                        break

            # Make sure we actually ran a check for this file.
            self.assertTrue(
                lexer_was_asserted,
                "Did not find '.. code-block:: xxxx' in [{}]".format(program_listing_file_path)
            )

    def get_hpp_and_f90_nodes(self, exhale_root):
        """
        Return the two :class:`~exhale.graph.ExhaleNode` objects for this project.

        **Parameters**

            ``exhale_root`` (:class:`~exhale.graph.ExhaleRoot`)
                The graph root object for this project.

        **Returns**

            :class:`python:tuple`
                A length two tuple of :class:`~exhale.graph.ExhaleNode` objects, ordered
                as ``(convert_hpp, conversions_f90)``.  These represent the files
                ``include/convert/convert.hpp`` and ``src/conversions.f90``,
                respectively.
        """
        convert_hpp          = None
        convert_hpp_path     = os.path.join("include", "convert", "convert.hpp")
        conversions_f90      = None
        conversions_f90_path = os.path.join("src", "conversions.f90")
        for f in exhale_root.files:
            if f.location == convert_hpp_path:
                convert_hpp = f
                continue
            elif f.location == conversions_f90_path:
                conversions_f90 = f
                continue

        self.assertTrue(
            convert_hpp is not None,
            "Could not find ExhaleNode with file location 'include/convert/convert.hpp'."
        )
        self.assertTrue(
            conversions_f90 is not None,
            "Could not find ExhaleNode with file location 'src/conversions.f90'."
        )

        return (convert_hpp, conversions_f90)

    def test_default_lexers(self):
        """
        Verify ``convert.hpp`` maps to ``"cpp"`` and ``conversions.f90`` to ``"fortran"``.
        """
        exhale_root = get_exhale_root(self)
        convert_hpp, conversions_f90 = self.get_hpp_and_f90_nodes(exhale_root)
        self.validate_pygments_lexers(
            exhale_root, {convert_hpp: "cpp", conversions_f90: "fortran"}
        )

    @confoverrides(exhale_args={"lexerMapping": {r".*\.f90": "python"}})
    def test_modified_fortran(self):
        """
        Verify regular expression overload of ``*.f90`` files map to ``"python"``.
        """
        exhale_root = get_exhale_root(self)
        convert_hpp, conversions_f90 = self.get_hpp_and_f90_nodes(exhale_root)
        self.validate_pygments_lexers(
            exhale_root, {convert_hpp: "cpp", conversions_f90: "python"}
        )
