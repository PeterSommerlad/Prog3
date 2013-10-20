#include "squareroot.h"
#include <stdexcept>
#include <cmath>
double square_root(double x) {
  if (x < 0)
    throw 42;//std::invalid_argument{"square_root imaginary"};
  return std::sqrt(x);
}
