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
        if(grid[i][j] == NULL && (i == 0 || i == grid_size_y-1 || j == 0 || j == grid_size_x-1)) {
          grid[i][j] = new world::Object("wall");
        } else if(grid[i][j] == NULL) {
          grid[i][j] = new world::Object();
        }
      }
    }
  }

  void Map::print(Cat * cat) {
    int char_length = 18;

    for(int j = 0; j < grid_size_x; j++) {
      if(j == 0 || j == grid_size_x-1) {
        std::cout << " " << std::string(char_length/3, '-');
      } else {
        std::cout << " " << std::string(char_length, '-');
      }
    }
    std::cout << std::endl;

    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(j == 0 || j == grid_size_x-1) {
          if(grid[i][j]->obj_name == "wall") {
            std::cout << "| " << std::string(char_length/3 - 2, 'X') << " ";
          } else {
            std::cout << "| " << grid[i][j]->obj_name << std::string(char_length/3 - grid[i][j]->obj_name.size() - 1, ' ');
          }
        } else {
          if(grid[i][j]->obj_name == "wall") {
            std::cout << "| " << std::string(char_length - 2, 'X') << " ";
          } else if(cat->pos_y == i && cat->pos_x == j) {
            std::cout << "| " << grid[i][j]->obj_name << std::string(char_length - grid[i][j]->obj_name.size() - 4, ' ') << "🐈  ";
          } else {
            std::cout << "| " << grid[i][j]->obj_name << std::string(char_length - grid[i][j]->obj_name.size() - 1, ' ');
          }
        }
      }
      std::cout << "|" << std::endl;

      for(int j = 0; j < grid_size_x; j++) {
        if(j == 0 || j == grid_size_x-1) {
          std::cout << " " << std::string(char_length/3, '-');
        } else {
          std::cout << " " << std::string(char_length, '-');
        }
      }
      std::cout << std::endl;
    }
  }
}
