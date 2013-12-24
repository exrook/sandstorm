#include "Game.h"

Game::Game(int argc, char** argv) {
  int width = 640, height = 480;
  
  WinMain = SDL_CreateWindow(argv[0], SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
  Renderer = SDL_CreateRenderer(WinMain, -1, SDL_RENDERER_ACCELERATED);
}
int Game::run() {
  while (Running) {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (EventH == 0) {
        if (e.type == SDL_QUIT) {
          Running = false;;
        }
      } else {
        event(e);
      }
    }
    
    SDL_RenderClear(Renderer);
    loop();
    SDL_RenderPresent(Renderer);
  }
  return 0;
}
Game::~Game() {
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(WinMain);
}
