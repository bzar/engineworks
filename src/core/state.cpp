#include "ew/state.h"
#include "ew/phase.h"
#include "ew/engine.h"

ew::State::State() :
  engine(nullptr), singletons(), entities(), phases()
{
}

ew::State::~State()
{
  for(Phase* const phase : phases)
  {
    delete phase;
  }
}

void ew::State::process(float const delta)
{
  for(Phase* const phase : phases)
  {
    phase->execute(delta);
  }
}

void ew::State::enter()
{

}

void ew::State::exit()
{

}
