/**
 * @file J2Gravity.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "gravity/J2Gravity.hpp"

#include <cmath>

#include "utils/constants.hpp"

Eigen::Vector3d J2Gravity::GetAcceleration(
    const Eigen::Vector3d &positon_ecef_m) {
  // shorthand notation
  using namespace constants;

  // position magnitude
  const double pos_m = positon_ecef_m.norm();
  const double posSqd_m = pos_m * pos_m;

  // earth zonal harmonic J2
  constexpr double j2 = 1.082'626'684e-3;

  // common factors
  const double gmOverR2 = wgs84::gravParam_m3ps2 / posSqd_m;
  const double commonJ2Factor =
      1.5 * wgs84::semiMajorAxis_m * wgs84::semiMajorAxis_m * j2 / posSqd_m;

  // compute sin(lat)^2
  const double sinGeocLatSqd =
      (positon_ecef_m(2) * positon_ecef_m(2) / posSqd_m);

  // compute gravity
  const double gx_msp2 = -gmOverR2 * (positon_ecef_m(0) / pos_m) *
                         (1.0 + commonJ2Factor * (1.0 - (5.0 * sinGeocLatSqd)));

  const double gy_msp2 = -gmOverR2 * (positon_ecef_m(1) / pos_m) *
                         (1.0 + commonJ2Factor * (1.0 - (5.0 * sinGeocLatSqd)));

  const double gz_msp2 = -gmOverR2 * (positon_ecef_m(2) / pos_m) *
                         (1.0 + commonJ2Factor * (3.0 - (5.0 * sinGeocLatSqd)));

  const Eigen::Vector3d gravity_ecef_mps2 {gx_msp2, gy_msp2, gz_msp2};
  return gravity_ecef_mps2;
}

GravityModel J2Gravity::GetType() const { return GravityModel::J2; }
