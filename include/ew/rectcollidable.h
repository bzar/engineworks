#ifndef EW_RECTCOLLIDABLE_H
#define EW_RECTCOLLIDABLE_H

namespace ew
{
  class RectCollidable
  {
  public:
    struct RectCollisionInformation
    {
      RectCollisionInformation(float x, float y, float w, float h, float vx, float vy) :
        x(x), y(y), w(w), h(h), vx(vx), vy(vy)
      {
      }

      float x = 0.0f;
      float y = 0.0f;
      float w = 0.0f;
      float h = 0.0f;
      float vx = 0.0f;
      float vy = 0.0f;
    };

    virtual RectCollisionInformation getRectCollisionInformation() = 0;
    virtual void setRectCollisionInformation(RectCollisionInformation const& newRectCollisionInformation) = 0;
    virtual void handleRectCollision(RectCollidable*) {}
  };
}
#endif // EW_RECTCOLLIDABLE_H
