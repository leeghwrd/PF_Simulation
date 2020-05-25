#include "Particle.h"

#include <cstdlib>
#include <cmath>

namespace lgh {

Particle::Particle(): x(0), y(0) {
  init();
}

Particle::~Particle() {

}

void Particle::init() {
  x = 0;
  y = 0;

  direction = (2 * M_PI * rand()) / RAND_MAX;
  speed = (0.04 * rand()) / RAND_MAX;

  speed *= speed;
}

void Particle::update(int interval) {

  direction += interval * 0.0002;

  double xspeed = speed * std::cos(direction);
  double yspeed = speed * std::sin(direction);

  // proportional to last time moving particle
  x += xspeed * interval;
  y += yspeed * interval;

  if (x < -1 || x > 1 || y < -1 || y > 1) {
    init();
  }

  if(rand() < RAND_MAX / 100) {
    init();
  }
}

void Particle::setX(double x) { x = x; }

double Particle::getX() { return x; }

void Particle::setY(double x) { y = y; }

double Particle::getY() { return y; }

} // namespace lgh