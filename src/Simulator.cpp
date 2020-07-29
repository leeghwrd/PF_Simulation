#include "Simulator.h"

namespace lgh {

// Simulator class Implementation

// Constructor
Simulator::Simulator() {}

// Destructor
Simulator::~Simulator() {}

// simulation loop, poll for user input
// input argument uses reference
void Simulator::run() {
  while (true) {
    // loop clock
    int elapsed = SDL_GetTicks();

    // update particles in swarm with each iteration of loop
    // with calculation of time elasped
    swarm.update(elapsed);

    // incrementally increase rgb values to a max of 255 using std::sin
    unsigned char red = (unsigned char)((1 + std::sin(elapsed * 0.0001)) * 128);
    unsigned char green =
        (unsigned char)((1 + std::sin(elapsed * 0.0002)) * 128);
    unsigned char blue =
        (unsigned char)((1 + std::sin(elapsed * 0.0003)) * 128);

    // populate partilces with amount of particles from NPARTICLES
    auto *particles = swarm.getParticles();
    for (int i = 0; i < swarm.NPARTICLES; i++) {
      // auto define particle from particles array
      auto particle = particles[i];

      // map particle space to screen space
      // place horizontally centered on screen
      int x = (particle.getX() + 1) * screen.SCREEN_WIDTH / 2;

      // map particle space to screen space vertically,
      // use different calculation due to height being 600px
      int y =
          particle.getY() * screen.SCREEN_WIDTH / 2 + screen.SCREEN_HEIGHT / 2;

      // set pixel color with each iteration of loop
      screen.setPixel(x, y, red, green, blue);
    }

    // run box blur algorithm on all pixels on screen
    screen.boxBlur();

    // update screen with each iteration of loop
    screen.update();

    // check for events (user input)
    if (input.processEvents() == false) {
      break;
    }
  }
}

}  // namespace lgh