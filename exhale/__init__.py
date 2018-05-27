# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

from __future__ import unicode_literals

import six
from sphinx.errors import ConfigError

__version__ = "0.1.8"


def _validate_is_dictionary_with_string_keys(d, title):
    # Make sure it is a dictionary.
    if type(d) is not dict:
        raise ConfigError(
            "`{title}` in `conf.py` must be a dictionary, but was `{got}`".format(
                title=title,
                got=type(d)
            )
        )

    # Make sure all of the keys are strings (values validated later).
    for key in d:
        if not isinstance(key, six.string_types):
            raise ConfigError(
                "`{title}` had key `{key}` of type `{key_t}`, but only strings are allowed".format(
                    title=title, key=key, key_t=type(key)
                )
            )


def environment_ready(app):
    # Defer importing configs until sphinx is running.
    from . import configs
    from . import utils
    from . import deploy

    exhale_args = app.config.exhale_args
    _validate_is_dictionary_with_string_keys(exhale_args, "exhale_args")

    exhale_projects = app.config.exhale_projects
    _validate_is_dictionary_with_string_keys(exhale_projects, "exhale_projects")

    exhale_global_args = app.config.exhale_global_args
    _validate_is_dictionary_with_string_keys(exhale_global_args, "exhale_global_args")

    import json
    print("exhale_args:")
    print(json.dumps(exhale_args, indent=2))

    print("exhale_projects:")
    print(json.dumps(exhale_projects, indent=2))

    print("exhale_global_args:")
    print(json.dumps(exhale_global_args, indent=2))

    # raise RuntimeError("haha")



    # First, setup the extension and verify all of the configurations.
    configs.apply_sphinx_configurations(app)
    ####### Next, perform any cleanup

    # Generate the full API!
    try:
        deploy.explode()
    except:
        utils.fancyError("Exhale: could not generate reStructuredText documents :/")


def setup(app):
    app.setup_extension("breathe")
    app.add_config_value("exhale_args", {}, "env")
    app.add_config_value("exhale_projects", {}, "env")
    app.add_config_value("exhale_global_args", {}, "env")

    app.connect("builder-inited", environment_ready)

    return {"version": __version__}
