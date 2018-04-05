import os


TEST_PATH = os.path.dirname(__file__)


class SphinxConfigMock(object):

    def __init__(self, config):
        for name, value in config.items():
            setattr(self, name, value)
        self.source_suffix = '.rst'


class SphinxAppMock(object):

    def __init__(self, project, config):
        self.config = SphinxConfigMock(config)
        self.srcdir = os.path.join(TEST_PATH, 'test_projects', project, 'doc')
        self.confdir = self.srcdir

        os.makedirs(self.srcdir, exist_ok=True)

        self.log = []

    def info(self, info):
        self.log.append(info)
