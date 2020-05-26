#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace lgh {

// Screen class definition

// Screen class handles creation of the os window
// it also creates the renderer, texture and buffer
// to plot pixels on the screen

class Screen {
public:
  // value set to not change 800x600 is common size for display
  const static int SCREEN_WIDTH = 800;
  const static int SCREEN_HEIGHT = 600;

private:
  // SDL member set to pointers
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;

  // buffer1 and buffer2 methods need access to 32 bits
  // rgba with each being 8 bits * 4 = 32bits
  Uint32 *buffer1;
  Uint32 *buffer2;

public:
  // constructor
  Screen();
  // destructor
  ~Screen();

  // update screen
  void update();
  // set pixel coordinate and color
  void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
  // add box blur effect to entire screen
  void boxBlur();

};

}  // namespace lgh

#endif // SCREEN_H_