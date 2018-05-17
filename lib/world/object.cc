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

  std::string Object::draw(const int &char_length, const int &grid_size_x, const int &x, const int &y, const bool &cat) {
    std::string r = "";

    if(x == 0 || x == grid_size_x-1) {
      if(obj_name == "wall") {
        r += std::string(char_length/3 - 2, 'X') + " ";
      } else {
        r += obj_name + std::string(char_length/3 - obj_name.size() - 1, ' ');
      }
    } else {
      if(obj_name == "wall") {
        r += std::string(char_length - 2, 'X') + " ";
      } else if(cat) {
        r += obj_name + std::string(char_length - obj_name.size() - 4, ' ') + "🐈  ";
      } else {
        r += obj_name + std::string(char_length - obj_name.size() - 1, ' ');
      }
    }
    return r;
  }
}
