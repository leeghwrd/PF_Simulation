#include "Input.h"


namespace lgh {

// Input class Implementation

// Constructor
Input::Input(){}

// Destructor
Input::~Input(){}

// process events returns false which causes program
// loop to exit when window is closed by user
bool Input::processEvents() {
  // argument event uses reference
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return false;
    }
  }
  // if user doesnt close window program keeps running
  return true;
}

}