#include "ew/controlphase.h"
#include "ew/controllable.h"

ew::ControlPhase::ControlPhase(ControllableWorld* world, ControlContext* context) :
  world(world), context(context)
{
}

void ew::ControlPhase::execute(float const delta)
{
  if(world->getControllableFocus() != nullptr)
  {
    world->getControllableFocus()->control(context);
  }
  else
  {
    for(Controllable* c : world->getControllables())
    {
      c->control(context);
    }
  }
}
