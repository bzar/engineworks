#include "ew/customphase.h"
#include "ew/customphasehandler.h"

ew::CustomPhase::CustomPhase(CustomPhaseHandler* handler, ew::State *state) : ew::Phase(state), handler(handler)
{
}

void ew::CustomPhase::execute(const float delta)
{
  handler->executeCustomPhase(delta, state);
}
