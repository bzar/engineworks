#ifndef EW_ENGINE_H
#define EW_ENGINE_H

#include "interfacemap.h"
#include "state.h"
#include "interceptor.h"

#include <unordered_map>
#include <list>

namespace ew {
  class Engine
  {
  public:
    Engine();
    void run();
    void advance(float const delta);
    void quit();
    bool isRunning();

    void addState(int id, State* state);
    void setState(int id);
    State* getState(int id);

    void addInterceptor(Interceptor<Engine>* interceptor);

    InterfaceMap singletons;
    InterfaceMultimap entities;

  private:
    std::unordered_map<int, State*> states;
    std::list<Interceptor<Engine>*> interceptors;
    State* current;
    State* next;
    bool running;

  };
}

#endif // EW_ENGINE_H
