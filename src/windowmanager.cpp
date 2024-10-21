/**
 * @file stub.cpp
 * @brief  A stub source file.
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 21, 2024
 * @note See header for full documentation.
 */

// TODO WindowManager does not check for unique ids.

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


/*-------------------------------------------------------- STANDARD INCLUDES */

#include <string> // for Window Title and ID
#include <memory> // Shared Pointers
#include <unordered_map> // class contains a hashmap
#include <vector> // class contains a vector

/*----------------------------------------------------------- LOCAL INCLUDES */

#include "windowmanager.h"

/*----------------------------------------------------- THIRD PARTY INCLUDES */

#include "GLFW/glfw3.h"

/*---------------------------------------------------- CLASS IMPLEMENTATIONS */

/**
 * @class WindowManager
 * Singleton class that manages application windows.
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

visuallua::WindowManager::WindowManager() {
  _windowList.reserve(_MAX_WINDOW_COUNT);
} // Constructor

/*--------------------------------------------------------------- DESTRUCTOR */

visuallua::WindowManager::~WindowManager() {
  _windowList.clear();
  _windowMap.clear();
} // Destructor

/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * Singleton accessor.
 */
visuallua::IWindowManager &visuallua::WindowManager::Instance() {
  static WindowManager instance;
  return instance;
} // Instance


/**
 * Creates a new Window.
 */
visuallua::Window_PTR visuallua::WindowManager::CreateNewWindow(
    int width, int height, std::string title, std::string id) {

  if(_windowList.size() >= _MAX_WINDOW_COUNT){
    // TODO Throw exception here.
  }

  if(_windowMap.contains(id)){
    // TODO Throw exception here.
  }

  GLFWwindow* rawWindow = glfwCreateWindow(
      width, height, title.c_str(), NULL, NULL);

  if(rawWindow == nullptr)
  {
    // TODO throw exception here.
  }

  auto window_ptr = std::make_shared<visuallua::Window>(rawWindow, id);
  _windowList.push_back(window_ptr);
  _windowMap[id] = window_ptr;

  return _windowList.back();
} // CreateNewWindow


/**
 * Returns the number of WindowPTR object instances in memory.
 */
size_t visuallua::WindowManager::NumberOfWindows() {
  return _windowList.size();
} // NumberOfWindows


/**
 * Get a WindowPTR object by array index.
 */
visuallua::Window_PTR visuallua::WindowManager::GetWindow(size_t index) {
  return _windowList.at(index);
} // GetWindow


/**
 * Get a WindowPTR object by unique string ID.
 */
visuallua::Window_PTR visuallua::WindowManager::GetWindow(std::string id) {
  return _windowMap.at(id);
} // GetWindow


/**
 * Destroy a WindowPTR object by WindowPTR object.
 */
int visuallua::WindowManager::DestroyWindow(visuallua::Window_PTR window) {
  _windowMap.erase(window->GetID());
  size_t index = _findWindowIndexFromValue(window);
  _windowList.erase(_windowList.begin() + index);

  return 1;
} // DestroyWindow


/**
 * Destroy a WindowPTR object by array index.
 */
int visuallua::WindowManager::DestroyWindow(size_t index) {
  return DestroyWindow(GetWindow(index));
} // DestroyWindow


/**
 * Destroy a WindowPTR object by unique string ID.
 */
int visuallua::WindowManager::DestroyWindow(std::string id) {
  Window_PTR window = _windowMap.at(id);
  return DestroyWindow(window);
} // DestroyWindow


/**
 * Sets WindowPTR object as current drawing context by WindowPTR object.
 */
void visuallua::WindowManager::SetCurrentContext(
    visuallua::Window_PTR window) {

  glfwMakeContextCurrent(window->GetRaw());
} // SetCurrentContext


/**
 * Sets WindowPTR object as current drawing context by array index.
 */
void visuallua::WindowManager::SetCurrentContext(size_t index) {
  glfwMakeContextCurrent(_windowList.at(index)->GetRaw());
} // SetCurrentContext


/**
 * Sets WindowPTR object as current drawing context by unique string id.
 */
void visuallua::WindowManager::SetCurrentContext(std::string id) {
  glfwMakeContextCurrent(_windowMap.at(id)->GetRaw());
} // SetCurrentContext


/**
 * Destroy all Windows.
 */
void visuallua::WindowManager::DestroyAll() {
  _windowList.clear();
  _windowMap.clear();
} // DestroyAll

/*---------------------------------------------------- PRIVATE CLASS METHODS */

/**
 * Find the index of the current Window object by value.
 */
size_t visuallua::WindowManager::_findWindowIndexFromValue(
    const visuallua::Window_PTR& window) {

  std::vector<Window_PTR>::iterator iter;
  iter = std::find(_windowList.begin(), _windowList.end(), window);
  return std::distance(_windowList.begin(), iter);
} // _findWindowIndexFromValue

