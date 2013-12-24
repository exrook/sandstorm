#include "util.h"

SDL_Texture* loadTexture(char const image[], SDL_Renderer *renderer) {
  SDL_Surface *bitmapSurface = IMG_Load(image);
  SDL_Texture *bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
  SDL_FreeSurface(bitmapSurface);
  return bitmapTex;
}
