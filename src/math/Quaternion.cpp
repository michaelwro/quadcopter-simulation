/**
 * @file Quaternion.cpp
 * @author Michael Wrona
 * @date 2024-08-04
 */

#include "math/Quaternion.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include "math/QuaternionToDcm.hpp"

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
  other.Reset();
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
  std::for_each(m_quat.begin(), m_quat.end(),
                [invNormSq](double& elm) { elm *= invNormSq; });
}

void Quaternion::Reset()
{
  m_quat[0] = 1.0;
  m_quat[1] = 0.0;
  m_quat[2] = 0.0;
  m_quat[3] = 0.0;
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
  std::for_each(m_quat.begin(), m_quat.end(), [](double& elm) { elm *= -1.0; });
}

void Quaternion::Invert()
{
  m_quat[1] *= -1.0;
  m_quat[2] *= -1.0;
  m_quat[3] *= -1.0;
}

Quaternion Quaternion::GetInverse() const
{
  Quaternion qInv = *this;
  qInv.Invert();
  return qInv;
}

void Quaternion::ForcePositiveRotation()
{
  if (m_quat[0] < 0.0) {
    Negate();
  }
}

Eigen::Vector3d Quaternion::Transform(const Eigen::Vector3d& vec) const
{
  // convert to DCM and return transformation
  const auto dcm = QuaternionToDcm(*this);
  return dcm * vec;
}

Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
  // get vector components
  const Eigen::Vector3d q1Vec(q1.x(), q1.y(), q1.z());
  const Eigen::Vector3d q2Vec(q2.x(), q2.y(), q2.z());

  // compute scalar component
  const double scalarPart = (q1.w() * q2.w()) - (q1Vec.dot(q2Vec));

  // compute vector part
  const Eigen::Vector3d vectorPart =
      (q1.w() * q2Vec) + (q2.w() * q1Vec) - q1Vec.cross(q2Vec);

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
