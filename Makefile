MKDIR = mkdir -p
CXX = g++
CXXFLAGS = -Wall -Werror

OUT_DIR = bin
IN_DIR = lib

SOURCE_FILES = ${IN_DIR}/main.cc ${IN_DIR}/dlhandler.cc

all:
	${MKDIR} ${OUT_DIR}
	${CXX} -o ${OUT_DIR}/cat.so ${IN_DIR}/cat.cc -shared -fPIC ${CXXFLAGS}
	${CXX} -o ${OUT_DIR}/main ${SOURCE_FILES} -ldl ${CXXFLAGS}
