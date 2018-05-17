#include <stdlib.h>
#include <string>
#include <iostream>
#include "dlhandler.h"
#include "world.h"

Cat* init_game(int &game_state, DLHandler * cat_handler);
void game_loop(int &game_state, world::World * world, Cat * cat, DLHandler * cat_handler);

int main(int argc, char *argv[]) {
  int game_state = 1;
  DLHandler * cat_handler = new DLHandler("bin/cat.so");
  world::World * world = new world::World("Cat room");
  Cat * cat = init_game(game_state, cat_handler);

  game_loop(game_state, world, cat, cat_handler);

  cat_handler->destroy(cat);
  delete world;
  delete cat_handler;

  return EXIT_SUCCESS;
}

Cat* init_game(int &game_state, DLHandler * cat_handler) {
  std::string name;
  int icon_number;
  std::string icon;
  std::string input;

  std::cout << "Welcome to cat room escape!" << std::endl << std::endl;
  std::cout << "What's your cat name? ";
  std::cin >> name;

  std::cout << "What's your cat icon? 1: 🐈   2: 🐅   3: 🐆   ";
  std::cin >> icon_number;

  if(icon_number == 1) { icon = "🐈"; } else
  if(icon_number == 2) { icon = "🐅"; } else
  if(icon_number == 3) { icon = "🐆"; } else { icon = "🐈"; }

  Cat * cat = cat_handler->create(name, icon);

  std::cout << std::endl << "Do you want to play? [Y/n] ";
  do {
    std::cin >> input;
    if(input == "n") {
      game_state = 0;
    } else if(input == "Y") {
      game_state = 1;
    } else {
      std::cout << "[Y/n]" << std::endl;
    }
  } while(!(input == "Y" || input == "n"));

  return cat;
}

void game_loop(int &game_state, world::World * world, Cat * cat, DLHandler * cat_handler) {
  std::string input;
  std::string printable;

  while(game_state == 1) {
    system("clear");

    std::cout << world->map->draw(cat);

    std::cout << std::endl << printable << std::endl;
    printable = "";

    std::cout << std::endl << "$ ";
    std::cin >> input;

    if(input == "q") {
      game_state = 0;
    } else if(input == "w") {
      cat->go_up(world);
    } else if(input == "s") {
      cat->go_down(world);
    } else if(input == "a") {
      cat->go_left(world);
    } else if(input == "d") {
      cat->go_right(world);
    } else if(input == "m") {
      printable = cat->meow();
    } else if(input == "r") {
      printable = cat_handler->reload();
    }
  }
}
