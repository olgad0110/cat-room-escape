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
	$(CXX) $^ -ldl -o $(BIN)/main

$(BIN)/cat.so: $(SO_OBJ_FILES)
	$(CXX) $^ -shared -fPIC -o $(BIN)/cat.so

$(OBJ)/cat.o: $(LIB)/cat.cc $(LIB_H)/cat.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -fPIC -o $@

$(OBJ)/object.o: $(LIB)/world/object.cc $(LIB_H)/object.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -fPIC -o $@

$(OBJ)/%.o: $(LIB)/%.cc $(LIB_H)/%.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@

$(OBJ)/%.o: $(LIB)/**/%.cc $(LIB_H)/%.h
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@

$(OBJ)/%.o: $(LIB)/%.cc
	$(CXX) $< $(CXXFLAGS) $(HLOOKUPFLAGS) -o $@
