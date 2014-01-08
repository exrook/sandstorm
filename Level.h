#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Sprite.h"

/// Allows for bitwise tricks (i.e. 0010 indicates down collision , 0100 = left)
enum class Direction {none, up = 1, down = 2, left = 4, right = 8};

class Level {
  protected:
    int Height, Width;
  public:
    virtual Direction collide(Sprite* pos)=0;
    virtual int h() {return Height;};
    virtual int w() {return Width;};
};

#endif
