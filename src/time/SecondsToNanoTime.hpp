/**
 * @file SecondsToNanoTime.hpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#pragma once

#include "time/NanoTime.hpp"

/**
 * @brief Convert [sec] to integer NanoTime.
 *
 * @param seconds Time in seconds.
 * @return NanoTime.
 */
NanoTime SecondsToNanoTime(const double seconds);
