#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace lgh {

class Swarm {
private:
  Particle *particles;

public:
  Swarm();
  ~Swarm();
  const static int NPARTICLES = 5000;
  Particle *getParticles();
};

}

#endif