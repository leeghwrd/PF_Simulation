#include "Input.h"


namespace lgh {

Input::Input(){}

Input::~Input(){}

bool Input::processEvents() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return false;
    }
  }

  return true;
}

}