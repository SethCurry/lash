load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "spdlog.so",
    srcs = glob(["src:*.cpp"]),
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["@fmtlib//:fmtlib.so"],
)
