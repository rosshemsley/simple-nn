#pragma once

#include <simplenet/activation_functions.h>
#include <simplenet/network_types.h>

#include <armadillo>
#include <cassert>
#include <iostream>

using namespace std;
namespace simplenet {

struct Layer {
    virtual vec feed_forward(const vec& input) const = 0;
    virtual ~Layer(){};
};

struct FullyConnectedLayer : Layer {
    FullyConnectedLayer(size_t n_input_gates, size_t n_output_gates) {
        weights.zeros(n_input_gates, n_output_gates);
        biases.zeros(n_output_gates);
    }

    vec feed_forward(const vec& input) const override {
        assert(input.n_rows == weights.n_cols);
        assert(weights.n_rows == biases.n_rows);
        return vec((weights * input + biases)).for_each(sigmoid);
    }

    mat weights;
    vec biases;
};

/// Unit tests
void test_layer();

} // namespace simplenet
