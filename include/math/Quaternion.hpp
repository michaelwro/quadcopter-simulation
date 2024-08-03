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

/**
 * @brief Quaternion to represent orientation. Uses a scalar-first
 * representation.
 */
class Quaternion {
public:
  double values[4] {1.0, 0.0, 0.0, 0.0};  //!< (--) Quaternion values

public:
  Quaternion() = default;
  ~Quaternion() = default;

  Quaternion(const double qw, const double qx, const double qy,
             const double qz) noexcept;

  Quaternion(const Quaternion&) = default;
  Quaternion& operator=(const Quaternion&) = default;

  /**
   * @brief Move construct a Quaternion.
   *
   * @param other Other quaternion.
   */
  Quaternion(Quaternion&& other);

  /**
   * @brief Move assign a Quaternion.
   *
   * @param other Other quaternion.
   * @return This quaternion.
   */
  Quaternion& operator=(Quaternion&& other);

  /**
   * @brief Get the number of elements in the quaternion (four).
   *
   * @return Four.
   */
  static constexpr std::size_t size() { return 4; }

  /**
   * @brief Get a quaternion's value.
   *
   * @param index Quaternion index.
   * @return Quaternion value.
   */
  const double& operator()(const std::size_t index) const;

  /**
   * @brief Get the quaternion scalar component.
   *
   * @return Scalar component.
   */
  const double& w() const { return values[0]; };

  /**
   * @brief Get the quaternion X-component.
   *
   * @return X-component.
   */
  const double& x() const { return values[1]; };

  /**
   * @brief Get the quaternion Y-component.
   *
   * @return Y-component.
   */
  const double& y() const { return values[2]; };

  /**
   * @brief Get the quaternion Z-component.
   *
   * @return Z-component.
   */
  const double& z() const { return values[3]; };

  /**
   * @brief Assign elements to a quaternion. Normalizes input.
   *
   * @param qw Scalar component.
   * @param qx X-component.
   * @param qy Y-component.
   * @param qz Z-component.
   * @return The quaternion.
   */
  static Quaternion assign(const double qw, const double qx, const double qy,
                           const double qz);

  /**
   * @brief Normalize the quaternion.
   */
  void normalize();

  /**
   * @brief Invert/conjugate this quaternion.
   */
  void invert();

  /**
   * @brief Get the inverse/conjugate of this quaternion.
   *
   * @return Quaternion inverse/conjugate.
   */
  Quaternion getInverse() const;
};

/**
 * @brief Get Quaternion element with compile-time bounds checks.
 *
 * @tparam index Quaternion index.
 * @param quat The Quaternion.
 * @return Quaternion value.
 */
template <std::size_t index>
const double& get(const Quaternion& quat)
{
  static_assert(index < Quaternion::size(), "Invalid index.");
  return quat(index);
}

/**
 * @brief Multiply two quaternions. From Section 1.8 of "Aircraft Control and
 * Simulation (B. L. Stevens et. al.)."
 *
 * @param p First quaternion.
 * @param q Second quaternion.
 * @return Quaternion product.
 */
Quaternion operator*(const Quaternion& p, const Quaternion& q);

}  // namespace sim

#endif  // SIM_MATH_QUATERNION_HPP
