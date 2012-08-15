#ifndef CONTROLPHASE_HH
#define CONTROLPHASE_HH

#include "ew/phase.h"
#include "ew/controllableworld.h"
#include "ew/controlcontext.h"

namespace ew
{
  class ControlPhase : public Phase
  {
  public:
    ControlPhase(ControllableWorld* world, ControlContext* context);
    void execute(float const delta);

  private:
    ControllableWorld* world;
    ControlContext* context;
  };
};
#endif
