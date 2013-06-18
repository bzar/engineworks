#ifndef EW_MANAGED_H
#define EW_MANAGED_H

#include "ew/state.h"

namespace ew {
 class ManagedToBeRemoved
 {
 public:
   virtual ~ManagedToBeRemoved() {}
 };

 class Managed : public ManagedToBeRemoved
 {
 public:
   Managed(State* state);
   void remove();

 private:
   State* state;
 };
}

#endif
