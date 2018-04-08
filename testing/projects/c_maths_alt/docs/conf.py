# -*- coding: utf-8 -*-
extensions = [
    'breathe',
    'exhale'
]

breathe_projects = {"c_maths_alt": "./_doxygen/xml"}
breathe_default_project = "c_maths_alt"

exhale_args = {
    # These arguments are required
    "containmentFolder":     "./api",
    "rootFileName":          "library_root.rst",
    "rootFileTitle":         "Library API",
    "doxygenStripFromPath":  "..",
    "exhaleExecutesDoxygen": True,
    "exhaleDoxygenStdin":    "INPUT = ../include"
}
source_suffix = '.rst'
master_doc = 'index'
