/**
 * @file Quaternion.test.cpp
 * @author Michael Wrona
 * @date 2024-08-04
 */

#include "math/Quaternion.hpp"

#include <gtest/gtest.h>

TEST(QuaternionTest, DefaultCtorIsUnity) {
  Quaternion q;

  EXPECT_DOUBLE_EQ(q.w(), 1.0);
  EXPECT_DOUBLE_EQ(q.x(), 0.0);
  EXPECT_DOUBLE_EQ(q.y(), 0.0);
  EXPECT_DOUBLE_EQ(q.z(), 0.0);
}

TEST(QuaternionTest, CtorNormalizes) {
  Quaternion q = Quaternion::Assign(4, 3, 2, 1);

  EXPECT_TRUE(q.w() != 4.0);
  EXPECT_TRUE(q.z() != 3.0);
  EXPECT_TRUE(q.y() != 2.0);
  EXPECT_TRUE(q.z() != 1.0);
}

TEST(QuaternionTest, Negates) {
  Quaternion q;

  q.Negate();

  EXPECT_DOUBLE_EQ(q.w(), -1.0);
  EXPECT_DOUBLE_EQ(q.x(), 0.0);
  EXPECT_DOUBLE_EQ(q.y(), 0.0);
  EXPECT_DOUBLE_EQ(q.z(), 0.0);
}

TEST(QuaternionTest, Inverts) {
  Quaternion q(1, 2, 3, 4);

  q.Invert();

  EXPECT_TRUE(q.w() > 0);
  EXPECT_TRUE(q.x() < 0);
  EXPECT_TRUE(q.y() < 0);
  EXPECT_TRUE(q.z() < 0);
}

TEST(QuaternionTest, ForcesPositiveRotation) {
  Quaternion q(-3, 2, 1, 1);

  q.ForcePositiveRotation();

  EXPECT_TRUE(q.w() > 0);
  EXPECT_TRUE(q.x() < 0);
  EXPECT_TRUE(q.y() < 0);
  EXPECT_TRUE(q.z() < 0);
}
