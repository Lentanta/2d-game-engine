
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "./Game/Game.h"

int main(int argc, char *argv[]) {
  Game game;

  game.Initialize();
  game.Run();
  game.Destroy();

  return 0;
}
