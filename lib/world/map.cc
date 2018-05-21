#include "map.h"

namespace world {
  Map::Map() {
    grid_size_x = 11;
    grid_size_y = 11;

    grid = new world::Tile**[grid_size_y];
    for(int i = 0; i < grid_size_y; ++i) {
      grid[i] = new world::Tile*[grid_size_x];
    }

    for(int i = 0; i < grid_size_y; i++) {
      for(int j = 0; j < grid_size_x; j++) {
        if(i == 0 || i == grid_size_y-1 || j == 0 || j == grid_size_x-1) {
          grid[i][j] = new world::Tile("wall");
        } else {
          grid[i][j] = new world::Tile();
        }
      }
    }

    create_object("table", 2, 3);
    create_object("table", 3, 3);
    create_object("chair", 2, 2);
    create_object("chair", 1, 3);
    create_object("chair", 2, 4);
    create_object("chair", 3, 4);
    create_object("chair", 3, 2);
    create_object("chair", 4, 3);
    create_object("sofa", 7, 2);
    create_object("sofa", 7, 3);
    create_object("sofa", 7, 4);
    create_object("sofa", 7, 5);
    create_object("TV", 9, 3);
    create_object("TV", 9, 4);
    create_object("TV table", 9, 2);
    create_object("TV table", 9, 5);
    create_object("bookstand", 1, 9);
    create_object("bookstand", 2, 9);
    create_object("sm bookstand", 3, 9);
    create_object("sm bookstand", 4, 9);
    create_object("shelf", 5, 9);
    create_object("shelf", 6, 9);
    create_object("shelf", 8, 9);
    create_object("shelf", 9, 8);
    create_object("door", 0, 6);
    create_object("door", 5, 0);
  }

  Map::~Map() {
    for(int i = 0; i < grid_size_y; ++i)
      delete [] grid[i];
    delete [] grid;
  }

  void Map::create_object(const std::string &obj_name, const int &x, const int &y) {
    world::Object * obj = new world::Object(obj_name);
    grid[y][x]->insert_object(obj);
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
