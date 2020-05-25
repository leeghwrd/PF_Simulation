#include "Screen.h"

namespace lgh {

Screen::Screen()
    : window(nullptr),
      renderer(nullptr),
      texture(nullptr),
      buffer1(nullptr),
      buffer2(nullptr) {
        
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
  }

  window = SDL_CreateWindow("Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    SDL_Quit();
  }

  // create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // create texture
  texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  // check if renderer creation is success
  if (renderer == nullptr) {
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  // check if texture creation is success
  if (texture == nullptr) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  // allocate memory, every pixel requires 32bits
  buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

  // set all pixels to black using hexadecimal value 0xFF
  memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
  memset(buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

Screen::~Screen() {
  // free buffer1 and buffer2 allocated memory
  delete[] buffer1;
  delete[] buffer2;

  // destroy SDL resources and quit
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
  // prevent pixels from plotting off the screen
  if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
    return;
  }

  Uint32 color = 0;

  // bit shifting
  color += red;
  color <<= 8;
  color += green;
  color <<= 8;
  color += blue;
  color <<= 8;
  color += 0xFF;

  // set buffer1 with pixels
  buffer1[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::update() {
  // update texture and renderer
  SDL_UpdateTexture(texture, NULL, buffer1, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

bool Screen::processEvents() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return false;
    }
  }

  return true;
}

void Screen::boxBlur() {
  Uint32 *temp = buffer1;

  buffer1 = buffer2;
  buffer2 = temp;

  for (int y = 0; y < SCREEN_HEIGHT; y++) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
      int redTotal = 0;
      int greenTotal = 0;
      int blueTotal = 0;

      for (int row = -1; row <= 1; row++) {
        for (int col = -1; col <= 1; col++) {
          int currentX = x + col;
          int currentY = y + row;

          if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 &&
              currentY < SCREEN_HEIGHT) {
            Uint32 color = buffer2[currentY * SCREEN_WIDTH + currentX];

            // shift bits
            Uint8 red = color >> 24;
            Uint8 green = color >> 16;
            Uint8 blue = color >> 8;

            redTotal += red;
            greenTotal += green;
            blueTotal += blue;
          }
        }
      }

      Uint8 red = redTotal / 9;
      Uint8 green = greenTotal / 9;
      Uint8 blue = blueTotal / 9;

      setPixel(x, y, red, green, blue);
    }
  }
}

}  // namespace lgh