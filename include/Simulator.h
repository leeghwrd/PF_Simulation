#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <SDL2/SDL.h>
#include "Screen.h"
#include "Swarm.h"
#include "Input.h"

namespace lgh {

// Simulator class definition

// this class runs the simulation program
class Simulator {
private:
  // private members instances for simulator
  Screen screen;
  Swarm swarm;

public:
  // constructor
  Simulator();

  // destructor
  ~Simulator();

  // starts main simulation loop
  // argument input uses reference
  void run(Input &input);

};

}

#endif