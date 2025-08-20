# -Wall for show warning
CPPFLAGS := -Wall -std=c++17
SOURCES := src/*.cpp
OUTPUT_FILE := game-engine

# Linking everthing in libs folder
LIBS_LINK := -I"./libs/" 

# Linking all SDL2
SDL_LINK := -lSDL2 -lSDL2_image

# Linking Lua script
LUA_LINK := -llua

build:
	g++ ${CPPFLAGS} ${SOURCES} ${LIBS_LINK} ${SDL_LINK} ${LUA_LINK} -o ${OUTPUT_FILE} 

run:
	./game-engine

clean:
	rm ./game-engine


