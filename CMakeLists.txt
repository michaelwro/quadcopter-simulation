cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)

# Have cmake create a compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    QuadcopterSimulation
    VERSION 0.0.1
    DESCRIPTION "Quadcopter simulation"
    HOMEPAGE_URL "https://github.com/michaelwro/quadcopter-simulation"
    LANGUAGES CXX
)


file(GLOB HEADER_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/math/*.hpp})


add_executable(main src/main.cpp)



