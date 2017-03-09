#include <network.h>

using namespace simplenet;

simplenet::Network::Network(std::initializer_list<std::shared_ptr<Layer>> initial) {
    layers.reserve(initial.size());
    for (auto l : initial) {
        layers.emplace_back(l);
    }
}

vec simplenet::Network::evaluate(const vec& input) {
    auto output = input;
    for (const auto& layer : layers) {
        output = layer->feed_forward(output);
    }
    return output;
}

void simplenet::Network::train(const vector<vec>& data,
                               const vector<vec>& labels,
                               int n_epochs,
                               int batch_size,
                               double learning_rate) {

    

}

/**
 * Unit tests
 */

void simplenet::test_network() {
}
