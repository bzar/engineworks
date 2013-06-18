#ifndef EW_MANAGEPHASE_H
#define EW_MANAGEPHASE_H

#include "ew/phase.h"
#include "ew/state.h"

namespace ew {
  class ManagePhase : public ew::Phase
  {
  public:
    ManagePhase(State *state);
    ~ManagePhase();
    void execute(const float);
  };
}
#endif
