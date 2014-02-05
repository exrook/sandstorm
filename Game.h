#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "SDL_image.h"
#include "util.h"

class Game {
  protected:
    SDL_Window *WinMain;
    SDL_Renderer *Renderer;
    bool Running = true;
    int EventH = 0; //Event Handling
    Game() {};
  public:
    Game(int argc, char** argv);
    virtual int run();
    virtual int event(SDL_Event e) {return 0;};
    virtual int loop()=0;
    ~Game();
};

#endif
