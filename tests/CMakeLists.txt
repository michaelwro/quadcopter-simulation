cmake_minimum_required(VERSION 3.19)

project(
    quadsim_tests
    VERSION 0.0.0
    DESCRIPTION "Quadcopter simulation tests."
    HOMEPAGE_URL "https://github.com/michaelwro/quadcopter-simulation"
    LANGUAGES CXX
)

enable_testing()


# get googletest
include(CTest)
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest/
    GIT_TAG v1.15.0
)

FetchContent_MakeAvailable(googletest)

# for ll tests below this file
include_directories(${quadsim_INCLUDE_DIR})
link_libraries(GTest::gtest_main quadsim)


add_subdirectory(time/)
