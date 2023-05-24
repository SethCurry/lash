workspace(name = "lash")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
  strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
)


http_archive(
    name = "spdlog",
    sha256 = "ca5cae8d6cac15dae0ec63b21d6ad3530070650f68076f3a4a862ca293a858bb",
    urls = 
    ["https://github.com/gabime/spdlog/archive/refs/tags/v1.11.0.tar.gz"],
    build_file = "@lash//lib/spdlog:BUILD",
)

http_archive(
  name = "fmtlib",
  urls = ["https://github.com/fmtlib/fmt/archive/refs/tags/10.0.0.tar.gz"],
  build_file = "@lash//lib/fmtlib:BUILD",
)