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

} // namespace lgh