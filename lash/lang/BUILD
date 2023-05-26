load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "lexer",
    srcs = ["lexer.cpp"],
    hdrs = ["lexer.hpp"],
    visibility = ["//visibility:public"],
    deps = ["@spdlog//:spdlog.so"],
)

cc_library(
    name = "parser",
    hdrs = ["parser.hpp"],
    visibility = ["//visibility:public"],
)