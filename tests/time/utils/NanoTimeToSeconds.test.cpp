/**
 * @file NanoTimeToSeconds.test.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/utils/NanoTimeToSeconds.hpp"

#include <gtest/gtest.h>

#include "time/NanoTime.hpp"

TEST(NanoTimeToSecondsTest, Converts)
{
  constexpr NanoTime input = 3'000'100'000'000;

  constexpr double expected = 3000.1;
  const double result = NanoTimeToSeconds(input);

  EXPECT_DOUBLE_EQ(expected, result);
}
