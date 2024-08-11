add_executable(math_test
    ${CMAKE_CURRENT_SOURCE_DIR}/CrossProdMatrix.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QuaternionToDcm.test.cpp
)

add_dependencies(math_test quadsim)

gtest_discover_tests(math_test)

add_subdirectory(utils/)
