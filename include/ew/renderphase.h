#ifndef RENDERPHASE_HH
#define RENDERPHASE_HH

#include "ew/phase.h"
#include "ew/renderableworld.h"
#include "ew/rendercontext.h"

namespace ew
{
  class RenderPhase : public Phase
  {
  public:
    RenderPhase(RenderableWorld* world, RenderContext* context) : world(world), context(context) {}
    void execute(float const delta);

  private:
    RenderableWorld* world;
    RenderContext* context;
  };
};
#endif
