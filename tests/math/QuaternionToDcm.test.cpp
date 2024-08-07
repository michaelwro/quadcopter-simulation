/**
 * @file QuaternionToDcm.test.cpp
 * @author Michael Wrona
 * @date 2024-08-06
 */

#include "math/QuaternionToDcm.hpp"

#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <cmath>

#include "spdlog/spdlog.h"

TEST(QuaternionToDcmTest, SchaubExample31_37) {
  const Quaternion quat(0.0, 1.0 / std::sqrt(2.0), 1.0 / std::sqrt(2.0), 0.0);

  const Eigen::Matrix3d expected {
      {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, -1.0}};

  const auto result = QuaternionToDcm(quat);

  // compare elements
  constexpr double tol = 1e-8;
  for (const std::size_t row : {0, 1, 2}) {
    for (const std::size_t col : {0, 1, 2}) {
      spdlog::info("R: {} C: {}", row, col);
      EXPECT_NEAR(expected(row, col), result(row, col), tol);
    }
  }
}

// https://www.mathworks.com/help/aerotbx/ug/dcm2quat.html
TEST(QuaternionToDcmTest, MathworksExample) {
  // form quaternion
  const Quaternion quat(0.8224, 0.2006, 0.5320, 0.0223);

  // form expected
  const Eigen::Matrix3d expected {{0.4330, 0.2500, -0.8660},
                                  {0.1768, 0.9186, 0.3536},
                                  {0.8839, -0.3062, 0.3536}};

  // compute result
  const auto result = QuaternionToDcm(quat);

  // compare elements
  constexpr double tol = 1e-3;
  for (const std::size_t row : {0, 1, 2}) {
    for (const std::size_t col : {0, 1, 2}) {
      spdlog::info("R: {} C: {}", row, col);
      EXPECT_NEAR(expected(row, col), result(row, col), tol);
    }
  }
}
