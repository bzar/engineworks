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

  private:
    bool rectsCollide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
  };
}
#endif // EW_RECTCOLLIDEPHASE_H
