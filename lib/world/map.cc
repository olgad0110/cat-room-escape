#include "world/map.h"

namespace world {
  Map::Map() {
    grid_size_x = 11;
    grid_size_y = 11;

    tiles_bitmap = al_load_bitmap("images/tiles.png");
    cat_bitmap = al_load_bitmap("images/cat.png");

    grid = new world::Tile**[grid_size_y];
    for(int i = 0; i < grid_size_y; ++i) {
      grid[i] = new world::Tile*[grid_size_x];
    }

    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if((i == 0 || i == grid_size_y-1 || j == 0 || j == grid_size_x-1) && !((j == 5 && i == 0) || (j == 0 && i == 6))) {
          grid[i][j] = new world::WallTile(j*TILE_SIZE, i*TILE_SIZE, tiles_bitmap);
        } else {
          grid[i][j] = new world::WoodenFloorTile(j*TILE_SIZE, i*TILE_SIZE, tiles_bitmap);
        }
      }
    }

    create_entity("table", 2, 3);
    create_entity("table", 3, 3);
    create_entity("chair", 2, 2);
    create_entity("chair", 1, 3);
    create_entity("chair", 2, 4);
    create_entity("chair", 3, 4);
    create_entity("chair", 3, 2);
    create_entity("chair", 4, 3);
    create_entity("sofa", 7, 2);
    create_entity("sofa", 7, 3);
    create_entity("sofa", 7, 4);
    create_entity("sofa", 7, 5);
    create_entity("TV", 9, 3);
    create_entity("TV", 9, 4);
    create_entity("TV table", 9, 2);
    create_entity("TV table", 9, 5);
    create_entity("bookstand", 1, 9);
    create_entity("bookstand", 2, 9);
    create_entity("sm bookstand", 3, 9);
    create_entity("sm bookstand", 4, 9);
    create_entity("shelf", 5, 9);
    create_entity("shelf", 6, 9);
    create_entity("shelf", 8, 9);
    create_entity("shelf", 9, 8);
    create_entity("door", 0, 6);
    create_entity("door", 5, 0);

    cat = new world::CatCharacter(128, 128, cat_bitmap);
    grid[1][1]->insert_entity(cat);
  }

  Map::~Map() {
    for(int i = 0; i < grid_size_y; ++i)
      delete [] grid[i];
    delete [] grid;

    al_destroy_bitmap(tiles_bitmap);
    al_destroy_bitmap(cat_bitmap);
  }

  void Map::create_entity(const std::string &obj_name, const int &x, const int &y) {
    world::Entity * obj = new world::Entity(obj_name);
    grid[y][x]->insert_entity(obj);
  }

  void Map::draw() {
    al_hold_bitmap_drawing(true);
    draw_tiles();
    draw_other_entities();
    al_hold_bitmap_drawing(false);
  }

  void Map::draw_tiles() {
    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        grid[i][j]->draw();
      }
    }
  }

  void Map::draw_other_entities() {
    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(grid[i][j]->entities.size() > 0) {
          for(entity_iterator it = grid[i][j]->entities.begin(); it < grid[i][j]->entities.end(); it++) {
            (*it)->draw();
          }
        }
      }
    }
  }
}
