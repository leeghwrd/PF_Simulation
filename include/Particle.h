#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace lgh {

class Particle {
private:
  double x;
  double y;
  
public:
  Particle();
  ~Particle();

  // getter / setters
  void setX(double x);
  double getX();
  void setY(double x);
  double getY();
};

}

#endif