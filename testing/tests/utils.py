# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for validating parts of :mod:`exhale.utils`.
"""

import pytest

from exhale.utils import tokenize_template

@pytest.mark.parametrize(
    "node_name,expected",
    [
        # Special case: empty list is returned for empty string.
        ("", []),
        # No template gets tokenized letter by letter.
        ("foo", ["foo"]),
        ("ns::foo", ["ns::foo"]),
        # Depth 1 templates.
        ("foo<12>", ["foo", ["12"]]),
        ("ns::foo<int, 66>", ["ns::foo", ["int", "66"]]),
        ("ns::foo<x, y, z>", ["ns::foo", ["x", "y", "z"]]),
        # Depth 2 templates.
        ("foo<std::array<int>>", ["foo", ["std::array", ["int"]]]),
        ("bar<Cls<x, y, z>>", ["bar", ["Cls", ["x", "y", "z"]]]),
        ("baz<Cls<x>, y, z>", ["baz", ["Cls", ["x"], "y", "z"]]),
        ("baz<x, Cls<y, z>, w>", ["baz", ["x", "Cls", ["y", "z"], "w"]]),
        ("boo<a, b, c, Cls<d, e, f>>", ["boo", ["a", "b", "c", "Cls", ["d", "e", "f"]]]),
        # Depth 3 templates for good measure.  And bleeding eyes.
        ("rawr<A<B<C>>>", ["rawr", ["A", ["B", ["C"]]]]),
        (
            "f<a, B<c, D<e>>, F<g, H<i, J<k, l>>>>",
            ["f", ["a","B", ["c","D", ["e"],],"F", ["g","H", ["i","J", ["k","l"]]]]]
        ),
        (
            "special::ImageBuffer< Image< 1920, 1080 >>::Data",
            ["special::ImageBuffer", ["Image", ["1920", "1080"]], "::Data"]
        ),
        (
            "special::unique::Nonsense< 11, snowflake::Ontology< 11 > >",
            ["special::unique::Nonsense", ["11", "snowflake::Ontology", ["11"]]]
        ),
        (
            "special::unique::Nonsense< 11, snowflake::Ontology< 11 >::test >::what",
            ["special::unique::Nonsense", ["11", "snowflake::Ontology", ["11"], '::test'], "::what"]
        )
    ]
)
def test_tokenize_template(node_name, expected):
    assert tokenize_template(node_name) == expected
