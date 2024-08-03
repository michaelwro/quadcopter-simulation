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

/**
 * @brief Integrate a system using the Runge Kutta 4th order (RK4) method.
 * @details https://lpsa.swarthmore.edu/NumInt/NumIntFourth.html
 *
 * @tparam N Number of states.
 * @param dt_sec Time step [sec].
 * @param integObj Integrable object.
 * @param state Current state values.
 * @return {new state}, {derivatrive of new state}
 */
template <std::size_t N>
std::tuple<std::array<double, N>, std::array<double, N>> IntegrateRk4(
    const double dt_sec, std::shared_ptr<IIntegrableObject<N>> integObj,
    const std::array<double, N>& state)
{
  // shorthand type
  using TypeStateVec = std::array<double, N>;

  // negative timestep is invalid
  assert(dt_sec > 0.0);

  /**
   * NOTE: using the square bracket operator should be fine since all arrays
   * have the same dimensions.
   */

  // calculate k1 = f(y0)
  TypeStateVec derivsK1 {};
  integObj->CalculateDerivatives(state, derivsK1);

  // calcualte k2 = f(y0 + (k1 * dt / 2))
  TypeStateVec theState = state;

  for (std::size_t idx = 0; idx < N; idx++) {
    theState[idx] = state[idx] + (0.5 * dt_sec * derivsK1[idx]);
  }

  TypeStateVec derivsK2 {};
  integObj->CalculateDerivatives(theState, derivsK2);

  // calculate k3 = f(y0 + (k2 * dt / 2))
  theState.fill(0.0);

  for (std::size_t idx = 0; idx < N; idx++) {
    theState[idx] = state[idx] + (0.5 * dt_sec * derivsK2[idx]);
  }

  TypeStateVec derivsK3 {};
  integObj->CalculateDerivatives(theState, derivsK3);

  // calculate k4 = f(y0 + (k3 * dt))
  theState.fill(0.0);

  for (std::size_t idx = 0; idx < N; idx++) {
    theState[idx] = state[idx] + (dt_sec * derivsK3[idx]);
  }

  TypeStateVec derivsK4 {};
  integObj->CalculateDerivatives(theState, derivsK4);

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
