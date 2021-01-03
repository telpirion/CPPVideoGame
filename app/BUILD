cc_binary(
    name = "cpp_videogame",
    srcs = ["main.cpp"],
    deps = [
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