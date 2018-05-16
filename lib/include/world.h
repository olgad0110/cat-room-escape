#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "object.h"
#include "map.h"

namespace world {
  typedef std::vector<world::Object*> object_vector;
  typedef object_vector::iterator object_iterator;

  class World {
    public:
      std::string world_name;
      object_vector objects;
      world::Map * map;

      World();
      World(std::string arg);
      ~World();

      world::Object * create_object(std::string name);
  };
}

#endif
