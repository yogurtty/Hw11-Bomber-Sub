#include "../headers/player.h"
#include "../headers/map.h"
//#include ".,/headers/ai.h"
#include <stdio.h>
#include <SDL2/SDL.h>


#define COLS (18)
#define ROWS (14)

int main(int argc, char *argv[]) {
  // initialize the SDL video subsystem
  fflush(stderr);
  fflush(stdout);
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
  SDL_Renderer *renderer = SDL_CreateRenderer(
    window, -1, SDL_RENDERER_ACCELERATED |
                SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // main event loop to keep the window open and responsive
  int running = 1;
  int player_row = 2;
  int player_col = 2;

  while (running) {
  SDL_Event event;
  // poll events from the queue
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
      else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
          case SDLK_ESCAPE:
            running = 0;
            break;
          case SDLK_UP:
          case SDLK_w: {
            if (player_row > 0) player_row--;
            break;
          }
          case SDLK_DOWN:
          case SDLK_s: {
            if (player_row > 0) player_row++;
            break;
          }
          case SDLK_LEFT:
          case SDLK_a: {
            if (player_col > 0) player_col--;
            break;
          }
          case SDLK_RIGHT:
          case SDLK_d: {
            if (player_col < (COLS - 1)) player_col++;
            break;
          }
          default: {
            break;
          }
        }
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
