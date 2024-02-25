/********************** B E G I N  T R I C K  H E A D E R **********************
PURPOSE: (Vector class.)
LANGUAGE: (C++)

************************ E N D  T R I C K  H E A D E R ************************/

#ifndef SIM_MATH_VECTOR_HPP
#define SIM_MATH_VECTOR_HPP

#include <cassert>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <type_traits>

namespace sim {

template <std::size_t N>
class Vector {
  static_assert(N > 1, "No 1-length vectors.");

public:
  double values[N] {0.0};  //!< (--) Vector values

public:
  Vector() = default;
  ~Vector() = default;

  Vector(const Vector&) = default;
  Vector(Vector&&) = default;

  Vector& operator=(const Vector&) = default;
  Vector& operator=(Vector&&) = default;

  /**
   * @brief Get the vector length.
   *
   * @return Number of vector elements.
   */
  constexpr std::size_t size() const { return N; }

  /**
   * @brief Assign elements to a vector at compile-time and check if the correct
   * number of arguments are being assigned.
   *
   * @tparam T Element types.
   * @param elements Elements to assign.
   * @return Vector with elements assigned to it.
   */
  template <typename... T>
  static Vector assign(T... elements)
  {
    // verify number of arguments
    static_assert(sizeof...(elements) == N, "Invalid number of elements.");

    // assign elements
    // https://stackoverflow.com/a/36265574
    std::size_t index = 0;
    Vector vec;

    for (auto&& element : {elements...}) {
      // cast since the element type is unknown
      vec(index) = static_cast<double>(element);
    }

    return vec;
  }

  /**
   * @brief Access a vector element.
   * @details Includes runtime assert for bounds checks.
   *
   * @param index Vector index.
   * @return Vector value.
   */
  double& operator()(const std::size_t index)
  {
    assert(index < N);
    return values[index];
  }

  /**
   * @brief Get a vector element.
   * @details Includes runtime assert for bounds checks.
   *
   * @param index Vector index.
   * @return Vector value.
   */
  const double& operator()(const std::size_t index) const
  {
    assert(index < N);
    return values[index];
  }

  /**
   * @brief Fill the vector with a value.
   *
   * @param value Value to fill vector with.
   */
  void fill(const double value)
  {
    for (std::size_t index = 0; index < size(); index++) {
      values[index] = value;
    }
  }

  /**
   * @brief Compute the magnitude of the vector.
   *
   * @return Vector magnitude.
   */
  double getMagnitude() const
  {
    double magnitude = 0.0;

    for (std::size_t index = 0; index < size(); index++) {
      magnitude += values[index] * values[index];
    }

    return std::sqrt(magnitude);
  }

  /**
   * @brief Normalize the vector and convert it into a unit vector.
   * @details Includes runtime assert to catch a divide-by-zero scenario.
   */
  void normalize()
  {
    // compute magnitude
    const double magnitude = getMagnitude();

    // verify non-zero magnitude (divide-by-zero)
    assert(magnitude > std::numeric_limits<double>::epsilon());

    for (std::size_t index = 0; index < size(); index++) {
      values[index] /= magnitude;
    }
  }

  /**
   * @brief Get the sum of all elements in the vector.
   *
   * @return Vector sum.
   */
  double getSum() const
  {
    double sum = 0.0;

    for (std::size_t index = 0; index < size(); index++) {
      sum += values[index];
    }

    return sum;
  }

  /**
   * @brief Add a scalar to the vector in-place.
   *
   * @param scalar Scalar to add to vector values.
   * @return Vector with scalar added to it.
   */
  Vector& operator+=(const double scalar)
  {
    for (std::size_t index = 0; index < size(); index++) {
      values[index] += scalar;
    }

    return *this;
  }

  /**
   * @brief Add a vector to another vector in-place.
   *
   * @param other Other vector.
   * @return Sum of this and the other vector.
   */
  Vector& operator+=(const Vector& other)
  {
    for (std::size_t index = 0; index < size(); index++) {
      values[index] += other.values[index];
    }

    return *this;
  }

