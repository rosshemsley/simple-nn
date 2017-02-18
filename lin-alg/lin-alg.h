#pragma once

#include <vector>

namespace LinAlg {

/// use built-in types to represent vectors and matrices
template <typename T>
using matrix = std::vector<std::vector<T>>;
using mat32 = matrix<float>;
using vec32 = std::vector<float>;

/// matrix-vector multiplication
vec32 mul(const mat32& a, const vec32& b);

/// Hadamard vector-vector multiplication
vec32 hadamard(const vec32& a, const vec32& b);

/// dot product of two vectors
float dot(const vec32& a, const vec32& b);
}
