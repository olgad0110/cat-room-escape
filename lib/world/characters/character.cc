#include "world/characters/character.h"

namespace world {
  Character::Character(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y) : Entity(a_name, a_int, a_ent, a_x, a_y, a_size_x, a_size_y) {
    movable = true;
    direction_hor = 0; // 0 left, 1 right
    direction_ver = 0; // 0 forward, 1 side, 2 back
  }

  Character::~Character() {}

  int Character::tile_x() {
    return x / TILE_SIZE;
  }

  int Character::tile_y() {
    return y / TILE_SIZE;
  }

  void Character::draw() {
    if(sprite != NULL) {
      sprite->draw(x, y, 0, (2 * direction_ver + direction_hor) * 123);
    }
  }

  void Character::look_at(const int &old_x, const int &old_y, const int &new_x, const int &new_y) {
    if(new_y > old_y) {
      direction_ver = 0;
    } else if(new_y < old_y) {
      direction_ver = 2;
    } else {
      direction_ver = 1;
    }

    if(new_x > old_x) {
      direction_hor = 1;
    } else if(new_x < old_x) {
      direction_hor = 0;
    }
  }
}
