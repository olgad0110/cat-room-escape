#ifndef CAT_H
#define CAT_H

#include <stdlib.h>
#include <string>
#include <iostream>

class Cat {
  public:
    std::string pet_name;

    Cat(std::string name);
    virtual ~Cat();

    virtual std::string class_name();
    virtual void meow();
};

typedef Cat * create_c(std::string name);
typedef void destroy_c(Cat * cat);

#endif
