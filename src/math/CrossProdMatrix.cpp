/**
 * @file CrossProdMatrix.cpp
 * @author Michael Wrona
 * @date 2024-08-06
 */

#include "math/CrossProdMatrix.hpp"

Eigen::Matrix3d CrossProdMatrix(const Eigen::Vector3d& vec) {
  Eigen::Matrix3d mat {
      {0.0, -vec(2), vec(1)}, {vec(2), 0.0, -vec(0)}, {-vec(1), vec(0), 0.0}};

  return mat;
}
