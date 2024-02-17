cc_library(
    name = "scene1",
    srcs = ["scene1.cpp"],
    hdrs = glob(
            ["*.h"],
        ),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "cpp_videogame",
    srcs = ["main.cpp"],
    deps = [
        ":scene1",
        "//src:character",
        "//src:character_builder",
        "//src:species",
        "//src:attributes",
    ],
    defines = ["USE_BAZEL"],
    linkopts = [
        "-framework OpenGL",
        "-framework GLUT",
    ],
)