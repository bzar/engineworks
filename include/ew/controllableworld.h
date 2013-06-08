#ifndef CONTROLLABLEWORLD_HH
#define CONTROLLABLEWORLD_HH

#include "ew/world.h"
#include <set>

namespace ew
{
  class Controllable;

  class ControllableWorld : public virtual World
  {
  public:
    ControllableWorld();
    virtual ~ControllableWorld();

    void registerControllable(Controllable* controllable);
    void unregisterControllable(Controllable* controllable);
    std::set<Controllable*> const& getControllables();

    void setControllableFocus(Controllable* focused);
    Controllable* getControllableFocus();

  private:
    std::set<Controllable*> controllablesToInsert;
    std::set<Controllable*> controllables;
    Controllable* focusedControllable;
  };
};
#endif
