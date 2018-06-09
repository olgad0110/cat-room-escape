#-----------------------#
#       variables       #
#-----------------------#

# directories and files #

OBJ = ./obj
BIN = ./bin
LIB = ./lib
LIB_H = ./lib/include

OBJ_FILES = $(OBJ)/dlhandler.o \
	$(OBJ)/map.o \
	$(OBJ)/object.o \
	$(OBJ)/world.o \
	$(OBJ)/main.o

SO_OBJ_FILES = $(OBJ)/cat.o \
	$(OBJ)/object.o

# defaults #

BUILD = release
ARCH = x86

# compiler options #

CXX = g++
CXXFLAGS = -c -Wall -Werror
HLOOKUPFLAGS = -I$(LIB_H)

ifeq ($(BUILD),debug)
	CXXFLAGS += -g
endif

#-----------------------#
#        targets        #
#-----------------------#

.PHONY: all
all:
	make main
	make slibs

.PHONY: main
main:
	make $(BIN)/main

.PHONY: slibs
slibs:
	make $(BIN)/cat.so

.PHONY: help
help:
	@echo
	@echo "  make [target] [OPTIONS]"
	@echo
	@echo "  targets:"
	@echo "     all       Builds application and shared libs (default)"
	@echo "     main      Builds application"
	@echo "     slibs     Builds shared libs for application"
	@echo "     clean     Cleans project build"
	@echo "     help      Prints this message"
	@echo
	@echo "  options:"
	@echo "     BUILD=release   Builds a release build (default)"
	@echo "     BUILD=debug     Builds a debug build"
	@echo "     ARCH=x86        Builds a x86 build (default)"
	@echo "     ARCH=arm        Builds an arm build"

.PHONY: clean
clean:
	rm -f $(OBJ)/*.o $(BIN)/main $(BIN)/cat.so

#-----------------------#
#         files         #
#-----------------------#

$(BIN)/main: $(OBJ_FILES)
	$(CXX) $^ -o $(BIN)/main -ldl

$(BIN)/cat.so: $(SO_OBJ_FILES)
	$(CXX) $^ -o $(BIN)/cat.so -shared -fPIC

$(OBJ)/%.o: $(LIB)/**/%.cc $(LIB_H)/%.h
	$(CXX) $(CXXFLAGS) $(HLOOKUPFLAGS) $< -o $@

$(OBJ)/%.o: $(LIB)/%.cc
	$(CXX) $(CXXFLAGS) $(HLOOKUPFLAGS) $< -o $@
