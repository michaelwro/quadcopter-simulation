add_executable(time_test
    ${CMAKE_CURRENT_SOURCE_DIR}/UtcTimeClock.test.cpp
)

add_dependencies(time_test quadsim)

gtest_discover_tests(time_test)

add_subdirectory(utils/)
