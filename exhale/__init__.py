# -*- coding: utf8 -*-
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

from __future__ import unicode_literals

# from . import configs
# from . import deploy
# from . import graph
# from . import parse
# from . import utils

import os
import six

from sphinx.errors import ConfigError, ExtensionError
from sphinx.util import logging

logger = logging.getLogger(__name__)

__version__ = "0.1.8"
# __all__ = ["configs", "deploy", "graph", "parse", "utils"]

from . import verify


def _upgrade_flat_to_nested_dict(app, from_key, nested_dict_name, to_key):
    exhale_args = app.config.exhale_args
    from_value = exhale_args.get(from_key, None)
    if from_value:
        if nested_dict_name in exhale_args:
            # Make sure it was specified as a nested dictionary
            if not isinstance(exhale_args[nested_dict_name], dict):
                raise ConfigError(
                    'exhale_args["{0}"] must be a dictionary.'.format(nested_dict_name)
                )
            # Force a failure if they have specified both the old and new way...
            if to_key in exhale_args[nested_dict_name]:
                raise ConfigError(
                    (
                        'Cannot auto-upgrade exhale_args["{from_key}"] to be ' +
                        'exhale_args["{nested}"]["{to_key}"]: key "{to_key}" ' +
                        'already exists!'
                    ).format(from_key=from_key, nested=nested_dict_name, to_key=to_key)
                )
            exhale_args[nested_dict_name][to_key] = from_value
        else:
            # exhale_args[nested_dict_name] does not exist yet, create it.
            exhale_args[nested_dict_name] = {to_key: from_value}

        # Delete key now that we have updated and warn user of the patch.
        del exhale_args[from_key]
        app.exhale_deferred_log.append(
            (
                'exhale_args["{from_key}"] is deprectated.  Please set nested ' +
                'dictionary exhale_args["{nested}"]["{to_key}"] instead.'
            ).format(from_key=from_key, nested=nested_dict_name, to_key=to_key)
        )
        app.config.exhale_args = exhale_args


def _upgrade_doxygen(app):
    mapping = (
        ('doxygenStripFromPath', 'stripFromPath'),
        ('exhaleUseDoxyfile', 'doxyfile'),
        ('exhaleDoxygenStdin', 'stdin'),
        ('exhaleSilentDoxygen', 'silent')
    )
    for from_key, to_key in mapping:
        _upgrade_flat_to_nested_dict(app, from_key, 'doxygen', to_key)

def _auto_upgrade(app):
    _upgrade_doxygen(app)


def _no_run():
    return False

class ExhaleProject(object):
    def __init__(self, config):
        self.app = config.app
        self.project_name = config.project_name
        self.config = config

        self.root = None

    def run_doxygen(self):
        if not self.config.exhaleExecutesDoxygen:
            return

        from . import deploy
        # All necessary information ready, go to where the Doxyfile is, run Doxygen
        # and then return back (where applicable) so sphinx can continue
        start = utils.get_time()
        status = None

        with utils.cd(self.app.confdir):
            self.app.info(utils.info("Exhale: executing doxygen."))
            status = deploy.generate_doxygen_xml(self.config)

        if status:
            raise ExtensionError(status)

        end = utils.get_time()
        self.app.info(utils.progress(
            "Exhale: doxygen ran successfully in {0}.".format(utils.time_string(start, end))
        ))

    def parse(self):
        from . import utils
        from .graph import ExhaleRoot
        import sys
        try:
            self.root = ExhaleRoot(self)
        except:
            utils.fancyError("Unable to create an `ExhaleRoot` object:")

        try:
            sys.stdout.write("{0}\n".format(utils.info("Exhale: parsing Doxygen XML.")))
            start = utils.get_time()

            self.root.parse()

            end = utils.get_time()
            sys.stdout.write("{0}\n".format(
                utils.progress("Exhale: finished parsing Doxygen XML in {0}.".format(
                    utils.time_string(start, end)
                ))
            ))
        except:
            utils.fancyError("Exception caught while parsing:")

    def explode(self):
        if _no_run():
            return

        import sys
        try:
            sys.stdout.write("{0}\n".format(
                utils.info("Exhale: generating reStructuredText documents.")
            ))
            start = utils.get_time()

            self.root.generateFullAPI()

            end = utils.get_time()
            sys.stdout.write("{0}\n".format(
                utils.progress("Exhale: generated reStructuredText documents in {0}.".format(
                    utils.time_string(start, end)
                ))
            ))
        except:
            utils.fancyError("Exception caught while generating:")

        # << verboseBuild
        #   toConsole only prints if verbose mode is enabled
        self.root.toConsole()

        # allow access to the result after-the-fact
        from . import configs
        configs._the_app.exhale_root = self.root

