#ifndef RENDERABLE_HH
#define RENDERABLE_HH

#include "ew/entity.h"
#include "ew/renderableworld.h"
#include "ew/rendercontext.h"

namespace ew
{
  class Renderable : public virtual Entity
  {
  public:
    Renderable(RenderableWorld* world, int zIndex = 0, int layer = 0) :
      Entity(world), renderableWorld(world), layer(layer), zIndex(zIndex)
    {
      renderableWorld->registerRenderable(this);
    }
    virtual ~Renderable() { if(renderableWorld != nullptr) renderableWorld->unregisterRenderable(this); }
    virtual void render(RenderContext* context) = 0;
    virtual int getLayer() const { return layer; }
    virtual int getZIndex() const { return zIndex; }
    void renderableUnregistered() { renderableWorld = nullptr; }

  private:
    RenderableWorld* renderableWorld;
    int const layer;
    int const zIndex;
  };
};
#endif
