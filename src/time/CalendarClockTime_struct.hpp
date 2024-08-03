/**
 * @file CalendarClockTime_struct.hpp
 * @author Michael Wrona
 * @date 2024-07-19
 */

#pragma once

#include <cstdint>

/**
 * @brief Calendar and clock time - year, month, day, hour, minute, and seconds.
 */
struct CalendarClockTime {
  std::uint16_t year;    //!< Year number
  std::uint16_t month;   //!< Month number
  std::uint16_t day;     //!< Day number
  std::uint16_t hour;    //!< Hour number
  std::uint16_t minute;  //!< Minute number
  double second;         //!< Second number, plus decimal seconds
};
