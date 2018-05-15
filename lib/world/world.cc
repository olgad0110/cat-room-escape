#include "world.h"

namespace world {
  World::World(std::string arg) {
    world_name = arg;
    std::cout << "Creating " << world_name << " world" << std::endl;
    create_object("chair");
    create_object("table");
    create_object("sofa");
    create_object("shelf");
  }

  World::~World() {
    for(object_iterator it = objects.begin(); it < objects.end(); it++) {
      delete (*it);
    }
    std::cout << "Destroying world" << std::endl;
  }

  world::Object * World::create_object(std::string obj_name) {
    world::Object * obj = new world::Object(obj_name);
    objects.push_back(obj);
    return obj;
  }
}
