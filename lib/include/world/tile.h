#ifndef WORLD_TILE_H
#define WORLD_TILE_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "world/world.h"
#include "world/entity.h"
#include "cat.h"

class Cat;

namespace world {
  class Entity;

  typedef std::vector<world::Entity*> entity_vector;
  typedef entity_vector::iterator entity_iterator;

  class Tile {
    public:
      int size_x;
      int size_y;
      bool collision;
      std::string name;
      entity_vector entities;

      Tile();
      Tile(const std::string &arg);
      ~Tile();

      void insert_entity(world::Entity * obj);
      bool can_be_entered();
      std::string draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &draw_cat, Cat * cat);
  };
}

#endif
