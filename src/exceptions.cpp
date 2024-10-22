/**
 * @file exceptions.cpp
 * @brief  Source file implementation of custom exceptions.
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 22, 2024
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


/*-------------------------------------------------------- STANDARD INCLUDES */

#include <utility> // std:: move
#include <string> // Our exception messages.

/*----------------------------------------------------------- LOCAL INCLUDES */

#include "exceptions.h" // This is an implementation of exceptions.

/*----------------------------------------------------- CLASS IMPLEMENTATION */

/**
 * @class VisLuaException
 * Extension of std::exception
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * VisLuaException Constructor.
 *
 */
vlua::VisLuaException::VisLuaException(std::string message) :
    _message(std::move(message))
{}

/*----------------------------------------------------- PUBLIC CLASS METHODS */


/**
 * VisLuaException message getter.
 *
 */
const char *vlua::VisLuaException::what() const noexcept {
  return _message.c_str();
}

/*----------------------------------------------------- CLASS IMPLEMENTATION */

/**
 * @class MaxWindowCountException
 * Exception thrown if the maximum number of application windows are reached.
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for MaxWindowCountException.
 *
 */

vlua::MaxWindowCountException::MaxWindowCountException(size_t maxWindowCount) :
    // std::format isn't widely available, so using concatenation instead.
    VisLuaException(std::string(
        "Maximum number of windows constructed. you may only have ") +
        std::to_string(maxWindowCount) + std::string("windows."))
{}

/*----------------------------------------------------- CLASS IMPLEMENTATION */

/**
 * @class WindowIDCollisionException
 * Exception thrown if there is an ID collision.
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for WindowIDCollisionException.
 *
 */
vlua::WindowIDCollisionException::WindowIDCollisionException() :
    VisLuaException("Window IDs must be unique.")
{}

/*----------------------------------------------------- CLASS IMPLEMENTATION */

/**
 * @class NULLWindowException
 * Exception thrown if the internal window pointer is a nullptr.
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for NULLWindowException.
 *
 */
vlua::NULLWindowException::NULLWindowException() :
    VisLuaException("Returned Window pointer is NULL.")
{}

/*----------------------------------------------------- CLASS IMPLEMENTATION */

/**
 * @class WindowCreationException
 * Exception thrown is window creation fails.
 */

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for WindowCreationException.
 *
 */
vlua::WindowCreationException::WindowCreationException() :
    VisLuaException("Window could not be created.")
{}
