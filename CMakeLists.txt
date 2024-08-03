cmake_minimum_required(VERSION 3.19)

project(
    quadsim
    VERSION 0.0.0
    DESCRIPTION "Quadcopter simulation."
    HOMEPAGE_URL "https://github.com/michaelwro/quadcopter-simulation"
    LANGUAGES C CXX
)

# generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# cmake modules
include(FetchContent)

# define build config options
option(QUAD_WARNINGS_AS_ERRORS "Treat compilation warnings as errors." ON)
option(QUAD_ASAN "Enable address sanitizer." OFF)
option(QUAD_BUILD_TESTING "Build tests." ON)


# set compilation output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# define compile options
# picked from Lefticus' recommendations:
# https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md#gcc--clang
set(quadsim_COMPILE_OPTIONS_BASE
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

set(quadsim_COMPILE_OPTIONS_DEBUG ${quadsim_COMPILE_OPTIONS_BASE} -O0 -g3)
set(quadsim_COMPILE_OPTIONS_RELEASE ${quadsim_COMPILE_OPTIONS_BASE} -O2 -g0)

# define compile definitions
set(quadsim_COMPILE_DEFINITIONS_BASE "")
set(quadsim_COMPILE_DEFINITIONS_DEBUG ${quadsim_COMPILE_DEFINITIONS_BASE})
set(quadsim_COMPILE_DEFINITIONS_RELEASE
    ${quadsim_COMPILE_DEFINITIONS_BASE} NDEBUG
)

# enable the address sanitizer for all targets here and below
# needs to get set before defining any targets
if(${QUAD_ASAN})
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

# get eigen library
# follows https://stackoverflow.com/a/77210377
FetchContent_Declare(
    Eigen3 SYSTEM
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
    GIT_SHALLOW TRUE
    SOURCE_SUBDIR cmake
)

FetchContent_MakeAvailable(Eigen3)

if(NOT TARGET Eigen3::Eigen)
    add_library(Eigen3::Eigen INTERFACE IMPORTED)
    set_target_properties(Eigen3::Eigen PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${eigen3_SOURCE_DIR})
endif()

# get spdlog library
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.14.1
)

FetchContent_MakeAvailable(spdlog)

# build 3rd party libs
add_subdirectory(lib/)

# create target and define options
add_library(quadsim STATIC)
add_subdirectory(src/)

set_target_properties(quadsim PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_features(quadsim
    PUBLIC
        cxx_std_20
        cxx_constexpr
)

set(quadsim_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)

target_include_directories(quadsim
    PUBLIC
        ${quadsim_INCLUDE_DIR}
        ${sofa_INCLUDE_DIRECTORY}
)

target_compile_options(quadsim
    PRIVATE
        $<$<BOOL:QUAD_WARNINGS_AS_ERRORS>:-Werror>
        $<$<CONFIG:Debug>:${quadsim_COMPILE_OPTIONS_DEBUG}>
        $<$<CONFIG:Release>:${quadsim_COMPILE_OPTIONS_RELEASE}>
)

target_compile_definitions(quadsim
    PRIVATE
        $<$<CONFIG:Debug>:${quadsim_COMPILE_DEFINITIONS_DEBUG}>
        $<$<CONFIG:Release>:${quadsim_COMPILE_DEFINITIONS_RELEASE}>
)

target_link_libraries(quadsim
    PUBLIC
        Eigen3::Eigen
        sofa
        spdlog
)

# add testing
if(${QUAD_BUILD_TESTING})
    enable_testing()
    add_subdirectory(tests/)
endif()
