#ifndef _SANDSTORM_H_
#define _SANDSTORM_H_

#include "SDL.h"
#include "SDL_image.h"
#include "util.h"
#include "Game.h"
#include "Entity.h"
#include "Platforms.h"

class Sandstorm: public Game {
  SDL_Texture* Background;
  Entity* Joe;
  Sprite* Sprites[100];
  Platforms* CurrentLevel;
  int SpriteNum = 0;
  int Rot = 0;
  public:
    Sandstorm(int argc, char** argv);
    int loop() override;
    int controls();
    int simulate();
    int   render();
    int event(SDL_Event e) override;
    ~Sandstorm();
};
#endif
