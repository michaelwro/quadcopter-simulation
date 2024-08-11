/**
 * @file J2Gravity.test.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "gravity/J2Gravity.hpp"

#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "gravity/GravityModel_enum.hpp"
#include "utils/constants.hpp"

TEST(J2GravityTest, ReturnsCorrectType) {
  J2Gravity gravModel {};
  EXPECT_TRUE(gravModel.GetType() == GravityModel::J2);
}

TEST(J2GravityTest, MagnitudeSeemsAboutRight) {
  J2Gravity gravModel {};

  // generate a position
  Eigen::Vector3d position {1, -1, -1};
  position = constants::wgs84::semiMajorAxis_m * position.normalized();

  // compute gravity
  const Eigen::Vector3d accelGrav_ecef_mps2 =
      gravModel.GetAcceleration(position);

  const double accelGrav_mps2 = accelGrav_ecef_mps2.norm();

  std::cout << accelGrav_mps2 << "\n";

  EXPECT_TRUE(accelGrav_mps2 > 9.7);
  EXPECT_TRUE(accelGrav_mps2 < 9.9);
}

TEST(J2GravityTest, GravityIsDown) {
  // positon at equator
  Eigen::Vector3d position_ecef_m {0, constants::wgs84::semiMajorAxis_m, 0};

  // compute gravity
  J2Gravity model {};
  const auto gravity_ecef_mps2 = model.GetAcceleration(position_ecef_m);

  EXPECT_TRUE(gravity_ecef_mps2(1) < 0);
}