#include "world/sprite.h"

namespace world {
  Sprite::Sprite(ALLEGRO_BITMAP * a_bitmap, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y) {
    bitmap = a_bitmap;
    x = a_x;
    y = a_y;
    size_x = a_size_x;
    size_y = a_size_y;
  }

  Sprite::~Sprite() {}

  void Sprite::draw(const int &pos_x, const int &pos_y) {
    al_draw_bitmap_region(bitmap, x, y, size_x, size_y, pos_x, pos_y, 0);
  }

  void Sprite::draw(const int &pos_x, const int &pos_y, const int &x, const int &y) {
    al_draw_bitmap_region(bitmap, x, y, size_x, size_y, pos_x, pos_y, 0);
  }
}
