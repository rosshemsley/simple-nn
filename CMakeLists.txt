project(simpleNN)

cmake_minimum_required(VERSION 2.8.0)
find_package(Armadillo REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -pedantic -O3 -Werror -Wall -g -fno-omit-frame-pointer")

include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories(simplenet/include)

include_directories(mnist)
set(MNIST_SOURCES
    mnist/mnist
)

set(SIMPLE_NN_SOURCES
    simplenet/src/simplenet
    simplenet/src/test
)

add_library(mnist STATIC ${MNIST_SOURCES})
target_link_libraries(mnist ${ARMADILLO_LIBRARIES})

add_library(simplenn STATIC ${SIMPLE_NN_SOURCES})
target_link_libraries(simplenn ${ARMADILLO_LIBRARIES})

add_executable(train main)
target_link_libraries(train mnist)

enable_testing()
