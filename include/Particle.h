#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace lgh {

class Particle {
private:
  double x;
  double y;
  double xSpeed;
  double ySpeed;

public:
  Particle();
  ~Particle();
  void update();

  // getter / setters
  void setX(double x);
  double getX();
  void setY(double y);
  double getY();
};

}

#endif