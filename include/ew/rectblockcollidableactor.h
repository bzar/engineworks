#ifndef EW_RECTBLOCKCOLLIDABLEACTOR_H
#define EW_RECTBLOCKCOLLIDABLEACTOR_H

#include "rectcollidable.h"

namespace ew {
  class RectBlockCollidableBlock;

  class RectBlockCollidableActor : public RectCollidable
  {
  public:
    virtual bool horizontalRectBlockCollision(RectBlockCollidableBlock& block, float const delta);
    virtual bool verticalRectBlockCollision(RectBlockCollidableBlock& block, float const delta);
    virtual void squishRectBlockCollision();
  };
}
#endif // EW_RECTBLOCKCOLLIDABLEACTOR_H
