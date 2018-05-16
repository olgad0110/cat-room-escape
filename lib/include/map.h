#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "object.h"

namespace world {
  typedef std::vector< std::vector<world::Object*> > object_table;

  class Map {
    public:
      object_table grid;

      Map();
      ~Map();
  };
}

#endif
