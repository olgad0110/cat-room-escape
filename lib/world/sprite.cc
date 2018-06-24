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
    int iso_x = pos_x - pos_y;
    int iso_y = (pos_x + pos_y) / 2;
    al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);

    // iso_x = (pos_x + 64) - pos_y;
    // iso_y = (pos_x + 64 + pos_y) / 2;
    // al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);

    // iso_x = pos_x - (pos_y + 64);
    // iso_y = (pos_x + pos_y + 64) / 2;
    // al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);

    // iso_x = (pos_x + 64) - (pos_y + 64);
    // iso_y = (pos_x + 64 + pos_y + 64) / 2;
    // al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);
  }

  void Sprite::draw(const int &pos_x, const int &pos_y, const int &x, const int &y) {
    int iso_x = pos_x - pos_y;
    int iso_y = (pos_x + pos_y) / 2;
    al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);

    // iso_x = (pos_x + 64) - pos_y;
    // iso_y = (pos_x + 64 + pos_y) / 2;
    // al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);

    // iso_x = pos_x - (pos_y + 64);
    // iso_y = (pos_x + pos_y + 64) / 2;
    // al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);

    // iso_x = (pos_x + 64) - (pos_y + 64);
    // iso_y = (pos_x + 64 + pos_y + 64) / 2;
    // al_draw_bitmap_region(bitmap, x, y, size_x, size_y, iso_x, iso_y, 0);  }
  }
}
