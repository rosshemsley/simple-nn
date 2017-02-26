project(simpleNN)

cmake_minimum_required(VERSION 2.8.0)
find_package(Armadillo REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} -std=c++11 -Wextra -pedantic -Wconversion")

include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories(simple_nn/include)
include_directories(mnist)

set(MNIST_SOURCES
    mnist/mnist
)

add_library(mnist STATIC ${MNIST_SOURCES})
target_link_libraries(mnist ${ARMADILLO_LIBRARIES})

set(SIMPLE_NN_SOURCES
    simple_nn/src/simple_nn
    simple_nn/src/test
)

add_library(simplenn STATIC ${SIMPLE_NN_SOURCES})
target_link_libraries(simplenn ${ARMADILLO_LIBRARIES})

add_executable(train main)
target_link_libraries(train mnist)

enable_testing()
