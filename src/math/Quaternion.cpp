/********************** B E G I N  T R I C K  H E A D E R **********************
PURPOSE: (Quaternion math utility.)
LANGUAGE: (C++)
LIBRARY DEPENDENCIES: (
  (Quaternion.cpp)
)
************************ E N D  T R I C K  H E A D E R ************************/

#include "math/Quaternion.hpp"

#include <cassert>
#include <cmath>
#include <initializer_list>
#include <limits>

namespace sim {

Quaternion::Quaternion(const double qw, const double qx, const double qy,
                       const double qz) noexcept
    : values {qw, qx, qy, qz}
{
  normalize();
}

/**
 * @details Other quaternion becomes a unit quaternion.
 */
Quaternion::Quaternion(Quaternion&& other)
{
  values[0] = other.values[0];
  other.values[0] = 1.0;

  for (std::size_t index : {1, 2, 3}) {
    values[index] = other.values[index];
    other.values[index] = 0.0;
  }
}

/**
 * @details Other quaternion becomes a unit quaternion.
 */
Quaternion& Quaternion::operator=(Quaternion&& other)
{
  values[0] = other.values[0];
  other.values[0] = 1.0;

  for (std::size_t index : {1, 2, 3}) {
    values[index] = other.values[index];
    other.values[index] = 0.0;
  }

  return *this;
}

Quaternion Quaternion::assign(const double qw, const double qx, const double qy,
                              const double qz)
{
  // NOTE: ctor normalizes
  return Quaternion(qw, qx, qy, qz);
}

/**
 * @details Includes runtime assert to check index.
 */
const double& Quaternion::operator()(const std::size_t index) const
{
  assert(index < Quaternion::size());
  return values[index];
}

void Quaternion::normalize()
{
  // compute magnitude
  double magnitude = 0.0;

  for (std::size_t idx = 0; idx < size(); idx++) {
    magnitude += values[idx] * values[idx];
  }

  // verify no-zero magnitude (div-by-zero)
  assert(magnitude >= std::numeric_limits<double>::epsilon());

  // normalize elements
  const double inv_norm = 1.0 / std::sqrt(magnitude);

  for (std::size_t idx = 0; idx < size(); idx++) {
    values[idx] /= inv_norm;
  }
}

void Quaternion::invert()
{
  values[1] *= -1.0;
  values[2] *= -1.0;
  values[3] *= -1.0;
}

Quaternion Quaternion::getInverse() const
{
  Quaternion quat(*this);
  quat.invert();
  return quat;
}

}  // namespace sim
