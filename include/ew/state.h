#ifndef EW_STATE_H
#define EW_STATE_H

#include <list>
#include "interfacemap.h"


namespace ew {
  class Engine;

  class State
  {
  public:
    State();
    virtual ~State();

    virtual void process(float const delta);
    virtual void enter();
    virtual void exit();

    InterfaceMap singletons;
    InterfaceMultimap entities;

    Engine* engine;

  protected:
    friend class Engine;
    std::list<class Phase*> phases;

  };
}

#endif // EW_STATE_H
