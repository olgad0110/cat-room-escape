MKDIR = mkdir -p
CXX = g++
CXXFLAGS = -Wall -Werror
HLOOKUPFLAGS = -I./lib/include

# OUT_DIR = bin
# IN_DIR = lib

# SOURCE_FILES = ${IN_DIR}/main.cc ${IN_DIR}/dlhandler.cc ${IN_DIR}/world/world.cc ${IN_DIR}/world/objects/object.cc

# ${OUT_DIR}/%.o: ${IN_DIR}/%.cc
# 	g++ -c -o $@ $<

# ${MKDIR} ${OUT_DIR}
# ${CXX} -o ${OUT_DIR}/cat.so ${IN_DIR}/cat.cc ${IN_DIR}/world/objects/object.cc -shared -fPIC ${CXXFLAGS}
# ${CXX} -o ${OUT_DIR}/main ${SOURCE_FILES} -ldl ${CXXFLAGS}

all:
	g++ -c -o bin/object.o lib/world/object.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/world.o lib/world/world.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/map.o lib/world/map.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/cat.o lib/cat.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/dlhandler.o lib/dlhandler.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/main.o lib/main.cc ${HLOOKUPFLAGS} ${CXXFLAGS}

	g++ -o bin/cat.so bin/cat.o bin/object.o -shared -fPIC ${CXXFLAGS}
	g++ -o bin/main bin/main.o bin/dlhandler.o bin/map.o bin/object.o bin/world.o -ldl ${CXXFLAGS}
