#ifndef ENTITY_HH
#define ENTITY_HH

#include "ew/world.h"

namespace ew
{
  class Entity
  {
  public:
    Entity(World* world) : world(world) { world->addEntity(this); }
    virtual ~Entity() {}

  protected:
    World* world;

  };
}

#endif
