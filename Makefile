#-----------------------#
#       variables       #
#-----------------------#

# directories and files #

OBJ = ./obj
BIN = ./bin
LIB = ./lib
LIB_H = ./lib/include

OBJ_FILES = $(OBJ)/main.o \
  $(OBJ)/game.o \
  $(OBJ)/manager.o \
  $(OBJ)/dlhandler.o \
  $(OBJ)/map.o \
  $(OBJ)/entity.o \
  $(OBJ)/world.o \
  $(OBJ)/tile.o \
  $(OBJ)/wall.o \
  $(OBJ)/wooden_floor.o \
  $(OBJ)/sprite.o \
  $(OBJ)/character.o \
  $(OBJ)/cat.o

SO_OBJ_FILES = $(OBJ)/cat.o \
	$(OBJ)/entity.o \
	$(OBJ)/tile.o

ALLEGRO = -lallegro -lallegro_main -lallegro_primitives -lallegro_image -lallegro_dialog -lallegro_audio -lallegro_acodec

# defaults #

BUILD = debug
ARCH = x86

# compiler options #

CXX = g++
CXXFLAGS = -c -Wall -Werror
HLOOKUPFLAGS = -I$(LIB_H)

ifeq ($(BUILD),debug)
	CXXFLAGS += -g
endif

ifeq ($(BUILD),release)
	RDIR = ./release
	BIN = $(RDIR)
endif

#-----------------------#
#        targets        #
#-----------------------#

.PHONY: all
all:
	@echo "#------ Creating $(BUILD) build in $(BIN) directory... ------#"
	mkdir -p $(BIN) $(OBJ)
	make main
	make slibs
	cp ./dlcompile.sh $(BIN)/
	@echo "#------ Compilation done. Run $(BIN)/main to start ------#"

.PHONY: main
main:
	@echo "#------ Compiling main... ------#"
	make $(BIN)/main

.PHONY: slibs
slibs:
	@echo "#------ Compiling shared libs... ------#"
	make $(BIN)/cat.so

.PHONY: help
help:
	@echo
	@echo "  make [target] [OPTIONS]"
	@echo
	@echo "  targets:"
	@echo "     all              Builds application and shared libs (default)"
	@echo "     main             Builds application"
	@echo "     slibs            Builds shared libs for application"
	@echo "     clean            Cleans project build"
	@echo "     help             Prints this message"
	@echo
	@echo "  options:"
	@echo "     BUILD=debug      Builds a debug build (default)"
	@echo "     BUILD=release    Builds a release build"
	@echo "     ARCH=x86         Builds a x86 build (default)"
	@echo "     ARCH=arm         Builds an arm build"
	@echo "     RDIR=release     Creates release in given directory (default: release)"

.PHONY: clean
clean:
	rm -f $(OBJ)/* $(BIN)/*
	rmdir $(OBJ) $(BIN)

#-----------------------#
#         files         #
#-----------------------#

$(BIN)/main: $(OBJ_FILES)
	$(CXX) $^ ${ALLEGRO} -ldl -o $(BIN)/main

$(BIN)/cat.so: $(SO_OBJ_FILES)
	# $(CXX) $^ -shared -fPIC -o $(BIN)/cat.so
	@echo "skip"

# $(OBJ)/cat.o: $(LIB)/cat.cc $(LIB_H)/cat.h
# 	# $(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -fPIC -o $@

$(OBJ)/%.o: $(LIB)/%.cc $(LIB_H)/%.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@

$(OBJ)/%.o: $(LIB)/**/%.cc $(LIB_H)/**/%.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@

$(OBJ)/%.o: $(LIB)/**/*/%.cc $(LIB_H)/**/*/%.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@

$(OBJ)/%.o: $(LIB)/%.cc
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@
