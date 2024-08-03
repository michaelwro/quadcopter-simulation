/**
 * @file IIntegrableObject.hpp
 * @author Michael Wrona
 * @date 2024-07-30
 */

#pragma once

#include <vector>

class IIntegrableObject {
public:
  IIntegrableObject() = default;
  virtual ~IIntegrableObject() = default;

  virtual std::vector<double> CalculateDerivatives(const double dt_sec) = 0;

  virtual void GetIntegResult(const std::vector<double>& result,
                              const double dt_sec) = 0;

  virtual int GetId() const = 0;
};
