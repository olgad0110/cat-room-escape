#include "cat.h"

Cat::Cat(std::string arg) {
  cat_name = arg;
  pos_x = 0;
  pos_y = 0;
  std::cout << "Creating " << cat_name << " cat, address: " << this << std::endl;
}

Cat::~Cat() {
  std::cout << "Destroying " << cat_name << " cat" << std::endl;
}

std::string Cat::class_name() {
  return "Cat";
}

void Cat::meow() {
  std::cout << "Meow! Meow! I'm very cute " << cat_name << std::endl;
}

void Cat::look_at(world::Object * obj) {
  std::cout << cat_name << " is looking at " << obj->obj_name << std::endl;
  std::cout << obj->describe() << std::endl;
}

void Cat::sit_on(world::Object * obj) {
  std::cout << cat_name << " is sitting on " << obj->obj_name << std::endl;
}

void Cat::go_up(world::World * world) {
  if(world->map->grid[pos_y-1] != NULL && world->map->grid[pos_y-1][pos_x] != NULL) {
    pos_y = pos_y-1;
  }
}

void Cat::go_down(world::World * world) {
  if(world->map->grid[pos_y+1] != NULL && world->map->grid[pos_y+1][pos_x] != NULL) {
    pos_y = pos_y+1;
  }
}

void Cat::go_left(world::World * world) {
  if(world->map->grid[pos_y][pos_x-1] != NULL) {
    pos_x = pos_x-1;
  }
}

void Cat::go_right(world::World * world) {
  if(world->map->grid[pos_y][pos_x+1] != NULL) {
    pos_x = pos_x+1;
  }
}

extern "C" {
  Cat * createCat(std::string name) {
    return new Cat(name);
  }

  void destroyCat(Cat * cat) {
    delete cat;
  }
}
