#ifndef EW_RENDERPHASE_H
#define EW_RENDERPHASE_H

#include "ew/phase.h"
#include "ew/renderable.h"

namespace ew {
 class RenderPhase : public Phase
 {
 public:
   void execute(const float delta);
 };
}

#endif
