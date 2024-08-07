/**
 * @file QuaternionToDcm.hpp
 * @author Michael Wrona
 * @date 2024-08-06
 */

#pragma once

#include <Eigen/Dense>

#include "math/Quaternion.hpp"

/**
 * @brief Convert a quaternion to the corresponding direction cosine matrix
 * (DCM)/transformation matrix, Schuster convention.
 * @details From https://sites.utexas.edu/renato/files/2022/07/Rotations.pdf
 *
 * @param q Quaternion to convert.
 * @return Quaternion converted to DCM.
 */
Eigen::Matrix3d QuaternionToDcm(const Quaternion& q);
