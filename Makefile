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

CXX = g++
CXXFLAGS = -c -Wall -Werror
HLOOKUPFLAGS = -I$(LIB_H)

$(BIN)/main: $(OBJ_FILES) $(BIN)/cat.so
	$(CXX) $^ -o $(BIN)/main -ldl

$(BIN)/cat.so: $(SO_OBJ_FILES)
	$(CXX) $^ -o $(BIN)/cat.so -shared -fPIC

$(OBJ)/%.o: $(LIB)/%.cc $(LIB_H)/%.h
	$(CXX) $(CXXFLAGS) $(HLOOKUPFLAGS) $< -o $@

$(OBJ)/%.o: $(LIB)/world/%.cc $(LIB_H)/%.h
	$(CXX) $(CXXFLAGS) $(HLOOKUPFLAGS) $< -o $@

$(OBJ)/%.o: $(LIB)/%.cc
	$(CXX) $(CXXFLAGS) $(HLOOKUPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)/*.o $(BIN)/main $(BIN)/cat.so