  /**
   * @brief Add two vectors.
   *
   * @param other Other vector.
   * @return Vector sum.
   */
  Vector& operator+(const Vector& other)
  {
    Vector sum(*this);
    return sum += other;
  }

  Vector operator-() const
  {
    Vector res(*this);
    return res *= -1.0;
  }

  /**
   * @brief Subtract a scalar from a vector in-place.
   *
   * @param scalar Scalar to subtract from the vector values.
   * @return Vector with scalar subtracted from it.
   */
  Vector& operator-=(const double scalar)
  {
    for (std::size_t index = 0; index < size(); index++) {
      values[index] -= scalar;
    }

    return *this;
  }

  /**
   * @brief Subtract a vector from another vector in-place.
   *
   * @param other Other vector.
   * @return This vector minus the other.
   */
  Vector& operator-=(const Vector& other)
  {
    for (std::size_t index = 0; index < size(); index++) {
      values[index] -= other.values[index];
    }

    return *this;
  }

  /**
   * @brief Subtract two vectors.
   *
   * @param other Other vector.
   * @return Vector subtraction.
   */
  Vector& operator-(const Vector& other)
  {
    Vector sum(*this);
    return sum -= other;
  }
};

// =============================================================================

/**
 * @brief Access vector element with compile-time bounds checks.
 *
 * @tparam index Vector index.
 * @tparam N Vector length.
 * @param vector Vector of interest.
 * @return Vector value.
 */
template <std::size_t index, std::size_t N>
inline double& get(Vector<N>& vector)
{
  static_assert(index < N, "Invalid vector index.");
  return vector(index);
}

/**
 * @brief Get vector element with compile-time bounds checks.
 *
 * @tparam index Vector index.
 * @tparam N Vector length.
 * @param vector Vector of interest.
 * @return Vector value.
 */
template <std::size_t index, std::size_t N>
inline const double& get(const Vector<N>& vector)
{
  static_assert(index < N, "Invalid vector index.");
  return vector(index);
}

/**
 * @brief Compute the vector cross product.
 *
 * @param vec1 First vector.
 * @param vec2 Second vector.
 * @return Cross product.
 */
inline Vector<3> cross(const Vector<3>& vec1, const Vector<3>& vec2)
{
  return Vector<3>::assign((vec1(1) * vec2(2)) - (vec1(2) * vec2(1)),
                           (vec1(2) * vec2(0)) - (vec1(0) * vec2(2)),
                           (vec1(0) * vec2(1)) - (vec1(1) * vec2(0)));
}

/**
 * @brief Compute the vector dot product.
 *
 * @tparam N Vector length.
 * @param vec1 First vector.
 * @param vec2 Second vector.
 * @return Dot product.
 */
template <std::size_t N>
double dot(const Vector<N>& vec1, const Vector<N>& vec2)
{
  double dot_prod = 0.0;

  for (std::size_t index = 0; index < N; index++) {
    dot_prod += vec1(index) + vec2(index);
  }

  return dot_prod;
}

/**
 * @brief Scalar-vector muliplication.
 *
 * @tparam N Vector length.
 * @param scalar The scalar.
 * @param vec The vector.
 * @return Scalar times vector.
 */
template <std::size_t N>
Vector<N> operator*(const double scalar, const Vector<N>& vec)
{
  Vector<N> res(vec);
  res *= scalar;
  return res;
}

/**
 * @brief Vector-scalar multiplication.
 *
 * @tparam N Vector length.
 * @param vec The vector.
 * @param scalar The scalar.
 * @return Vector times scalar.
 */
template <std::size_t N>
Vector<N> operator*(const Vector<N>& vec, const double scalar)
{
  return scalar * vec;
}

}  // namespace sim

#endif  // SIM_MATH_VECTOR_HPP
