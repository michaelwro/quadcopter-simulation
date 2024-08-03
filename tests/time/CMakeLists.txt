add_executable(test_time
    CalendarTimeToIsoString.test.cpp
)

add_dependencies(test_time quadsim)

gtest_discover_tests(test_time)
