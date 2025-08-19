#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "Game.h"
// #include <glm/glm.hpp>
// #include <sol/sol.hpp>

int main(int argc, char *argv[]) {
  // sol::state lua;
  // lua.open_libraries(sol::lib::base);
  // SDL_Init(SDL_INIT_EVERYTHING);

  // std::cout << "Hello, world!" << std::endl;

  Game game;

  game.Initialize();
  game.Run();

  return 0;
}
