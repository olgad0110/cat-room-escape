#include "world/tiles/wall.h"

namespace world {
  WallTile::WallTile(const int &a_x, const int &a_y, ALLEGRO_BITMAP * bitmap) : Tile("wall", false, false, a_x, a_y) {
    sprite = new Sprite(bitmap, 0, 0, TILE_SIZE, TILE_SIZE);
  }
}
