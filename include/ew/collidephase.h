#ifndef COLLIDEPHASE_HH
#define COLLIDEPHASE_HH

#include "ew/phase.h"
#include "ew/collidableworld.h"

namespace ew
{
  class CollidePhase : public Phase
  {
  public:
    CollidePhase(CollidableWorld* world) : world(world) {}
    void execute(float const delta);

  private:
    CollidableWorld* world;
  };
};
#endif
