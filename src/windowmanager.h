/**
 * @file windowmanager.h
 * @brief  Header file for WindowManager object
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

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

/*-------------------------------------------------------- STANDARD INCLUDES */

#include <string> // for Window Title and ID
#include <memory> // Shared Pointers
#include <unordered_map> // class contains a hashmap
#include <vector> // class contains a vector

/*----------------------------------------------------------- LOCAL INCLUDES */

#include "window.h" // Window and Window_PTR objects
#include "iwindowmanager.h" // WindowManager Interface

/*----------------------------------------------------- THIRD PARTY INCLUDES */

#include "GLFW/glfw3.h"

/**
 @namespace vlua
 VisualLua internal namespace.
*/
namespace vlua {

/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class WindowManager
 * Singleton class that manages application windows.
 */
class WindowManager : public IWindowManager {

private:

/*---------------------------------------------------- PRIVATE CLASS MEMBERS */

/**
 @var _MAX_WINDOW_COUNT;
 @brief Maximum number of windows.
*/
const size_t _MAX_WINDOW_COUNT = 256;

/**
 @var _windowList;
 @brief Vector of WindowPTR object instances.
*/
std::vector<Window_PTR> _windowList;

/**
 @var _windowMap;
 @brief Hashmap of WindowPTR object instances.
*/
std::unordered_map<std::string, Window_PTR> _windowMap;

/*---------------------------------------------------- PRIVATE CLASS METHODS */

/**
 * Find the index of the current Window object by value.
 *
 * @param window Window to find index of.
 * @return index of window.
 */
size_t _findWindowIndexFromValue(const Window_PTR& window);

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for WindowManager.
 */
WindowManager();

/*---------------------------------------------------- PRIVATE CLASS METHODS */

public:


/*--------------------------------------------------------------- DESTRUCTOR */

/**
 * Destructor for WindowManager.
 */
virtual ~WindowManager();

/*--------------------------------------------------------- COPY CONSTRUCTOR */

/**
 * Copy Constructor for WindowManager.
 *
 * UNUSED
 */
WindowManager(const WindowManager& other) = delete;

/*-------------------------------------------------------------- COPY ASSIGN */

/**
 * Copy Assignment operator for WindowManager.
 *
 * UNUSED
 */
WindowManager& operator=(const WindowManager& other) = delete;

/*--------------------------------------------------------- MOVE CONSTRUCTOR */

/**
 * Move Constructor for WindowManager
 *
 * UNUSED
 */
WindowManager(WindowManager&& other) noexcept = delete;

/*-------------------------------------------------------------- MOVE ASSIGN */

/**
 * Move Assignment Operator for WindowManager
 *
 * UNUSED
 */
WindowManager& operator=(WindowManager&& other) noexcept = delete;

/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * Singleton accessor.
 *
 * Use this to access the WindowManager singleton class.
 *
 * @return Reference to IWindowManager singleton.
 */
static IWindowManager& Instance();


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
Window_PTR CreateNewWindow(
    int width, int height, std::string title, std::string id) override;


/**
 * Returns the number of WindowPTR object instances in memory.
 *
 * @return size_t of the number of WindowPTR object instances.
 */
size_t NumberOfWindows() override;


/**
 * Get a WindowPTR object by array index.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  The array index to grab WindowPTR from.
 * @return WindowPTR object.
 */
Window_PTR GetWindow(size_t index) override;


/**
 * Get a WindowPTR object by unique string ID.
 *
 * @param  id  Unique string ID.
 * @return WindowPTR object.
 */
Window_PTR GetWindow(std::string id) override;


/**
 * Destroy a WindowPTR object by WindowPTR object.
 *
 * @param  window  Window to destroy.
 * @return void
 */
int DestroyWindow(Window_PTR window) override;


/**
 * Destroy a WindowPTR object by array index.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  The array index to of the WindowPTR we want to destroy.
 * @return void
 */
int DestroyWindow(size_t index) override;


/**
 * Destroy a WindowPTR object by unique string ID.
 *
 * @param  id  The unique string id of the WindowPTR we want to destroy.
 * @return void
 */
int DestroyWindow(std::string id) override;


/**
 * Sets WindowPTR object as current drawing context by WindowPTR object.
 *
 * Recommended only for iterating through objects.
 *
 * @param  window  WindowPTR to make current.
 * @return void
 */
void SetCurrentContext(Window_PTR window) override;


/**
 * Sets WindowPTR object as current drawing context by array index.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  The array index of the WindowPTR we want to make current.
 * @return void
 */
void SetCurrentContext(size_t index) override;


/**
 * Sets WindowPTR object as current drawing context by unique string id.
 *
 * Recommended only for iterating through objects.
 *
 * @param  index  Unique string id of the WindowPTR we want to make current.
 * @return void
 */
void SetCurrentContext(std::string id) override;


/**
 * Destroy all Windows.
 *
 * @return void
 */
void DestroyAll();

};

}

#endif
