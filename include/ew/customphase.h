#ifndef EW_CUSTOMPHASE_H
#define EW_CUSTOMPHASE_H

#include "ew/phase.h"
#include "ew/state.h"

namespace ew
{
  template<typename T, void (T::*method)(float const)>
  class CustomPhase : public ew::Phase
  {
  public:
    CustomPhase(State* state, T* target) : Phase(state), target(target)
    {
    }

    void execute(const float delta)
    {
      (target->*method)(delta);
    }

  private:
    T* target;
  };
}

#endif // EW_CUSTOMPHASE_H
