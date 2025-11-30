#include <SDL2/SDL_timer.h>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include "../Logger/Logger.h"
#include "Game.h"
#include <glm/glm.hpp>

// Implement constructor
Game::Game() {
  isRunning = false;
  Logger::Log("Game constructor called");
}

Game::~Game() {
  // TODO:...
  std::cout << "Game de-constructor called\n" << std::endl;
}

void Game::Initialize() {
  // 1.Initialize DSL
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Initialize SDL failed" << std::endl;
    return;
  };

  // 1a.Get current monitor width and height
  int8_t monitorIdx = 0;
  SDL_DisplayMode displayMode;
  SDL_GetCurrentDisplayMode(monitorIdx, &displayMode);

  windowWidth = 800;  // displayMode.w;
  windowHeight = 600; // displayMode.h;

  // 2.Creating a window
  window = SDL_CreateWindow(     //
      "2D Game Engine",          //
      SDL_WINDOWPOS_CENTERED,    //
      SDL_WINDOWPOS_CENTERED,    //
      windowWidth, windowHeight, //
      0);
  // SDL_WINDOW_BORDERLESS);

  if (!window) {
    std::cerr << "Error creating SDL window" << std::endl;
    return;
  }

  // 3.Creating a renderer
  int8_t defaultConfig = -1;
  renderer = SDL_CreateRenderer( //
      window,                    //
      defaultConfig,             //
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!renderer) {
    std::cerr << "Error creating SDL renderer" << std::endl;
    return;
  }

  // 4.Set fullscreen and prevent from stretching the window
  // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
  SDL_RenderSetLogicalSize(renderer, windowWidth, windowHeight);

  // When everything succesfull
  Logger::Log("SDL Init everything succesfull");
  isRunning = true;
}

void Game::ProcessInput() {
  SDL_Event sdlEvent;
  while (SDL_PollEvent(&sdlEvent)) {
    switch (sdlEvent.type) {

    case SDL_QUIT:
      isRunning = false;
      break;

    case SDL_KEYDOWN:
      if (sdlEvent.key.keysym.sym == SDLK_ESCAPE ||
          sdlEvent.key.keysym.sym == SDLK_q) {
        isRunning = false;
        Logger::Err("Force quit");
      };
      break;
    }
  }
}

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::Setup() {
  playerPosition = glm::vec2(10.0, 10.0);
  playerVelocity = glm::vec2(10, 5);
}

void Game::Update() {
  // If the PC is too fast then it have to wait by lock it in a while loop
  int delayTime = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPrevFrame);
  if (delayTime > 0 && delayTime < MILLISECS_PER_FRAME) {
    SDL_Delay(delayTime);
  };

  // delta time, divided by 1000 to convert millisec to sec
  double dt = (SDL_GetTicks() - millisecsPrevFrame) / 1000.0f;

  millisecsPrevFrame = SDL_GetTicks();

  playerPosition.x += playerVelocity.x * dt;
  playerPosition.y += playerVelocity.y * dt;
}

void Game::Render() {
  // Adding a blue background
  SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
  SDL_RenderClear(renderer);

  // Adding a white box
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_Rect rect = {10, 10, 50, 50};
  SDL_RenderFillRect(renderer, &rect);

  // Load a PNG texture with path
  SDL_Surface *surface = IMG_Load("./assets/images/tank-tiger-right.png");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  // Postion of the texture/image is display (x, y, w, h);
  SDL_Rect dstrect = {static_cast<int>(playerPosition.x),
                      static_cast<int>(playerPosition.y), 32, 32};

  // NULL is for portial of the texture image (Ex: 32x32 in a large image)
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_DestroyTexture(texture);

  // SDL supported double buffers
  SDL_RenderPresent(renderer);
}

void Game::Run() {
  Setup();

  // Main game loop
  while (isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Game::Destroy() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
