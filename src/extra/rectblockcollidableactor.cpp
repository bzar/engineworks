#include "ew/rectblockcollidableactor.h"
#include "ew/rectblockcollidableblock.h"

bool ew::RectBlockCollidableActor::horizontalRectBlockCollision(RectBlockCollidableBlock &block, float const delta)
{
  RectCollisionInformation a = getRectCollisionInformation();
  RectCollisionInformation b = block.getRectCollisionInformation();
  RectCollisionInformation result = {
    a.vx > b.vx ? b.x - a.w : b.x + b.w,
    a.y, a.w, a.h, 0, a.vy

  };
  setRectCollisionInformation(result);
  return true;
}

bool ew::RectBlockCollidableActor::verticalRectBlockCollision(RectBlockCollidableBlock &block, const float delta)
{
  RectCollisionInformation a = getRectCollisionInformation();
  RectCollisionInformation b = block.getRectCollisionInformation();
  RectCollisionInformation result = {
    a.x, a.vy > b.vy ? b.y - a.h : b.y + b.h,
    a.w, a.h, a.vx, 0

  };
  setRectCollisionInformation(result);
  return true;
}

void ew::RectBlockCollidableActor::squishRectBlockCollision()
{
}



