########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for the ``cpp_nesting`` project.
"""


import os
import re
import textwrap

from testing import get_exhale_root
from testing.base import ExhaleTestCase
from testing.decorators import confoverrides
from testing.hierarchies import                                                        \
    class_hierarchy, compare_class_hierarchy, compare_file_hierarchy, file_hierarchy


class TestedExclusionTypes(object):
    """
    An "enum" for listing exclusions we care about.

    Yes, I still need to support python 2.
    """

    NoExclusions = 0
    """No exclusions were requested."""

    AllImpl = 1
    """All ``r".*Impl$"`` should be excluded."""

    DetailImpl = 2
    """Only ``r".*detail::.*Impl$"`` should be excluded."""


class CPPPimpl(ExhaleTestCase):
    """
    Primary test class for project ``cpp_pimpl``.
    """

    test_project = "cpp_pimpl"
    """.. testproject:: cpp_pimpl"""

    def impl_link_names(self):
        """Link names for ``pimpl::{Earth,Jupiter}Impl``."""
        links = self.link_name_format_dict()
        return {
            "- :ref:`{pimpl_EarthImpl}`".format(**links),
            "- :ref:`{pimpl_JupiterImpl}`".format(**links)
        }

    def detail_impl_link_names(self):
        """Link names for ``pimpl::detail::{Earth,Jupiter}Impl``."""
        links = self.link_name_format_dict()
        return {
            "- :ref:`{pimpl_detail_EarthImpl}`".format(**links),
            "- :ref:`{pimpl_detail_JupiterImpl}`".format(**links),
        }

    def earth_hpp_link_names(self):
        """Link names for ``earth.hpp``."""
        links = self.link_name_format_dict()
        return {
            "- :ref:`{pimpl_Earth}`".format(**links),
            "- :ref:`{pimpl_Earth_v2}`".format(**links),
            "- :ref:`{pimpl_EarthImpl}`".format(**links),
            "- :ref:`{pimpl_detail_EarthImpl}`".format(**links)
        }

    def jupiter_hpp_link_names(self):
        """Link names for ``jupiter.hpp``."""
        links = self.link_name_format_dict()
        return {
            "- :ref:`{pimpl_Jupiter}`".format(**links),
            "- :ref:`{pimpl_Jupiter_v2}`".format(**links),
            "- :ref:`{pimpl_JupiterImpl}`".format(**links),
            "- :ref:`{pimpl_detail_JupiterImpl}`".format(**links)
        }

    def nspace_pimpl_link_names(self):
        """Link names for ``namespace pimpl``."""
        links = self.link_name_format_dict()
        return {
            "- :ref:`{pimpl_detail}`".format(**links),
            "- :ref:`{pimpl_Earth}`".format(**links),
            "- :ref:`{pimpl_Earth_v2}`".format(**links),
            "- :ref:`{pimpl_EarthImpl}`".format(**links),
            "- :ref:`{pimpl_Jupiter}`".format(**links),
            "- :ref:`{pimpl_Jupiter_v2}`".format(**links),
            "- :ref:`{pimpl_JupiterImpl}`".format(**links),
            "- :ref:`{pimpl_Planet}`".format(**links)
        }

    def nspace_pimpl_detail_link_names(self):
        """Link names for ``namespace pimpl::detail``."""
        links = self.link_name_format_dict()
        return {
            "- :ref:`{pimpl_detail_EarthImpl}`".format(**links),
            "- :ref:`{pimpl_detail_JupiterImpl}`".format(**links)
        }

    def link_name_format_dict(self):
        """
        Return a dictionary suitable for using with :any:`python:str.format`.

        Since Doxygen will behave differently on different platforms with respect to
        what the specific ``refid`` of a given node is, which affect the generated
        ``link_name`` for a given :class:`~exhale.graph.ExhaleNode`, they must be
        searched for after exhale runs for the given test function.

        **Return** (:class:`python:dict`)
            A dictionary with string keys and string values is returned, the key-value
            pairs are ``{name}``: ``{compound.link_name}``:

            +--------------------------------+--------------------------------------+
            | Key                            | C++ Compound ``link_name``           |
            +================================+======================================+
            | ``"pimpl"``                    | ``namespace pimpl``                  |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_detail"``             | ``namespace detail::pimpl``          |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_detail_EarthImpl"``   | ``class pimpl::detail::EarthImpl``   |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_detail_JupiterImpl"`` | ``class pimpl::detail::JupiterImpl`` |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_Earth"``              | ``class pimpl::Earth``               |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_Earth_v2"``           | ``class pimpl::Earth_v2``            |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_EarthImpl"``          | ``class pimpl::EarthImpl``           |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_Jupiter"``            | ``class pimpl::Jupiter``             |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_Jupiter_v2"``         | ``class pimpl::Jupiter_v2``          |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_JupiterImpl"``        | ``class pimpl::JupiterImpl``         |
            +--------------------------------+--------------------------------------+
            | ``"pimpl_Planet"``             | ``class pimpl::Planet``              |
            +--------------------------------+--------------------------------------+
        """
        pimpl = None
        pimpl_detail = None
        pimpl_detail_EarthImpl = None
        pimpl_detail_JupiterImpl = None
        pimpl_Earth = None
        pimpl_Earth_v2 = None
        pimpl_EarthImpl = None
        pimpl_Jupiter = None
        pimpl_Jupiter_v2 = None
        pimpl_JupiterImpl = None
        pimpl_Planet = None

        exhale_root = get_exhale_root(self)
        for node in exhale_root.all_nodes:
            if node.kind == "namespace":
                if node.name == "pimpl":
                    pimpl = node
                elif node.name == "pimpl::detail":
                    pimpl_detail = node
            elif node.kind == "class":
                if node.name == "pimpl::Earth":
                    pimpl_Earth = node
                elif node.name == "pimpl::Earth_v2":
                    pimpl_Earth_v2 = node
                elif node.name == "pimpl::EarthImpl":
                    pimpl_EarthImpl = node
                elif node.name == "pimpl::detail::EarthImpl":
                    pimpl_detail_EarthImpl = node
                elif node.name == "pimpl::Jupiter":
                    pimpl_Jupiter = node
                elif node.name == "pimpl::Jupiter_v2":
                    pimpl_Jupiter_v2 = node
                elif node.name == "pimpl::JupiterImpl":
                    pimpl_JupiterImpl = node
                elif node.name == "pimpl::detail::JupiterImpl":
                    pimpl_detail_JupiterImpl = node
                elif node.name == "pimpl::Planet":
                    pimpl_Planet = node

        # NOTE: test will crash if one is not found, which we want.
        return {
            "pimpl": pimpl.link_name,
            "pimpl_detail": pimpl_detail.link_name,
            "pimpl_detail_EarthImpl": pimpl_detail_EarthImpl.link_name,
            "pimpl_detail_JupiterImpl": pimpl_detail_JupiterImpl.link_name,
            "pimpl_Earth": pimpl_Earth.link_name,
            "pimpl_Earth_v2": pimpl_Earth_v2.link_name,
            "pimpl_EarthImpl": pimpl_EarthImpl.link_name,
            "pimpl_Jupiter": pimpl_Jupiter.link_name,
            "pimpl_Jupiter_v2": pimpl_Jupiter_v2.link_name,
            "pimpl_JupiterImpl": pimpl_JupiterImpl.link_name,
            "pimpl_Planet": pimpl_Planet.link_name
        }

    def expected_class_hierarchy(self, exclusions):
        """
        Return expected rst class hierarchy listing based on specified ``exclusions``.

        Helper method for :func:`validate_class_hierarchy`.

        **Parameters**

        ``exclusions`` (:class:`TestedExclusionTypes`)
            The exclusion that is currently being tested.

        **Return** (:class:`python:str`)
            The expected rst class listing.  If ``exclusions`` is invalid, then the
            string ``"INTERNAL TESTING ERROR"`` is returned.
        """
        full_class_hierarchy_lines = textwrap.dedent('''\
            - :ref:`{pimpl}`
                - :ref:`{pimpl_detail}`
                    - :ref:`{pimpl_detail_EarthImpl}`
                    - :ref:`{pimpl_detail_JupiterImpl}`
                - :ref:`{pimpl_Earth}`
                - :ref:`{pimpl_Earth_v2}`
                - :ref:`{pimpl_EarthImpl}`
                - :ref:`{pimpl_Jupiter}`
                - :ref:`{pimpl_Jupiter_v2}`
                - :ref:`{pimpl_JupiterImpl}`
                - :ref:`{pimpl_Planet}`
        ''').format(**self.link_name_format_dict()).splitlines()

        if exclusions == TestedExclusionTypes.NoExclusions:
            return "\n".join(full_class_hierarchy_lines)
        elif exclusions == TestedExclusionTypes.AllImpl:
            return "\n".join([
                line for line in full_class_hierarchy_lines
                if "detail" not in line and "impl" not in line.lower()
            ])
        elif exclusions == TestedExclusionTypes.DetailImpl:
            return "\n".join([
                line for line in full_class_hierarchy_lines
                if "detail" not in line
            ])

        return "INTERNAL TESTING ERROR"

    def validate_class_hierarchy(self, exclusions):
        """
        Validate generated class hierarchy rst list is correct based on ``exclusions``.

        **Parameters**

        ``exclusions`` (:class:`TestedExclusionTypes`)
            The exclusion that is currently being tested.
        """
        class_hierarchy_path = os.path.join(
            self.getAbsContainmentFolder(), "class_view_hierarchy.rst.include"
        )
        expected_class_hierarchy = self.expected_class_hierarchy(exclusions)
        with open(class_hierarchy_path) as class_hierarchy:
            class_hierarchy_contents = class_hierarchy.read()

        self.assertTrue(
            expected_class_hierarchy in class_hierarchy_contents,
            textwrap.dedent('''\
                Expected class hierarchy not in generated class hierarchy.

                Expected class hierarchy:
                {vsep}
                {expected}
                {vsep}

                Generated class hierarchy:
                {vsep}
                {generated}
            ''').format(
                vsep=('-' * 44),
                expected=expected_class_hierarchy,
                generated=class_hierarchy_contents
            )
        )

    def validate_namespace_listings(self, exclusions):
        """
        Validate generated namespace rst listings are correct based on ``exclusions``.

        This project contains two namespaces that are tested: ``namespace pimpl`` and
        ``namespace pimpl::detail``.

        **Parameters**

        ``exclusions`` (:class:`TestedExclusionTypes`)
            The exclusion that is currently being tested.
        """
        # First gather the two namespace nodes for this project so we can read in the
        # generated file's contents.
        exhale_root = get_exhale_root(self)
        # TODO: this may break if you un-do the reparenting stuff
        # There's only one top-level namespace
        pimpl = exhale_root.namespaces[0]
        pimpl_detail = None
        for child in pimpl.children:
            if child.kind == "namespace" and child.name == "pimpl::detail":
                pimpl_detail = child
                break

        # Make sure required / forbidden items check out for namespace pimpl
        pimpl_contents = self.contents_for_node(pimpl)
        if exclusions in {TestedExclusionTypes.NoExclusions, TestedExclusionTypes.DetailImpl}:
            pimpl_required = self.nspace_pimpl_link_names()
            pimpl_forbidden = None
        elif exclusions == TestedExclusionTypes.AllImpl:
            pimpl_required = self.nspace_pimpl_link_names() - self.impl_link_names()
            pimpl_forbidden = self.impl_link_names()

        self.cross_validate(
            pimpl_contents, required=pimpl_required, forbidden=pimpl_forbidden
        )

        # Make sure required / forbidden items check out for namespace pimpl::detail
        pimpl_detail_contents = self.contents_for_node(pimpl_detail)
        if exclusions == TestedExclusionTypes.NoExclusions:
            pimpl_detail_required = self.nspace_pimpl_detail_link_names()
            pimpl_detail_forbidden = None
        elif exclusions in {TestedExclusionTypes.AllImpl, TestedExclusionTypes.DetailImpl}:
            pimpl_detail_required = None
            pimpl_detail_forbidden = self.nspace_pimpl_detail_link_names()

        self.cross_validate(
            pimpl_detail_contents, required=pimpl_detail_required, forbidden=pimpl_detail_forbidden
        )

    def validate_file_listings(self):
        """
        Validate ``{earth,jupiter}.hpp`` link to all items (regardless of ``"listingExclude"``).
        """
        # Gather the exhale nodes for the two files we care about.
        exhale_root = get_exhale_root(self)
        earth_hpp = None
        jupiter_hpp = None
        for f in exhale_root.files:
            if "earth.hpp" in f.name:
                earth_hpp = f
            elif "jupiter.hpp" in f.name:
                jupiter_hpp = f

        # Make sure the "excluded" items are always included on file pages.
        self.cross_validate(
            self.contents_for_node(earth_hpp), required=self.earth_hpp_link_names(), forbidden=None
        )
        self.cross_validate(
            self.contents_for_node(jupiter_hpp), required=self.jupiter_hpp_link_names(), forbidden=None
        )

    def test_hierarchies(self):
        """Verify the class and file hierarchies."""
        compare_class_hierarchy(self, class_hierarchy(self.class_hierarchy_dict()))
        compare_file_hierarchy(self, file_hierarchy(self.file_hierarchy_dict()))

    # TODO: once config objects are in this override is not necessary, but currently
    #       the tests in tests/configs.py populate a listingExclude....
    @confoverrides(exhale_args={"listingExclude": []})
    def test_no_listing_exclusions(self):
        """Verify empty listing exclude results in no change in listed API."""
        self.validate_class_hierarchy(TestedExclusionTypes.NoExclusions)
        self.validate_namespace_listings(TestedExclusionTypes.NoExclusions)
        self.validate_file_listings()
        self.checkAllFilesIncluded()

    @confoverrides(exhale_args={"listingExclude": [r".*Impl$"]})
    def test_impl_exclude(self):
        """Verify ``r".*Impl$"`` excludes ``*Impl`` class names."""
        self.validate_class_hierarchy(TestedExclusionTypes.AllImpl)
        self.validate_namespace_listings(TestedExclusionTypes.AllImpl)
        self.validate_file_listings()
        self.checkAllFilesIncluded()

    @confoverrides(exhale_args={"listingExclude": [(r".*impl$", re.IGNORECASE)]})
    def test_impl_exclude_ignorecase(self):
        """
        Verify ``r".*impl$`` with :data:`python:re.IGNORECASE` excludes ``*Impl`` items.
        """
        self.validate_class_hierarchy(TestedExclusionTypes.AllImpl)
        self.validate_namespace_listings(TestedExclusionTypes.AllImpl)
        self.validate_file_listings()
        self.checkAllFilesIncluded()

    @confoverrides(exhale_args={"listingExclude": [r".*detail::.*Impl$"]})
    def test_detail_impl_exclude(self):
        """
        Verify ``r".*detail::.*Impl$`` excludes ``*detail::*Impl`` items.
        """
        self.validate_class_hierarchy(TestedExclusionTypes.DetailImpl)
        self.validate_namespace_listings(TestedExclusionTypes.DetailImpl)
        self.validate_file_listings()
        self.checkAllFilesIncluded()

    @confoverrides(exhale_args={"listingExclude": [(r".*detail::.*impl$", re.IGNORECASE)]})
    def test_detail_impl_exclude_ignorecase(self):
        """
        Verify ``r".*detail::.*impl$`` with |I| excludes ``*detail::*Impl`` items.

        .. |I| replace:: :data:`python:re.IGNORECASE`
        """
        self.validate_class_hierarchy(TestedExclusionTypes.DetailImpl)
        self.validate_namespace_listings(TestedExclusionTypes.DetailImpl)
        self.validate_file_listings()
        self.checkAllFilesIncluded()
