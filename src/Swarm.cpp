#include "Swarm.h"

namespace lgh {

Swarm::Swarm() {
  particles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
  delete [] particles;
}

Particle *Swarm::getParticles() {
  return particles;
}

void Swarm::update() {
  for (int i = 0; i < Swarm::NPARTICLES; i++) {
    particles[i].update();    
  }
}

} // namespace lgh