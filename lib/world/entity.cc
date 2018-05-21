#include "world/entity.h"

namespace world {
  Entity::Entity() {
    collision = false;
  }
  Entity::~Entity() {}

  Entity::Entity(const std::string &arg_n) {
    collision = true;
    obj_name = arg_n;
  }

  Entity::Entity(const std::string &arg_n, const bool &arg_c) {
    collision = arg_c;
    obj_name = arg_n;
  }

  std::string Entity::describe() {
    return "This is " + obj_name;
  }

  bool Entity::can_be_entered() {
    return !collision;
  }
}
