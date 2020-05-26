#include "Simulator.h"

namespace lgh {

Simulator::Simulator() {}

Simulator::~Simulator() {}

void Simulator::run(Input &input) {

  while (true) {

    int elapsed = SDL_GetTicks();
    
    swarm.update(elapsed);

    unsigned char red = (unsigned char)((1 + std::sin(elapsed * 0.0001)) * 128);
    unsigned char green = (unsigned char)((1 + std::sin(elapsed * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + std::sin(elapsed * 0.0003)) * 128);

    // populate partilces with amount of particles from NPARTICLES
    auto *particles = swarm.getParticles();

    for (int i = 0; i < swarm.NPARTICLES; i++) {
      auto particle = particles[i];
      int x = (particle.getX() + 1) * screen.SCREEN_WIDTH / 2;
      int y = particle.getY() * screen.SCREEN_WIDTH / 2 + screen.SCREEN_HEIGHT / 2;

      screen.setPixel(x, y, red, green, blue);
    }

    // run box blur algorithm
      screen.boxBlur();

    // draw screen
    screen.update();

    // check for messages/events
    if (input.processEvents() == false) {
      break;
    }
  }
}

}