#include <SDL2/SDL.h>

#include <iostream>

#include "Screen.h"

int main() {
  lgh::Screen screen;

  if (screen.init() == false) {
    std::cout << "Error initializing SDL." << std::endl;
  }

  bool quit = false;

  while (!quit) {
    // Update particles
    
    // draw particles
    for (int x = 0; x < lgh::Screen::SCREEN_WIDTH; x++) {
      for (int y = 0; y < lgh::Screen::SCREEN_HEIGHT; y++) {
        screen.setPixel(x, y, 128, 0, 255);
      }
    }

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