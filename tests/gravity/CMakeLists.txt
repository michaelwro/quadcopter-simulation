add_executable(gravity_test
    ${CMAKE_CURRENT_SOURCE_DIR}/J2Gravity.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SphericalGravity.test.cpp
)

add_dependencies(gravity_test quadsim)

gtest_discover_tests(gravity_test)