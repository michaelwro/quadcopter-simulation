/**
 * @file SimpleAtmosConditionsModel.hpp
 * @author Michael Wrona
 * @date 2024-08-18
 */

#pragma once

#include "atmos/AtmosConditions_struct.hpp"
#include "atmos/IConstantAtmosConditionsModel.hpp"
#include "utils/constants.hpp"

/**
 * @brief A simple atmosphere with constant conditions.
 */
class SimpleAtmosConditionsModel : public IConstantAtmosConditionsModel {
public:
  /**
   * @brief Construct a new SimpleAtmosConditionsModel object.
   */
  SimpleAtmosConditionsModel() = default;
  ~SimpleAtmosConditionsModel() = default;

  /**
   * @brief Set the pressure in [Pa].
   *
   * @param pressure_pa Pressure in [Pa].
   */
  void SetPressure(const double pressure_pa);

  /**
   * @brief Set the temperature in [C].
   *
   * @param temperature_c Temperature [C].
   */
  void SetTemperature(const double temperature_c);

  /**
   * @brief Set the density in [kg/m^3].
   *
   * @param density_kgpm3 Density [kg/m^3].
   */
  void SetDensity(const double density_kgpm3);

  /**
   * @brief Set the atmospheric conditions.
   *
   * @param conditions New conditions.
   */
  void Set(const AtmosConditions& conditions);

  /**
   * @brief Get the current conditions.
   */
  AtmosConditions GetConditions() override;

  /**
   * @brief Get the current temperature in [C].
   *
   * @return Current temperature [C].
   */
  double GetTemperature() const override;
  /**
   * @brief Get the current pressure [Pa].
   *
   * @return Pressure in [Pa].
   */
  double GetPressure() const override;

  /**
   * @brief Get the current density in [kg/m^3].
   *
   * @return Current density [kg/m^3].
   */
  double GetDensity() const override;

private:
  /**
   * @brief Current conditions. Defaults to 1962 US Standard Atmosphere values.
   */
  AtmosConditions m_conditions {
      .temperature_c = constants::atmos::standardTemperature_c,
      .pressure_pa = constants::atmos::standardPressure_pa,
      .density_kgpm3 = constants::atmos::standardDensity_kgpm3};
};
