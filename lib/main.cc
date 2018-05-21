#include <stdlib.h>
#include <string>
#include <iostream>

#include <allegro5/allegro.h>

#include "game.h"

int main(int argc, char *argv[]) {

  Game * game = new Game(60.0, 800, 600);
  game->initialize_allegro();
  game->loop();
  game->shutdown_allegro();
  delete game;

  return EXIT_SUCCESS;
}
