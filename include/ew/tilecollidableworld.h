#ifndef TILECOLLIDABLEWORLD_HH
#define TILECOLLIDABLEWORLD_HH

#include "ew/world.h"
#include <set>
#include <vector>

namespace ew
{
  class TileCollidable;

  class TileCollidableWorld : public virtual ew::World
  {
  public:
    struct TileCollideRect
    {
      float x;
      float y;
      float w;
      float h;
    };

    TileCollidableWorld();
    virtual ~TileCollidableWorld();

    void registerTileCollidable(TileCollidable* tileCollidable);
    void unregisterTileCollidable(TileCollidable* tileCollidable);
    std::set<TileCollidable*> const& getTileCollidables();

    virtual std::vector<TileCollideRect> getCollidingTiles(TileCollideRect const& rect) = 0;

  private:
    std::set<TileCollidable*> tileCollidablesToInsert;
    std::set<TileCollidable*> tileCollidables;
  };
};
#endif
