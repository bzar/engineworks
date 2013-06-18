#ifndef EW_PHASE_H
#define EW_PHASE_H

namespace ew {
  class Phase
  {
  public:
    Phase(class State* state);
    virtual ~Phase();
    virtual void execute(float const delta) = 0;

  protected:
    class State* state;
  };
}
#endif // EW_PHASE_H
