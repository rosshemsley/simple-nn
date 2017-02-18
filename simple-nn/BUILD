package(default_visibility = ["//visibility:public"])

cc_library(
    name = "simple-nn",
    srcs = ["simple-nn.cc"],
    hdrs = ["simple-nn.h"],
)

cc_test(
    timeout = "short",
    name = "simple-nn-test",
    srcs = ["test.cc"],
    deps = [":simple-nn"],
)
