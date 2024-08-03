/**
 * @file SimulationTime.hpp
 * @author Michael Wrona
 * @date 2024-07-19
 */

#pragma once

#include "time/CalendarClocktime.hpp"

/**
 * IDEAS:
 * - Use TAI as base time system to base everything else off of?
 */
class SimulationTimeUtc {
public:
  SimulationTimeUtc() = default;
  ~SimulationTimeUtc() = default;

private:
  double m_simElapsedTime_sec {};
  double m_initialEpochTime_sec {};

  CalendarClockTime m_initialUtcTime;
};
