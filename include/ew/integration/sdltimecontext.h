#ifndef SDLTIMECONTEXT_HH
#define SDLTIMECONTEXT_HH

#include "ew/timecontext.h"
#include "SDL/SDL.h"

class SDLTimeContext : public ew::TimeContext
{
public:
  virtual double timeInSeconds()
  {
    return SDL_GetTicks() / 1000.0;
  }
};
#endif
