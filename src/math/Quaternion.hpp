/**
 * @file Quaternion.hpp
 * @author Michael Wrona
 * @date 2024-08-04
 */

#pragma once

#include <Eigen/Dense>
#include <array>
#include <ostream>

/**
 * @brief Scalar-first, Schuster-convention transformation quaternion
 * implementation.
 */
class Quaternion {
public:
  /**
   * @brief Create a Quaternion.
   */
  Quaternion() = default;

  /**
   * @brief Create a Quaternion.
   *
   * @param w Scalar component.
   * @param x Vector x-component.
   * @param y Vector y-component.
   * @param z Vector z-component.
   */
  Quaternion(const double w, const double x, const double y, const double z);

  // default copy ctor and copy assign
  Quaternion(const Quaternion&) = default;
  Quaternion& operator=(const Quaternion&) = default;

  /**
   * @brief Quaternion move constructor. Resets other quaternion to unit
   * quaternion.
   *
   * @param other Other quaternion.
   */
  Quaternion(Quaternion&& other);

  /**
   * @brief Quaternion move assignment. Resets other quaternion to unit
   * quaternion.
   *
   * @param other Other quaternion.
   */
  Quaternion& operator=(Quaternion&& other);

  ~Quaternion() = default;

  /**
   * @brief Normalize quaternion values so that this is a unit quaternion.
   */
  void Normalize();

  /**
   * @brief Reset quaternion values to unity `[1, 0, 0, 0]`.
   */
  void Reset();

  /**
   * @brief Get the scalar component.
   *
   * @return Scalar component.
   */
  const double& w() const;

  /**
   * @brief Get the vector x-component.
   *
   * @return X-component.
   */
  const double& x() const;

  /**
   * @brief Get the vector y-component.
   *
   * @return Y-component.
   */
  const double& y() const;

  /**
   * @brief Get the vector z-component.
   *
   * @return Z-component.
   */
  const double& z() const;

  /**
   * @brief Create a new quaternion to assign values.
   *
   * @param w Scalar component.
   * @param x X-component.
   * @param y Y-component.
   * @param z Z-component.
   * @return New quaternion, NORMALIZED.
   */
  static Quaternion Assign(const double w, const double x, const double y,
                           const double z);

  /**
   * @brief Assign new values to this quaternion. Requires all elements to be
   * specified.
   *
   * @param w Scalar component.
   * @param x X-component.
   * @param y Y-component.
   * @param z Z-component.
   */
  void AssignElements(const double w, const double x, const double y,
                      const double z);

  /**
   * @brief Flip the sign of all quaternion elements. Multiplies all quaternion
   * elements by -1.
   */
  void Negate();

  /**
   * @brief Invert this quaternion / compute the conjugate.
   */
  void Invert();

  /**
   * @brief Get the inverse/conjugate of this quaternion.
   *
   * @return Quaternion inverse/conjugate.
   */
  Quaternion GetInverse() const;

  /**
   * @brief Force this quaternion to have a positive scalar component, which
   * corresponds to a positive rotation.
   */
  void ForcePositiveRotation();

  /**
   * @brief Transform a vector using this quaternion.
   *
   * `vec_a = quatAwrtB.Transform(vec_b);`
   *
   * @param vec Vector to transform.
   * @return Transformed vector.
   */
  Eigen::Vector3d Transform(const Eigen::Vector3d& vec) const;

private:
  /** @brief Underlying values, scalar first. */
  std::array<double, 4> m_quat {1, 0, 0, 0};
};

/**
 * @brief Quaternion multiplication. Schuster convention.
 * @details Multiplication from "Rotations, Transformations, Left
 * Quaternions, Right Quaternions" (R. Zanetti) equation 35.
 *
 * `quatAwrtC = quatAwrtB * quatBwrtC`
 *
 * @param q1 LHS quaternion.
 * @param q2 RHS quaternion.
 * @return Quaternion product.
 */
Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

/**
 * @brief Print a quaternion to a stream.
 *
 * @param[in,out] os Output stream
 * @param q The quaternion.
 * @return Stream with quaternion printed.
 */
std::ostream& operator<<(std::ostream& os, const Quaternion& q);
