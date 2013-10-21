#ifndef GLFWCONTROLCONTEXT_HH
#define GLFWCONTROLCONTEXT_HH

#include "ew/controlcontext.h"
#include "GLFW/glfw3.h"

class GLFWControlContext : public ew::ControlContext
{
public:
  static void charCallback(GLFWwindow*, unsigned int codePoint)
  {
    if(codePoint < 128)
    {
      lastChar = static_cast<char>(codePoint);
    }
  }

  GLFWControlContext(GLFWwindow* window) :
    ew::ControlContext(), window(window)
  {
    glfwSetCharCallback(window, charCallback);
  }

  virtual bool keyDown(int const key)
  {
    return glfwGetKey(window, key) == GLFW_PRESS;
  }

  virtual void update()
  {
    lastChar = '\0';
    glfwPollEvents();
  }

  virtual char lastPressedChar()
  {
    return lastChar;
  }

private:
  GLFWwindow* window;
  static char lastChar;
};

char GLFWControlContext::lastChar = '\0';

#endif
