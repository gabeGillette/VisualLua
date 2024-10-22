/**
 * @file glfwinstance.cpp
 * @brief  GLFWInstance singleton class implementation.
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 21 2024
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

#include "glfwinstance.h"

/*----------------------------------------------------- THIRD PARTY INCLUDES */

#include "GLFW/glfw3.h" // We need access to GLFW

/*---------------------------------------------------- CLASS IMPLEMENTATIONS */

/**
 * @class GLFWInstance
 * GLFWInstance singleton class
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

vlua::GLFWInstance::GLFWInstance() = default;
// Constructor

/*--------------------------------------------------------------- DESTRUCTOR */

vlua::GLFWInstance::~GLFWInstance() = default;
// Destructor


/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * Singleton accessor.
 */
vlua::GLFWInstance &vlua::GLFWInstance::Instance() {
  static GLFWInstance instance;
  return instance;
} // Instance


/**
 * Initialize GLFW.
 */
int vlua::GLFWInstance::Init() {
  if (!glfwInit()) return 0;
  return 1;
} // Init


/**
 * Deinitialize GLFW.
 */
void vlua::GLFWInstance::Deinit() {
  glfwTerminate();
} // Deinit

