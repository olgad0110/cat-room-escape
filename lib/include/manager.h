#ifndef MANAGER_H
#define MANAGER_H

#include "world/world.h"
#include "world/characters/character.h"

class Manager {
  public:
    world::World * world;

    Manager(world::World * a_world);
    ~Manager();

    void move(world::Character * character, const int &x, const int &y, const int &speed);
    bool can_move(world::Character * character, const int &new_x, const int &new_y);
    int tile_coord(const int &coord);
    bool corner_enterable(const int &x, const int &y);
};

#endif
