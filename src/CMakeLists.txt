# TOP-LEVEL PROJECT DEFINITIONS ================================================
cmake_minimum_required(VERSION 3.12)

# define the C++ standard
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()

# define project metadata
project(
    QuadcopterSimulation
    VERSION 0.0.0
    DESCRIPTION "Quadcopter simulation"
    HOMEPAGE_URL "https://github.com/michaelwro/quadcopter-simulation"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# cmake modules
include(FetchContent)


# PROJECT-WIDE CONFIGURATIONS & DEFINITIONS ====================================
# define build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Debug or Release" FORCE)
endif()

# treat warnings as errors
option(QUAD_WARNINGS_AS_ERRORS "Treat compilation warnings as errors." ON)

# build tests
option(QUAD_BUILD_TESTS "Build tests." ON)

# set compilation dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# COMPILATION OPTIONS & DEFINITIONS ============================================
# define compile options
# from lefticus' site:
# https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md#gcc--clang
set(quad_COMPILE_OPTIONS_BASE
    -pedantic
    -Wall
    -Wcast-align
    -Wconversion
    -Wextra
    -Wformat=2
    -Wimplicit-fallthrough
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpedantic
    -Wshadow
    -Wsign-conversion
    -Wunused
)

set(quad_COMPILE_OPTIONS_DEBUG ${quad_COMPILE_OPTIONS_BASE} -O0 -g3)
set(quad_COMPILE_OPTIONS_RELEASE ${quad_COMPILE_OPTIONS_BASE} -O1)

set(quad_COMPILE_DEFINITIONS_BASE SPDLOG_LEVEL_WARNING)
set(quad_COMPILE_DEFINITIONS_DEBUG ${quad_COMPILE_DEFINITIONS_BASE})
set(quad_COMPILE_DEFINITIONS_RELEASE ${quad_COMPILE_DEFINITIONS_BASE} NDEBUG)

# GET 3RD PARTY DEPS ===========================================================
FetchContent_Declare(
    Eigen3
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
)

FetchContent_MakeAvailable(Eigen3)


FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.14.1
)

FetchContent_MakeAvailable(spdlog)

# # BUILD SOFA LIBRARY ===========================================================
# add_subdirectory(lib/sofa/)
# # set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/sofa)
# # find_package(sofa)

# CREATE EXECUTABLE & ADD SOURCES ==============================================
add_executable(quad)

add_subdirectory(src/)

# CONFIGURE TARGET =============================================================
target_compile_features(quad PUBLIC cxx_std_17)

target_compile_options(quad
    PRIVATE
        $<$<BOOL:QUAD_WARNINGS_AS_ERRORS>:-Werror>
        $<$<CONFIG:Debug>:${quad_COMPILE_OPTIONS_DEBUG}>
        $<$<CONFIG:Release>:${quad_COMPILE_OPTIONS_RELEASE}>
)

target_compile_definitions(quad
    PRIVATE
        $<$<CONFIG:Debug>:${quad_COMPILE_DEFINITIONS_DEBUG}>
        $<$<CONFIG:Release>:${quad_COMPILE_DEFINITIONS_RELEASE}>
)

target_include_directories(quad
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${SOFA_INCLUDE_DIRECTORY}
)


target_link_libraries(quad
    PUBLIC
        Eigen3::Eigen
        spdlog
        sofa
        # ${CMAKE_CURRENT_SOURCE_DIR}/lib/sofa/build/lib/libsofa.a
)

# fuck you Eigen
# https://discourse.cmake.org/t/disable-warning-on-fetched-projects/1978/2
get_target_property(_inc Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(eigen SYSTEM INTERFACE ${_inc})



















