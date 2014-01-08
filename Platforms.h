#ifndef _PLATFORMS_H_
#define _PLATFORMS_H_

#include "Level.h"
#include "Entity.h"
#include <vector>

class Platforms: public Level {
  std::vector<SDL_Rect> Blocks;
  public:
    Platforms();
    Direction collide(Sprite* pos) override;
    std::vector<SDL_Rect> blocks() {return Blocks;};
};

#endif
