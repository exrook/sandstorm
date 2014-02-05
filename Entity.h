#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "SDL.h"
#include "Sprite.h"
#include "Level.h"

class Entity: public Sprite {
  signed int Xv = 0, Yv = 0, Height = 0;
  Level* CurrentLevel;
  public:
    Entity(const char image[], SDL_Renderer* renderer, int x, int y, Level* cl): Sprite(image, renderer, x, y) {CurrentLevel = cl;};
    int simulate(int dt=16);
    int xv() {return Xv;};
    int xv(int xv) {return Xv = xv;};
    int yv() {return Yv;};
    int yv(int yv) {return Yv = yv;};
    int height() {return Height;};
    int jump();
};
#endif
