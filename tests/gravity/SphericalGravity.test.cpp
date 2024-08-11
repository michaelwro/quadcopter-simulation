/**
 * @file SphericalGravity.test.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "gravity/SphericalGravity.hpp"

#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "gravity/GravityModel_enum.hpp"
#include "utils/constants.hpp"

TEST(SphericalGravityTest, ReturnsCorrectType) {
  SphericalGravity gravModel {};
  EXPECT_TRUE(gravModel.GetType() == GravityModel::Spherical);
}

TEST(SphericalGravityTest, MagnitudeSeemsAboutRight) {
  SphericalGravity gravModel {};

  // generate a position
  Eigen::Vector3d position {1, -1, 1};
  position = constants::wgs84::semiMajorAxis_m * position.normalized();

  // compute gravity
  const Eigen::Vector3d accelGrav_ecef_mps2 =
      gravModel.GetAcceleration(position);

  const double accelGrav_mps2 = accelGrav_ecef_mps2.norm();

  EXPECT_TRUE(accelGrav_mps2 > 9.7);
  EXPECT_TRUE(accelGrav_mps2 < 9.9);
}

TEST(SphericalGravityTest, GravityIsDown) {
  // positon at equator
  Eigen::Vector3d position_ecef_m {constants::wgs84::semiMajorAxis_m, 0, 0};

  // compute gravity
  SphericalGravity model {};
  const auto gravity_ecef_mps2 = model.GetAcceleration(position_ecef_m);

  EXPECT_TRUE(gravity_ecef_mps2(0) < 0);
}
