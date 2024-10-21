/**
 * @file window.cpp
 * @brief  Window class implementation source file.
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 21, 2024
 * @note See header for full documentation.
 */

/* MIT License

Copyright (c) 2024 Gabriel Gillette

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */


/*----------------------------------------------------------- LOCAL INCLUDES */

#include "window.h" // Header for our Window object.

/*----------------------------------------------------- THIRD PARTY INCLUDES */

#include "GLFW/glfw3.h" // We need GLFWWindow and some GLFW functions

/*---------------------------------------------------- CLASS IMPLEMENTATIONS */

/**
 * @class Window
 * Container for GLFWWindows
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

visuallua::Window::Window(GLFWwindow *GLFWWindow_PTR, std::string id) :
    _glfwWindow_PTR(GLFWWindow_PTR), _id(id)
{
} // constructor

/*--------------------------------------------------------------- DESTRUCTOR */

visuallua::Window::~Window() {
  glfwDestroyWindow(_glfwWindow_PTR);
} // destructor

/*--------------------------------------------------------- COPY CONSTRUCTOR */

visuallua::Window::Window(Window &other) {
  _id = other._id;
  _glfwWindow_PTR = other._glfwWindow_PTR;
} // copy constructor

/*-------------------------------------------------------------- COPY ASSIGN */

visuallua::Window &visuallua::Window::operator=(const Window &other) {
  if(this != &other) {
    glfwDestroyWindow(_glfwWindow_PTR);
    _glfwWindow_PTR = other._glfwWindow_PTR;
    _id = other._id;
  }
  return *this;
} // copy assignment operator

/*--------------------------------------------------------- MOVE CONSTRUCTOR */

visuallua::Window::Window(Window &&other) noexcept {
  _glfwWindow_PTR = other._glfwWindow_PTR;
  _id = other._id;
  other._glfwWindow_PTR = nullptr;
  other._id.clear();
} // move constructor

/*-------------------------------------------------------------- MOVE ASSIGN */

visuallua::Window &visuallua::Window::operator=(Window &&other) noexcept {
  if(this != &other) {
    glfwDestroyWindow(_glfwWindow_PTR);
    _glfwWindow_PTR = other._glfwWindow_PTR;
    _id = other._id;
    other._glfwWindow_PTR = nullptr;
    other._id.clear();
  }
  return *this;
} // move assignment operator


/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * Get the raw GLFWPointer.
 */
GLFWwindow *visuallua::Window::GetRaw() {
  return _glfwWindow_PTR;
} // GetRaw


/**
 * Get the Window's unique ID.
 */
std::string visuallua::Window::GetID() {
  return _id;
} // GetID
