/**
 * @file GravityModel_enum.hpp
 * @author Michael Wrona
 * @date 2024-08-02
 */

#pragma once

#include <cstdint>

/**
 * @brief Gravity model type.
 */
enum class GravityModel : std::uint32_t {
  Spherical = 0  //!< Spherical model
};
