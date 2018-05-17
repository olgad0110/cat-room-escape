#include <stdlib.h>
#include <string>
#include <iostream>
#include "dlhandler.h"
#include "world.h"

int main(int argc, char *argv[]) {
  std::string input;
  int state = 1;

  DLHandler * cat_handler = new DLHandler("bin/cat.so");

  world::World * world = new world::World("Cat room");

  std::cout << std::endl << "What's your cat name?" << std::endl;
  std::string name;
  std::cin >> name;
  Cat * cat1 = cat_handler->create(name);

  std::cout << "Starting game loop" << std::endl << std::endl;

  while(state == 1) {
    system("clear");
    world->map->print(cat1);

    std::cout << std::endl << "$ ";
    std::cin >> input;

    if(input == "q") {
      state = 0;

    } else if(input == "w") {
      cat1->go_up(world);
    } else if(input == "s") {
      cat1->go_down(world);
    } else if(input == "a") {
      cat1->go_left(world);
    } else if(input == "d") {
      cat1->go_right(world);

    } else if(input == "m") {
      cat1->meow();
    } else if(input == "r") {
      cat_handler->reload();
    }
  }

  cat_handler->destroy(cat1);
  delete world;
  delete cat_handler;

  return EXIT_SUCCESS;
}
