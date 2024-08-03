cmake_minimum_required(VERSION 3.19)

project(
    quadsim
    VERSION 0.0.0
    DESCRIPTION "Quadcopter simulation."
    HOMEPAGE_URL "https://github.com/michaelwro/quadcopter-simulation"
    LANGUAGES CXX
)

# generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# cmake modules
include(FetchContent)

# define build config options
option(QUAD_WARNINGS_AS_ERRORS "Treat compilation warnings as errors." ON)
option(QUAD_ASAN "Enable address sanitizer builds." OFF)


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

# get eigen library
FetchContent_Declare(
    Eigen3
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
)

FetchContent_MakeAvailable(Eigen3)

# make our compile warnings not apply to eigen headers
# https://discourse.cmake.org/t/disable-warning-on-fetched-projects/1978/2
get_target_property(_inc Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(eigen SYSTEM INTERFACE ${_inc})

# get spdlog library
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.14.1
)

FetchContent_MakeAvailable(spdlog)

# create target and define options
add_executable(quadsim)

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

# set target compile options
target_compile_options(quadsim
    PRIVATE
        $<$<BOOL:QUAD_ASAN>:-fsanitize=address>
        $<$<BOOL:QUAD_WARNINGS_AS_ERRORS>:-Werror>
        $<$<CONFIG:Debug>:${quadsim_COMPILE_OPTIONS_DEBUG}>
        $<$<CONFIG:Release>:${quadsim_COMPILE_OPTIONS_RELEASE}>
)
        
target_compile_definitions(quadsim
    PRIVATE
        $<$<CONFIG:Debug>:${quadsim_COMPILE_DEFINITIONS_DEBUG}>
        $<$<CONFIG:Release>:${quadsim_COMPILE_DEFINITIONS_RELEASE}>
)
        
target_link_options(quadsim
    PRIVATE
        $<$<BOOL:QUAD_ASAN>:-fsanitize=address>
)

target_link_libraries(quadsim
    PUBLIC
        Eigen3::Eigen
        spdlog
)



