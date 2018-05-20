#include <string>
#include <iostream>
#include "dlhandler.h"
#include "world.h"

class Game {
  public:
    int state;
    DLHandler * cat_handler;
    world::World * world;
    Cat * cat;

    Game();
    ~Game();

    void init();
    void loop();
};
