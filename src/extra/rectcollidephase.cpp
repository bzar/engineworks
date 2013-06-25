#include "ew/rectcollidephase.h"
#include "ew/rectcollidable.h"

ew::RectCollidePhase::RectCollidePhase(ew::State *state) : ew::Phase(state)
{
}

void ew::RectCollidePhase::execute(const float delta)
{
  auto iterable = state->entities.get<RectCollidable>();
  for(auto c1i = iterable.begin(); c1i != iterable.end(); ++c1i)
  {
    for(auto c2i = c1i; c2i != iterable.end(); ++c2i)
    {
      if(c2i == c1i)
        continue;

      RectCollidable* c1 = *c1i;
      RectCollidable* c2 = *c2i;
      RectCollidable::RectCollisionInformation i1 = c1->getRectCollisionInformation();
      RectCollidable::RectCollisionInformation i2 = c2->getRectCollisionInformation();

      if(i1.x > i2.x + i2.w || i1.y > i2.y + i2.h ||
         i1.x + i1.w < i2.x || i1.y + i1.h < i2.y)
        continue;

      c1->handleRectCollision(c2);
      c2->handleRectCollision(c1);
    }
  }
}
