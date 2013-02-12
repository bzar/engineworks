#ifndef GLFWRENDERCONTEXT_HH
#define GLFWRENDERCONTEXT_HH

#include "ew/rendercontext.h"
#include "GL/glfw3.h"

class GLFWRenderContext : public ew::RenderContext
{
public:
  GLFWRenderContext(GLFWwindow* window) : window(window)
  {
    
  }
  
  virtual void postRender()
  {
    glfwSwapBuffers(window);
  }
  
private:
  GLFWwindow* window;
};
#endif
