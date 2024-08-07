/**
 * @file UtcTimeClock.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/UtcTimeClock.hpp"

#include <sofa.h>
#include <spdlog/spdlog.h>

#include <cassert>
#include <cmath>

#include "time/utils/CalendarTimeToIsoString.hpp"

void UtcTimeClock::Increment(const double dt_sec) {
  assert(dt_sec >= 0.0);

  // convert DT to days
  const double dt_days = dt_sec / 86400.0;

  // increment JD by dt
  m_julianDate += dt_days;
  assert(m_julianDate >= 0.0);

  // convert new UTC in JD to calendar components
  int yearOut {};
  int monthOut {};
  int dayOut {};
  double fracOfDayOut {};

  const int ret =
      iauJd2cal(m_julianDate, 0.0, &yearOut, &monthOut, &dayOut, &fracOfDayOut);

  if (ret != 0) {
    spdlog::error("Invalid JD date input to iauJd2cal(): {:0.6f}",
                  m_julianDate);
  }

  // convert day fraction to hours, minutes, and seconds
  char signOut {};
  int integersHmsfOut[4] {};

  /**
   * Resolution of calculation, number of decimal points in the second. Since
   * we're converting fraction of a day, 9 should be fine.
   */
  constexpr int numSecondDecPoints = 9;

  assert(fracOfDayOut >= 0.0);
  iauD2tf(numSecondDecPoints, fracOfDayOut, &signOut, integersHmsfOut);

  // assign values
  assert(yearOut > 0);
  assert(monthOut > 0);
  assert(dayOut > 0);

  assert(signOut == '+');           // sign
  assert(integersHmsfOut[0] >= 0);  // hour
  assert(integersHmsfOut[1] >= 0);  // minute
  assert(integersHmsfOut[2] >= 0);  // second
  assert(integersHmsfOut[3] >= 0);  // fraction of second

  // convert second + fraction of second into decimal seconds
  const double seconds =
      static_cast<double>(integersHmsfOut[2]) +
      (integersHmsfOut[3] * std::pow(10.0, -numSecondDecPoints));

  using CalUintType = std::uint16_t;

  m_calendarTime = {.year = static_cast<CalUintType>(yearOut),
                    .month = static_cast<CalUintType>(monthOut),
                    .day = static_cast<CalUintType>(dayOut),
                    .hour = static_cast<CalUintType>(integersHmsfOut[0]),
                    .minute = static_cast<CalUintType>(integersHmsfOut[1]),
                    .second = seconds};

  spdlog::trace("New UTC time: {}", CalendarTimeToIsoString(m_calendarTime));
}

void UtcTimeClock::SetCalendarTime(const CalendarTime &time) {
  spdlog::warn("Setting new UTC time: {}", CalendarTimeToIsoString(time));

  m_calendarTime = time;

  // convert YMD to Julian DAY
  double djm0Out {};
  double djmOut {};
  int ret = iauCal2jd(time.year, time.month, time.day, &djm0Out, &djmOut);

  if (ret != 0) {
    spdlog::error("Bad date input, got {} back.", ret);
  }

  assert(djm0Out >= 0.0);
  assert(djmOut >= 0.0);

  const double julianDay = djm0Out + djmOut;

  // convert HMS to fraction of day
  double fracOfDayOut {};
  ret = iauTf2d('+', time.hour, time.minute, time.second, &fracOfDayOut);

  if (ret != 0) {
    spdlog::error("Bad HMS input, got {} back.", ret);
  }

  assert(fracOfDayOut >= 0.0);

  // add integer and fractional parts together to compute total JD
  m_julianDate = julianDay + fracOfDayOut;

  spdlog::debug("New JD: {:0.6f}", m_julianDate);
}

CalendarTime UtcTimeClock::GetCalendarTime() const { return m_calendarTime; }

double UtcTimeClock::GetJulianDate() const { return m_julianDate; }
