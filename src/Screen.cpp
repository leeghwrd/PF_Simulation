#include "Screen.h"

namespace lgh {

Screen::Screen()
    : window(NULL), renderer(NULL), texture(NULL), buffer(NULL) {}

Screen::~Screen() {}

bool Screen::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return false;
  }

  window = SDL_CreateWindow("Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    SDL_Quit();
    return false;
  }

  // create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // create texture
  texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  // check if renderer creation is success
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return false;
  }

  // check if texture creation is success
  if (renderer == NULL) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return false;
  }

  // allocate memory, every pixel requires 32bits
  buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

  // set all pixels to black using hexadecimal value 0xFF
  memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  // set RGBA values - currently green
  for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
    buffer[i] = 0x00FF80FF;
  }

  // setup texture and renderer
  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  return true;
}

bool Screen::processEvents() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return false;
    }
  }

  return true;
}

void Screen::close() {
  // free buffer allocated memory
  delete[] buffer;

  // destroy SDL resources and quit
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

}  // namespace lgh