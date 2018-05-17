#include "object.h"

namespace world {
  Object::Object() {
    std::cout << "Creating default object" << std::endl;
  }

  Object::Object(std::string arg) {
    obj_name = arg;
    std::cout << "Creating " << obj_name << " object" << std::endl;
  }

  Object::~Object() {
    std::cout << "Destroying " << obj_name << " object" << std::endl;
  }

  std::string Object::describe() {
    return "This is " + obj_name;
  }
}
