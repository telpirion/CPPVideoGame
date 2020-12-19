cc_test(
    name = "cppgame_test",
    srcs = [
        "Character_test.cpp",
        "CharacterBuilder_test.cpp",
        "main.cpp",
        "Species_test.cpp",
    ],
    copts = [
        "-Iexternal/gtest/include",
        "-DUSE_BAZEL",
    ],
    deps = [
        "//extern/googletest:gtest",
        "//src:species",
    ],
)