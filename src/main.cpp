#include <SDL2/SDL.h>

#include <iostream>

int main() {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL init failed!" << std::endl;
    return 1;
  }

  std::cout << "SDL init suceeded!" << std::endl;

  SDL_Window *window = SDL_CreateWindow(
      "Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    SDL_Quit();
    return 2;
  }

  // create renderer
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // create texture
  SDL_Texture *texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  // check if renderer creation is success
  if (renderer == NULL) {
    std::cout << "Could not create renderer" << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }

  // check if texture creation is success
  if (renderer == NULL) {
    std::cout << "Could not create texture" << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 4;
  }

  // allocate memory, every pixel requires 32bits
  Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

  // set all pixels to white using hexadecimal value 0xFF
  memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  // setup texture and renderer
  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  bool quit = false;

  SDL_Event event;

  while (!quit) {
    // Update particles
    // Draw particles
    // Check for messages/events
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  // free buffer allocated memory
  delete[] buffer;

  // destroy SDL resources and quit
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}