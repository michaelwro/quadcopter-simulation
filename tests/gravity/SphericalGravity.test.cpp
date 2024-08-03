/**
 * @file SphericalGravity.test.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "gravity/SphericalGravity.hpp"

#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "gravity/GravityModel_enum.hpp"

TEST(SphericalGravityTest, ReturnsCorrectType)
{
  SphericalGravity gravModel {};
  EXPECT_TRUE(gravModel.GetType() == GravityModel::Spherical);
}

TEST(SphericalGravityTest, MagnitudeSeemsAboutRight)
{
  SphericalGravity gravModel {};

  // generate a position
  constexpr double EARTH_RADIUS_M = 6378137.0;
  Eigen::Vector3d position {1, -1, 1};
  position = EARTH_RADIUS_M * position.normalized();

  // compute gravity
  const Eigen::Vector3d accelGrav_ecef_mps2 =
      gravModel.GetAcceleration(position);

  const double accelGrav_mps2 = accelGrav_ecef_mps2.norm();

  EXPECT_TRUE(accelGrav_mps2 > 9.7);
  EXPECT_TRUE(accelGrav_mps2 < 9.9);
}