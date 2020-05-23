#include <SDL2/SDL.h>

#include <iostream>
#include <cmath>
#include "Screen.h"

int main() {
  lgh::Screen screen;

  if (screen.init() == false) {
    std::cout << "Error initializing SDL." << std::endl;
  }

  while (true) {
    // Update particles
    
    // draw particles
    int elapsed = SDL_GetTicks();
    unsigned char red = (unsigned char)((1 + std::sin(elapsed * 0.001)) * 128);
    unsigned char green = (unsigned char)((1 + std::sin(elapsed * 0.002)) * 128);
    unsigned char blue = (unsigned char)((1 + std::sin(elapsed * 0.003)) * 128);
    
    for (int x = 0; x < lgh::Screen::SCREEN_WIDTH; x++) {
      for (int y = 0; y < lgh::Screen::SCREEN_HEIGHT; y++) {
        screen.setPixel(x, y, red, green, blue);
      }
    }

    // single white pixel at center of screen
    screen.setPixel(400, 300, 255, 255, 255);

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