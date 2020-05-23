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
    // Draw particles
    // Check for messages/events
    if (screen.processEvents() == false) {
      break;
    }
  }

  screen.close();

  return 0;
}