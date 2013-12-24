#include "Sandstorm.h"
#include <iostream>

Sandstorm::Sandstorm(int argc, char** argv): Game() {
  int width = 1440, height = 960;
  EventH = 1;
  
  WinMain = SDL_CreateWindow(argv[0], SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
  Renderer = SDL_CreateRenderer(WinMain, -1, SDL_RENDERER_SOFTWARE);
  Background = loadTexture("img/warning.png", Renderer);
  Joe = new Entity("img/joe.png", Renderer, 10, 280);
}
int Sandstorm::loop() {
  Uint32 timeout = SDL_GetTicks() + 16;
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_RIGHT]) {
    Joe->xv(4);
  } else if (state[SDL_SCANCODE_LEFT]) {
    Joe->xv(-4);
  } else {
    Joe->xv(0);
  }
  if (state[SDL_SCANCODE_V] && Joe->height() == 0)
    Joe->yv(-30);
  Joe->simulate();
  SDL_RenderCopyEx(Renderer, Background, NULL, NULL, Rot++, NULL, SDL_FLIP_NONE);
  SDL_RenderCopy(Renderer, Joe->texture(), NULL, Joe->pos(5));
  std::cout << "Joe x,y,vx,vy,height " << Joe->x() << ", " << Joe->y()
  << ", " << Joe->xv() << ", " << Joe->yv()
  << ", " << Joe->height() << std::endl;
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {}
  return 0;
}
int Sandstorm::event(SDL_Event e) {
  //std::cout << "Event:" << e.type << std::endl;
  switch (e.type) {
    case SDL_QUIT:
      Running = false;
      break;
  }
    
}
Sandstorm::~Sandstorm() {
  SDL_DestroyTexture(Background);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(WinMain);
}
