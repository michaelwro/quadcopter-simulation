/**
 * @file GetDcmEcefWrtEci.hpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#pragma once

#include <Eigen/Dense>

#include "utils/constants.hpp"

/**
 * @brief Compute the ECI to ECEF DCM according to the simulation time.
 *
 * @param simElapsedTime_sec Current simulation elapsed time [sec].
 * @param earthAngVec_radps Current earth angular velocity [rad/s], DEFAULTS to
 * WGS84 constant rate.
 * @return ECI to ECEF DCM.
 */
Eigen::Matrix3d GetDcmEcefWrtEci(
    const double simElapsedTime_sec,
    const double earthAngVec_radps = constants::wgs84::angVelMagn_radps);
