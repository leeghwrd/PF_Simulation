#include <SDL2/SDL.h>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Simulator.h"

int main() {

  // Random seed generator for time
  std::srand(time(NULL));

  // create instance of simulator
  lgh::Simulator simulator;

  // create instance of input
  lgh::Input input;

  // execute simulator and poll for input
  simulator.run(input);

  return 0;
}