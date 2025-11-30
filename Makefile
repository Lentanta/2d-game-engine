# Compiler and flags
CXX := g++
# -Wall for show warning
CXXFLAGS := -Wall -std=c++17 

INCLUDE_PATH := -I./libs
SOURCE_FILES := src/*.cpp \
								src/Game/*.cpp \
								src/Logger/*.cpp
OBJ_FILE := game-engine

# Linking SDL2 and Lua script
SDL_LINK := -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
LUA_LINK := -llua

build:
	${CXX} ${CXXFLAGS} ${INCLUDE_PATH} ${SOURCE_FILES} ${SDL_LINK} ${LUA_LINK} -o ${OBJ_FILE} 

run:
	./game-engine

clean:
	rm ./game-engine


