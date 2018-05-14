#include <stdlib.h>
#include "dlhandler.h"

int main(int argc, char *argv[]) {

  DLHandler * cat_handler = new DLHandler("bin/cat.so");
  std::string reload;

  while (true) {
    std::cout << "What's your cat name?" << std::endl;
    std::string name;
    std::cin >> name;

    Cat * cat1 = cat_handler->create(name);
    std::cout << std::endl << "Cat with name " << cat1->pet_name << " created." << std::endl;
    cat1->meow();
    cat_handler->destroy(cat1);

    std::cout << std::endl << "Do you want to reload dynamic library? [Y/n]" << std::endl;
    std::cin >> reload;

    if (reload == "Y") {
      cat_handler->reload();
    } else {
      break;
    }
  }

  delete cat_handler;

  return EXIT_SUCCESS;
}
