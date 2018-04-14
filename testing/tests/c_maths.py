"""
Tests on the c_maths project
"""

import os

from testing import TEST_PROJECTS_ROOT
from testing.base import ExhaleTestCase
from testing.decorators import confoverrides, no_run


class CMathsTests(ExhaleTestCase):
    test_project = 'c_maths'

    def test_app(self):
        self.checkRequiredConfigs()
        self.copyThisProject()

    @confoverrides(exhale_args={"containmentFolder": "./alt_api"})
    def test_alt_out(self):
        self.checkRequiredConfigs()


@no_run
class CMathsTestsNoRun(ExhaleTestCase):

    test_project = 'c_maths'

    def test_classwide_no_run(self):
        exhale_args = self.app.config.exhale_args
        containmentFolder = exhale_args['containmentFolder']

        self.assertEqual(containmentFolder, './api')

        # check that nothing has been generated
        api_dir = os.path.join(self.testroot, containmentFolder)
        self.assertFalse(os.path.exists(api_dir))
