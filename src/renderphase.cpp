#include "ew/renderphase.h"
#include "ew/renderable.h"

void ew::RenderPhase::execute(float const delta)
{
  for(Renderable* r : world->getRenderables())
  {
    r->render(context);
  }
}
