MKDIR = mkdir -p
CXX = g++
CXXFLAGS = -Wall -Werror
HLOOKUPFLAGS = -I./lib/include
ALLEGRO = -lallegro -lallegro_main -lallegro_primitives -lallegro_image -lallegro_dialog -lallegro_audio -lallegro_acodec

# OUT_DIR = bin
# IN_DIR = lib

# SOURCE_FILES = ${IN_DIR}/main.cc ${IN_DIR}/dlhandler.cc ${IN_DIR}/world/world.cc ${IN_DIR}/world/entities/entity.cc

# ${OUT_DIR}/%.o: ${IN_DIR}/%.cc
# 	g++ -c -o $@ $<

# ${MKDIR} ${OUT_DIR}
# ${CXX} -o ${OUT_DIR}/cat.so ${IN_DIR}/cat.cc ${IN_DIR}/world/entities/entity.cc -shared -fPIC ${CXXFLAGS}
# ${CXX} -o ${OUT_DIR}/main ${SOURCE_FILES} -ldl ${CXXFLAGS}

all:
	g++ -c -o bin/entity.o lib/world/entity.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/tile.o lib/world/tile.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/world.o lib/world/world.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/map.o lib/world/map.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/cat.o lib/cat.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/dlhandler.o lib/dlhandler.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/manager.o lib/manager.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/game.o lib/game.cc ${HLOOKUPFLAGS} ${CXXFLAGS}
	g++ -c -o bin/main.o lib/main.cc ${HLOOKUPFLAGS} ${CXXFLAGS}

	g++ -o bin/cat.so bin/cat.o bin/entity.o bin/tile.o -shared -fPIC ${CXXFLAGS}
	g++ -o bin/main bin/main.o bin/game.o bin/manager.o bin/dlhandler.o bin/map.o bin/entity.o bin/world.o bin/tile.o -ldl ${CXXFLAGS} ${ALLEGRO}
