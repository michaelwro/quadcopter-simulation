/**
 * @file Conversions.hpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#pragma once

#include "utils/constants.hpp"

/**
 * @brief Collections of unit conversions.
 */
class Conversions {
public:
  Conversions() = default;
  ~Conversions() = default;

  /**
   * @brief Convert an angle from radians to degrees.
   *
   * @param radians Angle in [rad].
   * @return Angle in [deg].
   */
  static inline constexpr double Rad2Deg(const double radians) {
    return radians * 180.0 / constants::pi;
  }

  /**
   * @brief Convert an angle from degrees to radians.
   *
   * @param degrees Angle ion [deg].
   * @return Angle in [rad].
   */
  static inline constexpr double Deg2Rad(const double degrees) {
    return degrees * constants::pi / 180.0;
  }
};
