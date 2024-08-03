/**
 * @file TimeManager.hpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#pragma once

#include "time/CalendarTime_struct.hpp"
#include "time/SimulationTimeClock.hpp"
#include "time/UtcTimeClock.hpp"

/**
 * @brief Maintainer of all simulation clocks.
 */
class TimeManager {
public:
  TimeManager() = default;
  ~TimeManager() = default;

  /**
   * @brief Set the initial simulation UTC time.
   *
   * @param initUtcTime Initial UTC time.
   */
  void Initialize(const CalendarTime& initUtcTime);

  /**
   * @brief Increment the simulation's clocks by a timestep.
   *
   * @param dt_sec Period in [sec].
   */
  void Increment(const double dt_sec);

  /**
   * @brief Get the simulations's UTC clock.
   *
   * @return UTC clock instance.
   */
  const UtcTimeClock& GetUtcClock() const;

  /**
   * @brief Get the simulation's simulation epoch time clock.
   *
   * @return Sim epoch time clock.
   */
  const SimulationTimeClock& GetSimulationClock() const;

private:
  UtcTimeClock m_utcTimeClock {};         //!< UTC clock (primary clock).
  SimulationTimeClock m_simTimeClock {};  //!< Sim epoch time clock.
  CalendarTime m_initUtcTime {};          //!< Initial UTC time.
};
