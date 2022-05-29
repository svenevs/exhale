# # -*- coding: utf8 -*-
# ########################################################################################
# # This file is part of exhale.  Copyright (c) 2017-2022, Stephen McDowell.             #
# # Full BSD 3-Clause license available here:                                            #
# #                                                                                      #
# #                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
# ########################################################################################
# """
# Tests for validating some of ``exhale/utils.py``.
# """

# import re

# import pytest

# from exhale.utils import tokenize, tokenize_template, groupsToNamedGroups

# @pytest.mark.parametrize(
#     "node_name,expected",
#     # NOTE: we only care about valid C++ here...
#     [
#         # Special case: empty list is returned for empty string.
#         ("", []),
#         # No template gets tokenized letter by letter.
#         ("foo", ["f", "o", "o"]),
#         ("ns::foo", list("ns::foo")),
#         # Depth 1 templates.
#         ("foo<12>", list("foo") + [list("12")]),
#         ("ns::foo<int, 66>", list("ns::foo") + [list("int, 66")]),
#         ("ns::foo<x, y, z>", list("ns::foo") + [list("x, y, z")]),
#         # Depth 2 templates.
#         ("foo<std::array<int>>", list("foo") + [list("std::array") + [list("int")]]),
#         ("bar<Cls<x, y, z>>", list("bar") + [list("Cls") + [list("x, y, z")]]),
#         (
#             "baz<Cls<x>, y, z>",
#             list("baz") + [
#                 list("Cls") + [
#                     list("x")
#                 ] +
#                 list(", y, z")
#             ]
#         ),
#         (
#             "baz<x, Cls<y, z>, w>",
#             list("baz") + [
#                 list("x, Cls") + [
#                     list("y, z")
#                 ] +
#                 list(", w")
#             ]
#         ),
#         (
#             "boo<a, b, c, Cls<d, e, f>>",
#             list("boo") + [
#                 list("a, b, c, Cls") + [
#                     list("d, e, f")
#                 ]
#             ]
#         ),
#         # Depth 3 templates for good measure.  And bleeding eyes.
#         ("rawr<A<B<C>>>", list("rawr") + [list("A") + [list("B") + [list("C")]]]),
#         (
#             "f<a, B<c, D<e>>, F<g, H<i, J<k, l>>>>",
#             list("f") + [
#                 list("a, B") + [
#                     list("c, D") + [
#                         list("e")
#                     ]
#                  ] + list(", F") + [
#                     list("g, H") + [
#                         list("i, J") + [
#                             list("k, l")
#                         ]
#                     ]
#                 ]
#             ]
#         )
#     ]
# )
# def test_tokenize(node_name, expected):
#     assert tokenize(node_name, "<", ">") == expected
#     x = []
#     groupsToNamedGroups(tokenize(node_name, "<", ">"), x)
#     assert join_token_groups(tokenize(node_name, "<", ">")) == x
#     assert templateListToNodeName(join_token_groups(tokenize(node_name, "<", ">")))


# def test_tokenize_errors():
#     with pytest.raises(ValueError) as exc_info:
#         tokenize("asdf", "<", "<")
#     assert exc_info.type is ValueError
#     exc_info.match(
#         "Cannot tokenize 'asdf' using start='<' and end='<', start and end may not be "
#         "the same.")

#     mismatches = [
#         (
#             ("foo<", "<", ">"),
#             (
#                 "Cannot tokenize 'foo<' using start='<' and end='>'.  There must be an "
#                 "equivalent number of start and end tags, but found 1 '<' and 0 '>'."
#             ),
#         ),
#         (
#             ("foo]", "[", "]"),
#             re.escape(
#                 "Cannot tokenize 'foo]' using start='[' and end=']'.  There must be an "
#                 "equivalent number of start and end tags, but found 0 '[' and 1 ']'."
#             ),
#         )
#     ]
#     for args, pattern in mismatches:
#         with pytest.raises(ValueError) as exc_info:
#             tokenize(*args)
#         assert exc_info.type is ValueError
#         exc_info.match(pattern)
