#include "world/tiles/tile.h"

namespace world {
  Tile::Tile(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y) : Entity(a_name, a_int, a_ent, a_x, a_y, TILE_SIZE, TILE_SIZE) {
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

  // std::string Tile::draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &draw_cat, Cat * cat) {
  //   std::string r = "";
  //   std::string obj_name;
  //   if(entities.size() > 0) {
  //     obj_name = entities.front()->obj_name;
  //   } else {
  //     obj_name = name;
  //   }

  //   if(x == 0 || x == grid_size_x-1) {
  //     if(obj_name == "wall") {
  //       r += std::string(char_length/3 - 2, 'X') + " ";
  //     } else {
  //       r += obj_name + std::string(char_length/3 - obj_name.size() - 1, ' ');
  //     }
  //   } else {
  //     if(obj_name == "wall") {
  //       r += std::string(char_length - 2, 'X') + " ";
  //     } else if(draw_cat) {
  //       r += obj_name + std::string(char_length - obj_name.size() - 4, ' ') + cat->icon + "  ";
  //     } else {
  //       r += obj_name + std::string(char_length - obj_name.size() - 1, ' ');
  //     }
  //   }
  //   return r;
  // }
}
