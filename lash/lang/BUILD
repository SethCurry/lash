load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "lexer",
    srcs = ["lexer.cpp"],
    hdrs = ["lexer.hpp"],
    visibility = ["//visibility:public"],
    deps = ["@spdlog//:spdlog.so", "//lash/util:chars.so"],
)

cc_library(
    name = "parser",
    srcs = ["parser.cpp"],
    hdrs = ["parser.hpp"],
    visibility = ["//visibility:public"],
    deps = ["@spdlog//:spdlog.so", "//lash/lang:lexer"],
)