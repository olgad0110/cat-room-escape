#include "world/tiles/tile.h"

namespace world {
  Tile::Tile(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y) : Entity(a_name, a_int, a_ent, a_x, a_y, TILE_WIDTH, TILE_HEIGHT) {
    movable = false;
    entities.reserve(10);
  }

  Tile::~Tile() {
    for(entity_iterator it = entities.begin(); it < entities.end(); it++) {
      delete (*it);
    }
  }

  void Tile::insert_entity(world::Entity * obj) {
    entities.push_back(obj);
    if(name == "wall") {
      name = "wooden_floor";
      enterable = true;
    }
  }
}
