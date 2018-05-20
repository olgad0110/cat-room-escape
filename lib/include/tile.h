#ifndef WORLD_TILE_H
#define WORLD_TILE_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "world.h"
#include "object.h"
#include "cat.h"

class Cat;

namespace world {
  class Object;

  typedef std::vector<world::Object*> object_vector;
  typedef object_vector::iterator object_iterator;

  class Tile {
    public:
      int size_x;
      int size_y;
      bool collision;
      std::string name;
      object_vector objects;

      Tile();
      Tile(const std::string &arg);
      ~Tile();

      void insert_object(world::Object * obj);
      bool can_be_entered();
      std::string draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &draw_cat, Cat * cat);
  };
}

#endif
