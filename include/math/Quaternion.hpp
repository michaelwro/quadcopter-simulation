/********************** B E G I N  T R I C K  H E A D E R **********************
PURPOSE: (Quaternion math utility.)
LANGUAGE: (C++)
LIBRARY DEPENDENCIES: (
  (math/Quaternion.cpp)
)
************************ E N D  T R I C K  H E A D E R ************************/

#ifndef SIM_MATH_QUATERNION_HPP
#define SIM_MATH_QUATERNION_HPP

#include <cstddef>

namespace sim {
namespace math {

class Quaternion {
public:
  double q[4] {1, 0, 0, 0};  //!< (--) Quaternion values

public:
  Quaternion() = default;
  ~Quaternion() = default;

  Quaternion(const double qs, const double qx, const double qy,
             const double qz) noexcept;

  constexpr std::size_t size() const noexcept { return 4; }

  void normalize();
};

}  // namespace math
}  // namespace sim

#endif  // SIM_MATH_QUATERNION_HPP
