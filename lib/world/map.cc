#include "map.h"

namespace world {
  Map::Map(const int &x, const int &y) {
    grid_size_x = x;
    grid_size_y = y;

    grid = new world::Object**[grid_size_y];
    for(int i = 0; i < grid_size_y; ++i) {
      grid[i] = new world::Object*[grid_size_x];
    }

    std::cout << "Creating map" << std::endl;
  }

  Map::~Map() {
    for(int i = 0; i < grid_size_y; ++i)
      delete grid[i];
    delete grid;

    std::cout << "Destroying map" << std::endl;
  }

  void Map::insert_object(world::Object * object, int x, int y) {
    grid[y][x] = object;
  }

  void Map::fill_empty() {
    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(grid[i][j] == NULL) {
          grid[i][j] = new world::Object("floor");
        }
      }
    }
  }

  void Map::print() {
    std::cout << "Map created" << std::endl;
    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(grid[i][j] != NULL) {
          std::cout << " | " << grid[i][j]->obj_name << " | ";
        } else {
          std::cout << " | NULL | ";
        }
      }
      std::cout << std::endl;
    }
  }
}
