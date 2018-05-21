#include "world/characters/character.h"

namespace world {
  Character::Character(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y) : Entity(a_name, a_int, a_ent, a_x, a_y, a_size_x, a_size_y) {
    movable = true;
  }

  Character::~Character() {}

  int Character::tile_x() {
    return x / TILE_SIZE;
  }

  int Character::tile_y() {
    return y / TILE_SIZE;
  }
}
