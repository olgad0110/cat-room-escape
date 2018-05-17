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

      Object();
      Object(std::string arg);
      ~Object();

      std::string describe();
      std::string draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &cat);
  };
}

#endif
