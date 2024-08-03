add_executable(time_utils_test
    CalendarTimeToIsoString.test.cpp
    NanoTimeToSeconds.test.cpp
    SecondsToNanoTime.test.cpp
)

add_dependencies(time_utils_test quadsim)

gtest_discover_tests(time_utils_test)
