#include "SDL.h"
#include <random>
#include <vector>


const int M = 600; // Width
const int N = 600; // Height


int main(int argc, char *argv[]) {
  /* SDL initialization */
  SDL_Init(SDL_INIT_VIDEO);
  //Creating window
  SDL_Window *window = SDL_CreateWindow("Stupid Renderer", 100, 100, M, N, SDL_WINDOW_SHOWN);
  //Creating render
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_RenderClear(renderer);


  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      SDL_SetRenderDrawColor(renderer, (255.0*i/M), 128, (255.0*j/N), SDL_ALPHA_OPAQUE);
      SDL_RenderDrawPoint(renderer, i, j);
    }
  }


  /* SDL drawing */
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);

  /* SDL closing */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
