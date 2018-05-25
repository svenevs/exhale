# Upload Notes

For when I forget how I did this...

```console
# Build the source distribution and universal wheel
# saved into dist/ folder
$ tox -e dist

# Upload!
$ twine upload dist/*
```

Make sure that your `~/.pypirc` has `username` under `[pypi]` or specify it to `twine` directly.
