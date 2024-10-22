/**
 * @file window.h
 * @brief  Header for Window type, wrapper for GLFWWindow
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 21, 2024
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

#ifndef WINDOW_H
#define WINDOW_H

/*-------------------------------------------------------- STANDARD INCLUDES */

#include <memory> // Shared Pointers
#include <string> // window id

/*----------------------------------------------------- THIRD PARTY INCLUDES */

#include "GLFW/glfw3.h" // We need GLFWWindow

/*----------------------------------------------------- FORWARD DECLARATIONS */

/**
 @namespace vlua
 VisualLua internal namespace.
*/
namespace vlua {

/**
 * @class Window
 * Container for GLFWWindows
 */
class Window {

/*---------------------------------------------------- PRIVATE CLASS MEMBERS */

private:

/**
 * @var _glfwWindow_PTR
 * Internal pointer to GLFWwindow type.
 */
GLFWwindow* _glfwWindow_PTR;

/**
 * @var _id
 * Window's unique ID.
 */
std::string _id;

public:

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for Window object.
 *
 * @param GLFWWindow_PTR raw pointer to GLFWwindow object.
 * @param id Unique string ID.
 */
Window(GLFWwindow* GLFWWindow_PTR, std::string id);

/*--------------------------------------------------------------- DESTRUCTOR */

/**
 * Destructor for Window object.
 */
virtual ~Window();

/*--------------------------------------------------------- COPY CONSTRUCTOR */

/**
 * Copy constructor for Window object.
 * @param other Window to copy.
 */
Window(Window& other);

/*-------------------------------------------------------------- COPY ASSIGN */

/**
 * Copy assignment operator for Window object
 * @param other Window to copy from.
 * @return Copy of Window.
 */
Window& operator=(const Window& other);

/*--------------------------------------------------------- MOVE CONSTRUCTOR */

/**
 * Move Constructor for Window object.
 * @param other Window to move from.
 */
Window(Window&& other) noexcept;

/*-------------------------------------------------------------- MOVE ASSIGN */

/**
 * Move assign operator for Window object.
 * @param other Window to move from.
 * @return Moved Window object.
 */
Window& operator=(Window&& other) noexcept;

/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * Get the raw GLFWPointer.
 * @return GLFWwindow pointer.
 */
GLFWwindow* GetRaw();


/**
 * Get the Window's unique ID.
 * @return Window's ID.
 */
std::string GetID();

};

/*----------------------------------------------------------------- TYPEDEFS */

typedef std::shared_ptr<Window> Window_PTR;

}

#endif
