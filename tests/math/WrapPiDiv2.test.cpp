/**
 * @file WrapPiDiv2.test.cpp
 * @author Michael Wrona
 * @date 2024-08-11
 */

#include "math/WrapPiDiv2.hpp"

#include <gtest/gtest.h>

#include "math/WrapPiDiv2.hpp"
#include "utils/Conversions.hpp"

TEST(WrapPiDiv2Test, WithinBoundsUnmodified) {
  const double angle = Conversions::Deg2Rad(130.0);
  const double result = WrapPiDiv2(angle);

  EXPECT_DOUBLE_EQ(angle, result);
}

TEST(WrapPiDiv2Test, NegativeWithinBoundsUnmodified) {
  const double angle = Conversions::Deg2Rad(-83);
  const double result = WrapPiDiv2(angle);

  EXPECT_DOUBLE_EQ(angle, result);
}

TEST(WrapPiDiv2Test, AboveBoundsWrapped) {
  const double angle = Conversions::Deg2Rad(190);

  const double expected = Conversions::Deg2Rad(-170);
  const double result = WrapPiDiv2(angle);

  EXPECT_DOUBLE_EQ(expected, result);
}

TEST(WrapPiDiv2Test, NegativeBelowBoundsWrapped) {
  const double angle = Conversions::Deg2Rad(-200);

  const double expected = Conversions::Deg2Rad(160);
  const double result = WrapPiDiv2(angle);

  EXPECT_DOUBLE_EQ(expected, result);
}
