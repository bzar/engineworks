#include "ew/managed.h"

ew::Managed::Managed(ew::State *state) : ManagedToBeRemoved(), state(state)
{
}

void ew::Managed::remove()
{
  state->entities.insert<ManagedToBeRemoved>(this);
}
