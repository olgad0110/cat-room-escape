#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "entity.h"
#include "tile.h"
#include "map.h"

namespace world {
  class Map;
  class Entity;
  class Tile;

  class World {
    public:
      std::string name;
      world::Map * map;

      World(const std::string &arg);
      ~World();
  };
}

#endif
