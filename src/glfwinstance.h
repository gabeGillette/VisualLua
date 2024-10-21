/**
 * @file glfwinstance.h
 * @brief  Header for GLFWInstance singleton class.
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

#ifndef GLFWINSTANCE_H
#define GLFWINSTANCE_H

/*-------------------------------------------------------- STANDARD INCLUDES */

/*----------------------------------------------------------- LOCAL INCLUDES */

/*----------------------------------------------------- THIRD PARTY INCLUDES */

#include "GLFW/glfw3.h" // We need access to GLFW


/**
 @namespace visuallua
 VisualLua internal namespace.
*/
namespace visuallua {



/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class Stub
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 */
class GLFWInstance {

private:

/*---------------------------------------------------- PRIVATE CLASS METHODS */



/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for GFLWInstance.
 */
GLFWInstance();

public:

/*--------------------------------------------------------------- DESTRUCTOR */

/**
 * Destructor for GLFWInstance.
 */
virtual ~GLFWInstance();

/*--------------------------------------------------------- COPY CONSTRUCTOR */

/**
 * Copy Constructor for GLFWInstance.
 *
 * UNUSED
 */
GLFWInstance(const GLFWInstance& other) = delete;

/*-------------------------------------------------------------- COPY ASSIGN */

/**
 * Copy Assignment operator for GLFWInstance.
 *
 * UNUSED
 */
GLFWInstance& operator=(const GLFWInstance& other) = delete;

/*--------------------------------------------------------- MOVE CONSTRUCTOR */

/**
 * Move Constructor for GLFWInstance
 *
 * UNUSED
 */
GLFWInstance(GLFWInstance&& GLFWInstance) noexcept = delete;

/*-------------------------------------------------------------- MOVE ASSIGN */

/**
 * Move Assignment Operator for GLFWInstance
 *
 * UNUSED
 */
GLFWInstance& operator=(GLFWInstance&& other) noexcept = delete;

/*----------------------------------------------------- PUBLIC CLASS MEMBERS */

/*----------------------------------------------------- PUBLIC CLASS METHODS */


/**
 * Singleton accessor.
 *
 * Use this to access the GLFWInstance singleton class.
 *
 * @return Reference to GLFWInstance singleton.
 */
static GLFWInstance& Instance();


/**
 * Initialize GLFW.
 *
 * You must run this method before using the singleton.
 *
 * @return int value, 1 for success, 0 for for fail.
 */
int Init();

/**
 * Deinitialize GLFW.
 *
 * Clean up GLFW.
 *
 * @return void.
 */
void Deinit();



};

}; 

#endif
