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
      "Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    SDL_Quit();
    return 2;
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}