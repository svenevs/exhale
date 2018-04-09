import pytest


def with_config(**config):

    def actual_decorator(method):
        if config:
            method = pytest.mark.sphinx(confoverrides=config)(method)
        return method

    return actual_decorator
