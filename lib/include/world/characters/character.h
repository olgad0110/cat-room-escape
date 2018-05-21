#ifndef WORLD_CHARACTER_H
#define WORLD_CHARACTER_H

#include <stdlib.h>
#include <string>

#include "world/entity.h"
#include "world/tiles/tile.h"

namespace world {
  class Character : public Entity {
    public:
      bool movable;
      int direction_hor;
      int direction_ver;

      Character(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y);
      ~Character();

      int tile_x();
      int tile_y();

      void draw();
      void look_at(const int &old_x, const int &old_y, const int &new_x, const int &new_y);
  };
}

#endif
