/**
 * @file UtcTimeClock.hpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#pragma once

#include "time/CalendarTime_struct.hpp"
#include "time/ICalendarTimeClock.hpp"

class UtcTimeClock : public ICalendarTimeClock {
public:
  UtcTimeClock() = default;
  ~UtcTimeClock() = default;

  /**
   * @brief Increment the UTC time by a duration `dt`.
   *
   * @param dt_sec Timestep in [sec].
   */
  void Increment(const double dt_sec);

  /**
   * @brief Set a new calendar time. ONLY USE IF YOU KNOW WHAT YOU'RE DOING.
   *
   * @param time New calendar time.
   */
  void SetCalendarTime(const CalendarTime& time);

  /**
   * @brief Get the current calendar UTC time.
   *
   * @return Current UTC time.
   */
  CalendarTime GetCalendarTime() const override;

private:
  double m_julianDate {};          //!< Current UTC time as Julian date number
  CalendarTime m_calendarTime {};  //!< Current UTC calendar time
};
