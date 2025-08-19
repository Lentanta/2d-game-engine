#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "Game.h"
#include <SDL2/SDL.h>
#include <ostream>

// Implement constructor
Game::Game() {
  isRunning = false;
  std::cout << "Game constructor called" << std::endl;
}

Game::~Game() {
  // TODO:

  std::cout << "Game de-constructor called\n" << std::endl;
}

void Game::Initialize() {
  // 1.Initialize DSL
  int initRes = SDL_Init(SDL_INIT_EVERYTHING);
  if (initRes != 0) {
    std::cerr << "Initialize SDL failed" << std::endl;
    return;
  };

  // 2.Creating a window
  window = SDL_CreateWindow( //
      "2D Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,
      600, SDL_WINDOW_BORDERLESS);

  if (!window) {
    std::cerr << "Error creating SDL window" << std::endl;
    return;
  }

  // 3.Creating a renderer
  int defaultConfig = -1;
  renderer = SDL_CreateRenderer(window, defaultConfig, 0);

  if (!renderer) {
    std::cerr << "Error creating SDL renderer" << std::endl;
    return;
  }

  // When everything succesfull
  std::cout << "SDL Init everything succesfull" << std::endl;
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
      if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
      };
      break;
    }
  }
}

void Game::Update() {}
void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
  SDL_RenderClear(renderer);

  // TODO: redner game objects

  SDL_RenderPresent(renderer);
}

void Game::Run() {
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
