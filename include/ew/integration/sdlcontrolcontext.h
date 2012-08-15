#ifndef SDLCONTROLCONTEXT_HH
#define SDLCONTROLCONTEXT_HH

#include "ew/controlcontext.h"
#include "SDL/SDL.h"

class SDLControlContext : public ew::ControlContext
{
public:
  SDLControlContext() :
    ew::ControlContext()
  {
  }

  virtual bool keyDown(int const key)
  {
    return SDL_GetKeyState(nullptr)[key];
  }

  virtual void update()
  {
    SDL_PumpEvents();
  }
};

#endif