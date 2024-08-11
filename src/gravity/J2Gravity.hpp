/**
 * @file J2Gravity.hpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#pragma once

#include "gravity/GravityModel_enum.hpp"
#include "gravity/IGravityModel.hpp"

/**
 * @brief Compute earth gravitational acceleration with a J2 model.
 */
class J2Gravity : public IGravityModel {
public:
  /**
   * @brief Create a J2Gravity object.
   */
  J2Gravity() = default;
  virtual ~J2Gravity() = default;

  /**
   * @brief Compute the gravitational acceleration in the ECEF frame.
   *
   * @param positon_ecef_m Body ECEF position [m].
   * @return Gravitational acceleration [m/s^2].
   */
  Eigen::Vector3d GetAcceleration(
      const Eigen::Vector3d& positon_ecef_m) override;

  /**
   * @brief Get this model's type.
   *
   * @return Model type.
   */
  GravityModel GetType() const override;
};
