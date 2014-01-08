#include "Platforms.h"

Platforms::Platforms(): Blocks(10) {
  Blocks.push_back({0,900,10000,70});
}

Direction Platforms::collide(Sprite* pos) {
  for (auto i : Blocks) {
    if ((abs(pos->x() - i.x) * 2 < (pos->w() + i.w)) && (abs(pos->y() - i.y) * 2 < (pos->h() + i.h))) {
      if (pos->y() < i.y && pos->y() > (i.y + i.h)) {// if pos is not intersecting on the top or bottom
        if (pos->x() >= i.x)
          return Direction::left; // pos is intersecting on the right relative to pos
        else
          return Direction::right; // pos is intersecting on the left relative to pos
      } else if (pos->y() >= i.y) 
        return Direction::up;
      else
        return Direction::down;
      
    }
  }
  return Direction::none;
}
