#ifndef EW_RECTCOLLIDEPHASE_H
#define EW_RECTCOLLIDEPHASE_H

#include "ew/phase.h"
#include "ew/state.h"

namespace ew
{
  class RectCollidePhase : public ew::Phase
  {
  public:
    RectCollidePhase(ew::State* state);

    void execute(const float delta);
  };
}
#endif // EW_RECTCOLLIDEPHASE_H
