#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace lgh {

// Particle Definition  
class Particle {
private:

  // x, and y are for particle location
  double x;
  double y;

  // speed and direction handle the movement of particles on screen
  double speed;
  double direction;

  // recalculate location of random particles
  void init();

public:
  // constructor
  Particle();

  // destructor
  ~Particle();

  // update particles with interval
  // interval argument as a reference
  void update(int &interval);

  // getter / setters
  void setX(double x);
  double getX();
  void setY(double y);
  double getY();
};

}

#endif