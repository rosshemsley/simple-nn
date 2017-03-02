#include <layer.h>

#include <cassert>

/**
 * Unit tests
 */

using namespace std;
using namespace simplenet;

namespace {

void test_fully_connected_layer_1() {
    auto layer = FullyConnectedLayer(3, 2);
    layer.biases = vec{{7, 8, 9}};
    layer.weights = mat{
        {1, 2},
        {3, 4},
        {5, 6},
    };

    const auto input = vec{-1, -2};
    const auto output = layer.feed_forward(input);
    const auto expected = vec{2, -3, -8};
    assert(approx_equal(output, expected, "absdiff", 0.002));
}

}

void simplenet::test_layer() {
    test_fully_connected_layer_1();
}
