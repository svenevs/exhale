"""
Tests on the c_maths project
"""

import os

import pytest

from testing.base import ExhaleTestCase, TEST_DOC_DIR


class CMathsTests(ExhaleTestCase):

    test_project = 'c_maths'

    config = {
        'exhale_args': {
            'containmentFolder': './exhale'
        }
    }

    def test_app(self):
        exh_args = self.app.config.exhale_args
        cont_fold = exh_args['containmentFolder']

        self.assertEqual(cont_fold, './exhale')

        api_dir = os.path.join(TEST_DOC_DIR, cont_fold)
        self.assertTrue(os.path.isfile(os.path.join(api_dir, exh_args['rootFileName'])))
        self.assertTrue(os.path.isfile(os.path.join(api_dir, 'function_add.rst')))
        self.assertTrue(os.path.isfile(os.path.join(api_dir, 'file_projects_c_maths_include_main.h.rst')))

    @pytest.mark.sphinx(confoverrides={
        'exhale_args': {
            'containmentFolder': './doxygen'
        }
    })
    def test_app_change_config(self):
        exh_args = self.app.config.exhale_args
        cont_fold = exh_args['containmentFolder']

        self.assertEqual(cont_fold, './doxygen')

        api_dir = os.path.join(TEST_DOC_DIR, cont_fold)
        self.assertTrue(os.path.isfile(os.path.join(api_dir, exh_args['rootFileName'])))
