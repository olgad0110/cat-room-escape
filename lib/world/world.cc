#include "world.h"

namespace world {
  World::World(const std::string &arg) {
    name = arg;
    map = new Map();
  }

  World::~World() {
    delete map;
  }
}
