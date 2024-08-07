/**
 * @file SphericalGravity.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "gravity/SphericalGravity.hpp"

Eigen::Vector3d SphericalGravity::GetAcceleration(
    const Eigen::Vector3d& position_ecef_m) {
  /**
   * @brief Earth's `mu` gravity parameter `Gm` [m^3/s^2]
   * https://www.unoosa.org/pdf/icg/2012/template/WGS_84.pdf
   */
  constexpr double EARTH_GM_M3PS2 = 3.986'004'418e14;

  // compute position magnitude
  const double position_m = position_ecef_m.norm();

  /**
   * Compute acceleration magnitude.
   * g = GM / r^2
   */
  const double acceleration_mps2 = EARTH_GM_M3PS2 / (position_m * position_m);

  // gravity is simply along the negative of the position vector
  const Eigen::Vector3d acceleration_ecef_mps2 =
      -acceleration_mps2 * position_ecef_m.normalized();

  return acceleration_ecef_mps2;
}

GravityModel SphericalGravity::GetType() const {
  return GravityModel::Spherical;
}
