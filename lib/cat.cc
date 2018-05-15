#include "cat.h"

Cat::Cat(std::string arg) {
  cat_name = arg;
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

extern "C" {
  Cat * createCat(std::string name) {
    return new Cat(name);
  }

  void destroyCat(Cat * cat) {
    delete cat;
  }
}
