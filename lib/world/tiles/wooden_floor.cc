#include "world/tiles/wooden_floor.h"

namespace world {
  WoodenFloorTile::WoodenFloorTile(const int &a_x, const int &a_y, ALLEGRO_BITMAP * bitmap) : Tile("wooden_floor", false, true, a_x, a_y) {
    sprite = new Sprite(bitmap, 128, 0, TILE_SIZE, TILE_SIZE);
  }
}
