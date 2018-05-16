#ifndef CAT_H
#define CAT_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include "object.h"

class Cat {
  public:
    std::string cat_name;
    int test;

    Cat(std::string arg);
    virtual ~Cat();

    virtual std::string class_name();
    virtual void meow();
    virtual void look_at(world::Object * obj);
    virtual void sit_on(world::Object * obj);
};

typedef Cat * create_c(std::string name);
typedef void destroy_c(Cat * cat);

#endif
