#include <iostream>
#include "GLFW/glfw3.h"
#include "windowmanager.h"
#include "glfwinstance.h"

int main(void)
{

  visuallua::GLFWInstance::Instance().Init();

  visuallua::Window_PTR testWindow =
      visuallua::WindowManager::Instance().CreateNewWindow(
          640, 480, "VisualLua", "main");

  visuallua::WindowManager::Instance().SetCurrentContext(testWindow);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(testWindow->GetRaw()))
  {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(testWindow->GetRaw());

    /* Poll for and process events */
    glfwPollEvents();
  }

  visuallua::WindowManager::Instance().DestroyAll();
  visuallua::GLFWInstance::Instance().Deinit();

  return 0;
}


