#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <string>

#include "world/map.h"
#include "world/characters/cat.h"

namespace world {
  class World {
    public:
      std::string name;
      world::Map * map;
      world::CatCharacter * cat;

      World(const std::string &arg);
      ~World();
  };
}

#endif
