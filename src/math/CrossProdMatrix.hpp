/**
 * @file CrossProdMatrix.hpp
 * @author Michael Wrona
 * @date 2024-08-06
 */

#pragma once

#include <Eigen/Dense>

/**
 * @brief Transform a vector to the matrix-form required to compute the vector
 * cross product by matrix-vector multiplication. Commonly denoted as `a x b =
 * A[x]b`.
 * https://groups.csail.mit.edu/graphics/classes/6.837/F01/Lecture09/Slide10.html
 *
 * @param vec Vector to transform into matrix.
 * @return Vector transformed to cross-product matrix.
 */
Eigen::Matrix3d CrossProdMatrix(const Eigen::Vector3d& vec);
