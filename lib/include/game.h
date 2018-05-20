#ifndef GAME_H
#define GAME_H

#include "dlhandler.h"
#include "world.h"
#include "manager.h"

class Game {
  public:
    int state;
    DLHandler * cat_handler;
    world::World * world;
    Cat * cat;
    Manager * manager;

    Game();
    ~Game();

    void init();
    void loop();
};

#endif
