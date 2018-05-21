#include "world/entity.h"

namespace world {
  Entity::Entity(const std::string &a_name, const bool &a_int, const bool &a_ent, const int &a_x, const int &a_y, const int &a_size_x, const int &a_size_y) {
    name = a_name;
    interactive = a_int;
    enterable = a_ent;
    x = a_x;
    y = a_y;
    size_x = a_size_x;
    size_y = a_size_y;
    sprite = NULL;
  }

  Entity::~Entity() {}

  Entity::Entity(const std::string &a_name) {
    name = a_name;
  }

  bool Entity::is_enterable() {
    return enterable;
  }

  bool Entity::is_interactive() {
    return interactive;
  }

  void Entity::draw() {
    if(sprite != NULL) {
      sprite->draw(x, y);
    }
  }
}
