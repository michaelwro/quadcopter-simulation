/**
 * @file WrapTwoPi.test.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "math/utils/WrapTwoPi.hpp"

#include <gtest/gtest.h>

#include <limits>

#include "math/utils/WrapPiDiv2.hpp"
#include "utils/Conversions.hpp"

TEST(WrapTwoPiTest, WithinBoundsUnmodified) {
  const double angle = Conversions::Deg2Rad(170.0);
  const double result = WrapTwoPi(angle);

  EXPECT_DOUBLE_EQ(angle, result);
}

TEST(WrapTwoPiTest, AboveBoundsWrapped) {
  const double angle = Conversions::Deg2Rad(375);

  const double expected = Conversions::Deg2Rad(375 - 360);
  const double result = WrapTwoPi(angle);

  EXPECT_NEAR(expected, result, 5 * std::numeric_limits<double>::epsilon());
}

TEST(WrapTwoPiTest, NegativeBelowBoundsWrapped) {
  const double angle = Conversions::Deg2Rad(-35);

  const double expected = Conversions::Deg2Rad(360 - 35);
  const double result = WrapTwoPi(angle);

  EXPECT_DOUBLE_EQ(expected, result);
}
