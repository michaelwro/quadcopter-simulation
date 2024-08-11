add_executable(math_test
    ${CMAKE_CURRENT_SOURCE_DIR}/CrossProdMatrix.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QuaternionToDcm.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrapPiDiv2.test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrapTwoPi.test.cpp
)

add_dependencies(math_test quadsim)

gtest_discover_tests(math_test)
