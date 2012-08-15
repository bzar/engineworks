#include "ew/tilecollidableworld.h"
#include "ew/tilecollidable.h"

ew::TileCollidableWorld::TileCollidableWorld() :
  World(), tileCollidables(), tileCollidablesToInsert()
{
  onMaintenance([&]() {
    if(!tileCollidablesToInsert.empty())
    {
      tileCollidables.insert(tileCollidablesToInsert.begin(), tileCollidablesToInsert.end());
      tileCollidablesToInsert.clear();
    }
  });

}

ew::TileCollidableWorld::~TileCollidableWorld()
{
  for(TileCollidable* t : tileCollidables)
  {
    t->tileCollidableUnregistered();
  }
}


void ew::TileCollidableWorld::registerTileCollidable(TileCollidable* tileCollidable)
{
  tileCollidablesToInsert.insert(tileCollidable);
}

void ew::TileCollidableWorld::unregisterTileCollidable(TileCollidable* tileCollidable)
{
  tileCollidablesToInsert.erase(tileCollidable);
  tileCollidables.erase(tileCollidable);
  tileCollidable->tileCollidableUnregistered();
}

std::set<ew::TileCollidable*> const& ew::TileCollidableWorld::getTileCollidables()
{
  return tileCollidables;
}
