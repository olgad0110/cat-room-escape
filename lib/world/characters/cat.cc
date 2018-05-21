#include "world/characters/cat.h"

namespace world {
  CatCharacter::CatCharacter(const int &a_x, const int &a_y, ALLEGRO_BITMAP * bitmap) : Character("cat", false, false, a_x, a_y, 128, 128) {
    sprite = new Sprite(bitmap, 0, 0, 128, 128);
  }
}
