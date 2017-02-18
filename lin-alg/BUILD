package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lin-alg",
    srcs = ["lin-alg.cc"],
    hdrs = ["lin-alg.h"],
)

cc_test(
    timeout = "short",
    name = "lin-alg-test",
    srcs = ["test.cc"],
    deps = [":lin-alg"],
)
