#include "ew/managephase.h"
#include "ew/managed.h"
#include <list>

ew::ManagePhase::ManagePhase(ew::State *state) :
  Phase(state)
{
}

ew::ManagePhase::~ManagePhase()
{
  // Copy pointers first, since deleting managed objects
  // modifies state->entities.get<Managed>(), causing
  // invalid reads if the container is being iterated
  std::list<Managed*> toDelete;
  for(Managed* m : state->entities.get<Managed>())
  {
    toDelete.push_back(m);
  }

  for(Managed* m : toDelete)
  {
    delete m;
  }
}

void ew::ManagePhase::execute(const float)
{
  for(ManagedToBeRemoved* m : state->entities.get<ManagedToBeRemoved>())
  {
    delete m;
  }

  state->entities.clear<ManagedToBeRemoved>();
}
