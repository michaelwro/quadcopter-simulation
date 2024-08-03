/**
 * @file IGravityModel.hpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#pragma once

#include <Eigen/Dense>

#include "gravity/GravityModel_enum.hpp"

/**
 * @brief Generic gravity model interface definition.
 */
class IGravityModel {
public:
  IGravityModel() = default;
  virtual ~IGravityModel() = default;

  /**
   * @brief Compute gravitational accleleration in the earth-centered,
   * earth-fixed (ECEF) frame.
   * @details Gravitational acceleration is downwards, towards earth's center.
   *
   * @param positon_ecef_m Body position [m] in the ECEF frame.
   * @return Gravitational acceleration [m/s^2].
   */
  virtual Eigen::Vector3d GetAcceleration(
      const Eigen::Vector3d& positon_ecef_m) = 0;

  /**
   * @brief Get the type of this model.
   *
   * @return Gravity model type.
   */
  virtual GravityModel GetType() const = 0;
};
