#ifndef UPDATABLEWORLD_HH
#define UPDATABLEWORLD_HH

#include "ew/world.h"
#include <set>

namespace ew
{
  class Updatable;

  class UpdatableWorld : public virtual World
  {
  public:
    UpdatableWorld();
    virtual ~UpdatableWorld();

    void registerUpdatable(Updatable* updatable);
    void unregisterUpdatable(Updatable* updatable);
    std::set<Updatable*> const& getUpdatables();

  private:
    std::set<Updatable*> updatablesToInsert;
    std::set<Updatable*> updatables;
  };
};
#endif
