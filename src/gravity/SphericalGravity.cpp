/**
 * @file SphericalGravity.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "gravity/SphericalGravity.hpp"

#include "utils/constants.hpp"

Eigen::Vector3d SphericalGravity::GetAcceleration(
    const Eigen::Vector3d& position_ecef_m) {
  // compute position magnitude
  const double position_m = position_ecef_m.norm();

  /**
   * Compute acceleration magnitude.
   * g = GM / r^2
   */
  const double acceleration_mps2 =
      constants::wgs84::gravParam_m3ps2 / (position_m * position_m);

  // gravity is simply along the negative of the position vector
  const Eigen::Vector3d acceleration_ecef_mps2 =
      -acceleration_mps2 * position_ecef_m.normalized();

  return acceleration_ecef_mps2;
}

GravityModel SphericalGravity::GetType() const {
  return GravityModel::Spherical;
}
