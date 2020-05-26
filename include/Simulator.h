#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <SDL2/SDL.h>
#include "Screen.h"
#include "Swarm.h"
#include "Input.h"

namespace lgh {

class Simulator {
private:
  Screen screen;
  Swarm swarm;

public:
  Simulator();
  ~Simulator();

  void run(Input &input);

};

}

#endif