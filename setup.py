# noqa: D100
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2021, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

import os
import sys

# NOTE: full `setuptools` is required for this project
from setuptools import find_packages, setup
setup(
    name="exhale",
    version="0.3.0.dev",
    packages=find_packages(exclude=["testing", "testing.*"]),
    # See MANIFEST.in
    include_package_data=True,
    # Because we are including non-python data files, it cannot be compressed
    zip_safe=False,
    # Metadata for PyPI
    author="Stephen McDowell",
    author_email="exhale.hosted@gmail.com",
    description="temporary value for RTD",
    long_description="temporary value for RTD",
    url="https://github.com/svenevs/exhale",
    license="BSD",
    # See: https://pypi.python.org/pypi?%3Aaction=list_classifiers
    classifiers=[
        "Development Status :: 2 - Pre-Alpha",
        "Framework :: Sphinx :: Extension",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: BSD License",
        "Natural Language :: English",
        "Programming Language :: Python",
        "Programming Language :: Python :: 2",
        "Programming Language :: Python :: 3",
        "Topic :: Documentation :: Sphinx",
        "Topic :: Software Development :: Documentation",
    ]
)
