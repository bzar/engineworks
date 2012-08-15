#ifndef RENDERABLEWORLD_HH
#define RENDERABLEWORLD_HH

#include <set>
#include "ew/world.h"

namespace ew
{
  class Renderable;

  class RenderableWorld : public virtual World
  {
  public:
    class ZComparator
    {
    public:
      bool operator()(Renderable const* a, Renderable const* b);
    };

    RenderableWorld();
    virtual ~RenderableWorld();

    void registerRenderable(Renderable* renderable);
    void unregisterRenderable(Renderable* renderable);
    std::set<Renderable*, ZComparator> const& getRenderables();

  private:
    std::set<Renderable*> renderablesToInsert;
    std::set<Renderable*, ZComparator> renderables;
  };
};
#endif
