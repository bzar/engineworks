#ifndef GLHCKGLFWRENDERCONTEXT_HH
#define GLHCKGLFWRENDERCONTEXT_HH

#include "ew/glfwrendercontext.h"
#include "GL/glhck.h"

class GlhckGLFWRenderContext : public GLFWRenderContext
{
public:
  GlhckGLFWRenderContext() : GLFWRenderContext()
  {
  }

  virtual void postRender()
  {
    GLFWRenderContext::postRender();
    glhckClear();
  }
};
#endif
