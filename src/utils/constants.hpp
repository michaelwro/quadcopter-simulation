/**
 * @file constants.hpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#pragma once

#include <cmath>

namespace constants {

inline constexpr double pi = M_PI;           //!< pi constant
inline constexpr double piDiv2 = M_PI_2;     //!< pi / 2
inline constexpr double twoPi = 2.0 * M_PI;  //!< 2 * pi
inline constexpr double piDiv4 = M_PI_4;     //!< pi / 4

namespace wgs84 {
/**
 * @brief `mu = GM` gravity parameter [m^3/s^2].
 */
inline constexpr double gravParam_m3ps2 = 3.986'004'418e14;

/**
 * @brief Earth inertial angular velocity magnitude [rad/s].
 */
inline constexpr double angVelMagn_radps = 7.292'115'0e-5;

/**
 * @brief Earth `a` equatorial radius / ellipse semimajor axis [m].
 */
inline constexpr double semiMajorAxis_m = 6'378'137.0;

/**
 * @brief Ellipse flattening `f`.
 */
inline constexpr double flattening = 1.0 / 298.257'223'563;

/**
 * @brief Earth `b` polar radius / ellipse semimnor axis [m].
 */
inline constexpr double semiMinorAxis_m = semiMajorAxis_m * (1.0 - flattening);

/**
 * @brief Earth ellipse eccentricity.
 */
inline static const double eccentricity =
    std::sqrt((semiMajorAxis_m * semiMajorAxis_m) -
              (semiMinorAxis_m * semiMinorAxis_m)) /
    semiMajorAxis_m;

};  // namespace wgs84
};  // namespace constants
