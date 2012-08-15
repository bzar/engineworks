#ifndef ENTITY_HH
#define ENTITY_HH

#include "ew/world.h"
#include "ew/uniqueid.h"

namespace ew
{
  class Entity
  {
  public:
    Entity(World* world) : world(world) { world->addEntity(this); }
    virtual ~Entity() {}
    virtual UID getEntityId() const = 0;

  protected:
    World* world;

  };
};

#endif