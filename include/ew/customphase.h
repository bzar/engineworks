#ifndef EW_CUSTOMPHASE_H
#define EW_CUSTOMPHASE_H

#include "ew/phase.h"
#include "ew/state.h"

namespace ew
{
  class CustomPhaseHandler;

  class CustomPhase : public ew::Phase
  {
  public:
    CustomPhase(CustomPhaseHandler* handler, ew::State* state);

    void execute(const float delta);

  private:
    CustomPhaseHandler* handler;
  };
}

#endif // EW_CUSTOMPHASE_H
