/**
 * @file Quaternion.cpp
 * @author Michael Wrona
 * @date 2024-08-04
 */

#include "math/Quaternion.hpp"

#include <Eigen/Dense>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

Quaternion::Quaternion(const double w, const double x, const double y,
                       const double z)
    : m_quat {w, x, y, z}
{
  Normalize();
}

Quaternion::Quaternion(Quaternion&& other)
{
  m_quat[0] = std::exchange(other.m_quat[0], 1.0);
  m_quat[1] = std::exchange(other.m_quat[1], 0.0);
  m_quat[2] = std::exchange(other.m_quat[2], 0.0);
  m_quat[3] = std::exchange(other.m_quat[3], 0.0);
}

Quaternion& Quaternion::operator=(Quaternion&& other)
{
  m_quat = other.m_quat;
  other.AssignElements(1, 0, 0, 0);
  return *this;
}

void Quaternion::Normalize()
{
  const double normSq = std::accumulate(
      m_quat.cbegin(), m_quat.cend(), 0.0,
      [](double accumd, const double elm) { return accumd += elm * elm; });

  // div by zero check
  assert(normSq > std::numeric_limits<double>::epsilon());

  // normalize
  const double invNormSq = 1.0 / normSq;
  for (auto& elm : m_quat) {
    elm *= invNormSq;
  }
}

const double& Quaternion::w() const { return m_quat[0]; }
const double& Quaternion::x() const { return m_quat[1]; }
const double& Quaternion::y() const { return m_quat[2]; }
const double& Quaternion::z() const { return m_quat[3]; }

Quaternion Quaternion::Assign(const double w, const double x, const double y,
                              const double z)
{
  // ctor normalizes
  return {w, x, y, z};
}

void Quaternion::AssignElements(const double w, const double x, const double y,
                                const double z)
{
  m_quat = {w, x, y, z};
  Normalize();
}

void Quaternion::Negate()
{
  for (auto& elm : m_quat) {
    elm *= -1.0;
  }
}

void Quaternion::Invert()
{
  m_quat[1] *= -1.0;
  m_quat[2] *= -1.0;
  m_quat[3] *= -1.0;
}

Quaternion Quaternion::GetInverse() const
{
  return {m_quat[0], -m_quat[1], -m_quat[2], -m_quat[3]};
}

void Quaternion::ForcePositiveRotation()
{
  if (m_quat[0] < 0.0) {
    Negate();
  }
}

Quaternion operator*(const Quaternion& p, const Quaternion& q)
{
  // get vector components
  const Eigen::Vector3d pvec(p.x(), p.y(), p.z());
  const Eigen::Vector3d qvec(q.x(), q.y(), q.z());

  // compute scalar component
  const double scalarPart = (p.w() * q.w()) - (pvec.dot(qvec));

  // compute vector part
  const Eigen::Vector3d vectorPart =
      (p.w() * qvec) + (q.w() * pvec) - pvec.cross(qvec);

  // ctor normalizes
  return {scalarPart, vectorPart(0), vectorPart(1), vectorPart(2)};
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q)
{
  std::stringstream ss;

  ss << std::fixed << std::setprecision(std::numeric_limits<double>::digits10)
     << q.w() << ", " << q.x() << ", " << q.y() << ", " << q.z();

  os << ss.str();
  return os;
}
