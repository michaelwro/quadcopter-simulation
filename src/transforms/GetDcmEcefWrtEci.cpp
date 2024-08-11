/**
 * @file GetDcmEcefWrtEci.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "transforms/GetDcmEcefWrtEci.hpp"

#include <cassert>
#include <cmath>

#include "math/WrapTwoPi.hpp"
#include "utils/constants.hpp"

Eigen::Matrix3d GetDcmEcefWrtEci(const double simElapsedTime_sec,
                                 const double earthAngVec_radps) {
  assert(simElapsedTime_sec > 0);

  /**
   * Convert time to "Greenwich hour angle" aka integrated earth
   * rotation angle.
   */
  const double hourAngle_rad =
      WrapTwoPi(earthAngVec_radps * simElapsedTime_sec);

  assert(hourAngle_rad < constants::twoPi);

  // create ecef/eci DCM
  const double sinAngle = std::sin(hourAngle_rad);
  const double cosAngle = std::cos(hourAngle_rad);

  Eigen::Matrix3d dcmEcefWrtEci {
      {cosAngle, sinAngle, 0.0}, {-sinAngle, cosAngle, 0.0}, {0.0, 0.0, 1.0}};

  return dcmEcefWrtEci;
}
