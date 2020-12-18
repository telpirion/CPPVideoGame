load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

#http_archive(
#    name = "gtest",
#    build_file = "extern/gtest.BUILD",
#    strip_prefix = "googletest-release-1.8.0/googletest",
#    url = "https://github.com/google/googletest/archive/release-1.8.0.zip",
#)

http_archive(
    name = "glfw",
    build_file = "@//extern:glfw.BUILD",
    strip_prefix = "glfw-3.3.2",
    urls = ["https://github.com/glfw/glfw/archive/3.3.2.zip"],
)
