target_sources(quadsim
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/SimulationTimeClock.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TimeManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UtcTimeClock.cpp
)

add_subdirectory(utils/)