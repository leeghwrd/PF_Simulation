#include "Particle.h"

#include <cstdlib>
#include <cmath>

namespace lgh {

// Particle Implementation

// Particle Constructor uses intializer list to set x and y coordinates to 0  
Particle::Particle(): x(0), y(0) {

  // draw particle initial random location
  init();
}

// Particle Destructor
Particle::~Particle() {}

// calculate speed and direction of particle
void Particle::init() {
  // reset x, and y location to 0
  x = 0;
  y = 0;

  direction = (2 * M_PI * rand()) / RAND_MAX;
  speed = (0.04 * rand()) / RAND_MAX;

  speed *= speed;
}

// update particle location with an interval calculation
void Particle::update(int &interval) {
  
  // set a curl affect on particle
  direction += interval * 0.0002;

  double xspeed = speed * std::cos(direction);
  double yspeed = speed * std::sin(direction);

  // proportional to last time moving particle
  x += xspeed * interval;
  y += yspeed * interval;

  // dont allow particles to go off screen, instead redraw
  // at new random location close to center of screen  
  if (x < -1 || x > 1 || y < -1 || y > 1) {
    init();
  }

  // redraw 1 out of 100 particles randomly 
  if(rand() < RAND_MAX / 100) {
    init();
  }
}

// getters / setters for x and y coordinates
void Particle::setX(double x) { x = x; }

double Particle::getX() { return x; }

void Particle::setY(double x) { y = y; }

double Particle::getY() { return y; }

} // namespace lgh