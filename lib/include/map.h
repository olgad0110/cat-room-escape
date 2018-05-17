#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "object.h"
#include "cat.h"

class Cat;

namespace world {
  class Map {
    public:
      int grid_size_x;
      int grid_size_y;
      world::Object*** grid;

      Map(const int &x, const int &y);
      ~Map();

      void insert_object(world::Object * object, int x, int y);
      void fill_empty();
      std::string draw(Cat * cat);
    private:
      std::string draw_horizontal_border(const int &char_length);
  };
}

#endif
