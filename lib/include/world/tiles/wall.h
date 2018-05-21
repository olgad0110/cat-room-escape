#ifndef WORLD_TILES_WALL_H
#define WORLD_TILES_WALL_H

#include <stdlib.h>
#include <string>

#include "world/tiles/tile.h"

namespace world {
  class WallTile : public Tile {
    public:
      WallTile(const int &a_x, const int &a_y, ALLEGRO_BITMAP * bitmap);
  };
}

#endif
