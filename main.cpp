#include "SDL.h"
#include <random>
#include <vector>
#include <iostream>

#include "Vec3.h"
#include "Sphere.h"
#include "LightSource.h"

const int M = 600; // Width
const int N = 600; // Height

std::vector <Sphere> spheres;
std::vector <LightSource> light_sources;

void addFigures() {
  light_sources.push_back(LightSource(1, 0, 0, Color(255, 255, 255)));

  spheres.push_back(Sphere(0,    -1, 3,    1, Color(242,  76,  39)));
  spheres.push_back(Sphere(-2,    1, 4,    1, Color( 86, 185, 208)));
  spheres.push_back(Sphere(2,     1, 3,    1, Color(1,  255,  39)));
  spheres.push_back(Sphere(0, -5001, 0, 5000, Color(251, 186,  66)));
}

void renderFigures(SDL_Renderer *renderer) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      double x = (2.0 * i) / M - 1,
             y = 1 - (2.0 * j)/ N;
      Vec3 scr(x, y, 1);
      Color scr_clr(0, 0, 0);

      Vec3 res(0, 0, 0),
           res_norm(0, 0, 0),
           cur_res(0, 0, 0);

      for (Sphere i: spheres) {
        cur_res = crossing(i, scr);
        if (cur_res.length() != 0 &&
           (cur_res.length() < res.length() || res.length() == 0)) {
          res = cur_res;
          res_norm = (i.o - res);
          scr_clr = i.color;
        }
      }

      for (LightSource i: light_sources) {
        Vec3 source_dir = i.o - res;

        // bool no_obstacles = true;
        // for (Sphere i: spheres) {
        //   Vec3 crs = crossing2(i, source_dir);
        //   if (crs.length() != 0 && crs.length() > 0 && crs.length() < source_dir.length()) {
        //     no_obstacles = false;
        //   }
        // }

        scr_clr = Color(scr_clr.r() * cos(source_dir, res_norm),
                        scr_clr.g() * cos(source_dir, res_norm),
                        scr_clr.b() * cos(source_dir, res_norm));
      }

      SDL_SetRenderDrawColor(renderer, scr_clr.r(), scr_clr.g(), scr_clr.b(), SDL_ALPHA_OPAQUE);
      SDL_RenderDrawPoint(renderer, i, j);
    }
  }
}


int main(int argc, char *argv[]) {
  /* SDL initialization */
  SDL_Init(SDL_INIT_VIDEO);
  //Creating window
  SDL_Window *window = SDL_CreateWindow("Stupid Renderer", 100, 100, M, N, SDL_WINDOW_SHOWN);
  //Creating render
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_RenderClear(renderer);

  addFigures();
  renderFigures(renderer);

  /* SDL drawing */
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);

  /* SDL closing */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
