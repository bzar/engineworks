#ifndef EW_INTERCEPTOR_H
#define EW_INTERCEPTOR_H

namespace ew
{
  template<typename T>
  class Interceptor
  {
  public:
    Interceptor() = default;
    virtual void before(T* t) {}
    virtual void after(T* t) {}
  };
}
#endif // EW_INTERCEPTOR_H
