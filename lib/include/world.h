#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "object.h"
#include "map.h"

namespace world {
  class Map;
  class Object;

  typedef std::vector<world::Object*> object_vector;
  typedef object_vector::iterator object_iterator;

  class World {
    public:
      std::string world_name;
      object_vector objects;
      world::Map * map;

      World();
      World(const std::string &arg);
      ~World();

      world::Object * create_object(const std::string &obj_name);
  };
}

#endif
