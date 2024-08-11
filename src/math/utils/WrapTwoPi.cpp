/**
 * @file WrapTwoPi.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "math/utils/WrapTwoPi.hpp"

#include <cmath>

#include "utils/constants.hpp"

double WrapTwoPi(const double angle_rad) {
  double mod = std::fmod(angle_rad, constants::twoPi);

  if (mod < 0) {
    mod += constants::twoPi;
  }

  return mod;
}
