add_executable(transforms_test
    ${CMAKE_CURRENT_SOURCE_DIR}/GetDcmEcefWrtEci.test.cpp
)

add_dependencies(transforms_test quadsim)

gtest_discover_tests(transforms_test)
