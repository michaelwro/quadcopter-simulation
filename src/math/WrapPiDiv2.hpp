/**
 * @file WrapPiDiv2.hpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#pragma once

/**
 * @brief Wrap an angle to be within [-pi/2, pi/2) rad -> [-180, 180) deg.
 *
 * @param angle_rad Angle in [rad].
 * @return Angle wrapped within [-pi/2, pi/2).
 */
double WrapPiDiv2(const double angle_rad);
