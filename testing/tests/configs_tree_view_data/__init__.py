########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Helper module for :mod:`~testing.tests.configs_tree_view`.

Defines :data:`class_hierarchy_ground_truth` and :data:`file_hierarchy_ground_truth`
here for convenience, and to hide away the dubious nature by which these tests are
validated.
"""
import platform
from pathlib import Path

this_file_dir = Path(__file__).parent.absolute()
"""The path to the directory containing this file."""

class_data_root = this_file_dir / "classes"
"""The class view hierarchy test validation data root for tree view."""

file_data_root = this_file_dir / "files"
"""The file view hierarchy test validation root for tree view."""

tree_view_keys = {"default_rst_list", "collapsible_lists", "bootstrap"}
"""Available kinds of tree views to validate against."""


def read_default_data(root: Path, file_name: str, is_html: bool) -> str:
    """
    Open, read, and return the contents of the file ``{root}/{file_name}``.

    If the default data being read is html (collapsible lists and bootstrap),
    underscores in the refid need to be replaced with dashes since the link generated
    follows an html anchor (``#``).

    The stored data files include the unix doxygen refids, on windows they are replaced
    with the expected refid.  Doxygen only seems to differ on the platforms when there
    is nesting / specialization occurring.  The tree view tests are validating against
    the ``cpp_nesting`` project which has a large amount of this going on.
    """
    # First elem: unix refid, second item: windows refid.
    # NOTE: order matters!!!  You must replace the nested ones first before their
    # parent otherwise the parent one will break the nested unix item.
    unix_to_windows_refid_map = [
        (
            "structspecial_1_1complex_1_1Fold",
            "structspecial_1_1complex_1_1_fold"
        ),
        ################################################################################
        (
            "structspecial_1_1complex_1_1has__type__member_3_01T_00_01void__t_3_01typename_01T_1_1type_01_4_01_4",  # noqa: E501
            "structspecial_1_1complex_1_1has__type__member_3_01_t_00_01void__t_3_01typename_01_t_1_1type_01_4_01_4",  # noqa: E501
        ),
        ################################################################################
        (
            "structspecial_1_1complex_1_1IntPtr",
            "structspecial_1_1complex_1_1_int_ptr"
        ),
        (
            "structspecial_1_1complex_1_1IntRef",
            "structspecial_1_1complex_1_1_int_ref"
        ),
        ################################################################################
        (
            "structspecial_1_1unique_1_1snowflake_1_1Ontology_3_0111_01_4",
            "structspecial_1_1unique_1_1snowflake_1_1_ontology_3_0111_01_4"
        ),
        (
            "structspecial_1_1unique_1_1snowflake_1_1Ontology",
            "structspecial_1_1unique_1_1snowflake_1_1_ontology"
        ),
        ################################################################################
        (
            "structspecial_1_1unique_1_1Nonsense_3_0111_00_01snowflake_1_1Ontology_3_0111_01_4_01_4",
            "structspecial_1_1unique_1_1Nonsense_3_0111_00_01snowflake_1_1_ontology_3_0111_01_4_01_4"
        ),
        (
            "structspecial_1_1unique_1_1Nonsense_3_01X_00_01snowflake_1_1Ontology_3_01X_01_4_01_4",
            "structspecial_1_1unique_1_1Nonsense_3_01_x_00_01snowflake_1_1_ontology_3_01_x_01_4_01_4"
        ),
        (
            "structspecial_1_1unique_1_1Nonsense",
            "structspecial_1_1unique_1_1_nonsense"
        ),
        ################################################################################
        (
            "structspecial_1_1Base_3_012_01_4_1_1InnerTemplatedStruct_3_014_00_01dont__use__this_01_4",
            "structspecial_1_1Base_3_012_01_4_1_1_inner_templated_struct_3_014_00_01dont__use__this_01_4"
        ),
        (
            "structspecial_1_1Base_3_012_01_4_1_1InnerTemplatedStruct",
            "structspecial_1_1Base_3_012_01_4_1_1_inner_templated_struct"
        ),
        (
            "structspecial_1_1Base_3_012_01_4_1_1InnerStruct",
            "structspecial_1_1Base_3_012_01_4_1_1_inner_struct"
        ),
        (
            "structspecial_1_1Base_3_012_01_4_1_1AnotherNestedStruct",
            "structspecial_1_1Base_3_012_01_4_1_1_another_nested_struct"
        ),
        (
            "structspecial_1_1Base_3_012_01_4",
            "structspecial_1_1_base_3_012_01_4"
        ),
        (
            "structspecial_1_1Base_1_1A",
            "structspecial_1_1Base_1_1_a"
        ),
        (
            "structspecial_1_1Base",
            "structspecial_1_1_base"
        ),
        ################################################################################
        (
            "structspecial_1_1Normal_1_1Nested_1_1Like_1_1Usual",
            "structspecial_1_1Normal_1_1Nested_1_1Like_1_1_usual"
        ),
        (
            "structspecial_1_1Normal_1_1Nested_1_1Like",
            "structspecial_1_1Normal_1_1Nested_1_1_like"
        ),
        (
            "structspecial_1_1Normal_1_1Nested",
            "structspecial_1_1Normal_1_1_nested"
        ),
        (
            "structspecial_1_1Normal",
            "structspecial_1_1_normal"
        ),
        ################################################################################
        (
            "classspecial_1_1ImageBuffer_3_01Image_3_011920_00_011080_01_4_00_01float_00_01128_01_4",
            "classspecial_1_1ImageBuffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4"
        ),
        (
            "classspecial_1_1ImageBuffer_3_01TImage_00_01Tdata__t_00_014_01_4",
            "classspecial_1_1ImageBuffer_3_01_t_image_00_01_tdata__t_00_014_01_4"
        ),
        (
            "classspecial_1_1ImageBuffer",
            "classspecial_1_1_image_buffer"
        ),
        ################################################################################
        (
            "structspecial_1_1ImageBuffer_3_01Image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1Data",
            "structspecial_1_1Image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_data"  # noqa: E501
        ),
        (
            "structspecial_1_1ImageBuffer_3_01Image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1SomeThing",    # noqa: E501
            "structspecial_1_1Image_buffer_3_01_image_3_011920_00_011080_01_4_00_01float_00_01128_01_4_1_1_some_thing"  # noqa: E501
        ),
        ################################################################################
        (
            "structspecial_1_1ImageBuffer_3_01TImage_00_01Tdata__t_00_014_01_4_1_1Data",
            "structspecial_1_1Image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_data"
        ),
        (
            "structspecial_1_1ImageBuffer_3_01TImage_00_01Tdata__t_00_014_01_4_1_1SomeThing",
            "structspecial_1_1Image_buffer_3_01_t_image_00_01_tdata__t_00_014_01_4_1_1_some_thing"
        ),
        ################################################################################
        (
            "structspecial_1_1ImageBuffer_1_1Data",
            "structspecial_1_1_image_buffer_1_1_data"
        ),
        (
            "structspecial_1_1ImageBuffer_1_1SomeThing",
            "structspecial_1_1_image_buffer_1_1_some_thing"
        ),
        ################################################################################
        (
            "structspecial_1_1Image",
            "structspecial_1_1_image"
        ),
    ]

    with open(root / file_name) as f:
        contents = f.read()

    if platform.system() in {"Darwin", "Windows"}:
        for unix_refid, windows_refid in unix_to_windows_refid_map:
            # For html, two replacements are needed.  The generated page is named as
            # {refid}.html with underscores in tact, but the anchor names are #{refid}
            # with underscores as hyphens.
            contents = contents.replace(unix_refid, windows_refid)
            if is_html:
                # Anchors transform __ to _ and then - first.
                unix_anchor = unix_refid.replace("__", "_").replace("_", "-")
                windows_anchor = windows_refid.replace("__", "_").replace("_", "-")
                contents = contents.replace(unix_anchor, windows_anchor)

    return contents


class_hierarchy_ground_truth = {
    k: read_default_data(class_data_root, f"{k}.txt", k != "default_rst_list")
    for k in tree_view_keys
}
"""
Ground truth for the three versions of class hierarchies.

Keys and what they represent:

``"default_rst_list"``
    The reStructuredText list version (``createTreeView=False``).

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).
"""

file_hierarchy_ground_truth = {
    k: read_default_data(file_data_root, f"{k}.txt", k != "default_rst_list")
    for k in tree_view_keys
}
"""
Ground truth for the three versions of file hierarchies.

Keys and what they represent:

``"default_rst_list"``
    The reStructuredText list version (``createTreeView=False``).

``"collapsible_lists"``
    The collapsible lists version of the tree view (raw html unordered list).

``"bootstrap"``
    The bootstrap version of the tree view (raw JavaScript function returning json data).
"""
