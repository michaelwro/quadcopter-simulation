add_executable(test_time
    ${CMAKE_CURRENT_SOURCE_DIR}/UtcTimeClock.test.cpp
)

add_dependencies(test_time quadsim)

gtest_discover_tests(test_time)

add_subdirectory(utils/)
