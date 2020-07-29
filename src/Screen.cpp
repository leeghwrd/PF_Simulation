#include "Screen.h"

#include <iostream>

namespace lgh {

// Screen class Implementation

// Constructor use initializer list to set values to nullptr's
Screen::Screen()
    : window(nullptr),
      renderer(nullptr),
      texture(nullptr),
      buffer1(nullptr),
      buffer2(nullptr) {
  // error initialzing SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Failed to initialize SDL!" << std::endl;
    std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
  }

  // create window with no specific window postion, usually opens at center of
  // screen width and heiht values are 800x600, Set window title
  window = SDL_CreateWindow("Particle Fire Simulation", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  // quit program if window fails to intialize
  if (window == nullptr) {
    SDL_Quit();
  }

  // create renderer and use fallback software rendering
  // works locally and in udacity workspace without problems
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

  // check if renderer creation is success
  // if not destroy window and exit
  if (renderer == nullptr) {
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  // create texture and use pixel format as byte array
  texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  // check if texture creation is success
  // if not destroy render, window and then exit
  if (texture == nullptr) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  // sanity check that memory is being allocated
  std::cout << "Allocating memory for buffer1 and buffer2" << std::endl;

  // allocate memory, every pixel requires 32bits
  buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

  // set all pixels to black using hexadecimal value 0xFF
  memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
  memset(buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

Screen::~Screen() {
  // free buffer1 and buffer2 allocated memory
  std::cout << "Deallocating memory for buffer1 and buffer2" << std::endl;

  delete[] buffer1;
  delete[] buffer2;

  // destroy SDL resources and quit
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// set pixel coordinate and color using bit shifting operations
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
  // prevent pixels from plotting off the screen
  if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
    return;
  }

  Uint32 color = 0;

  // bit shift color values
  // results in values that
  // like: 0xFF003400, 0x123456

  // each color shifts 8 bits
  // until the final alpha value
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

// update screen texture and rendering via SDL
void Screen::update() {
  SDL_UpdateTexture(texture, NULL, buffer1, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

// implementation of box blur algorithm
// longer the pixel are on screen, more
// blur affect is added to them
void Screen::boxBlur() {
  // swap buffers so pixel info is in buffer2
  Uint32 *temp = buffer1;

  buffer1 = buffer2;
  buffer2 = temp;

  // iterate over all pixels
  for (int y = 0; y < SCREEN_HEIGHT; y++) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
      int redTotal = 0;
      int greenTotal = 0;
      int blueTotal = 0;

      // all pixels in entire row
      for (int row = -1; row <= 1; row++) {
        // all pixels in entire column
        for (int col = -1; col <= 1; col++) {
          int currentX = x + col;
          int currentY = y + row;

          // ignore pixels that arent on the screen
          if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 &&
              currentY < SCREEN_HEIGHT) {
            // access buffer that contains pixel info
            Uint32 color = buffer2[currentY * SCREEN_WIDTH + currentX];

            // get buffer2 pixel color value
            // using bit shifting

            // right shift by 24bit
            Uint8 red = color >> 24;
            // right shift by 16bit
            Uint8 green = color >> 16;
            // right shift by 8bit
            Uint8 blue = color >> 8;

            redTotal += red;
            greenTotal += green;
            blueTotal += blue;
          }
        }
      }

      // set actual color
      Uint8 red = redTotal / 9;
      Uint8 green = greenTotal / 9;
      Uint8 blue = blueTotal / 9;

      // set the final calculated pixel location and color
      setPixel(x, y, red, green, blue);
    }
  }
}

}  // namespace lgh