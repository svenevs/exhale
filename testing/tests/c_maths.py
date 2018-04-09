"""
Tests on the c_maths project
"""

import os

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
