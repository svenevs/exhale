Exhale Configs Module
========================================================================================

.. contents::

.. automodule:: exhale.configs

.. _required_configs:

Required Configuration Arguments
----------------------------------------------------------------------------------------

.. begin_minimum_requirements_breathe_and_exhale

Both Breathe and Exhale require that you **already** have Doxygen ``xml`` documentation
generated **before** they are launched.  See the :ref:`usage_fully_automated` section
for more information.

There are **6** required arguments you must provide in your ``conf.py``.  **2** are for
Breathe, and **4** are for Exhale.

Required Arguments for Breathe
****************************************************************************************

Breathe is setup to allow for multiple projects being controlled by a **single**
``conf.py`` to rule them all.  Exhale only supports generating **one** "project" API at
a time.  The project that Exhale will generate is determined by what you signal to
Breathe as your *default* project.  The two arguments that must be present in your
``conf.py`` for Breathe are as follows:

**Mapping of Project Names to Doxygen XML Output Paths**
    ``breathe_projects`` (dict)
        - Keys: strings that are the name of a given project.
        - Values: strings that are (absolute or relative) paths to where the Doxygen XML
          output has been generated.

        So if the Doxygen documentation was generated to the path ``./doxyoutput/xml``,
        and your project was called ``"My Project"``, you would include the following in
        your ``conf.py``:

        .. code-block:: py

           breathe_projects = {
               "My Project": "./doxyoutput/xml"
           }

        .. tip::

           When specifying relative paths, they are all relative to ``conf.py``.

**Selecting the Project to Generate**
    ``breathe_default_project`` (str)
        Since Breathe can support multiple projects, specify the default project so that
        Exhale will know which one to use (when more than one project is available).

        Following from the example above, where the key in ``breathe_projects`` we want
        to generate is ``"My Project"``, you would include the following you your
        ``conf.py``:

        .. code-block:: py

           breathe_default_project = "My Project"

Required Arguments for Exhale
****************************************************************************************

Users must provide the following values to ``exhale_args`` in their ``conf.py``.

.. tip::

   Recall the variable name conventions from above.  If you want to specify the value
   for ``containmentFolder`` so that :data:`exhale.configs.containmentFolder` is
   populated, the name of the *key* is the string ``"containmentFolder"``.  Each entry
   below details what the ``type`` of the *value* of the key should be.  So in this case
   you might have

   .. code-block:: py

      exhale_args = {
          "containmentFolder": "./api",
          # other required entries here
      }

.. end_minimum_requirements_breathe_and_exhale

.. autodata:: exhale.configs.containmentFolder

.. autodata:: exhale.configs.rootFileName

.. autodata:: exhale.configs.rootFileTitle

.. autodata:: exhale.configs.doxygenStripFromPath

Optional Configuration Arguments
----------------------------------------------------------------------------------------

Build Process Logging, Colors, and Debugging
****************************************************************************************

.. autodata:: exhale.configs.verboseBuild

.. autodata:: exhale.configs.alwaysColorize

.. autodata:: exhale.configs.generateBreatheFileDirectives

Root API Document Customization and Treeview
****************************************************************************************

.. autodata:: exhale.configs.afterTitleDescription

.. autodata:: exhale.configs.afterBodySummary

.. autodata:: exhale.configs.createTreeView

.. autodata:: exhale.configs.treeViewIsBootstrap

.. autodata:: exhale.configs.fullToctreeMaxDepth

Breathe Customization
****************************************************************************************

.. autodata:: exhale.configs.customSpecificationsMapping

.. autodata:: exhale.configs._closure_map_sanity_check

.. _configs_doxygen_execution_and_customization:

Doxygen Execution and Customization
****************************************************************************************

.. autodata:: exhale.configs.doxygenOutputDirectory

.. autodata:: exhale.configs.exhaleExecutesDoxygen

.. autodata:: exhale.configs.exhaleUseDoxyfile

.. autodata:: exhale.configs.exhaleDoxygenStdin

.. autodata:: exhale.configs.DEFAULT_DOXYGEN_STDIN_BASE

.. autodata:: exhale.configs.exhaleSilentDoxygen

Utility Variables
----------------------------------------------------------------------------------------

.. autodata:: exhale.configs.SECTION_HEADING

.. autodata:: exhale.configs.SUB_SECTION_HEADING

.. autodata:: exhale.configs.SUB_SUB_SECTION_HEADING

.. autodata:: exhale.configs._the_app

.. autodata:: exhale.configs._app_src_dir

Secondary Sphinx Entry Point
----------------------------------------------------------------------------------------

.. autofunction:: exhale.configs.apply_sphinx_configurations
