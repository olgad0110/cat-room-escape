#include "object.h"

namespace world {
  Object::Object() {
    collision = false;
  }
  Object::~Object() {}

  Object::Object(const std::string &arg_n) {
    collision = true;
    obj_name = arg_n;
  }

  Object::Object(const std::string &arg_n, const bool &arg_c) {
    collision = arg_c;
    obj_name = arg_n;
  }

  std::string Object::describe() {
    return "This is " + obj_name;
  }

  bool Object::can_be_entered() {
    return !collision;
  }
}
