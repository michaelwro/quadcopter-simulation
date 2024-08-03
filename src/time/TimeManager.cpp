/**
 * @file TimeManager.cpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#include "time/TimeManager.hpp"

#include <cassert>

void TimeManager::Initialize(const CalendarTime& initUtcTime)
{
  m_initUtcTime = initUtcTime;

  m_utcTimeClock.SetCalendarTime(initUtcTime);
}

void TimeManager::Increment(const double dt_sec)
{
  assert(dt_sec > 0);

  m_utcTimeClock.Increment(dt_sec);
  m_simTimeClock.Increment(dt_sec);
}

const UtcTimeClock& TimeManager::GetUtcClock() const { return m_utcTimeClock; }

const SimulationTimeClock& TimeManager::GetSimulationClock() const
{
  return m_simTimeClock;
}
