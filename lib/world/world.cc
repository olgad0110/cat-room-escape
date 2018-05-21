#include "world/world.h"

namespace world {
  World::World(const std::string &arg) {
    name = arg;
    map = new Map();
    cat = map->cat;
  }

  World::~World() {
    delete map;
  }
}
