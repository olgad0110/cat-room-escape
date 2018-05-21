#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "cat.h"

class Cat;

namespace world {
  class Entity {
    public:
      std::string obj_name;
      bool collision;

      Entity();
      Entity(const std::string &arg_n);
      Entity(const std::string &arg_n, const bool &arg_c);
      ~Entity();

      std::string describe();
      std::string draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &draw_cat, Cat * cat);
      bool can_be_entered();
  };
}

#endif
