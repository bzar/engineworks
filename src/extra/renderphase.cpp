#include "ew/renderphase.h"
#include "ew/state.h"

ew::RenderPhase::RenderPhase(State *state) : Phase(state)
{
}

void ew::RenderPhase::execute(const float)
{
  for(Renderable* u : state->entities.get<Renderable>())
  {
    u->render();
  }
}


