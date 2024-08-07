/**
 * @file CrossProdMatrix.test.cpp
 * @author Michael Wrona
 * @date 2024-08-06
 */

#include "math/CrossProdMatrix.hpp"

#include <gtest/gtest.h>

#include <Eigen/Dense>

TEST(CrossProdMatrixTest, EquivalentToCrossProduct) {
  const Eigen::Vector3d a {-1, 2, 3};
  const Eigen::Vector3d b {4, -5, 6};

  const Eigen::Vector3d expected = a.cross(b);

  const Eigen::Vector3d result = CrossProdMatrix(a) * b;

  EXPECT_DOUBLE_EQ(expected(0), result(0));
  EXPECT_DOUBLE_EQ(expected(1), result(1));
  EXPECT_DOUBLE_EQ(expected(2), result(2));
}
