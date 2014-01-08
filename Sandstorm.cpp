#include "Sandstorm.h"
#include <iostream>

Sandstorm::Sandstorm(int argc, char** argv): Game() {
  int width = 1440, height = 960;
  EventH = 1;
  
  WinMain = SDL_CreateWindow(argv[0], 30, 30, width, height, 0);
  Renderer = SDL_CreateRenderer(WinMain, -1, SDL_RENDERER_ACCELERATED);
  Background = loadTexture("img/warning.png", Renderer);
  CurrentLevel = new Platforms();
  Joe = new Entity("img/joe.png", Renderer, 10, 800, CurrentLevel);
}

int Sandstorm::loop() {
  Uint32 timeout = SDL_GetTicks() + 16;
  controls();
  simulate();
  render();
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
  return 0;
}

int Sandstorm::controls() {
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_RIGHT]) {
    Joe->xv(4);
  } else if (state[SDL_SCANCODE_LEFT]) {
    Joe->xv(-4);
  } else {
    Joe->xv(0);
  }
  if (state[SDL_SCANCODE_V])
    Joe->jump();
  if (state[SDL_SCANCODE_C]) {
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    std::cout << "Mouse x,y (" << mx << ", " << my << ")" << std::endl;
    Sprite* temp = new Sprite("img/cat.png", Renderer, mx, my);
    if (SpriteNum > 99)
      SpriteNum = 0;
    Sprites[SpriteNum] = temp;
    SpriteNum++;
  }
  return 0;
}

int Sandstorm::simulate() {
  Joe->simulate();
  return 0;
}

int Sandstorm::render() {
  SDL_RenderCopyEx(Renderer, Background, NULL, NULL, Rot++, NULL, SDL_FLIP_NONE);
  for(int i = 0; i < SpriteNum; i++) {
    SDL_RenderCopy(Renderer, Sprites[i]->texture(), NULL, Sprites[i]->pos(2));
  }
  SDL_SetRenderDrawColor(Renderer, 0, 0, 255, 225);
  for(auto i : CurrentLevel->blocks()) {
    SDL_RenderFillRect(Renderer, new SDL_Rect(i));
    //std::cout << "Rendering block at: (" << i.x << ", " << i.y << ", " << i.w << ", " << i.h << ")" << std::endl;
  }
  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
  SDL_RenderCopy(Renderer, Joe->texture(), NULL, Joe->pos(5));
  return 0;
}

Sandstorm::~Sandstorm() {
  SDL_DestroyTexture(Background);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(WinMain);
}
