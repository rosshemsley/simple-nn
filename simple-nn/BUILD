package(default_visibility = ["//visibility:public"])

cc_library(
    name = "simple-nn",
    srcs = ["src/simple-nn.cc"],
    hdrs = ["include/simple-nn.h"],
)

cc_test(
    timeout = "short",
    name = "simple-nn-test",
    srcs = ["src/test.cc"],
    deps = [":simple-nn"],
)
