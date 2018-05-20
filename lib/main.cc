#include <stdlib.h>
#include <string>
#include <iostream>
#include "game.h"

int main(int argc, char *argv[]) {
  Game * game = new Game;
  game->init();

  game->loop();

  delete game;
  return EXIT_SUCCESS;
}
