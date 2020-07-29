#include <SDL2/SDL.h>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Simulator.h"

int main() {
  // random seed generator for time
  std::srand(time(NULL));

  // create instance of simulator
  lgh::Simulator simulator;

  // run simulator and poll for input
  simulator.run();

  return 0;
}