#ifndef WORLD_WORLD_H
#define WORLD_WORLD_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "objects/object.h"

namespace world {
  typedef std::vector<world::Object*> object_vector;
  typedef object_vector::iterator object_iterator;

  class World {
    public:
      std::string world_name;
      object_vector objects;

      World();
      World(std::string arg);
      ~World();

      world::Object * create_object(std::string name);
  };
}

#endif
