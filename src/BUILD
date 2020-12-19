cc_library(
    name = "character",
    srcs = ["Character.cpp"],
    hdrs = glob(
            ["*.h"],
        ),
    deps = [
        ":species",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "character_builder",
    srcs = ["CharacterBuilder.cpp"],
    hdrs = glob(
            ["*.h"],
        ),
    deps = [
        ":character",
        ":species",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "species",
    srcs = ["Species.cpp"],
    hdrs = glob(
            ["*.h"],
        ),
    deps = [":attributes"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "attributes",
    srcs = ["Attributes.cpp"],
    hdrs = ["Attributes.h"],
    visibility = ["//visibility:public"],
)