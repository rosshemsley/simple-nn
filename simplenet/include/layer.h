#pragma once

#include <armadillo>
#include <cassert>

#include <activation_functions.h>
#include <network_types.h>

namespace simplenet {

struct Layer {
    virtual vec feed_forwards(const vec& input) const = 0;
    virtual ~Layer(){};
};

struct FullyConnectedLayer : Layer {
    FullyConnectedLayer(size_t n_input_gates, size_t n_output_gates) {
        weights.zeros(n_output_gates, n_input_gates);
        biases.zeros(n_output_gates);
    }

    vec feed_forwards(const vec& input) const override {
        assert(input.n_rows == weights.n_cols);
        assert(weights.n_rows == biases.n_rows);
        return vec((weights * input + biases)).for_each(sigmoid);
    }

    vec weights;
    vec biases;
};

} // namespace simplenet
