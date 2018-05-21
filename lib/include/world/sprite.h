#ifndef WORLD_SPRITE_H
#define WORLD_SPRITE_H

#include <stdlib.h>
#include <string>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

namespace world {
  class Sprite {
    public:
      ALLEGRO_BITMAP * bitmap;
      int x;
      int y;
      int size_x;
      int size_y;

      Sprite(ALLEGRO_BITMAP * a_bitmap, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y);
      ~Sprite();

      void draw(const int &pos_x, const int &pos_y);
  };
}

#endif
