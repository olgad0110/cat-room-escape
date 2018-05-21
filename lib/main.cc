#include <stdlib.h>
#include <string>
#include <iostream>

#include <allegro5/allegro.h>

#include "game.h"

int main(int argc, char *argv[]) {

  Game * game = new Game(60.0, 11*128, 11*128);
  game->loop();
  delete game;

  return EXIT_SUCCESS;
}
