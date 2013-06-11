#ifndef GLFWCONTROLCONTEXT_HH
#define GLFWCONTROLCONTEXT_HH

#include "ew/controlcontext.h"
#include "GLFW/glfw3.h"

class GLFWControlContext : public ew::ControlContext
{
public:
  GLFWControlContext(GLFWwindow* window) :
    ew::ControlContext(), window(window)
  {
  }

  virtual bool keyDown(int const key)
  {
    return glfwGetKey(window, key) == GLFW_PRESS;
  }

  virtual void update()
  {
    glfwPollEvents();
  }
private:
  GLFWwindow* window;
};

#endif
