#include "ew/updatephase.h"
#include "ew/state.h"

ew::UpdatePhase::UpdatePhase(ew::State *state) :
  Phase(state)
{
}

void ew::UpdatePhase::execute(const float delta)
{
  for(Updatable* u : state->entities.get<Updatable>())
  {
    u->update(delta);
  }
}


