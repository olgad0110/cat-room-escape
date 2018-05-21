#include "world/tiles/wall.h"

namespace world {
  WallTile::WallTile(const int &a_x, const int &a_y) : Tile("wall", false, false, a_x, a_y) {}
}
