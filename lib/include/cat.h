#ifndef CAT_H
#define CAT_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include "object.h"
#include "tile.h"
#include "world.h"

namespace world {
  class World;
  class Object;
  class Tile;
}

class Cat {
  public:
    std::string cat_name;
    std::string icon;
    int pos_x;
    int pos_y;

    Cat(const std::string &arg_n, const std::string &arg_i);
    virtual ~Cat();

    virtual std::string meow();
    virtual void look_at(world::Object * obj);
    virtual void sit_on(world::Object * obj);
    virtual void go_up(world::World * world);
    virtual void go_down(world::World * world);
    virtual void go_left(world::World * world);
    virtual void go_right(world::World * world);

};

typedef Cat * create_c(const std::string &name, const std::string &icon);
typedef void destroy_c(Cat * cat);

#endif
