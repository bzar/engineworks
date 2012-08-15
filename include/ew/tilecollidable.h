#ifndef TILECOLLIDABLE_HH
#define TILECOLLIDABLE_HH

#include "ew/entity.h"
#include "ew/tilecollidableworld.h"

namespace ew
{
  class TileCollidable : public virtual ew::Entity
  {
  public:
    TileCollidable(TileCollidableWorld* world) : ew::Entity(world), tileCollidableWorld(world)
    {
      tileCollidableWorld->registerTileCollidable(this);
    }
    virtual ~TileCollidable() { if(tileCollidableWorld != nullptr) tileCollidableWorld->unregisterTileCollidable(this); }
    void tileCollidableUnregistered() { tileCollidableWorld = nullptr; }

    virtual TileCollidableWorld::TileCollideRect getTileCollideRect() = 0;
    virtual void moveHorizontally(float const delta) = 0;
    virtual void moveVertically(float const delta) = 0;

    virtual void tileCollisionTop(float const y) = 0;
    virtual void tileCollisionBottom(float const y) = 0;
    virtual void tileCollisionLeft(float const x) = 0;
    virtual void tileCollisionRight(float const x) = 0;

  private:
    TileCollidableWorld* tileCollidableWorld;
  };
};
#endif
