#ifndef GLHCKGLFWRENDERCONTEXT_HH
#define GLHCKGLFWRENDERCONTEXT_HH

#include "glfwrendercontext.h"
#include "glhck/glhck.h"

class GlhckGLFWRenderContext : public GLFWRenderContext
{
public:
  GlhckGLFWRenderContext(GLFWwindow window) : GLFWRenderContext(window)
  {
  }

  virtual void postRender()
  {
    glhckRender();
    GLFWRenderContext::postRender();
    glhckClear();
  }
};
#endif
