#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "util.h"

class Sprite {
  SDL_Texture* Texture;
  protected:
    SDL_Rect Pos = {0,0,0,0};
    int XPos = 0,YPos = 0;
  public:
    Sprite(const char* image, SDL_Renderer* renderer, int x, int y) {
      Texture = loadTexture(image, renderer);
      XPos = x; YPos = y;
      int w,h;
      SDL_QueryTexture(Texture, NULL, NULL, &w, &h);
      Pos = {x,y,w,h};
    }
    int x() {return XPos;};
    int x(int x) { Pos.x = x; return XPos = x;};
    int y() {return YPos;};
    int y(int y) { Pos.y = y; return YPos = y;};
    SDL_Texture* texture() { return Texture;};
    SDL_Rect* pos(int s=1) {
      SDL_Rect scale = {Pos.x,Pos.y,Pos.w*s,Pos.h*s};
      return new SDL_Rect(scale);
    }
};
#endif
