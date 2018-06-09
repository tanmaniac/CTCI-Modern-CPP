cc_test(
    name = "ctci-tests",
    srcs = glob(["*.cpp"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        "//include/arrays-and-strings:arrays-and-strings",
    ],
)