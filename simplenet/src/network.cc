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
        output = layer->feed_forwards(output);
    }
    return output;
}

void simplenet::test_network() {
    
}
