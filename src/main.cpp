#include <iostream>
#include "GLFW/glfw3.h"
#include "glfwinstance.h"

int main(void)
{
  //GLFWwindow* window;

  /* Initialize the library */
  //if (!glfwInit())
    //return -1;
   visuallua::GLFWInstance::Instance().Init();

  /* Create a windowed mode window and its OpenGL context */
  visuallua::GLFWInstance::Instance().GetWindowPTR() = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!visuallua::GLFWInstance::Instance().GetWindowPTR())
  {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(visuallua::GLFWInstance::Instance().GetWindowPTR());

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(visuallua::GLFWInstance::Instance().GetWindowPTR()))
  {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(visuallua::GLFWInstance::Instance().GetWindowPTR());

    /* Poll for and process events */
    glfwPollEvents();
  }

  visuallua::GLFWInstance::Instance().Deinit();

  //glfwTerminate();
  return 0;
}


