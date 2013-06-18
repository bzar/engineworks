#include "ew/renderphase.h"
#include "ew/state.h"

void ew::RenderPhase::execute(const float)
{
  for(Renderable* u : state->entities.get<Renderable>())
  {
    u->render();
  }
}


