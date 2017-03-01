#pragma once

#include <activation_functions.h>
#include <layer.h>
#include <network_types.h>

#include <memory>
#include <vector>

namespace simplenet {

class Network {
  public:
    Network(std::initializer_list<std::shared_ptr<Layer>>);

    vec evaluate(const vec&);

    std::vector<std::shared_ptr<Layer>> layers;
};

/// Unit tests
void test_network();

} // namespace simplenet
