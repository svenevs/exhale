# This file is part of exhale: https://github.com/svenevs/exhale
#
# Copyright (c) 2017, Stephen McDowell
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
# * Neither the name of exhale nor the names of its
#   contributors may be used to endorse or promote products derived from
#   this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

from . import deploy
from . import utils

import os
from sphinx.errors import ConfigError, ExtensionError

__version__ = "0.1.0"

def environment_ready(app):
    ####################################################################################
    # Make sure they have the `breathe` configs setup in a way that we can use them.   #
    ####################################################################################
    # Breathe allows users to have multiple projects to configure in one `conf.py`
    # A dictionary of keys := project names, values := path to Doxygen xml output dir
    breathe_projects = app.config.breathe_projects
    if not breathe_projects:
        raise ConfigError("You must set the `breathe_projects` in `conf.py`.")
    elif type(breathe_projects) is not dict:
        raise ConfigError("The type of `breathe_projects` in `conf.py` must be a dictionary.")
    # The breathe_default_project is required by `exhale` to determine where to look for
    # the doxygen xml.
    #
    # TODO: figure out how to allow multiple breathe projects?
    breathe_default_project = app.config.breathe_default_project
    if not breathe_default_project:
        raise ConfigError("You must set the `breathe_default_project` in `conf.py`.")
    elif type(breathe_default_project) is not str:
        raise ConfigError("The type of `breathe_default_project` must be a string.")

    if breathe_default_project not in breathe_projects:
        raise ConfigError(
            "The given breathe_default_project='{0}' was not a valid key in `breathe_projects`:\n{1}".format(
            breathe_default_project, breathe_projects
        ))

    # Grab where the Doxygen xml output is supposed to go, make sure it is a string,
    # defer validation of existence until after potentially running Doxygen based on
    # the configs given to exhale
    doxy_xml_dir = breathe_projects[breathe_default_project]
    if type(doxy_xml_dir) is not str:
        raise ConfigError(
            "The type of `breathe_projects[breathe_default_project]` from `conf.py` was not a string."
        )

    ####################################################################################
    # Initial sanity-check that we have the arguments needed.                          #
    ####################################################################################
    exhale_args = app.config.exhale_args
    if not exhale_args:
        raise ConfigError("You must set the `exhale_args` dictionary in `conf.py`.")
    elif type(exhale_args) is not dict:
        raise ConfigError("The type of `exhale_args` in `conf.py` must be a dictionary.")

    ####################################################################################
    # In the `exhale_args` argument validation, the expected keys are identical to the #
    # names of various global "constants" available in the `configs` module.  The      #
    # design was to be able to simply set the `configs` from here rather than creating #
    # a "setter" method for anything that can change.                                  #
    #                                                                                  #
    # This is a strange thing to do, and you will probably never see such ridiculous   #
    # behavior anywhere else.  It'll work fine, as long as you don't touch it ;)       #
    ####################################################################################
    # effectively: configs_module = from . import configs
    configs_module = __import__("configs", globals(), level=1)

    ####################################################################################
    # Gather the mandatory input for exhale.                                           #
    ####################################################################################
    key_error = "Did not find required key `{key}` in `exhale_args`."
    val_error = "The type of the value for key `{key}` must be `{exp}`, but was `{got}`."

    req_kv = [
        ("containmentFolder",    str,  True),
        ("rootFileName",         str, False),
        ("rootFileTitle",        str, False),
        ("doxygenStripFromPath", str,  True)
    ]
    for key, expected_type, make_absolute in req_kv:
        # Make sure we have the key
        if key not in exhale_args:
            raise ConfigError(key_error.format(key=key))
        # Make sure the value is at the very least the correct type
        val   = exhale_args[key]
        val_t = type(val)
        if val_t is not expected_type:
            raise ConfigError(val_error.format(key=key, exp=expected_type, got=val_t))
        # If the string represents a path, make it absolute
        if make_absolute:
            val = os.path.abspath(val)
        # Set the config for use later
        setattr(configs_module, key, val)

    ####################################################################################
    # Validate what can be checked from the required arguments at this time.           #
    ####################################################################################
    containmentFolder    = getattr(configs_module, "containmentFolder")
    rootFileName         = getattr(configs_module, "rootFileName")
    doxygenStripFromPath = getattr(configs_module, "doxygenStripFromPath")

    # Make sure they know this is a bad idea
    if containmentFolder == app.srcdir:
        app.warn(
            "Exhale: setting `containmentFolder` to the source directory (e.g. '.') is a BAD idea."
        )

    # We *ONLY* generate reStructuredText, make sure Sphinx is expecting this as well as
    # the to-be-generated library root file is correctly suffixed.
    if not rootFileName.endswith(".rst"):
        raise ConfigError(
            "The given `rootFileName` ({0}) did not end with '.rst'; Exhale is reStructuredText only.".format(
                rootFileName
            )
        )
    if ".rst" not in app.config.source_suffix:
        raise ConfigError(
            "Exhale is reStructuredText only, but '.rst' was not found in `source_suffix` list of `conf.py`."
        )

    # Make sure the doxygen strip path is an exclude-able path
    if not os.path.exists(doxygenStripFromPath):
        raise ConfigError(
            "The path given as `doxygenStripFromPath` ({0}) does not exist!".format(doxygenStripFromPath)
        )

    ####################################################################################
    # Gather the optional input for exhale.                                            #
    ####################################################################################
    opt_kv = [
        ("afterTitleDescription",         str),
        ("createTreeView",                bool),
        ("treeViewIsBootstrap",           bool),
        ("fullToctreeMaxDepth",           int),
        ("customSpecificationsMapping",   dict),
        ("exhaleExecutesDoxygen",         bool),
        ("exhaleUseDoxyfile",             bool),
        ("exhaleDoxygenStdin",            str),
        ("exhaleSilentDoxygen",           bool),
        ("generateBreatheFileDirectives", bool)
    ]
    for key, expected_type in opt_kv:
        # Override the default settings if the key was provided
        if key in exhale_args:
            # Make sure the value is at the very least the correct type
            val   = exhale_args[key]
            val_t = type(val)
            if val_t is not expected_type:
                raise ConfigError(val_error.format(key=key, exp=expected_type, got=val_t))
            # Set the config for use later
            setattr(configs_module, key, val)

    ####################################################################################
    # Verify some potentially inconsistent or ignored settings.                        #
    ####################################################################################
    # treeViewIsBootstrap only takes meaning when createTreeView is True
    createTreeView      = getattr(configs_module, "createTreeView")
    treeViewIsBootstrap = getattr(configs_module, "treeViewIsBootstrap")
    if not createTreeView and treeViewIsBootstrap:
        app.warn("Exhale: `treeViewIsBootstrap=True` ignored since `createTreeView=False`")

    # fullToctreeMaxDepth > 5 may produce other sphinx issues unrelated to exhale
    fullToctreeMaxDepth = getattr(configs_module, "fullToctreeMaxDepth")
    if fullToctreeMaxDepth > 5:
        app.warn(
            "Exhale: `fullToctreeMaxDepth={0}` is greater than 5 and may build errors for non-html.".format(
                fullToctreeMaxDepth
            )
        )

    # Make sure that we received a valid mapping created by utils.makeCustomSpecificationsMapping
    customSpecificationsMapping = getattr(configs_module, "customSpecificationsMapping")
    sanity = getattr(configs_module, "_closure_map_sanity_check")
    insane = "`customSpecificationsMapping` *MUST* be made using  exhale.utils.makeCustomSpecificationsMapping"
    if customSpecificationsMapping:
        # Sanity check to make sure exhale made this mapping
        if sanity not in customSpecificationsMapping:
            raise ConfigError(insane)
        elif customSpecificationsMapping[sanity] != sanity:  # LOL
            raise ConfigError(insane)
        # Sanity check #2: enforce no new additions were made
        expected_keys = set([sanity]) | set(utils.AVAILABLE_KINDS)
        provided_keys = set(customSpecificationsMapping.keys())
        diff = provided_keys - expected_keys
        if diff:
            raise ConfigError("Found extra keys in `customSpecificationsMapping`: {0}".format(diff))
        # Sanity check #3: make sure the return values are all strings
        for key in customSpecificationsMapping:
            val_t = type(customSpecificationsMapping[key])
            if val_t is not str:
                raise ConfigError(
                    "`customSpecificationsMapping` key `{key}` gave value type `{val_t}` (need `str`).".format(
                        key=key, val_t=val_t
                    )
                )

    # Specify where the doxygen output should be going
    setattr(configs_module, "doxygenOutputDirectory", doxy_xml_dir)

    # If requested, the time is nigh for executing doxygen.  The strategy:
    # 1. Execute doxygen if requested
    # 2. Verify that the expected doxy_xml_dir (specified to `breathe`) was created
    # 3. Assuming everything went to plan, let exhale take over and create all of the .rst docs
    exhaleExecutesDoxygen = getattr(configs_module, "exhaleExecutesDoxygen")
    exhaleUseDoxyfile     = getattr(configs_module, "exhaleUseDoxyfile")
    exhaleDoxygenStdin    = getattr(configs_module, "exhaleDoxygenStdin")
    if exhaleExecutesDoxygen:
        # Cannot use both, only one or the other
        if exhaleUseDoxyfile and (exhaleDoxygenStdin is not None):
            raise ConfigError("You must choose one of `exhaleUseDoxyfile` or `exhaleDoxygenStdin`, not both.")

        # The Doxyfile *must* be at the same level as conf.py
        # This is done so that when separate source / build directories are being used,
        # we can guarantee where the Doxyfile is.
        if exhaleUseDoxyfile:
            doxyfile_path = os.path.abspath(os.path.join(app.confdir, "Doxyfile"))
            if not os.path.exists(doxyfile_path):
                raise ConfigError("The file [{0}] does not exist".format(doxyfile_path))

        here = os.path.abspath(os.curdir)
        if here == app.confdir:
            returnPath = None
        else:
            returnPath = here

        # All necessary information ready, go to where the Doxyfile is, run Doxygen
        # and then return back (where applicable) so sphinx can continue
        if returnPath:
            app.info(utils.info("Exhale: changing directories to [{0}] to execute Doxygen.".format(app.confdir)))
            os.chdir(app.confdir)
        app.info(utils.info("Exhale: executing doxygen."))
        status = deploy.generateDoxygenXML()
        # Being overly-careful to put sphinx back where it was before potentially erroring out
        if returnPath:
            app.info(utils.info("Exhale: changing directories back to [{0}] after Doxygen.".format(returnPath)))
            os.chdir(returnPath)
        if status:
            raise ExtensionError(status)
        else:
            app.info(utils.progress("Exhale: doxygen ran successfully!"))
    else:
        if exhaleUseDoxyfile:
            app.warn("Exhale: `exhaleUseDoxyfile` ignored since `exhaleExecutesDoxygen=False`")
        if exhaleDoxygenStdin is not None:
            app.warn("Exhale: `exhaleDoxygenStdin` ignored since `exhaleExecutesDoxygen=False`")
        if exhaleSilentDoxygen:
            app.warn("Exhale: `exhaleSilentDoxygen=True` ignored since `exhaleExecutesDoxygen=False`")

    # Either Doxygen was run prior to this being called, or we just finished running it.
    # Make sure that the files we need are actually there.
    if not os.path.isdir(doxy_xml_dir):
        raise ConfigError(
            "Exhale: the specified folder [{0}] does not exist.  Has Doxygen been run?".format(doxy_xml_dir)
        )
    index = os.path.join(doxy_xml_dir, "index.xml")
    if not os.path.isfile(index):
        raise ConfigError("Exhale: the file [{0}] does not exist.  Has Doxygen been run?".format(index))

    # Legacy / debugging feature, warn of its purpose
    generateBreatheFileDirectives = getattr(configs_module, "generateBreatheFileDirectives")
    if generateBreatheFileDirectives:
        app.warn("Exhale: `generateBreatheFileDirectives` is a debugging feature not intended for production.")

    ####################################################################################
    # Generate all of the reStructuredText documents!!!                                #
    ####################################################################################
    app.info(utils.info("Exhale: generating reStructuredText documents."))
    try:
        deploy.explode()
    except Exception as e:
        raise ExtensionError("Exhale: could not generate reStructuredText documents:\n{0}".format(e))

    ####################################################################################
    # If using a fancy treeView, add the necessary frontend files.                     #
    ####################################################################################
    if createTreeView:
        if treeViewIsBootstrap:
            tree_data_static_base = "treeView-bootstrap"
            tree_data_css = [os.path.join("bootstrap-treeview", "bootstrap-treeview.min.css")]
            tree_data_js  = [
                os.path.join("bootstrap-treeview", "bootstrap-treeview.min.js"),
                os.path.join("bootstrap-treeview", "apply-bootstrap-treview.js")
            ]
            tree_data_ext = []
        else:
            tree_data_static_base = "treeView"
            tree_data_css = [os.path.join("collapsible-lists", "css", "tree_view.css")]
            tree_data_js  = [
                os.path.join("collapsible-lists", "js", "CollapsibleLists.compressed.js"),
                os.path.join("collapsible-lists", "js", "apply-collapsible-lists.js")
            ]
            # The tree_view.css file uses these
            tree_data_ext = [
                os.path.join("collapsible-lists", "css", "button-closed.png"),
                os.path.join("collapsible-lists", "css", "button-open.png"),
                os.path.join("collapsible-lists", "css", "button.png"),
                os.path.join("collapsible-lists", "css", "list-item-contents.png"),
                os.path.join("collapsible-lists", "css", "list-item-last-open.png"),
                os.path.join("collapsible-lists", "css", "list-item-last.png"),
                os.path.join("collapsible-lists", "css", "list-item-open.png"),
                os.path.join("collapsible-lists", "css", "list-item.png"),
                os.path.join("collapsible-lists", "css", "list-item-root.png"),
            ]

        # Make sure we have everything we need
        collapse_data = os.path.join(os.path.abspath(os.path.dirname(__file__)), "data", tree_data_static_base)
        if not os.path.isdir(collapse_data):
            raise ExtensionError(
                "Exhale: the path to [{0}] was not found, possible installation error.".format(collapse_data)
            )
        else:
            all_files = tree_data_css + tree_data_js + tree_data_ext
            missing   = []
            for file in all_files:
                path = os.path.join(collapse_data, file)
                if not os.path.isfile(path):
                    missing.append(path)
            if missing:
                raise ExtensionError(
                    "Exhale: the path(s) {0} were not found, possible installation error.".format(missing)
                )

        # We have all the files we need, the extra files will be copied automatically by
        # sphinx to the correct _static/ location, but stylesheets and javascript need
        # to be added explicitly
        app.config.html_static_path.append(collapse_data)

        # Add the stylesheets
        for css in tree_data_css:
            app.add_stylesheet(css)

        # Add the javascript
        for js in tree_data_js:
            app.add_javascript(js)

    # If we are not to execute doxygen for the user, warn if configs are being ignored

    # import ipdb
    # ipdb.set_trace()
    # if "containmentFolder" not in exhale_args:
    #     raise ConfigError(key_error.format(key="containmentFolder"))
    # containmentFolder = exhale_args["containmentFolder"]
    # if type(containmentFolder) is not str:
    #     raise ValueError(
    #         "The type of the value for the key `containmentFolder` must be a string, but was: {0}".format(
    #             type(containmentFolder)
    #         )
    #     )
    # import ipdb
    # ipdb.set_trace()

def setup(app):
    app.setup_extension("breathe")
    app.connect("builder-inited", environment_ready)

    exhale_doxygen_output_dir : "doxy"
    app.add_config_value("exhale_args", {}, "env")

    return {"version": __version__}
