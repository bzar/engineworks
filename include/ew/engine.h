#ifndef ENGINE_HH
#define ENGINE_HH

#include <map>

#include "ew/state.h"
#include "ew/timer.h"
#include "ew/controlcontext.h"
#include "ew/rendercontext.h"
#include "ew/timecontext.h"

namespace ew
{
  class Engine
  {
  public:
    Engine(ControlContext* controlContext, RenderContext* renderContext, TimeContext* timeContext);

    void run();
    void quit();
    void addState(int id, State* state);
    void setState(int id);
    ControlContext* getControlContext() const;
    RenderContext* getRenderContext() const;
    TimeContext* getTimeContext() const;
    Timer const& getTimer() const;

  private:
    ControlContext* controlContext;
    RenderContext* renderContext;
    TimeContext* timeContext;
    std::map<int, State*> states;
    State* current;
    State* next;

    Timer timer;
    bool running;
  };
};
#endif
