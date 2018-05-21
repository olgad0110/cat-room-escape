#ifndef WORLD_TILES_WOODEN_FLOOR_H
#define WORLD_TILES_WOODEN_FLOOR_H

#include <stdlib.h>
#include <string>

#include "world/tiles/tile.h"

namespace world {
  class WoodenFloorTile : public Tile {
    public:
      WoodenFloorTile(const int &a_x, const int &a_y);
  };
}

#endif
