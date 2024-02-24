/********************** B E G I N  T R I C K  H E A D E R **********************
PURPOSE: (Simulation time clock.)
LANGUAGE: (C++)
LIBRARY DEPENDENCIES: (
  (time/SimulationTime.cpp)
)
************************ E N D  T R I C K  H E A D E R ************************/

#ifndef SIM_TIME_SIMULATION_TIME_HPP
#define SIM_TIME_SIMULATION_TIME_HPP

namespace sim {

/**
 * @brief Clock to get simulation time.
 * @details Uses `exec_get_sim_time()` to get second time.
 */
class SimulationTime {
public:
  double time_sec {};  //!< (s) Simulation time

public:
  SimulationTime() = default;
  ~SimulationTime() = default;

  SimulationTime(const SimulationTime&) = delete;
  SimulationTime& operator=(const SimulationTime&) = delete;

  /**
   * @brief Initialize the simulation time.
   */
  void Initialize();

  /**
   * @brief Update simulation time.
   */
  void Update();

  /**
   * @brief Get simulation time in seconds.
   *
   * @return Simulation time [sec].
   */
  double GetSecondTime() const;
};

}  // namespace sim

#endif  // SIM_TIME_SIMULATION_TIME_HPP
