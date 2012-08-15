#ifndef TILECOLLIDEPHASE_HH
#define TILECOLLIDEPHASE_HH

#include "ew/phase.h"
#include "ew/tilecollidableworld.h"

namespace ew
{
  class TileCollidePhase : public ew::Phase
  {
  public:
    TileCollidePhase(TileCollidableWorld* world) : world(world) {}
    void execute(float const delta);

  private:
    TileCollidableWorld* world;
  };
};
#endif