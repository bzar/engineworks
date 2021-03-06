#include "ew/engine.h"

ew::Engine::Engine() : states(), interceptors(), current(nullptr), next(nullptr), running(false)
{
}

void ew::Engine::run()
{
  running = true;
}

void ew::Engine::advance(const float delta)
{
  if(!running)
    return;

  if(next != nullptr)
  {
    if(current != nullptr)
      current->exit();

    current = next;
    current->enter();
    next = nullptr;
  }

  for(auto i = interceptors.begin(); i != interceptors.end(); ++i)
  {
    (*i)->before(this);
  }

  current->process(delta);

  for(auto i = interceptors.rbegin(); i != interceptors.rend(); ++i)
  {
    (*i)->after(this);
  }
}

void ew::Engine::quit()
{
  running = false;
}

bool ew::Engine::isRunning()
{
  return running;
}

void ew::Engine::addState(int id, State* state)
{
  if(getState(id) != nullptr)
    return;

  states[id] = state;
  state->engine = this;
}

void ew::Engine::setState(int id)
{
  State* existing = getState(id);
  if(existing == nullptr || existing == current)
    return;

  next = existing;
}

ew::State* ew::Engine::getState(int id)
{
  auto existing = states.find(id);
  if(existing == states.end())
    return nullptr;

  return existing->second;
}

void ew::Engine::addInterceptor(Interceptor<ew::Engine> *interceptor)
{
  interceptors.push_back(interceptor);
}