def environment_ready(app):
    # Defer importing configs until sphinx is running.
    from . import configs
    from . import utils
    from . import deploy

    app.exhale_deferred_log = []

    # initial type-safety checks for `exhale_args`
    exhale_args = app.config.exhale_args
    verify.is_dictionary_with_string_keys(exhale_args, "exhale_args")

    # initial type-safety checks for `exhale_projects`
    exhale_projects = app.config.exhale_projects
    verify.is_dictionary_with_string_keys(exhale_projects, "exhale_projects")
    for project in exhale_projects:
        verify.is_dictionary_with_string_keys(
            exhale_projects[project], "exhale_projects['{0}']".format(project)
        )

    # initial type-safety checks for `exhale_global_args`
    exhale_global_args = app.config.exhale_global_args
    verify.is_dictionary_with_string_keys(exhale_global_args, "exhale_global_args")

    # `exhale_args` implies Exhale can overwrite `exhale_projects`
    if exhale_args and exhale_projects:
        raise ConfigError(
            "`exhale_args` and `exhale_projects` may not both be specified.  "
            "Using `exhale_args` implies a single project."
        )

    # `exhale_args` cannot be used with `exhale_global_args`
    if exhale_args and exhale_global_args:
        raise ConfigError(
            "`exhale_args` and `exhale_global_args` may not both be specified.  "
            "Using `exhale_args` implies a single project."
        )


    # Monkeypatch: check if user was specifying breathe configs manually
    breathe_projects = app.config.breathe_projects
    breathe_default_project = app.config.breathe_default_project

    if breathe_projects or breathe_default_project:
        app.exhale_deferred_log.append(
            '`breathe_projects` and `breathe_default_project` are populated '
            'automatically.  You can safely delete them.'
        )

    if breathe_projects and breathe_default_project:
        # breathe_default_project means that :project: is not needed for the generated
        # .. doxygen*:: directives.  If it is not an entry in `breathe_projects`, this
        # is a huge problem.
        if breathe_default_project not in breathe_projects:
            raise ConfigError(
                '`breathe_default_project` must be a key in `breathe_projects`.  '
                '*INSTEAD* of fixing this, please consider letting Exhale '
                'automatically populate these for you (delete both from `conf.py`).'
            )

    # Create `exhale_projects` when `exhale_args` is being used
    if exhale_args:
        # If user setup their config
        if breathe_default_project:
            exhale_projects = {breathe_default_project: exhale_args}
        else:
            # If `project` not set in `conf.py`, this will be `Python`.  Using this
            # value is particularly misleading, so `exhale_auto` will be used.
            if app.config.project != 'Python':
                project = app.config.project
            else:
                project = 'exhale_auto'
            exhale_projects = {project: exhale_args}
        app.config.exhale_projects = exhale_projects
    # else:

    # Make sure if specified, `breathe_projects` matches `exhale_projects`
    if breathe_projects:
        if set(exhale_projects.keys()) != set(breathe_projects.keys()):
            raise ConfigError(
                'exhale_projects.keys() must be identical to breathe_projects.keys().'
            )
        # Case 1: user specified `breathe_projects`, these will be used by Exhale
    else:
        # Case 2: auto-specify the doxygen output directories for breathe
        # outdir would be e.g. /path/to/_build/html, we will create doxygen here
        build_dir = os.path.abspath(os.path.dirname(app.outdir))
        doxygen_output_directory = os.path.join(build_dir, 'doxygen')

        if len(exhale_projects) == 1:
            the_project = list(exhale_projects.keys())[0]
            breathe_projects = {
                the_project: os.path.join(doxygen_output_directory, 'xml')
            }
            breathe_default_project = the_project
        else:
            breathe_projects = {
                proj: os.path.join(doxygen_output_directory, proj, 'xml')
                for proj in exhale_projects
            }
            breathe_default_project = None

    app.config.breathe_projects = breathe_projects
    app.config.breathe_default_project = breathe_default_project

    _auto_upgrade(app)

    # app.setup_extension("breathe")

    # First, setup the extension and verify all of the configurations.
    configs.apply_sphinx_configurations(app)

    ####### Next, perform any cleanup
    # generate each project
    for project_name in exhale_projects:
        config = configs.Config(app, project_name)
        project = ExhaleProject(config)
        project.run_doxygen()
        project.parse()
        project.explode()


