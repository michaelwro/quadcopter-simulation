/**
 * @file CalendarTimeToIsoString.test.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/utils/CalendarTimeToIsoString.hpp"

#include <gtest/gtest.h>

#include <string>

#include "time/CalendarTime_struct.hpp"

/**
 * Expected ISO string length.
 * xx-xx-xxTxx:xx:xx.xxxxxx -> 26 chars
 */
constexpr int defaultIsoDecimals = 6;
constexpr int defaultIsoStrLen =
    4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + defaultIsoDecimals;

TEST(CalendarTimeToIsoStringTest, PrintsDateStrMixedPadding) {
  const CalendarTime time {.year = 2024,
                           .month = 9,
                           .day = 21,
                           .hour = 2,
                           .minute = 23,
                           .second = 45.123456};

  const std::string expected = "2024-09-21T02:23:45.123456";
  const std::string result = CalendarTimeToIsoString(time);

  EXPECT_STREQ(expected.c_str(), result.c_str());
  EXPECT_EQ(result.length(), defaultIsoStrLen);
}

TEST(CalendarTimeToIsoStringTest, ControlsDecimalPrecision) {
  const CalendarTime time {.year = 2069,
                           .month = 4,
                           .day = 20,
                           .hour = 16,
                           .minute = 20,
                           .second = 4.2};

  constexpr int decimals = 2;
  const std::string expected = "2069-04-20T16:20:04.20";
  const std::string result = CalendarTimeToIsoString(time, decimals);

  EXPECT_STREQ(expected.c_str(), result.c_str());
  EXPECT_EQ(result.length(),
            defaultIsoStrLen - (defaultIsoDecimals - decimals));
}
