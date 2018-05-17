#include "map.h"

namespace world {
  Map::Map(const int &x, const int &y) {
    grid_size_x = x;
    grid_size_y = y;

    grid = new world::Object**[grid_size_y];
    for(int i = 0; i < grid_size_y; ++i) {
      grid[i] = new world::Object*[grid_size_x];
    }
  }

  Map::~Map() {
    for(int i = 0; i < grid_size_y; ++i)
      delete grid[i];
    delete grid;
  }

  void Map::insert_object(world::Object * object, const int &x, const int &y) {
    grid[y][x] = object;
  }

  void Map::fill_empty() {
    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(grid[i][j] == NULL && (i == 0 || i == grid_size_y-1 || j == 0 || j == grid_size_x-1)) {
          grid[i][j] = new world::Object("wall", true);
        } else if(grid[i][j] == NULL) {
          grid[i][j] = new world::Object();
        }
      }
    }
  }

  std::string Map::draw(Cat * cat) {
    int char_length = 18;
    bool draw_cat;
    std::string result = "";

    result += draw_horizontal_border(char_length);

    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(cat->pos_x == j && cat->pos_y == i) { draw_cat = true; } else { draw_cat = false; }
        result += "| " + grid[i][j]->draw(char_length, grid_size_x, j, i, draw_cat, cat);
      }
      result += "|\n";
      result += draw_horizontal_border(char_length);
    }
    return result;
  }

  std::string Map::draw_horizontal_border(const int &char_length) {
    std::string r = "";
    for(int j = 0; j < grid_size_x; j++) {
      if(j == 0 || j == grid_size_x-1) {
        r = r + " " + std::string(char_length/3, '-');
      } else {
        r = r + " " + std::string(char_length, '-');
      }
    }
    r = r + "\n";
    return r;
  }
}
