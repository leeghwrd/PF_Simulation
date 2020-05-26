#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>

namespace lgh {

// Input class definition

// Input handles input from user
class Input {
private:
  // uses SDL for events
  SDL_Event event;

public:
  // constructor
  Input();
  // destructor
  ~Input();

  // processEvents method handles user input
  bool processEvents();

};

}

#endif