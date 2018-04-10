import pytest

from exhale import deploy


# we need to use class scope so that this fixture is generated before other ones
# see _pytest.fixtures.FixtureManager.getfixtureclosure
@pytest.fixture(scope='class')
def no_run():
    explode = deploy.explode
    deploy.explode = lambda: None
    yield
    deploy.explode = explode
