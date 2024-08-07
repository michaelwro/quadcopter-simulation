/**
 * @file SimulationTimeClock.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "time/SimulationTimeClock.hpp"

void SimulationTimeClock::Increment(const double dt_sec) {
  // increment sim elapsed seconds
  const NanoTime dt_nsec = SecondsToNanoTime(dt_sec);
  m_epochTime_nsec += dt_nsec;
  m_epochTime_sec = NanoTimeToSeconds(m_epochTime_nsec);
}

double SimulationTimeClock::GetEpochSeconds() const { return m_epochTime_sec; }

NanoTime SimulationTimeClock::GetEpochNanoTime() const {
  return m_epochTime_nsec;
}
