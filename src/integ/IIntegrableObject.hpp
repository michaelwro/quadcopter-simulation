/**
 * @file IIntegrableObject.hpp
 * @author Michael Wrona
 * @date 2024-07-30
 */

#pragma once

#include <array>
#include <cstddef>

template <std::size_t N>
class IIntegrableObject {
public:
  IIntegrableObject() = default;
  virtual ~IIntegrableObject() = default;

  virtual void CalculateDerivatives(const std::array<double, N>& states,
                                    std::array<double, N>& statesDeriv) = 0;

  static constexpr std::size_t GetNumStates() { return N; };
};
