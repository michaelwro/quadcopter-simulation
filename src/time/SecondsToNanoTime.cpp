/**
 * @file SecondsToNanoTime.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/SecondsToNanoTime.hpp"

#include <cassert>
#include <cmath>

NanoTime SecondsToNanoTime(const double seconds)
{
  assert(seconds >= 0.0);
  return static_cast<NanoTime>(std::floor(seconds * 1e9));
}
