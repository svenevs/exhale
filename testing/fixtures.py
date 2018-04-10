import pytest

from exhale import deploy


# we need to use session scope so that this fixture is generated before everything else
# see _pytest.fixtures.FixtureManager.getfixtureclosure
@pytest.fixture(scope='session')
def no_run():
    explode = deploy.explode
    deploy.explode = lambda: None
    yield
    deploy.explode = explode
