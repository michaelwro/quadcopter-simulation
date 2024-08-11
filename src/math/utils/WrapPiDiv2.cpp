/**
 * @file WrapPiDiv2.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "math/utils/WrapPiDiv2.hpp"

#include <cmath>

#include "utils/constants.hpp"

double WrapPiDiv2(const double angle_rad) {
  double mod = std::fmod(angle_rad + constants::pi, constants::twoPi);

  if (mod < 0) {
    mod += constants::twoPi;
  }

  return mod - constants::pi;
}
