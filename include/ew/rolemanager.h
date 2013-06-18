#ifndef EW_ROLEMANAGER_H
#define EW_ROLEMANAGER_H

#include "state.h"

namespace ew
{
  template<typename Target, typename... Roles>
  class RoleManager
  {
  public:
    RoleManager(Target* target, ew::State* state) : target(target), state(state)
    {
      addRoles<Roles...>();
    }
    ~RoleManager()
    {
      removeRoles<Roles...>();
    }

  private:
    template<typename Role, typename Role2, typename... Rest>
    void addRoles()
    {
      state->entities.insert<Role>(target);
      addRoles<Role2, Rest...>();
    }
    template<typename Role>
    void addRoles()
    {
      state->entities.insert<Role>(target);
    }

    template<typename Role, typename Role2, typename... Rest>
    void removeRoles()
    {
      state->entities.remove<Role>(target);
      removeRoles<Role2, Rest...>();
    }
    template<typename Role>
    void removeRoles()
    {
      state->entities.remove<Role>(target);
    }

    Target* target;
    State* state;
  };
}
#endif // EW_ROLEMANAGER_H
