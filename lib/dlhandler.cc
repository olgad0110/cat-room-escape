#include "dlhandler.h"

DLHandler::DLHandler(const char * path) {
  dl_path = path;
  reload();
}

DLHandler::~DLHandler() {
  dlclose(handler);
}

std::string DLHandler::reload() {
  compile();

  if (handler != NULL) { dlclose(handler); }
  load_dl(dl_path);

  create = (create_c*) dlsym(handler, "createCat");
  handle_error();

  destroy = (destroy_c*) dlsym(handler,"destroyCat");
  handle_error();

  return "Compiling cat.so... Done";
}

void DLHandler::compile() {
  system("./dlcompile.sh");
}

bool DLHandler::load_dl(const char * path) {
  handler = dlopen(path, RTLD_LAZY);
  if (!handler) {
    std::cerr << "Cannot load dynamic library: " << dlerror() << std::endl;
    return false;
  }
  return true;
}

bool DLHandler::handle_error() {
  const char* dlsym_error = dlerror();
  if (dlsym_error) {
    std::cout << "Cannot load symbol: " << dlsym_error << std::endl;
    return false;
  }
  return true;
}
