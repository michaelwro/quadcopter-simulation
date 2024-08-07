/**
 * @file QuaternionToRotMat.cpp
 * @author Michael Wrona
 * @date 2024-08-06
 */

#include "math/QuaternionToRotMat.hpp"

#include "math/CrossProdMatrix.hpp"

Eigen::Matrix3d QuaternionToDcm(const Quaternion& q) {
  const Eigen::Vector3d qvec {q.x(), q.y(), q.z()};
  const Eigen::Matrix3d qmat = CrossProdMatrix(qvec);

  return Eigen::Matrix3d::Identity() + (2.0 * q.w() * qmat) +
         (2.0 * qmat * qmat);
}
