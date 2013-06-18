#include "ew/engine.h"
#include "ew/state.h"
#include "ew/updatable.h"
#include "ew/managed.h"
#include "ew/updatephase.h"
#include "ew/managephase.h"
#include "ew/rolemanager.h"

#include <iostream>
#include <string>

class ManagedEntity1 : public ew::Updatable, public ew::Managed
{
public:
  ManagedEntity1(ew::State* state, std::string const& name, int life) :
    ew::Updatable(), ew::Managed(state), roles(this, state),
    name(name), life(life)
  {
  }

  ~ManagedEntity1()
  {
    std::cout << "destructing " << name << std::endl;
  }

  void update(const float delta)
  {
    life -= 1;
    if(life <= 0)
    {
      std::cout << "removing " << name << std::endl;
      remove();
    }
    else
    {
      std::cout << name << " has " << life << " life left" << std::endl;
    }
  }

private:
  ew::RoleManager<ManagedEntity1, ew::Updatable, ew::Managed> roles;
  std::string name;
  int life;
};

class State1 : public ew::State
{
public:
  State1() : ew::State()
  {
    phases = {new ew::ManagePhase(this), new ew::UpdatePhase(this)};
  }
  ~State1()
  {
    std::cout << "~State1" << std::endl;
  }
};

int main()
{
  ew::Engine engine;
  State1 state1;

  new ManagedEntity1(&state1, "A", 1);
  new ManagedEntity1(&state1, "B", 2);
  new ManagedEntity1(&state1, "C", 3);

  engine.addState(0, &state1);

  engine.setState(0);

  engine.run();
  engine.advance(1.0f);
  engine.advance(1.0f);
  engine.quit();

  return 0;
}

