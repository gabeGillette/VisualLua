/**
 * @file iwindowmanager.h
 * @brief  WindowManager Interface.
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

#ifndef IWINDOWMANAGER_H
#define IWINDOWMANAGER_H

/*-------------------------------------------------------- STANDARD INCLUDES */

#include <string> // For window title and id

/*----------------------------------------------------------- LOCAL INCLUDES */

#include "window.h" // for window object

/**
 @namespace visuallua
 VisualLua internal namespace.
*/
namespace visuallua {

/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class IWindowManager
 * Interface for Window Manager class.
 */
class IWindowManager {

public:


/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * Creates a new Window.
 *
 * Creates a new window, this does not make it the current context.
 *
 * @param  width  The Window's width.
 * @param  height The Window's height.
 * @param  title  The Window's Title
 * @param  id     The Window's unique string ID.
 * @return Created WindowPTR object.
 */
virtual Window_PTR CreateNewWindow(
    int width, int height, std::string title, std::string id) = 0;


/**
 * Returns the number of WindowPTR object instances in memory.
 *
 * @return size_t of the number of WindowPTR object instances.
 */
virtual size_t NumberOfWindows() = 0;


/**
 * Get a WindowPTR object by array index.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  The array index to grab WindowPTR from.
 * @return WindowPTR object.
 */
virtual Window_PTR GetWindow(size_t index) = 0;


/**
 * Get a WindowPTR object by unique string ID.
 *
 * @param  id  Unique string ID.
 * @return WindowPTR object.
 */
virtual Window_PTR GetWindow(std::string id) = 0;


/**
 * Destroy a WindowPTR object by WindowPTR object.
 *
 * @param  window  Window to destroy.
 * @return void
 */
virtual int DestroyWindow(Window_PTR window) = 0;


/**
 * Destroy a WindowPTR object by array index.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  The array index to of the WindowPTR we want to destroy.
 * @return void
 */
virtual int DestroyWindow(size_t index) = 0;


/**
 * Destroy a WindowPTR object by unique string ID.
 *
 * @param  id  The unique string id of the WindowPTR we want to destroy.
 * @return void
 */
virtual int DestroyWindow(std::string id) = 0;


/**
 * Sets WindowPTR object as current drawing context by WindowPTR object.
 *
 * Recommended only for iterating through objects.
 *
 * @param  window  WindowPTR to make current.
 * @return void
 */
virtual void SetCurrentContext(Window_PTR window) = 0;


/**
 * Sets WindowPTR object as current drawing context by array index.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  The array index of the WindowPTR we want to make current.
 * @return void
 */
virtual void SetCurrentContext(size_t index) = 0;


/**
 * Sets WindowPTR object as current drawing context by unique string id.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  Unique string id of the WindowPTR we want to make current.
 * @return void
 */
virtual void SetCurrentContext(std::string id) = 0;

/**
 * Destroy all Windows.
 *
 * @return void
 */
virtual void DestroyAll() = 0;

};

}

#endif
