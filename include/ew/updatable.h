#ifndef EW_UPDATABLE_H
#define EW_UPDATABLE_H

namespace ew {
 class Updatable
 {
 public:
   virtual void update(float const delta) = 0;
 };
}

#endif
