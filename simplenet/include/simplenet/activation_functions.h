#pragma once

#include <cmath>

inline float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}
