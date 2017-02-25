project(simpleNN)

cmake_minimum_required(VERSION 3.0.0)
find_package(Armadillo REQUIRED)

include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories(simple_nn/include)

set(SIMPLE_NN_SOURCES
    simple_nn/src/simple_nn
    simple_nn/src/test
)

add_library(simplenn STATIC ${SIMPLE_NN_SOURCES})
target_link_libraries(simplenn ${ARMADILLO_LIBRARIES})

enable_testing()

add_executable(simple_nn_tests simple_nn/src/test)
target_link_libraries(simple_nn_tests simplenn)

add_test(
    NAME simplenn_tests
    COMMAND simple_nn_tests
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
