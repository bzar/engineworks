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
      bool first = true;
      float x = 0;
      for(auto r : world->getCollidingTiles(r2))
      {
        if(r1.x < r2.x)
        {
          x = first || r.x < x ? r.x : x;
        }
        else
        {
          x = first || r.x + r.w > x ? r.x + r.w : x;
        }
        first = false;
      }

      if(!first)
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
      bool first = true;
      float y = 0;
      for(auto r : world->getCollidingTiles(r2))
      {
        if(r1.y < r2.y)
        {
          y = first || r.y < y ? r.y : y;
        }
        else
        {
          y = first || r.y + r.h > y  ? r.y + r.h : y;
        }
        first = false;
      }

      if(!first)
      {
        if(r1.y < r2.y)
        {
          t->tileCollisionBottom(y);
        }
        else
        {
          t->tileCollisionTop(y);
        }
        first = false;
      }
    }
  }
}
