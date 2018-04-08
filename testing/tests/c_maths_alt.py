import pytest
pytest_plugins = 'sphinx.testing.fixtures'

import os

# temporary
this_file_dir = os.path.abspath(os.path.dirname(__file__))
testing_dir = os.path.dirname(this_file_dir)
test_docs_dir = os.path.abspath(os.path.join(
    testing_dir, "projects", "c_maths_alt", "docs"
))

@pytest.mark.sphinx('html', testroot=test_docs_dir)
def test_cmaths_alt(app):
    containmentFolder    = app.config.exhale_args["containmentFolder"]
    containmentFolder    = os.path.abspath(os.path.join(app.srcdir, containmentFolder))
    rootFileName         = app.config.exhale_args["rootFileName"]
    rootFileTitle        = app.config.exhale_args["rootFileTitle"]
    doxygenStripFromPath = app.config.exhale_args["doxygenStripFromPath"]
    root_file_path = os.path.join(containmentFolder, rootFileName)
    print("ROOT FILE PATH: {}".format(root_file_path))
    assert os.path.isfile(root_file_path)

    # tmp, you can just not do this to avoid html generation
    app.build()

