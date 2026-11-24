#include "player.h"
#include "map.h"
#include "ai.h"
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  // initialize the SDL video subsystem
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // create the window
  SDL_Window *window = SDL_CreateWindow("titletitletitle",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        800, 600,
                                        SDL_WINDOW_SHOWN);
  if (window == NULL) {
    fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
      SDL_Quit();
      return 1;
  }

  // create renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                              SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // main event loop to keep the window open and responsive
  int running = 1;
  SDL_Event event;

  while (running) {
  // poll events from the queue
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
    }

    SDL_SetRenderDrawColor(renderer, 100, 230, 60, 60);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
  }

  // cleanup and shut down
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
