#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace lgh {

class Swarm {
private:
  Particle *particles;
  int lastTime;

public:
  Swarm();
  ~Swarm();
  void update(int elapsed);
  const static int NPARTICLES = 1000;
  Particle *getParticles();
};

}

#endif