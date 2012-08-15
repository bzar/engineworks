#include "ew/tilecollidephase.h"
#include "ew/tilecollidable.h"

void ew::TileCollidePhase::execute(float const delta)
{
  for(TileCollidable* t : world->getTileCollidables())
  {
    TileCollidableWorld::TileCollideRect r1 = t->getTileCollideRect();
    t->moveHorizontally(delta);
    TileCollidableWorld::TileCollideRect r2 = t->getTileCollideRect();

    if(r1.x != r2.x)
    {
      float x = r2.x;
      for(auto r : world->getCollidingTiles(r2))
      {
        if(r1.x < r2.x)
        {
          x = r.x < x + r2.w ? r.x - r2.w : x;
        }
        else
        {
          x = r.x + r.w > x ? r.x + r.w : x;
        }
      }

      if(x != r2.x)
      {
        if(r1.x < r2.x)
        {
          t->tileCollisionRight(x);
        }
        else
        {
          t->tileCollisionLeft(x);
        }
      }
    }

    r1 = t->getTileCollideRect();
    t->moveVertically(delta);
    r2 = t->getTileCollideRect();

    if(r1.y != r2.y)
    {
      float y = r2.y;
      for(auto r : world->getCollidingTiles(r2))
      {
        if(r1.y < r2.y)
        {
          y = r.y < y + r2.h ? r.y - r2.h : y;
        }
        else
        {
          y = r.y + r.h > y  ? r.y + r.h : y;
        }
      }

      if(y != r2.y)
      {
        if(r1.y < r2.y)
        {
          t->tileCollisionBottom(y);
        }
        else
        {
          t->tileCollisionTop(y);
        }
      }
    }
  }
}
