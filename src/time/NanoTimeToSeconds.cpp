/**
 * @file NanoTimeToSeconds.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/NanoTimeToSeconds.hpp"

double NanoTimeToSeconds(const NanoTime time)
{
  return static_cast<double>(time) / 1e9;
}
