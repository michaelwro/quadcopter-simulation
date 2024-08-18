/**
 * @file SimpleAtmosConditionsModel.cpp
 * @author Michael Wrona
 * @date 2024-08-18
 */

#include "atmos/SimpleAtmosConditionsModel.hpp"

#include <spdlog/spdlog.h>

void SimpleAtmosConditionsModel::SetPressure(const double pressure_pa) {
  assert(pressure_pa > 0);
  m_conditions.pressure_pa = pressure_pa;
}

void SimpleAtmosConditionsModel::SetTemperature(const double temperature_c) {
  m_conditions.temperature_c = temperature_c;
}

void SimpleAtmosConditionsModel::SetDensity(const double density_kgpm3) {
  assert(density_kgpm3 > 0);
  m_conditions.density_kgpm3 = density_kgpm3;
}

void SimpleAtmosConditionsModel::Set(const AtmosConditions& conditions) {
  assert(conditions.pressure_pa > 0);
  assert(conditions.density_kgpm3 > 0);

  m_conditions = conditions;
}

AtmosConditions SimpleAtmosConditionsModel::GetConditions() {
  return m_conditions;
}

double SimpleAtmosConditionsModel::GetTemperature() const {
  return m_conditions.temperature_c;
}

double SimpleAtmosConditionsModel::GetPressure() const {
  return m_conditions.pressure_pa;
}

double SimpleAtmosConditionsModel::GetDensity() const {
  return m_conditions.density_kgpm3;
}
