#include "world.h"

namespace world {
  World::World(std::string arg) {
    world_name = arg;
    std::cout << "Creating " << world_name << " world" << std::endl;

    map = new Map(3, 3);
    map->insert_object(create_object("chair"), 0, 0);
    map->insert_object(create_object("table"), 1, 1);
    map->insert_object(create_object("sofa"), 2, 2);
    map->insert_object(create_object("shelf"), 1, 2);
    map->fill_empty();
    map->print();
  }

  World::~World() {
    for(object_iterator it = objects.begin(); it < objects.end(); it++) {
      delete (*it);
    }
    delete map;
    std::cout << "Destroying world" << std::endl;
  }

  world::Object * World::create_object(std::string obj_name) {
    world::Object * obj = new world::Object(obj_name);
    objects.push_back(obj);
    return obj;
  }
}
