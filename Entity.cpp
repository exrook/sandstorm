#include "Entity.h"

int Entity::simulate(signed int dt) {
  Height = 280 - YPos;
  Yv = Yv + 3;
  x((Xv*(dt/16))+XPos);
  if (Yv+YPos > 280) {
    y(280); Yv = 0;
  } else
    y((Yv*(dt/16))+YPos);
  return 0;
}
