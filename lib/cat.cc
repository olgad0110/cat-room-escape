#include "cat.h"

Cat::Cat(std::string name) {
  std::cout << "creating cat object" << std::endl;
  pet_name = name;
}

Cat::~Cat() {
  std::cout << "deleting cat object" << std::endl;
}

std::string Cat::class_name() {
  return "Cat";
}

void Cat::meow() {
  std::cout << "Meow! Meow! I'm very cute " << pet_name << std::endl;
}

extern "C" {
  Cat * createCat(std::string name) {
    return new Cat(name);
  }

  void destroyCat(Cat * cat) {
    delete cat;
  }
}
