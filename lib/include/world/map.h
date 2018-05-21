#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

#include "world/entity.h"
#include "world/tiles/tile.h"
#include "world/tiles/wall.h"
#include "world/tiles/wooden_floor.h"

namespace world {
  class Entity;
  class Tile;

  class Map {
    public:
      int grid_size_x;
      int grid_size_y;
      world::Tile*** grid;
      ALLEGRO_BITMAP * cat_bitmap;
      ALLEGRO_BITMAP * tiles_bitmap;

      Map();
      ~Map();

      void create_entity(const std::string &obj_name, const int &x, const int &y);

      void draw();
      void draw_tiles();
      // std::string draw(Cat * cat);
    // private:
      // std::string draw_horizontal_border(const int &char_length);
  };
}

#endif
