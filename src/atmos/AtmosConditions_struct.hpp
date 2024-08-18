/**
 * @file AtmosConditions_struct.hpp
 * @author Michael Wrona
 * @date 2024-08-18
 */

#pragma once

/**
 * @brief Atmospheric conditions.
 */
struct AtmosConditions {
  double temperature_c;  //!< Temperature in [C]
  double pressure_pa;    //!< Pressure in [Pa]
  double density_kgpm3;  //!< Density in [kg/m^3]
};
