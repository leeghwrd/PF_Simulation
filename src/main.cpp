#include <SDL2/SDL.h>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Screen.h"
#include "Swarm.h"

int main() {

  std::srand(time(NULL));

  lgh::Screen screen;

  if (screen.init() == false) {
    std::cout << "Error initializing SDL." << std::endl;
  }

  lgh::Swarm swarm;

  while (true) {
    // Update particles

    // draw particles

    int elapsed = SDL_GetTicks();
    unsigned char red = (unsigned char)((1 + std::sin(elapsed * 0.001)) * 128);
    unsigned char green = (unsigned char)((1 + std::sin(elapsed * 0.002)) * 128);
    unsigned char blue = (unsigned char)((1 + std::sin(elapsed * 0.003)) * 128);

    lgh::Particle *particles = swarm.getParticles();

    for (int i = 0; i < lgh::Swarm::NPARTICLES; i++) {
      lgh::Particle particle = particles[i];
      int x = (particle.getX() + 1) * lgh::Screen::SCREEN_WIDTH / 2;
      int y = (particle.getY() + 1) * lgh::Screen::SCREEN_HEIGHT / 2;

    screen.setPixel(x, y, red, green, blue);
    
    }

    // draw screen
    screen.update();

    // Check for messages/events
    if (screen.processEvents() == false) {
      break;
    }
  }

  screen.close();

  return 0;
}