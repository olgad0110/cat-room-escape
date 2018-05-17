#ifndef CAT_H
#define CAT_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include "object.h"
#include "world.h"

namespace world {
  class World;
}

class Cat {
  public:
    std::string cat_name;
    int pos_x;
    int pos_y;

    Cat(std::string arg);
    virtual ~Cat();

    virtual std::string class_name();
    virtual void meow();
    virtual void look_at(world::Object * obj);
    virtual void sit_on(world::Object * obj);
    virtual void go_up(world::World * world);
    virtual void go_down(world::World * world);
    virtual void go_left(world::World * world);
    virtual void go_right(world::World * world);

};

typedef Cat * create_c(std::string name);
typedef void destroy_c(Cat * cat);

#endif
