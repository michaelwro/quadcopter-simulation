/**
 * @file IIntegrableObject.hpp
 * @author Michael Wrona
 * @date 2024-07-30
 */

#pragma once

#include <array>
#include <cstddef>

#include "time/TimeManager.hpp"

/**
 * @brief Base class for integrable objects.
 *
 * @tparam N Number of state variables.
 */
template <std::size_t N>
class IIntegrableObject {
public:
  IIntegrableObject() = default;
  virtual ~IIntegrableObject() = default;

  /**
   * @brief Using the input state values and time manager, compute the state
   * variable derivatives.
   *
   * @param timeManager Time manager with the correct time at this timestep.
   * @param states State vector variables.
   * @param statesDeriv Derivative of state variables.
   */
  virtual void CalculateDerivatives(const TimeManager& timeManager,
                                    const std::array<double, N>& states,
                                    std::array<double, N>& statesDeriv) = 0;

  /**
   * @brief Get the number of integration state variables.
   * @return Number of states.
   */
  static constexpr std::size_t GetNumStates() { return N; };
};
