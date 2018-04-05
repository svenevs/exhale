"""
Tests on the c_maths project
"""

from testing.base import ExhaleTestCase


class CMathsTests(ExhaleTestCase):

    test_project = 'c_maths'

    def test_configure(self):
        self.configure()

    def test_run_exhale(self):
        self.run_exhale()
