#ifndef SDLRENDERCONTEXT_HH
#define SDLRENDERCONTEXT_HH

#include "ew/rendercontext.h"
#include "SDL/SDL.h"

class SDLRenderContext : public ew::RenderContext
{
public:
  SDLRenderContext(SDL_Surface* screen) : RenderContext(), screen(screen), ticks(SDL_GetTicks()) {}
  virtual void preRender()
  {
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF ));
  }
  virtual void postRender()
  {
    SDL_Flip(screen);
  }
  virtual void waitUntilNextFrame()
  {
    int prev = ticks;
    ticks = SDL_GetTicks();
    if(ticks < prev + 1000/FPS)
    {
      SDL_Delay(1000/FPS - (ticks - prev));
    }
  }

  SDL_Surface* getScreen() const { return screen; }

private:
  static int const FPS = 60;
  SDL_Surface* screen;
  int ticks;
};
#endif
