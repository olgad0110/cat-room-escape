#include "game.h"

Game::Game() {
  state = 0;
  cat_handler = new DLHandler("bin/cat.so");
  world = new world::World("Cat room");
}

Game::~Game() {
  cat_handler->destroy(cat);
  delete world;
  delete cat_handler;
}

void Game::init() {
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

  cat = cat_handler->create(name, icon);

  std::cout << std::endl << "Do you want to play? [Y/n] ";
  do {
    std::cin >> input;
    if(input == "n") {
      state = 0;
    } else if(input == "Y") {
      state = 1;
    } else {
      std::cout << "[Y/n]" << std::endl;
    }
  } while(!(input == "Y" || input == "n"));
}

void Game::loop() {
  std::string input;
  std::string printable;

  while(state == 1) {
    system("clear");

    std::cout << world->map->draw(cat);

    std::cout << std::endl << printable << std::endl;
    printable = "";

    std::cout << std::endl << "$ ";
    std::cin >> input;

    if(input == "q") {
      state = 0;
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
