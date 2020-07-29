#include "Swarm.h"

#include <iostream>

namespace lgh {

// Swarm class Implementation

// Constructor intializer list with lastTime set to 0 and
// allocates memory for particles array of the number of particles
Swarm::Swarm() : lastTime(0), particles(new Particle[NPARTICLES]) {
  std::cout << "Allocating memory for particles" << std::endl;
}

// Destructor releases memory for particles
Swarm::~Swarm() {
  std::cout << "Deallocating memory for particles" << std::endl;
  delete[] particles;
}

// return the amount of particles in swarm
Particle *Swarm::getParticles() { return particles; }

// calculate particles with number of particles in swarm
// NPARTICLES is set to '5000'
void Swarm::update(int elapsed) {
  int interval = elapsed - lastTime;

  for (int i = 0; i < Swarm::NPARTICLES; i++) {
    particles[i].update(interval);
  }

  // time since program started running
  lastTime = elapsed;
}

}  // namespace lgh