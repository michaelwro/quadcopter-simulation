/**
 * @file NanoTimeToSeconds.hpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#pragma once

#include "time/NanoTime.hpp"

/**
 * @brief Convert integer NanoTime to decimal seconds.
 *
 * @param time Nanosecond time.
 * @return Decimal seconds.
 */
double NanoTimeToSeconds(const NanoTime time);
