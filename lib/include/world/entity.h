#ifndef WORLD_ENTITY_H
#define WORLD_ENTITY_H

#include <stdlib.h>
#include <string>

#include "world/sprite.h"

namespace world {
  class Entity {
    public:
      std::string name;
      bool interactive;
      bool enterable;
      int x;
      int y;
      int size_x;
      int size_y;
      Sprite * sprite;

      Entity(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y);
      Entity(const std::string &a_name);
      virtual ~Entity();

      bool is_enterable();
      bool is_interactive();

      void draw();
  };
}

#endif
