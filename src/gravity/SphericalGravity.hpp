/**
 * @file SphericalGravity.hpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#pragma once

#include <Eigen/Dense>

#include "gravity/IGravityModel.hpp"

/**
 * @brief A spherical gravity model simply uses `GM / r^2` to compute gravity.
 */
class SphericalGravity : public IGravityModel {
public:
  /**
   * @brief Create a SphericalGravity object.
   */
  SphericalGravity() = default;
  ~SphericalGravity() override = default;

  /**
   * @brief Calculate the gravitational acceleration vector at the specified
   * ECEF location.
   *
   * @param position_ecef_m Body ECEF position [m].
   * @return Gravitational acceleration in the ECEF frame [m/s^2].
   */
  Eigen::Vector3d GetAcceleration(
      const Eigen::Vector3d& position_ecef_m) override;

  /**
   * @brief Get this gravity model's type.
   *
   * @return Model type.
   */
  virtual GravityModel GetType() const override;
};
