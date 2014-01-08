#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "util.h"

class Sprite {
  SDL_Texture* Texture;
  protected:
    SDL_Rect Pos = {0,0,0,0};
    int XPos = 0,YPos = 0, Width = 0, Height = 0;
  public:
    Sprite(const char* image, SDL_Renderer* renderer, int x, int y) {
      Texture = loadTexture(image, renderer);
      XPos = x; YPos = y;
      SDL_QueryTexture(Texture, NULL, NULL, &Width, &Height);
      Pos = {x,y,Width,Height};
    }
    inline int x() {return XPos;};
    int x(int x) { Pos.x = x; return XPos = x;};
    inline int y() {return YPos;};
    int y(int y) { Pos.y = y; return YPos = y;};
    inline int w() {return Width;};
    inline int h() {return Height;};
    SDL_Texture* texture() { return Texture;};
    SDL_Rect* pos(int s=1) {
      SDL_Rect scale = {Pos.x,Pos.y,Pos.w*s,Pos.h*s};
      return new SDL_Rect(scale);
    }
};
#endif
