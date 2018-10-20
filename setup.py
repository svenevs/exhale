# noqa: D100
########################################################################################
# This file is part of exhale.  Copyright (c) 2017-2018, Stephen McDowell.             #
# Full BSD 3-Clause license available here:                                            #
#                                                                                      #
#                https://github.com/svenevs/exhale/blob/master/LICENSE                 #
########################################################################################

import os
import sys

# NOTE: full `setuptools` is required for this project
from setuptools import find_packages, setup

# TIP: hello!  It was challenging to get the right long description to show up on pypi,
#      I eventually discovered this tool, which you should also use!
#
#          https://github.com/pypa/readme_renderer

########################################################################################
# Gather brief and long descriptions from README.rst.                                  #
########################################################################################
b_desc_begin = ".. begin_exhale_brief_desc"
b_desc_end   = ".. end_exhale_brief_desc"
l_desc_begin = ".. begin_exhale_long_desc"    # read from here until remainder of file
b_avoid_raw  = ".. begin_strip_raw_for_pypi"  # fancy highlighting with bold not allowed
e_avoid_raw  = ".. end_strip_raw_for_pypi"    # because of .. raw:: html
here         = os.path.abspath(os.path.dirname(__file__))

# Process the file, reading the markers.  Store brief / long desc in corresponding lists
# to join the list together as a single string at the end.
try:
    readme_path  = os.path.join(here, "README.rst")
    brief_desc   = []
    inside_brief = False
    long_desc    = []
    inside_long  = False
    inside_raw   = False
    with open(readme_path) as readme:
        for line in readme:
            # See if we are at a being / end marker
            if line.startswith(b_desc_begin):
                inside_brief = True
                continue
            elif line.startswith(b_desc_end):
                inside_brief = False
                continue
            elif line.startswith(l_desc_begin):
                inside_long = True
                continue
            elif line.startswith(b_avoid_raw):
                inside_raw = True
                # the code that breaks pypi is
                # .. raw:: html
                #    <div class="highlight-rest">
                #      <div class="highlight">
                #        <pre>
                #    .. toctree::
                #       :maxdepth: 2
                #
                #       about
                #       <b>api/library_root</b></pre>
                #      </div>
                #    </div>
                #
                # so just add the unstylized version
                long_desc.append(".. code-block:: rst\n\n")
                long_desc.append("   .. toctree::\n")
                long_desc.append("      :maxdepth: 2\n\n")
                long_desc.append("      about\n")
                long_desc.append("      api/library_root\n\n")
                continue
            elif line.startswith(e_avoid_raw):
                inside_raw = False
                continue

            # If we are inside brief or long, append to the corresponding list
            if inside_brief:
                brief_desc.append(line)
            elif inside_long and not inside_raw:
                long_desc.append(line)

    # Simple sanity check, make sure we got the brief and long descriptions.
    if not brief_desc:
        raise RuntimeError("Did not acquire the brief description from README.rst.")
    if not long_desc:
        raise RuntimeError("Did not acquire the long description from README.rst.")

    # Make the lists strings.  No special reStructuredText formatting is present in the
    # brief / long descriptions (e.g. no block-level .. note:: or listings), which is
    # why we are not joining with a newline
    brief_desc = " ".join(line.strip() for line in brief_desc)
    long_desc  = "".join(line for line in long_desc)
except Exception as e:
    raise RuntimeError("Could not acquire the brief / long description from README.rst:\n{0}".format(e))

########################################################################################
# Gather the version information inside of exhale/__init__.py.                         #
########################################################################################
sys.path.insert(0, here)
import exhale  # noqa: E402, I100
version = exhale.__version__

########################################################################################
# Gather the requirements from requirements.txt.                                       #
########################################################################################
try:
    requirements_path = os.path.join(here, "requirements.txt")
    requirements      = []
    with open(requirements_path) as req:
        for line in req:
            # Allow for comments in the requirements.txt
            # NOTE: will break if using raw github egg urls!
            if "#" in line:
                the_requirement = line.split("#")[0]
                if len(the_requirement) > 0 and not the_requirement.isspace():
                    requirements.append(the_requirement.strip())
            else:
                requirements.append(line.strip())
except Exception as e:
    raise RuntimeError("Could not acquire the requirements from requirements.txt:\n{0}".format(e))

########################################################################################
# Setup the extension!!!                                                               #
########################################################################################
setup(
    name="exhale",
    version=version,
    packages=find_packages(exclude=["testing", "testing.*"]),
    install_requires=requirements,
    setup_requires=requirements,
    # See MANIFEST.in
    include_package_data=True,
    # Because we are including non-python data files, it cannot be compressed
    zip_safe=False,
    # Because Exhale hooks into / generates *BEFORE* any reading or writing occurs, it
    # is parallel safe by default
    parallel_read_safe=True,
    parallel_write_safe=True,
    # Metadata for PyPI
    author="Stephen McDowell",
    author_email="exhale.hosted@gmail.com",
    description=brief_desc,
    long_description=long_desc,
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
