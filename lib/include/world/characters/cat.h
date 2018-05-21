#ifndef WORLD_CHARACTER_CAT_H
#define WORLD_CHARACTER_CAT_H

#include <stdlib.h>
#include <string>

#include "world/characters/character.h"

namespace world {
  class CatCharacter : public Character {
    public:
      bool movable;

      CatCharacter(const int &a_x, const int &a_y, ALLEGRO_BITMAP * bitmap);
  };
}

#endif
