/**
 * @file UtcTimeClock.test.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/UtcTimeClock.hpp"

#include <gtest/gtest.h>

#include "time/CalendarTime_struct.hpp"

class UtcTimeClockTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {}

  /**
   * Used the USNO JD <-> UT1 converter site.
   * https://aa.usno.navy.mil/data/JulianDate
   */
  const CalendarTime time = {.year = 2024,
                             .month = 7,
                             .day = 27,
                             .hour = 11,
                             .minute = 34,
                             .second = 56};

  static constexpr double timeJd = 2460518.982593;

  static constexpr double increment_sec {6.0};
  static constexpr double increment_days {increment_sec / 86400.0};

  const CalendarTime timeIncremented = {.year = 2024,
                                        .month = 7,
                                        .day = 27,
                                        .hour = 11,
                                        .minute = 35,
                                        .second = 2};

  static constexpr double timeJdIncremented {timeJd + increment_days};
};

TEST_F(UtcTimeClockTest, SetsTimeAndIncrements) {
  constexpr double toleranceJd = 1e-6;
  constexpr double toleranceSec = 1e-4;

  UtcTimeClock clock;

  // set time
  clock.SetCalendarTime(time);

  // check new JD
  EXPECT_NEAR(timeJd, clock.GetJulianDate(), toleranceJd);

  // increment
  constexpr double increment_sec = 6.0;
  constexpr double increment_days = increment_sec / 86400.0;

  clock.Increment(increment_sec);

  // check new JD
  EXPECT_NEAR(timeJdIncremented, clock.GetJulianDate(), toleranceJd);

  // check new time
  const auto newTime = clock.GetCalendarTime();

  EXPECT_EQ(timeIncremented.year, newTime.year);
  EXPECT_EQ(timeIncremented.month, newTime.month);
  EXPECT_EQ(timeIncremented.day, newTime.day);
  EXPECT_EQ(timeIncremented.hour, newTime.hour);
  EXPECT_EQ(timeIncremented.minute, newTime.minute);
  EXPECT_NEAR(timeIncremented.second, newTime.second, toleranceSec);
}