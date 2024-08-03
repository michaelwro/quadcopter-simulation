/**
 * @file SimulationTimeClock.hpp
 * @author Michael Wrona
 * @date 2024-07-19
 */

#pragma once

#include <cassert>

#include "time/IEpochTimeClock.hpp"
#include "time/NanoTime.hpp"
#include "time/utils/NanoTimeToSeconds.hpp"
#include "time/utils/SecondsToNanoTime.hpp"

/**
 * @brief Simulation time keeps track of the elapsed simulation seconds.
 */
class SimulationTimeClock : public IEpochTimeClock {
public:
  /**
   * @brief Create a `SimulationTimeClock` object.
   */
  SimulationTimeClock() = default;
  ~SimulationTimeClock() override = default;

  /**
   * @brief Increment simulation time by a timestep.
   *
   * @param dt_sec Period in [sec].
   */
  void Increment(const double dt_sec);

  /**
   * @brief Get the current number of simulation elapsed seconds.
   *
   * @return Simulation seconds.
   */
  double GetEpochSeconds() const override;

  /**
   * @brief Get the current number of simulation elapsed integer nanoseconds.
   *
   * @return Simulation nanoseconds.
   */
  NanoTime GetEpochNanoTime() const override;

private:
  double m_epochTime_sec {};     //!< Elapsed seconds.
  NanoTime m_epochTime_nsec {};  //!< Elapsed nanoseconds.
};
