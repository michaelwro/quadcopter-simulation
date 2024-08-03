#include <spdlog/spdlog.h>

#include <Eigen/Dense>
#include <iostream>

int main()
{
  // NEED TO INSTALL FMT FOR LOGGER
  spdlog::set_level(spdlog::level::debug);  // Set global log level to debug
  spdlog::info("testing 123!!!");

  Eigen::Matrix2d m;
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = m(1, 0) + m(0, 1);

  std::cout << m << "\n";

  return 0;
}
