#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace world {
  class Object {
    public:
      std::string obj_name;
      bool collision;

      Object();
      Object(const std::string &arg_n);
      Object(const std::string &arg_n, const bool &arg_c);
      ~Object();

      std::string describe();
      std::string draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &cat);
      bool can_be_entered();
  };
}

#endif
