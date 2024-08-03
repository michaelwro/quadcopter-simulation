/**
 * @file SimulationTime.hpp
 * @author Michael Wrona
 * @date 2024-07-19
 */

#pragma once

// #include "time/IEpochTime.hpp"
#include "time/ICalendarTimeClock.hpp"
/**
 * @brief Simulation time is atomic time
 *
 */
class SimulationTime : public ICalendarTimeClock {
public:
  SimulationTime() = default;
  ~SimulationTime() = default;

  CalendarTime GetCalendarTime() const override;

  // double Get

private:
  // double m_simElapsedTime_sec {};
  // double m_initialEpochTime_sec {};

  // CalendarClockTime m_initialUtcTime;
};
