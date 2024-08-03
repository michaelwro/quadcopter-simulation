target_sources(quadsim
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/CalendarTimeToIsoString.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/NanoTimeToSeconds.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SecondsToNanoTime.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UtcTimeClock.cpp
)