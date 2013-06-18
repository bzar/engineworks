#ifndef EW_UPDATEPHASE_H
#define EW_UPDATEPHASE_H

#include "ew/phase.h"
#include "ew/updatable.h"
#include "ew/state.h"

namespace ew {
 class UpdatePhase : public Phase
 {
 public:
   UpdatePhase(State* state);
   void execute(const float delta);
 };
}

#endif
