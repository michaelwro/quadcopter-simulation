/**
 * @file GetDcmEcefWrtEci.test.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "transforms/GetDcmEcefWrtEci.hpp"

#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <limits>

#include "utils/constants.hpp"

TEST(GetDcmEcefWrtEciTest, SanityCheckSimple) {
  Eigen::Vector3d position_eci {1, 0, 0};

  // rotate 90 deg
  const double time_sec = 1.0;
  const double rate_radps = constants::piDiv2;

  const auto dcmEcefWrtEci = GetDcmEcefWrtEci(time_sec, rate_radps);

  const auto position_ecef = dcmEcefWrtEci * position_eci;

  const double tolerance = 5.0 * std::numeric_limits<double>::epsilon();

  EXPECT_NEAR(position_ecef(0), 0, tolerance);
  EXPECT_NEAR(position_ecef(1), -1, tolerance);
  EXPECT_NEAR(position_ecef(2), 0, tolerance);
}
