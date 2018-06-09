# Cracking the Coding Interview - C++ solutions

Modern C++ solutions to Cracking the Coding Interview (6th edition). Also a way for me to experiment with [Bazel](https://www.bazel.build/).

## Building

```bash
bazel build ...
```

## Running tests

Test are built with [googletest](https://github.com/google/googletest). To run them:

```bash
bazel test ... {--test_output=all}
```

The `--test_output` flag is optional if you would like to see the full output from gtest.
