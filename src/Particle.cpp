#include "Particle.h"
#include <cstdlib>

namespace lgh {

Particle::Particle() {
  x = ((2.0 * std::rand()) / RAND_MAX) - 1;
  y = ((2.0 * std::rand()) / RAND_MAX) - 1;

}

Particle::~Particle() {

}

void Particle::setX(double x) { x = x; }

double Particle::getX() { return x; }

void Particle::setY(double x) { y = y; }

double Particle::getY() { return y; }

} // namespace lgh