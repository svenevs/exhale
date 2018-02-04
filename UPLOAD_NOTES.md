# Upload Notes

For when I forget how I did this...

```console
# Build the source distribution
$ python setup.py sdist

# Build the universal wheel
$ python setup.py bdist_wheel --universal

# Upload!
$ twine upload dist/*
```

Make sure that your `~/.pypirc` has `username` under `[pypi]` or specify it to `twine` directly.
