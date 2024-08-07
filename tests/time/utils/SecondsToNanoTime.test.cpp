/**
 * @file SecondsToNanoTime.test.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/utils/SecondsToNanoTime.hpp"

#include <gtest/gtest.h>

#include "time/NanoTime.hpp"

TEST(SecondsToNanoTimeTest, Converts) {
  constexpr double input = 123456789.123;

  constexpr NanoTime expected = 123'456'789'123'000'000;
  const NanoTime result = SecondsToNanoTime(input);

  EXPECT_EQ(expected, result);
}

TEST(SecondsToNanoTimeDeathTest, AssertsOnNegativeInput) {
  constexpr double input = 123456789.123;

  NanoTime res {};
  EXPECT_DEBUG_DEATH({ res = SecondsToNanoTime(-1123.456); }, "");
}