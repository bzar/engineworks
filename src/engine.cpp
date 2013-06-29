#include "ew/engine.h"
#include "ew/world.h"

ew::Engine::Engine(ControlContext* controlContext, RenderContext* renderContext, TimeContext* timeContext) :
  controlContext(controlContext), renderContext(renderContext), timeContext(timeContext),
  states(), current(nullptr), timer(timeContext), running(false)
{
}

void ew::Engine::run()
{
  running = true;
  timer.tick();

  while(running)
  {
    if(next != nullptr)
    {
      if(current != nullptr)
        current->exit();

      current = next;
      current->getWorld()->maintenance();
      current->enter();
      next = nullptr;
    }
    double delta = timer.getDeltaTime();
    controlContext->update();
    renderContext->preRender();
    current->process(delta);
    current->getWorld()->maintenance();
    renderContext->postRender();
    renderContext->waitUntilNextFrame();
    timer.tick();
  }
}

void ew::Engine::quit()
{
  running = false;
}

void ew::Engine::addState(int id, State* state)
{
  auto existing = states.find(id);
  if(existing != states.end())
  {
    if(existing->second == current)
      return;

    delete existing->second;
  }

  states[id] = state;
}

void ew::Engine::setState(int id)
{
  auto existing = states.find(id);
  if(existing == states.end() || existing->second == current)
    return;

  next = existing->second;
}

ew::State* ew::Engine::getState(int id)
{
  auto existing = states.find(id);
  if(existing == states.end())
    return nullptr;

  return existing->second;
}

ew::ControlContext* ew::Engine::getControlContext() const
{
  return controlContext;
}

ew::RenderContext* ew::Engine::getRenderContext() const
{
  return renderContext;
}

ew::TimeContext* ew::Engine::getTimeContext() const
{
  return timeContext;
}

ew::Timer const& ew::Engine::getTimer() const
{
  return timer;
}
