#!/bin/bash

echo "Compiling cat.so..."
g++ -c -o bin/cat.o lib/cat.cc -I./lib/include
g++ -o bin/cat.so bin/cat.o bin/object.o -shared -fPIC
echo "Done."
