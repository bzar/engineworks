#include "ew/world.h"
#include "ew/entity.h"
#include "ew/renderable.h"
#include "ew/updatable.h"
#include "ew/collidable.h"

ew::World::World() :
  entities(), entitiesToInsert(), entitiesToRemove(), maintenanceCallbacks()
{
}

ew::World::~World()
{
  for(Entity* e : entities)
  {
    delete e;
  }
}

void ew::World::addEntity(Entity* entity)
{
  entitiesToInsert.insert(entity);
}

void ew::World::removeEntity(Entity* entity)
{
  auto toBeInserted = entitiesToInsert.find(entity);
  if(toBeInserted != entitiesToInsert.end())
  {
    delete entity;
    entitiesToInsert.erase(toBeInserted);
  }
  else
  {
    entitiesToRemove.insert(entity);
  }
}

void ew::World::maintenance()
{
  for(Entity* entity : entitiesToRemove)
  {
    entities.erase(entity);
    delete entity;
  }

  entities.insert(entitiesToInsert.begin(), entitiesToInsert.end());
  entitiesToInsert.clear();
  entitiesToRemove.clear();

  for(auto cb : maintenanceCallbacks)
  {
    cb();
  }

}

void ew::World::onMaintenance(std::function<void ()> callback)
{
  maintenanceCallbacks.push_front(callback);
}