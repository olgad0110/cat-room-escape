#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "object.h"
#include "tile.h"
#include "cat.h"

class Cat;

namespace world {
  class Object;
  class Tile;

  class Map {
    public:
      int grid_size_x;
      int grid_size_y;
      world::Tile*** grid;

      Map();
      ~Map();

      void create_object(const std::string &obj_name, const int &x, const int &y);
      std::string draw(Cat * cat);
    private:
      std::string draw_horizontal_border(const int &char_length);
  };
}

#endif
