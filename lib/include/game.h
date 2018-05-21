#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

#include "dlhandler.h"
#include "world/world.h"
#include "manager.h"

enum pushed_keys {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

class Game {
  public:
    float fps;
    int display_x;
    int display_y;

    ALLEGRO_DISPLAY * display;
    ALLEGRO_TIMER * timer;
    ALLEGRO_EVENT_QUEUE * event_queue;
    // ALLEGRO_BITMAP * tiles_bitmap;
    // ALLEGRO_BITMAP * cat_bitmap;

    int state;
    DLHandler * cat_handler;
    world::World * world;
    Cat * cat;
    Manager * manager;

    Game(const float &a_fps, const int &a_display_x, const int &a_display_y);
    ~Game();

    void loop();

  private:
    void initialize_allegro();
    void shutdown_allegro();
};

#endif
