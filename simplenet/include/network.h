#pragma once

#include <activation_functions.h>
#include <layer.h>
#include <network_types.h>

#include <memory>
#include <vector>

namespace simplenet {

class Network {
  public:
    Network(std::initializer_list<std::unique_ptr<Layer>> initial) {
        layers.reserve(initial.size());
        for (auto l : initial) {
            layers.emplace_back(l);
        }
    }

    vec evaluate(const vec& input) {
        auto output = input;
        for (const auto& layer : layers) {
            output = layer->feed_forwards(output);
        }
        return output;
    }

    std::vector<std::unique_ptr<Layer>> layers;
};

} // namespace simplenet
