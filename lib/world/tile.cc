#include "tile.h"

namespace world {
  Tile::Tile() {
    size_x = 10;
    size_y = 10;
    collision = false;
  }

  Tile::Tile(const std::string &arg) {
    size_x = 10;
    size_y = 10;
    name = arg;
    if(name == "wall") {
      collision = true;
    } else {
      collision = false;
    }
  }

  Tile::~Tile() {
    for(object_iterator it = objects.begin(); it < objects.end(); it++) {
      delete (*it);
    }
  }

  void Tile::insert_object(world::Object * obj) {
    objects.push_back(obj);
    if(name == "wall") {
      name = "";
      collision = false;
    }
  }

  bool Tile::can_be_entered() {
    return !collision;
  }

  std::string Tile::draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &draw_cat, Cat * cat) {
    std::string r = "";
    std::string obj_name;
    if(objects.size() > 0) {
      obj_name = objects.front()->obj_name;
    } else {
      obj_name = name;
    }

    if(x == 0 || x == grid_size_x-1) {
      if(obj_name == "wall") {
        r += std::string(char_length/3 - 2, 'X') + " ";
      } else {
        r += obj_name + std::string(char_length/3 - obj_name.size() - 1, ' ');
      }
    } else {
      if(obj_name == "wall") {
        r += std::string(char_length - 2, 'X') + " ";
      } else if(draw_cat) {
        r += obj_name + std::string(char_length - obj_name.size() - 4, ' ') + cat->icon + "  ";
      } else {
        r += obj_name + std::string(char_length - obj_name.size() - 1, ' ');
      }
    }
    return r;
  }
}
