#include "manager.h"

Manager::Manager(world::World * a_world) {
  world = a_world;
}

Manager::~Manager() {}

void Manager::move(world::Character * character, const int &x, const int &y, const int &speed) {
  int new_x = character->x + x * speed;
  int new_y = character->y + y * speed;

  if(can_move(character, new_x, new_y)) {
    int old_x = character->x;
    int old_y = character->y;
    int old_tile_x = character->tile_x();
    int old_tile_y = character->tile_y();

    character->x = new_x;
    character->y = new_y;

    if(tile_coord(new_x) != old_tile_x || tile_coord(new_y) != old_tile_y) {
      world->map->grid[tile_coord(new_y)][tile_coord(new_x)]->entities.push_back(character);

      for(world::entity_iterator it = world->map->grid[old_tile_y][old_tile_y]->entities.begin(); it < world->map->grid[old_tile_y][old_tile_y]->entities.end(); it++) {
        if((*it)->name == character->name) {
          world->map->grid[old_tile_y][old_tile_y]->entities.erase(it);
          break;
        }
      }
    }

    character->look_at(old_x, old_y, new_x, new_y);
  }
}

bool Manager::can_move(world::Character * character, const int &new_x, const int &new_y) {

  return corner_enterable(new_x, new_y) &&
    corner_enterable(new_x+character->size_x-1, new_y) &&
    corner_enterable(new_x+character->size_x-1, new_y+character->size_y-1) &&
    corner_enterable(new_x, new_y+character->size_y-1);
}

int Manager::tile_coord(const int &coord) {
  if(coord < 0) {
    return -1;
  } else {
    return coord / world::TILE_SIZE;
  }
}

bool Manager::corner_enterable(const int &x, const int &y) {
  bool inside_map = (tile_coord(x) < world->map->grid_size_x) && (tile_coord(x) >= 0) &&
    (tile_coord(y) < world->map->grid_size_y) && (tile_coord(y) >= 0);

  return inside_map && world->map->grid[tile_coord(y)][tile_coord(x)]->is_enterable();
}
