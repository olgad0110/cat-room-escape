#include "world.h"

namespace world {
  World::World(std::string arg) {
    world_name = arg;
    std::cout << "Creating " << world_name << " world" << std::endl;

    map = new Map(11, 11);
    map->insert_object(create_object("table"), 2, 3);
    map->insert_object(create_object("table"), 3, 3);
    map->insert_object(create_object("chair"), 2, 2);
    map->insert_object(create_object("chair"), 1, 3);
    map->insert_object(create_object("chair"), 2, 4);
    map->insert_object(create_object("chair"), 3, 4);
    map->insert_object(create_object("chair"), 3, 2);
    map->insert_object(create_object("chair"), 4, 3);
    map->insert_object(create_object("sofa"), 7, 2);
    map->insert_object(create_object("sofa"), 7, 3);
    map->insert_object(create_object("sofa"), 7, 4);
    map->insert_object(create_object("sofa"), 7, 5);
    map->insert_object(create_object("TV"), 9, 3);
    map->insert_object(create_object("TV"), 9, 4);
    map->insert_object(create_object("TV table"), 9, 2);
    map->insert_object(create_object("TV table"), 9, 5);
    map->insert_object(create_object("bookstand"), 1, 9);
    map->insert_object(create_object("bookstand"), 2, 9);
    map->insert_object(create_object("sm bookstand"), 3, 9);
    map->insert_object(create_object("sm bookstand"), 4, 9);
    map->insert_object(create_object("shelf"), 5, 9);
    map->insert_object(create_object("shelf"), 6, 9);
    map->insert_object(create_object("shelf"), 8, 9);
    map->insert_object(create_object("shelf"), 9, 8);
    map->insert_object(create_object("door"), 0, 6);
    map->insert_object(create_object("door"), 5, 0);
    map->fill_empty();
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
