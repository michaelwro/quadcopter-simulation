add_executable(math_utils_test
    ${CMAKE_CURRENT_SOURCE_DIR}/WrapPiDiv2.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrapTwoPi.test.cpp
)

add_dependencies(math_utils_test quadsim)

gtest_discover_tests(math_utils_test)
