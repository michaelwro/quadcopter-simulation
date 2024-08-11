/**
 * @file WrapTwoPi.hpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#pragma once

/**
 * @brief Wrap an angle to stay within [0, 2pi) rad -> [0, 360) deg.
 *
 * @param angle_rad Angle in radians.
 * @return Equivalent angle within [0, 2pi)
 */
double WrapTwoPi(const double angle_rad);
