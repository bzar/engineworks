#include "ew/rectblockcollidephase.h"
#include "ew/rectblockcollidableactor.h"
#include "ew/rectblockcollidableblock.h"
#include <iostream>

static float const EPSILON = 0.001;
static float const ONE_PLUS_EPSILON = 1 + EPSILON;

ew::RectBlockCollidePhase::RectBlockCollidePhase(ew::State *state) : ew::Phase(state)
{
}

void ew::RectBlockCollidePhase::execute(const float delta)
{
  for(RectBlockCollidableActor* actor : state->entities.get<RectBlockCollidableActor>())
  {
    bool collisions = false;

    int xDir1 = 0;
    int yDir1 = 0;
    bool squished = false;

    collisions = false;

    for(RectBlockCollidableBlock* block : state->entities.get<RectBlockCollidableBlock>())
    {
      RectCollidable::RectCollisionInformation a = actor->getRectCollisionInformation();
      RectCollidable::RectCollisionInformation b = block->getRectCollisionInformation();

      bool horizontalCollision = rectsCollide(a.x, a.y - a.vy * delta, a.w, a.h, b.x, b.y - b.vy * delta, b.w, b.h);

      if(horizontalCollision)
      {
        int xDir2 = b.x > a.x ? -1 : 1;
        if(xDir1 != 0 && xDir1 != xDir2)
        {
          squished = true;
          break;
        }
        else
        {
          xDir1 = xDir2;
          collisions = actor->horizontalRectBlockCollision(*block, delta);
        }
      }
    }
    for(RectBlockCollidableBlock* block : state->entities.get<RectBlockCollidableBlock>())
    {
      RectCollidable::RectCollisionInformation a = actor->getRectCollisionInformation();
      RectCollidable::RectCollisionInformation b = block->getRectCollisionInformation();

      bool verticalCollision = rectsCollide(a.x, a.y, a.w, a.h, b.x, b.y, b.w, b.h);

      if(verticalCollision)
      {
        int yDir2 = b.y > a.y ? -1 : 1;
        if(yDir1 != 0 && yDir1 != yDir2)
        {
          squished = true;
          break;
        }
        else
        {
          yDir1 = yDir2;
          collisions = actor->verticalRectBlockCollision(*block, delta);
        }
      }
    }

    if(squished)
    {
      actor->squishRectBlockCollision();
    }
  }
}


bool ew::RectBlockCollidePhase::rectsCollide(float x1, float y1, float w1, float h1,
                                         float x2, float y2, float w2, float h2)
{
  return x1 < x2 + w2 && y1 < y2 + h2 &&
         x2 < x1 + w1 && y2 < y1 + h1;
}
