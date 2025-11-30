#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

const int FPS = 30;

// 1000 is 1 second Ex: 1000 / 60 = 16.6667s per frame
// So if the PC is running more than 16.6667s then it have to wait
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game {

private:
  bool isRunning;
  int millisecsPrevFrame;
  SDL_Window *window;
  SDL_Renderer *renderer;

public:
  Game();
  ~Game();

  void Initialize();
  void Run();
  void Setup();
  void ProcessInput();
  void Update();
  void Render();
  void Destroy();

  int windowWidth;
  int windowHeight;
};

#endif
