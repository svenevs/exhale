#
# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup ------------------------------------------------------------------------
import sys
from pathlib import Path
from textwrap import dedent

repo_root = Path(__file__).parent.absolute().parent
sys.path.insert(0, str(repo_root))  # path to `exhale`

import exhale

# -- Project information ---------------------------------------------------------------
needs_sphinx = "4.3.1"

project = "Exhale"
copyright = "2017-2024, Stephen McDowell"
author = "Stephen McDowell"
version = exhale.__version__
release = exhale.__version__

# -- General configuration -------------------------------------------------------------
extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.todo",
    "sphinx.ext.graphviz",
    "sphinx.ext.intersphinx",
    # NOTE: viewcode isn't working, probably because of how my docs are setup
    #       and the lack of __all__ definitions?
    "sphinx.ext.viewcode",
    "sphinx_issues"
]
# make linkcheck does not support GitHub README.md anchors (they are synthetic anchors)
linkcheck_ignore = [
    r"https://github.com/jonmiles/bootstrap-treeview#.*"
]
templates_path = ["_templates"]
exclude_patterns = ["_build"]

# -- Options for HTML output -----------------------------------------------------------
html_title = "Exhale: Automatic C++ Library API Generation"
html_short_title = "Exhale"
html_theme = "sphinx_rtd_theme"
html_theme_options = {
    "navigation_depth": -1
}
html_static_path = ["_static"]
html_css_files = ["custom.css"]

# -- sphinx.ext.autodoc Extension Configuration ----------------------------------------
autodoc_member_order = "bysource"

# -- sphinx.ext.todo Extension Configuration -------------------------------------------
todo_include_todos = True
todo_link_only = True

# -- sphinx.ext.viewcode Extension Configuration ---------------------------------------
viewcode_follow_imported_members = True

# -- sphinx_issues Extension Configuration ---------------------------------------------
# See: https://github.com/sloria/sphinx-issues
issues_github_path = "svenevs/exhale"

# -- Intersphinx Extension Configuration -----------------------------------------------
intersphinx_mapping = {
    "python": ("https://docs.python.org/", None),
    "sphinx": ("https://www.sphinx-doc.org/en/master", None),
    "pytest": ("https://docs.pytest.org/en/latest/", None),
    # See _intersphinx/README.md
    "bs4": (
        "https://www.crummy.com/software/BeautifulSoup/bs4/doc",
        "_intersphinx/bs4_objects.inv"
    )
}

def setup(app):
    # https://github.com/sphinx-doc/sphinx/issues/5562#issuecomment-434296574
    # So that I can link to e.g., :confval:`sphinx:html_static_path`.
    app.add_object_type("confval", "confval",
                        objname="configuration value",
                        indextemplate="pair: %s; configuration value")

    # Add on the various extensions.
    sys.path.insert(0, str(repo_root / "docs" / "_extensions"))
    from autotested import autotested, visit_autotested_node, depart_autotested_node, AutoTestedDirective
    app.add_node(autotested, html=(visit_autotested_node, depart_autotested_node))
    app.add_directive("autotested", AutoTestedDirective)

    from exhaleversion import exhaleversion, visit_exhaleversion_node, depart_exhaleversion_node, ExhaleVersionDirective
    app.add_node(exhaleversion, html=(visit_exhaleversion_node, depart_exhaleversion_node))
    app.add_directive("exhaleversion", ExhaleVersionDirective)

    from testproject import testproject, visit_testproject_node, depart_testproject_node, TestProjectDirective
    app.add_node(testproject, html=(visit_testproject_node, depart_testproject_node))
    app.add_directive("testproject", TestProjectDirective)
    ####################################################################################
    # Multiline string documentation                                                   #
    ####################################################################################
    from textwrap import dedent

    from exhale.configs import DEFAULT_DOXYGEN_STDIN_BASE
    default_parts = DEFAULT_DOXYGEN_STDIN_BASE.strip().splitlines()
    multiline_var = "\n   ".join(p for p in default_parts)
    with open("DEFAULT_DOXYGEN_STDIN_BASE_value.rst", "w") as dcv:
        dcv.write(dedent("""
            The value of this variable is a multiline string with contents:

            .. code-block:: py

        """))
        dcv.write("   {multiline_var}".format(multiline_var=multiline_var))
        dcv.write(dedent("""
            .. note::

               The above value is presented for readability, when using this variable
               take note of any leading or trailing ``\\n`` characters.
        """))

    from exhale.utils import LANG_TO_LEX
    longest = 0
    for key in LANG_TO_LEX:
        longest = max(longest, len(key))
    with open("LANG_TO_LEX_value.rst", "w") as ltlv:
        ltlv.write(dedent("""
            .. code-block:: py

               LANG_TO_LEX = {
        """))
        nkeys = len(LANG_TO_LEX)
        idx = 0
        for key in LANG_TO_LEX:
            nspace = longest - len(key) + 1
            spacing = " " * nspace
            ltlv.write('       "{key}":{spacing}"{value}"'.format(
                key=key,
                spacing=spacing,
                value=LANG_TO_LEX[key]
            ))
            if idx < nkeys - 1:
                ltlv.write(",")
            ltlv.write("\n")

            idx += 1

        ltlv.write("   }\n\n")
