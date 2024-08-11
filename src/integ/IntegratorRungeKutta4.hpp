/**
 * @file IntegratorRungeKutta4.hpp
 * @author Michael Wrona
 * @date 2024-07-30
 */

#pragma once

#include <spdlog/spdlog.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <tuple>

#include "integ/IIntegrableObject.hpp"
#include "time/TimeManager.hpp"

/**
 * @brief Integrate a system using the Runge Kutta 4th order (RK4) method.
 * @details https://lpsa.swarthmore.edu/NumInt/NumIntFourth.html
 *
 * @tparam N Number of states.
 * @param dt_sec Time step [sec].
 * @param timeManager Simulation time manager (copy, we'll mod the copy).
 * @param integObj Integrable object.
 * @param state Current state values.
 * @return {new state}, {derivatrive of new state}
 */
template <std::size_t N>
std::tuple<std::array<double, N>, std::array<double, N>> IntegrateRk4(
    const double dt_sec, const TimeManager& timeManager,
    std::shared_ptr<IIntegrableObject<N>> integObj,
    const std::array<double, N>& state) {
  // shorthand type
  using TypeStateVec = std::array<double, N>;

  // negative timestep is invalid
  assert(dt_sec > 0.0);

  /**
   * NOTE: using the square bracket operator should be fine since all arrays
   * have the same dimensions.
   */

  // calculate k1 = f(y0)
  TimeManager timeManagerK1 = timeManager;  // at t = t0

  TypeStateVec derivsK1 {};
  integObj->CalculateDerivatives(timeManagerK1, state, derivsK1);

  // calcualte k2 = f(y0 + (k1 * dt / 2))
  TypeStateVec theState = state;

  for (std::size_t idx = 0; idx < N; idx++) {
    theState[idx] = state[idx] + (0.5 * dt_sec * derivsK1[idx]);
  }

  TimeManager timeManagerK2 = timeManager;
  timeManagerK2.Increment(0.5 * dt_sec);  // at t = t0 + (h/2)

  TypeStateVec derivsK2 {};
  integObj->CalculateDerivatives(timeManagerK2, theState, derivsK2);

  // calculate k3 = f(y0 + (k2 * dt / 2))
  theState.fill(0.0);

  for (std::size_t idx = 0; idx < N; idx++) {
    theState[idx] = state[idx] + (0.5 * dt_sec * derivsK2[idx]);
  }

  TimeManager timeManagerK3 = timeManager;
  timeManagerK3.Increment(0.5 * dt_sec);  // at t = t0 + (h/2)

  TypeStateVec derivsK3 {};
  integObj->CalculateDerivatives(timeManagerK3, theState, derivsK3);

  // calculate k4 = f(y0 + (k3 * dt))
  theState.fill(0.0);

  for (std::size_t idx = 0; idx < N; idx++) {
    theState[idx] = state[idx] + (dt_sec * derivsK3[idx]);
  }

  TimeManager timeManagerK4 = timeManager;
  timeManagerK4.Increment(dt_sec);  // at t = t0 + h

  TypeStateVec derivsK4 {};
  integObj->CalculateDerivatives(timeManagerK4, theState, derivsK4);

  // calculate the integral result
  TypeStateVec stateResult {};

  for (std::size_t idx = 0; idx < N; idx++) {
    stateResult[idx] =
        state[idx] + ((dt_sec / 6.0) * (derivsK1[idx] + (2.0 * derivsK2[idx]) +
                                        (2.0 * derivsK3[idx]) + derivsK4[idx]));
  }

  // calculate the derivative of the state result
  TypeStateVec stateDerivResult {};
  integObj->CalculateDerivatives(stateResult, stateDerivResult);

  return std::make_tuple(stateResult, stateDerivResult);
}
