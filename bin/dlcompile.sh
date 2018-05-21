#!/bin/bash

g++ -c -o bin/cat.o lib/cat.cc -I./lib/include
g++ -o bin/cat.so bin/cat.o bin/entity.o bin/tile.o -shared -fPIC
