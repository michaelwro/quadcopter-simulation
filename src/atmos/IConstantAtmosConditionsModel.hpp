/**
 * @file IConstantAtmosConditionsModel.hpp
 * @author Michael Wrona
 * @date 2024-08-18
 */

#pragma once

#include "atmos/AtmosConditions_struct.hpp"

/**
 * @brief Constant atmospheric conditions model.
 */
class IConstantAtmosConditionsModel {
public:
  IConstantAtmosConditionsModel() = default;
  virtual ~IConstantAtmosConditionsModel() = default;

  /**
   * @brief Get the current conditions.
   */
  virtual AtmosConditions GetConditions() = 0;

  /**
   * @brief Get the current temperature in [C].
   *
   * @return Current temperature [C].
   */
  virtual double GetTemperature() const = 0;
  /**
   * @brief Get the current pressure [Pa].
   *
   * @return Pressure in [Pa].
   */
  virtual double GetPressure() const = 0;

  /**
   * @brief Get the current density in [kg/m^3].
   *
   * @return Current density [kg/m^3].
   */
  virtual double GetDensity() const = 0;
};
