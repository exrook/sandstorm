#include "Entity.h"
#include <iostream>

int Entity::simulate(signed int dt) {
  Direction hit = CurrentLevel->collide(this);
  if (hit != Direction::none) {
    std::cout << "Collided at (" << x() << ", " << y() << ") at " << static_cast<int>(hit);
    std::cout << std::endl;
  }
  if (hit != Direction::down)
    Yv += 1;
  switch (hit) {
    case Direction::none:
      
      break;
    case Direction::up:
      if (Yv < 0)
        Yv = -Yv;
      break;
    case Direction::down:
      if (Yv > 5)
        Yv = 3;
      else 
        Yv = 0;
      break;
    case Direction::left:
      if (Xv < 0)
        Xv = -Xv;
      break;
    case Direction::right:
      if (Xv > 0)
        Xv = -Xv;
      break;
  }
  x((Xv*(dt/16))+XPos);
  y((Yv*(dt/16))+YPos);
  return 0;
}

int Entity::jump() {
  return 0;
}
