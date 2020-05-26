#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>

namespace lgh {

class Input {
private:
  SDL_Event event;

public:
  Input();
  ~Input();

  bool processEvents();

};

}

#endif