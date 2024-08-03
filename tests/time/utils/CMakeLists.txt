add_executable(test_time_utils
    CalendarTimeToIsoString.test.cpp
    NanoTimeToSeconds.test.cpp
    SecondsToNanoTime.test.cpp
)

add_dependencies(test_time_utils quadsim)

gtest_discover_tests(test_time_utils)
