#include <stdlib.h>
#include <string>
#include <iostream>
#include "dlhandler.h"
#include "world.h"

int main(int argc, char *argv[]) {

  DLHandler * cat_handler = new DLHandler("bin/cat.so");
  std::string reload;

  world::World * w = new world::World("Cat room");

  std::cout << std::endl << "What's your cat name?" << std::endl;
  std::string name;
  std::cin >> name;
  Cat * cat1 = cat_handler->create(name);

  while (true) {
    cat1->meow();

    for(world::object_iterator it = w->objects.begin(); it < w->objects.end(); it++) {
      cat1->look_at(*it);
    }

    std::cout << std::endl << "Do you want to reload dynamic library? [Y/n]" << std::endl;
    std::cin >> reload;

    if (reload == "Y") {
      cat_handler->reload();
    } else {
      break;
    }
  }

  cat_handler->destroy(cat1);
  delete w;
  delete cat_handler;

  return EXIT_SUCCESS;
}
