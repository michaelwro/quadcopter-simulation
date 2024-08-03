/**
 * @file CalendarTimeToIsoString.cpp
 * @author Michael Wrona
 * @date 2024-07-28
 */

#include "time/utils/CalendarTimeToIsoString.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>

std::string CalendarTimeToIsoString(const CalendarTime& time,
                                    const int decimals)
{
  std::stringstream ss {};

  /**
   * Number of decimal second characters.
   * XX.XXXXXX = 9 chars
   */
  const int numDecSecChars = 2 + 1 + decimals;

  // format as ISO itme string.
  ss << std::setfill('0') << std::setw(4) << time.year;
  ss << "-";
  ss << std::setfill('0') << std::setw(2) << time.month;
  ss << "-";
  ss << std::setfill('0') << std::setw(2) << time.day;
  ss << "T";
  ss << std::setfill('0') << std::setw(2) << time.hour;
  ss << ":";
  ss << std::setfill('0') << std::setw(2) << time.minute;
  ss << ":";
  ss << std::fixed << std::setprecision(decimals) << std::setfill('0')
     << std::setw(numDecSecChars) << time.second;

  return ss.str();
}
