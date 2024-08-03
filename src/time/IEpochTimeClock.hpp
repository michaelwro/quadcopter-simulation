/**
 * @file IEpochTimeClock.hpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#pragma once

#include "time/CalendarTime_struct.hpp"
#include "time/NanoTime.hpp"

/**
 * @brief Define a time source that determines time since an epoch.
 */
class IEpochTimeClock {
public:
  IEpochTimeClock() = default;
  virtual ~IEpochTimeClock() = default;

  /**
   * @brief Get the elapsed decimal seconds since this time system's epoch.
   *
   * @return Duration since epoch.
   */
  virtual double GetEpochSeconds() const = 0;

  /**
   * @brief Get the elapsed nanosecond time since this time system's epoch.
   *
   * @return Nanosecond duration since epoch.
   */
  virtual NanoTime GetEpochNanoTime() const = 0;
};
