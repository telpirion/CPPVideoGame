cc_test(
    name = "species_test",
    srcs = ["Species_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    defines = ["USE_BAZEL"],
    deps = [
        "//extern/googletest:gtest",
        "//extern/googletest:gtest_main",
        "//src:species",
    ],
)

cc_test(
    name = "character_builder_test",
    srcs = ["CharacterBuilder_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    defines = ["USE_BAZEL"],
    deps = [
        "//extern/googletest:gtest",
        "//extern/googletest:gtest_main",
        "//src:character",
        "//src:character_builder",
    ],
)

cc_test(
    name = "character_test",
    srcs = ["Character_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    defines = ["USE_BAZEL"],
    deps = [
        "//extern/googletest:gtest",
        "//extern/googletest:gtest_main",
        "//src:character",
        "//src:character_builder",
        "//src:species",
    ],
)