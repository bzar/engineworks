#include "ew/engine.h"
#include "ew/state.h"
#include "ew/phase.h"
#include "ew/interceptor.h"

#include <iostream>

class Interceptor1 : public ew::Interceptor<ew::Engine>
{
  void before(ew::Engine* e) override
  {
    std::cout << "(1) Interceptor1 before" << std::endl;
  }

  void after(ew::Engine* e) override
  {
    std::cout << "(4) Interceptor1 after" << std::endl;
  }
};

class Phase1 : public ew::Phase
{
public:
  Phase1(ew::State* state) : ew::Phase(state) {}
  void execute(const float delta) override
  {
    std::cout << "(2) Phase1, delta = " << delta << std::endl;
  }
};

class Phase2 : public ew::Phase
{
public:
  Phase2(ew::State* state) : ew::Phase(state) {}
  void execute(const float delta) override
  {
    std::cout << "(3) Phase2, delta = " << delta << std::endl;
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
  Interceptor1 interceptor1;
  State1 state1;

  engine.addState(0, &state1);
  engine.addInterceptor(&interceptor1);

  engine.setState(0);

  engine.run();
  engine.advance(42.0f);
  engine.quit();
  engine.advance(1.0f);

  return 0;
}
