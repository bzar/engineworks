#include "ew/engine.h"
#include "ew/state.h"
#include "ew/phase.h"
#include "ew/rolemanager.h"

#include <iostream>

class Interface1
{
public:
  virtual void foo() = 0;
};

class Interface2
{
public:
  virtual void bar() = 0;
};

class Concrete1 : public Interface1
{
public:
  Concrete1(ew::State* state) : roles(this, state) {}
  void foo() override { std::cout << "Concrete 1 as Interface 1" << std::endl; }
private:
  ew::RoleManager<Concrete1, Interface1> roles;
};

class Concrete2 : public Interface2
{
public:
  Concrete2(ew::State* state) : roles(this, state) {}
  void bar() override { std::cout << "Concrete 2 as Interface 2" << std::endl; }
private:
  ew::RoleManager<Concrete2, Interface2> roles;
};

class Concrete12 : public Interface1, public Interface2
{
public:
  Concrete12(ew::State* state) : roles(this, state) {}
  void foo() override { std::cout << "Concrete 12 as Interface 1" << std::endl; }
  void bar() override { std::cout << "Concrete 12 as Interface 2" << std::endl; }
private:
  ew::RoleManager<Concrete12, Interface1, Interface2> roles;
};

class Phase1 : public ew::Phase
{
public:
  Phase1(ew::State* state) : ew::Phase(state) {}
  void execute(const float delta) override
  {
    for(Interface1* i : state->entities.get<Interface1>())
    {
      i->foo();
    }
  }
};

class Phase2 : public ew::Phase
{
public:
  Phase2(ew::State* state) : ew::Phase(state) {}
  void execute(const float delta) override
  {
    for(Interface2* i : state->entities.get<Interface2>())
    {
      i->bar();
    }
  }
};


class State1 : public ew::State
{
public:
  State1() : ew::State()
  {
    phases = {new Phase1(this), new Phase2(this)};
  }
};

int main()
{
  ew::Engine engine;
  State1 state1;

  Concrete1 c1(&state1);
  Concrete2 c2(&state1);
  Concrete12 c12(&state1);

  engine.addState(0, &state1);

  engine.setState(0);

  engine.run();
  engine.advance(42.0f);
  engine.quit();

  return 0;
}

