########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2024, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################
"""
Utility functionality for the testing suite.
"""

try:
    from collections.abc import Mapping
except ImportError:
    # TODO: remove when dropping python 2.7
    from collections import Mapping


def deep_update(orig, override):
    """
    Update leaf values of a data structure (nested dictionaries and lists).

    **Parameters**
        Both ``orig`` and ``override`` should be of the same type.  E.g. both ``orig``
        and ``override`` are a :class:`python:dict`, or both are a :class:`python:list`.

        ``orig`` (:class:`python:dict` or :class:`python:list`)
            The original data structure.

        ``override`` (:class:`python:dict` or :class:`python:list`)
            The overriding data structure.

    **Return**
        :class:`python:dict` or :class:`python:list`
            The ``orig`` object, updated with the ``override`` values.
    """
    if not override:
        return orig

    for key, val in override.items():
        if isinstance(val, Mapping):
            try:
                deep_update(orig[key], val)
            except KeyError:
                orig[key] = val

        elif isinstance(val, list):
            try:
                orig_val = orig[key]

                if not isinstance(orig_val, list):
                    raise KeyError

                for i, v in enumerate(val):
                    if not i and val[i] is None:
                        # ignoring modified list markers
                        continue
                    orig_val.append(v)

            except KeyError:
                orig[key] = val

        else:
            orig[key] = override[key]
    return orig
