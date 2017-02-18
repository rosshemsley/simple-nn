#include <vector>

namespace LinAlg {
using matrix<T> = vector<vector<T>>;
using mat32 = matrix<float>;
using vec32 = vector<float>;

/// matrix-vector multiplication
vec32 mul(const mat32& a, const vec32& b);

/// Hadamard vector-vector multiplication
vec32 hadamard(const vec32& a, const vec32& b);

/// dot product of two vectors
vec32 dot(const vec32& a, vec32& b);
}
