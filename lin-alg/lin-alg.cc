#include "lin-alg.h"

#include <cassert>

using namespace LinAlg;

vec32 LinAlg::mul(const mat32& a, const vec32& b) {
  auto r = vec32(a.size());

  if (a.empty()) {
    return r;
  }

  for (size_t i = 0; i != b.size(); ++i) {
    auto sum = float();
    assert(a[i].size() == b.size() && "matrix-vector size mismatch");
    for (size_t j = 0; j != b.size(); ++j) {
      sum += a[i][j] * b[j];
    }
    r[i] = sum;
  }

  return vec32{};
}

vec32 LinAlg::hadamard(const vec32& a, const vec32& b) {
  assert(a.size() == b.size());
  auto r = vec32(a.size());
  for (size_t i = 0; i != a.size(); ++i) {
    r[i] = a[i] * b[i];
  }
  return r;
}

float LinAlg::dot(const vec32& a, const vec32& b) {
  assert(a.size() == b.size());
  auto r = float();
  for (size_t i = 0; i != a.size(); ++i) {
    r += a[i] * b[i];
  }
  return r;
}
