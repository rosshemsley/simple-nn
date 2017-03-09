#pragma once

#include <simplenet/activation_functions.h>
#include <simplenet/layer.h>
#include <simplenet/network_types.h>

#include <memory>
#include <vector>

namespace simplenet {

class Network {
  public:
    Network(std::initializer_list<std::shared_ptr<Layer>>);

    /**
     * @brief      Evaluate the network on a given input.
     *
     *             input is a vector with `n_rows` matching the number of input gates of the first
     *             layer of the network.
     */
    vec evaluate(const vec& input);

    /**
     * @brief      Use stochastic gradient descent to train the network.
     *
     *             Takes a vector of training samples, each having `n_rows` matching the number of
     *             input gates of the first layer, and the associated labels, with `n_rows` matching
     *             the number of output gates.
     */
    void train(const std::vector<vec>& data,
               const std::vector<vec>& labels,
               int n_epochs,
               int batch_size,
               double learning_rate);

    std::vector<std::shared_ptr<Layer>> layers;
};

/// Unit tests
void test_network();

} // namespace simplenet
