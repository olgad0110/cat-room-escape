#ifndef DL_HANDLER_H
#define DL_HANDLER_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include "cat.h"

class DLHandler {
  public:
    const char * dl_path;
    void * handler;
    create_c * create;
    destroy_c * destroy;

    DLHandler(const char * path);
    ~DLHandler();
    void reload();

  private:
    bool load_dl(const char * path);
    bool handle_error();
};

#endif
