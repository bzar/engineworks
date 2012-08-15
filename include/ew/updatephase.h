#ifndef UPDATEPHASE_HH
#define UPDATEPHASE_HH

#include "ew/phase.h"
#include "ew/updatableworld.h"

namespace ew
{
  class UpdatePhase : public Phase
  {
  public:
    UpdatePhase(UpdatableWorld* world) : world(world) {}
    void execute(float const delta);

  private:
    UpdatableWorld* world;
  };
};
#endif
