#ifndef EW_RECTBLOCKCOLLIDEPHASE_H
#define EW_RECTBLOCKCOLLIDEPHASE_H

#include "ew/phase.h"
#include "ew/state.h"

namespace ew
{
  class RectBlockCollidePhase : public ew::Phase
  {
  public:
    RectBlockCollidePhase(ew::State* state);

    void execute(const float delta);

  private:
    static bool rectsCollide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
  };
}
#endif // EW_RECTBLOCKCOLLIDEPHASE_H
