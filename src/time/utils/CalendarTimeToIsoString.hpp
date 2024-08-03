/**
 * @file CalendarTimeToIsoString.hpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#pragma once

#include <string>

#include "time/CalendarTime_struct.hpp"

/**
 * @brief Convert calendar time to a string.
 *
 * @param time Calendar time.
 * @param decimals Decimal precision, default 6.
 * @return Time formatted as a string.
 */
std::string CalendarTimeToIsoString(const CalendarTime& time,
                                    const int decimals = 6);
