Exhale Configs Module
========================================================================================

.. automodule:: exhale.configs

.. _required_configs:

Required Configuration Arguments
----------------------------------------------------------------------------------------

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

.. autodata:: exhale.configs.containmentFolder

.. autodata:: exhale.configs.rootFileName

.. autodata:: exhale.configs.rootFileTitle

.. autodata:: exhale.configs.doxygenStripFromPath

Optional Configuration Arguments
----------------------------------------------------------------------------------------

.. autodata:: exhale.configs.verboseBuild

.. autodata:: exhale.configs.alwaysColorize

.. autodata:: exhale.configs.afterTitleDescription

.. autodata:: exhale.configs.afterBodySummary

.. autodata:: exhale.configs.createTreeView

.. autodata:: exhale.configs.treeViewIsBootstrap

.. autodata:: exhale.configs.fullToctreeMaxDepth

.. autodata:: exhale.configs.customSpecificationsMapping

.. autodata:: exhale.configs._closure_map_sanity_check

.. autodata:: exhale.configs.doxygenOutputDirectory

.. autodata:: exhale.configs.exhaleExecutesDoxygen

.. autodata:: exhale.configs.exhaleUseDoxyfile

.. autodata:: exhale.configs.exhaleDoxygenStdin

.. autodata:: exhale.configs.DEFAULT_DOXYGEN_STDIN_BASE

.. autodata:: exhale.configs.exhaleSilentDoxygen

.. autodata:: exhale.configs.exhaleApiTocTreeMaxDepth

.. autodata:: exhale.configs.generateBreatheFileDirectives

Utility Variables
----------------------------------------------------------------------------------------

.. autodata:: exhale.configs.SECTION_HEADING

.. autodata:: exhale.configs.SUB_SECTION_HEADING

.. autodata:: exhale.configs.SUB_SUB_SECTION_HEADING

.. autodata:: exhale.configs._the_app

.. autodata:: exhale.configs._app_src_dir
