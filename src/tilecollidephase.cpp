#include "ew/tilecollidephase.h"
#include "ew/tilecollidable.h"

float const ew::TileCollidePhase::EPSILON = 0.00001;

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
          x = r.x < x + r2.w ? r.x - r2.w - EPSILON : x;
        }
        else
        {
          x = r.x + r.w > x ? r.x + r.w + EPSILON : x;
        }
      }

      t->setTileX(x);
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
          y = r.y < y + r2.h ? r.y - r2.h - EPSILON : y;
        }
        else
        {
          y = r.y + r.h > y  ? r.y + r.h + EPSILON : y;
        }
      }

      t->setTileY(y);
    }
  }
}
