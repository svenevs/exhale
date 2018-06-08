import six
from sphinx.errors import ConfigError

def is_dictionary_with_string_keys(d, title):
    # Make sure it is a dictionary.
    if type(d) is not dict:
        raise ConfigError(
            "`{title}` in `conf.py` must be a dictionary, but was `{got}`.".format(
                title=title,
                got=type(d)
            )
        )

    # Make sure all of the keys are strings (values validated later).
    for key in d:
        if not isinstance(key, six.string_types):
            raise ConfigError(
                "`{title}` had key `{key}` of type `{key_t}`, but only strings are allowed.".format(
                    title=title, key=key, key_t=type(key)
                )
            )


def is_list_of_strings(lst, title):
    for spec in lst:
        if not isinstance(spec, six.string_types):
            raise ConfigError(
                "`{title}` must be a list of strings, but `{spec}` was of type `{spec_t}`.".format(
                    title=title,
                    spec=spec,
                    spec_t=type(spec)
                )
            )