/********************** B E G I N  T R I C K  H E A D E R **********************
PURPOSE: (Simulation time clock.)
LANGUAGE: (C++)
LIBRARY DEPENDENCIES: (
  (SimulationTime.cpp)
)
************************ E N D  T R I C K  H E A D E R ************************/

#include "time/SimulationTime.hpp"

#include "trick/exec_proto.h"

namespace sim {

/**
 * @details Calls `exec_get_sim_time()`
 */
void SimulationTime::Initialize() { time_sec = exec_get_sim_time(); }

/**
 * @details Calls `exec_get_sim_time()`
 */
void SimulationTime::Update() { time_sec = exec_get_sim_time(); }

double SimulationTime::GetSecondTime() const { return time_sec; }

}  // namespace sim
