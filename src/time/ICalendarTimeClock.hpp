/**
 * @file ICalendarTimeClock.hpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#pragma once

#include "time/CalendarTime_struct.hpp"

/**
 * @brief A `CalendarTimeClock` determines time as year, month, day, etc.
 *
 */
class ICalendarTimeClock {
public:
  ICalendarTimeClock() = default;
  virtual ~ICalendarTimeClock() = default;

  /**
   * @brief Get the current calendar time (year, month, day, etc.).
   *
   * @return Current calendar time.
   */
  virtual CalendarTime GetCalendarTime() const = 0;
};
