#include "Particle.h"

#include <cstdlib>
#include <cmath>

namespace lgh {

Particle::Particle(): x(0), y(0) {
  direction = (2 * M_PI * rand()) / RAND_MAX;
  speed = (0.001 * rand()) / RAND_MAX;
}

Particle::~Particle() {

}

void Particle::update() {
  double xspeed = speed * std::cos(direction);
  double yspeed = speed * std::sin(direction);

  x += xspeed;
  y += yspeed;
}

void Particle::setX(double x) { x = x; }

double Particle::getX() { return x; }

void Particle::setY(double x) { y = y; }

double Particle::getY() { return y; }

} // namespace lgh