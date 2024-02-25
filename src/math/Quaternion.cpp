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
#include <limits>

namespace sim {
namespace math {

Quaternion::Quaternion(const double qs, const double qx, const double qy,
                       const double qz) noexcept
    : q {qs, qx, qy, qz}
{
  // NORMALIZE
}

void Quaternion::normalize()
{
  // compute magnitude
  double magnitude = 0.0;

  for (std::size_t idx = 0; idx < size(); idx++) {
    magnitude += q[idx] * q[idx];
  }

  // verify no-zero magnitude (div-by-zero)
  assert(magnitude >= 8.0 * std::numeric_limits<double>::epsilon());

  // normalize elements
  const double inv_norm = 1.0 / std::sqrt(magnitude);

  for (std::size_t idx = 0; idx < size(); idx++) {
    q[idx] /= inv_norm;
  }
}

}  // namespace math
}  // namespace sim
