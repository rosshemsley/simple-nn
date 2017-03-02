project(simplenet)

cmake_minimum_required(VERSION 2.8.0)
find_package(Armadillo REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wextra -pedantic -O3 -Werror -Wall -g -fno-omit-frame-pointer")

include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories(simplenet/include)

include_directories(mnist)
set(MNIST_SOURCES
    mnist/mnist
)

set(SIMPLE_NN_SOURCES
    simplenet/src/layer
    simplenet/src/network
    simplenet/src/simplenet
    simplenet/src/test
)

add_library(mnist STATIC ${MNIST_SOURCES})
target_link_libraries(mnist ${ARMADILLO_LIBRARIES})

add_library(simplenet STATIC ${SIMPLE_NN_SOURCES})
target_link_libraries(simplenet ${ARMADILLO_LIBRARIES})

add_executable(simplenet_tests simplenet/src/test)
target_link_libraries(simplenet_tests simplenet)

add_executable(run main)
target_link_libraries(run mnist)
target_link_libraries(run simplenet)

enable_testing()

add_test(
    NAME simplenet_tests
    COMMAND simplenet_tests
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
