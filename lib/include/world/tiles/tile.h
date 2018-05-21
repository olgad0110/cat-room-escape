#ifndef WORLD_TILE_H
#define WORLD_TILE_H

#include <stdlib.h>
#include <string>
#include <vector>

#include "world/entity.h"

namespace world {
  const int TILE_SIZE = 128;

  typedef std::vector<world::Entity*> entity_vector;
  typedef entity_vector::iterator entity_iterator;

  class Tile : public Entity {
    public:
      entity_vector entities;
      bool movable;

      Tile(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y);
      ~Tile();

      void insert_entity(world::Entity * obj);
  };
}

#endif
