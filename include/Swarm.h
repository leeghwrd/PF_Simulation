#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace lgh {

// Swarm class manages a collection of particles
// Swarm definition

class Swarm {
private:
  // collection of particles
  Particle *particles;
  // calculate time of program running
  int lastTime;

public:
  // constructor
  Swarm();
  
  // destructor
  ~Swarm();

  // calculate particles swarm and update 
  void update(int elapsed);
  
  // amount of particles to add to particle swarm
  const static int NPARTICLES = 1000;

  // getParticles returns particles 
  Particle *getParticles();
};

}

#endif