def build_finished(app, exception):
    if app.exhale_deferred_log:
        from . import utils
        logger.info(utils.info(
            'Exhale v1.0+ has improved its interface.  These improvements required '
            'monkey-patching your configuration.  Please consider the following '
            'update(s) to your `conf.py`:'
        ))
        for idx in range(len(app.exhale_deferred_log)):
            message = app.exhale_deferred_log[idx]
            logger.info('{0}. {1}'.format(idx + 1, message))


def setup(app):
    # Exhale needs to either
    #
    # 1. Configure itself based on user-specified `breathe_projects` (prior to v1.0.0)
    # 2. Setup `breathe_projects` automatically
    #
    # For (2) to happen, the order in which sphinx extensions are listed in `conf.py`
    # is how they will be processed.  Unfortunately, if 'breathe' was before 'exhale'
    # then this means it is already too late :S
    #
    # However, we can append 'breathe' on our own!  So this is what we encourage (no
    # 'breathe' entry in 'extensions' list).
    if 'breathe' not in app.config.extensions:
        app.config.extensions.append('breathe')
    else:
        exhale_idx = app.config.extensions.index('exhale')
        breathe_idx = app.config.extensions.index('breathe')
        if exhale_idx > breathe_idx:
            # Naive re-order: just stick them both at the back, this kind of extension
            # order dependency is likely very rare.
            extensions = [
                ext for ext in app.config.extensions if ext != 'breathe'
            ]
            from six.moves import StringIO
            err_msg = StringIO()
            err_msg.write(
                'As of exhale v1.0.0, `breathe` must appear *AFTER* `exhale` in the '
                '`extensions` list in `conf.py`.  Unfortunately, this cannot be fixed '
                'automatically by exhale, by the time this code is executing it is '
                'already too late.  Please *DELETE* `breathe` to allow exhale to fix '
                'this for you (exhale will setup breathe internally).  Your new '
                '`extensions` list should look like:\n\n'
            )
            err_msg.write('extensions = [\n')

            num_extensions = len(extensions)
            for idx in range(num_extensions):
                ext = extensions[idx]
                err_msg.write("    '{0}'".format(ext))
                if idx < num_extensions - 1:
                    err_msg.write(',')
                err_msg.write('\n')

            err_msg.write(']\n')
            raise ExtensionError(err_msg.getvalue())

    app.add_config_value("exhale_args", {}, "env")
    app.add_config_value("exhale_projects", {}, "env")
    app.add_config_value("exhale_global_args", {}, "env")

    app.connect("builder-inited", environment_ready)
    app.connect("build-finished", build_finished)


    return {
        "version": __version__,
        "parallel_read_safe": True,
        "parallel_write_safe": True
    }
