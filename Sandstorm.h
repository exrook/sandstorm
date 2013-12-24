#ifndef _SANDSTORM_H_
#define _SANDSTORM_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "util.h"
#include "Game.h"
#include "Entity.h"

class Sandstorm: public Game {
  SDL_Texture* Background;
  Entity* Joe;
  int Rot = 0;
  public:
    Sandstorm(int argc, char** argv);
    int loop() override;
    int event(SDL_Event e) override;
    ~Sandstorm();
};
#endif
