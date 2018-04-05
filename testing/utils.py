import os
from contextlib import contextmanager
from collections import Mapping


@contextmanager
def cd(path):
    """
    A context manager that temporarily changes the current working directory
    """
    old_dir = os.getcwd()
    os.chdir(path)
    try:
        yield
    finally:
        os.chdir(old_dir)


def deep_update(orig, override):
    """
    Updates leaf values of a data structure (nested dicts and lists)

    :param orig: the original dictionary
    :param override: the overriding dictionary
    """

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
