/**
 * @file CalendarTime_struct.hpp
 * @author Michael Wrona
 * @date 2024-07-19
 */

#pragma once

#include <cstdint>

/**
 * @brief Calendar and clock time - year, month, day, hour, minute, and seconds.
 */
struct CalendarTime {
  std::uint16_t year;    //!< Year number, ex: 2024
  std::uint16_t month;   //!< Month number [1 - 12]
  std::uint16_t day;     //!< Day number [1, 31]
  std::uint16_t hour;    //!< Hour number [0, 24)
  std::uint16_t minute;  //!< Minute number [0, 60)
  double second;         //!< Second number, plus decimal seconds [0, 60)
};
