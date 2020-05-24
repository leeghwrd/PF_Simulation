#include "Swarm.h"

namespace lgh {

Swarm::Swarm(): lastTime(0) {
  particles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
  delete [] particles;
}

Particle *Swarm::getParticles() {
  return particles;
}

void Swarm::update(int elapsed) {
  
  int interval = elapsed - lastTime;

  for (int i = 0; i < Swarm::NPARTICLES; i++) {
    particles[i].update(interval);    
  }

  // time since program started running
  lastTime = elapsed;
}

} // namespace lgh