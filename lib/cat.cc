#include "cat.h"

Cat::Cat(const std::string &arg_n, const std::string &arg_i) {
  cat_name = arg_n;
  icon = arg_i;
  pos_x = 1;
  pos_y = 1;
  std::cout << cat_name << " has woken up ready to play." << std::endl;
}

Cat::~Cat() {
  std::cout << cat_name << " decided to go to sleep." << std::endl;
}

std::string Cat::meow() {
  return "Meow! Meow! I'm very cute "+cat_name;
}

void Cat::look_at(world::Object * obj) {
  std::cout << cat_name << " is looking at " << obj->obj_name << std::endl;
  std::cout << obj->describe() << std::endl;
}

void Cat::sit_on(world::Object * obj) {
  std::cout << cat_name << " is sitting on " << obj->obj_name << std::endl;
}

void Cat::go_up(world::World * world) {
  if(pos_y-1 < world->map->grid_size_y && pos_y-1 >= 0 && world->map->grid[pos_y-1][pos_x]->can_be_entered()) {
    pos_y = pos_y-1;
  }
}

void Cat::go_down(world::World * world) {
  if(pos_y+1 < world->map->grid_size_y && pos_y+1 >= 0 && world->map->grid[pos_y+1][pos_x]->can_be_entered()) {
    pos_y = pos_y+1;
  }
}

void Cat::go_left(world::World * world) {
  if(pos_x-1 < world->map->grid_size_x && pos_x-1 >= 0 && world->map->grid[pos_y][pos_x-1]->can_be_entered()) {
    pos_x = pos_x-1;
  }
}

void Cat::go_right(world::World * world) {
  if(pos_x+1 < world->map->grid_size_x && pos_x+1 >= 0 && world->map->grid[pos_y][pos_x+1]->can_be_entered()) {
    pos_x = pos_x+1;
  }
}

extern "C" {
  Cat * createCat(const std::string &name, const std::string &icon) {
    return new Cat(name, icon);
  }

  void destroyCat(Cat * cat) {
    delete cat;
  }
}
