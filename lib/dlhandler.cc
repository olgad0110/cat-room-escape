#include "dlhandler.h"

DLHandler::DLHandler(const char * path) {
  dl_path = path;
  reload();
}

DLHandler::~DLHandler() {
  dlclose(handler);
}

void DLHandler::reload() {
  system("g++ -shared -fPIC lib/cat.cc -o bin/cat.so");
  if (handler != NULL) { dlclose(handler); }

  load_dl(dl_path);

  create = (create_c*) dlsym(handler, "createCat");
  handle_error();

  destroy = (destroy_c*) dlsym(handler,"destroyCat");
  handle_error();

  std::cout << std::endl;
}

bool DLHandler::load_dl(const char * path) {
  handler = dlopen(path, RTLD_LAZY);
  if (!handler) {
    std::cerr << "Cannot load dynamic library: " << dlerror() << std::endl;
    return false;
  }
  std::cout << "Loaded dynamic library" << std::endl;
  return true;
}

bool DLHandler::handle_error() {
  const char* dlsym_error = dlerror();
  if (dlsym_error) {
    std::cout << "Cannot load symbol: " << dlsym_error << std::endl;
    return false;
  }
  std::cout << "Loaded symbol" << std::endl;
  return true;
}
