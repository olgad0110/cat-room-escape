#include <stdlib.h>
#include <string>
#include <iostream>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

#include "game.h"

int main(int argc, char *argv[]) {
  Game * game = new Game;

  al_init();
  al_init_image_addon();

  ALLEGRO_DISPLAY * display = al_create_display(128*11,128*11);
  ALLEGRO_BITMAP * tiles_bitmap = al_load_bitmap("images/tiles.png");
  ALLEGRO_BITMAP * cat_bitmap = al_load_bitmap("images/cat.png");

  for(int i = 0; i < game->world->map->grid_size_y; i++) {
    for(int j = 0; j < game->world->map->grid_size_x; j++) {
      if(game->world->map->grid[i][j]->name == "wall") {
        al_draw_bitmap_region(tiles_bitmap, 0, 0, 128, 128, 128*j, 128*i, 0);
      } else if(game->world->map->grid[i][j]->name == "") {
        al_draw_bitmap_region(tiles_bitmap, 128, 0, 128, 128, 128*j, 128*i, 0);
      }
    }
  }

  al_draw_bitmap_region(cat_bitmap, 128, 0, 128, 128, 128, 128, 0);

  al_flip_display();
  al_rest(10);

  al_destroy_display(display);
  al_destroy_bitmap(tiles_bitmap);
  al_destroy_bitmap(cat_bitmap);

  game->init();

  game->loop();

  delete game;
  return EXIT_SUCCESS;
}
