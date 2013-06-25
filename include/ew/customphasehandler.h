#ifndef EW_CUSTOMPHASEHANDLER_H
#define EW_CUSTOMPHASEHANDLER_H

namespace ew {
  class State;

  class CustomPhaseHandler
  {
  public:
    virtual void executeCustomPhase(float const delta, State* state) = 0;
  };
}
#endif // EW_CUSTOMPHASEHANDLER_H
