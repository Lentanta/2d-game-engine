# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++17 -I./libs

# -Wall for show warning
CPPFLAGS := -Wall -std=c++17
SOURCES := src/*.cpp
OUTPUT_FILE := game-engine

# Linking all SDL2
SDL_LINK := -lSDL2 -lSDL2_image

# Linking Lua script
LUA_LINK := -llua

build:
	${CXX} ${CXXFLAGS} ${SOURCES} ${SDL_LINK} ${LUA_LINK} -o ${OUTPUT_FILE} 

run:
	./game-engine

clean:
	rm ./game-engine


