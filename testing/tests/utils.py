########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Tests for validating parts of :mod:`exhale.utils`.
"""
import re

from exhale.utils import join_template_tokens, tokenize_template

import pytest

templates = [
    # Special case: empty list is returned for empty string.
    ("", []),
    # No template gets tokenized letter by letter.
    ("foo", ["foo"]),
    ("ns::foo", ["ns::foo"]),
    # Depth 1 templates.
    ("foo< 12 >", ["foo", ["12"]]),
    ("ns::foo< int, 66 >", ["ns::foo", ["int", "66"]]),
    ("ns::foo< x, y, z >", ["ns::foo", ["x", "y", "z"]]),
    # Depth 2 templates.
    ("foo< std::array< int > >", ["foo", ["std::array", ["int"]]]),
    ("bar< Cls< x, y, z > >", ["bar", ["Cls", ["x", "y", "z"]]]),
    ("baz< Cls< x >, y, z >", ["baz", ["Cls", ["x"], "y", "z"]]),
    ("baz< x, Cls< y, z >, w >", ["baz", ["x", "Cls", ["y", "z"], "w"]]),
    ("boo< a, b, c, Cls< d, e, f > >", ["boo", ["a", "b", "c", "Cls", ["d", "e", "f"]]]),
    # Depth 3 templates for good measure.  And bleeding eyes.
    ("rawr< A< B< C > > >", ["rawr", ["A", ["B", ["C"]]]]),
    (
        "f< a, B< c, D< e > >, F< g, H< i, J< k, l > > > >",
        ["f", ["a", "B", ["c", "D", ["e"]], "F", ["g", "H", ["i", "J", ["k", "l"]]]]]
    ),
    (
        "special::ImageBuffer< Image< 1920, 1080 > >::Data",
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
"""
Shared template test case parameters, (node_name, template_tokens expected value).

.. warning::

    Test cases are unfortunately whitespace sensitive, the node_name string must have
    exactly 1 space after any ``<`` and exactly one space before any ``>``.
"""

extra_templates = [
    # Test interior whitespace is folded into a single space.
    (
        "special::complex::Fold< typename... \t\t\t   \t Ts>",
        ["special::complex::Fold", ["typename... Ts"]]
    ),
    (
        "special::complex::Fold<     typename \t  ...   Ts >",
        ["special::complex::Fold", ["typename ... Ts"]]
    ),
    (
        "special::complex::Fold<typename \t \t ...Ts>",
        ["special::complex::Fold", ["typename ...Ts"]]
    ),
    # It's so ugly it's pretty.
    (
        "has_type_member< T      , void_t  < typename     T::type  >",
        ["has_type_member", ["T", "void_t", ["typename T::type"]]]
    ),
    # Getting lazy with these tests, just care about special symbols.
    ("template <class...>", ["template", ["class..."]]),
    ("template< class, class=void >", ["template", ["class", "class=void"]]),
    (
        "template<class, class   =   void>",
        ["template", ["class", "class = void"]]
    ),
    ("template <const int* I>", ["template", ["const int* I"]]),
    ("template < const   int   *  I>", ["template", ["const int * I"]]),
    ("template <const int& I>", ["template", ["const int& I"]]),
    ("template <const int      &I>", ["template", ["const int &I"]])
    # TODO: probably more examples directly from the specs should be added, but this is
    # hopefully good enough for now.
    # https://en.cppreference.com/w/cpp/language/template_parameters
    #
    # https://github.com/svenevs/exhale/pull/159#discussion_r892041086
    # We may have issues with pointer to member of object and specializations
    # and if we do then we'll have to fix it.  First somebody can donate code.
]
"""
Only used for testing :func:`~exhale.utils.tokenize_template` (not joining back to the
original name).  These tests include some more complicated templates to ensure the
regular expression matching is valid, and some permutations of the whitespace as well
for testing how tokens are getting split.
"""


@pytest.mark.parametrize("node_name,expected", templates + extra_templates)
def test_tokenize_template(node_name, expected):
    """
    Tests for :func:`~exhale.utils.tokenize_template`.
    """
    assert tokenize_template(node_name) == expected


@pytest.mark.parametrize("node_name", [n[0] for n in templates])
def test_join_template_tokens(node_name):
    """
    Tests for :func:`~exhale.utils.join_template_tokens`.
    """
    assert join_template_tokens(tokenize_template(node_name)) == node_name


def test_join_template_tokens_edge_cases():
    """
    Edge case tests for :func:`~exhale.utils.join_template_tokens`.
    """
    with pytest.raises(ValueError) as exc_info:
        join_template_tokens("hi there")
    exc_info.match(
        "Expected tokens to be a list, but got <class 'str'> instead.")

    assert join_template_tokens([]) == ""

    with pytest.raises(ValueError) as exc_info:
        join_template_tokens([["foo"]])
    exc_info.match(re.escape(
        "The first token must be a string, but the type of tokens[0] is <class "
        "'list'>."))
