/**
 * @file exceptions.h
 * @brief  Custom exceptions header.
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 22, 2024
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

#ifndef VISLUA_EXCEPTIONS_H
#define VISLUA_EXCEPTIONS_H

/*-------------------------------------------------------- STANDARD INCLUDES */

#include <exception> // Obviously we need exceptions.
#include <string> // For exception descriptions.


/**
 @namespace vlua
 VisualLua internal namespace.
*/
namespace vlua {


/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class VisLuaException
 * Extension of std::exception
 *
 */
class VisLuaException : public std::exception {

private:

/*---------------------------------------------------- PRIVATE CLASS MEMBERS */

/**
 @var _message;
 @brief Exception description.
*/
std::string _message;

public:


/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * VisLuaException Constructor.
 *
 */
explicit VisLuaException(std::string message);

/*--------------------------------------------------------------- DESTRUCTOR */

/**
 * VisLuaException Destructor.
 *
 */
~VisLuaException() override = default;

/*--------------------------------------------------------- COPY CONSTRUCTOR */

/**
 * VisLuaException Copy Constructor.
 *
 */
VisLuaException(const VisLuaException& other) = default;

/*-------------------------------------------------------------- COPY ASSIGN */

/**
 * VisLuaException Copy assignment operator.
 *
 */
VisLuaException& operator=(
    const VisLuaException& other) = default;

/*--------------------------------------------------------- MOVE CONSTRUCTOR */

/**
 * VisLuaException Move Constructor.
 *
 */
VisLuaException(
    VisLuaException&& MaxWindowCountException) noexcept = default;

/*-------------------------------------------------------------- MOVE ASSIGN */

/**
 * VisLuaException Move assignment operator.
 *
 */
VisLuaException& operator=(
        VisLuaException&& other) noexcept = default;


/*----------------------------------------------------- PUBLIC CLASS METHODS */

/**
 * VisLuaException message getter.
 *
 * Override of std::exception::what().
 *
 * @return Exception message.
 */
[[nodiscard]] const char* what() const noexcept override;

};

/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class MaxWindowCountException
 * Exception thrown if the maximum number of application windows are reached.
 *
 */
class MaxWindowCountException : public VisLuaException {

public:

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for MaxWindowCountException.
 *
 * @param maxWindowCount maxWindowCount for message.
 */
explicit MaxWindowCountException(size_t maxWindowCount);

};

/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class WindowIDCollisionException
 * Exception thrown if there is an ID collision.
 *
 */
class WindowIDCollisionException : public VisLuaException {

public:

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for WindowIDCollisionException.
 *
 */
WindowIDCollisionException();

};

/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class NULLWindowException
 * Exception thrown if the internal window pointer is a nullptr.
 *
 */
class NULLWindowException : public VisLuaException {

public:

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for NULLWindowException.
 *
 */
NULLWindowException();

};

/*--------------------------------------------------- CLASS DECLARATION BODY */

/**
 * @class WindowCreationException
 * Exception thrown is window creation fails.
 *
 */
class WindowCreationException : public VisLuaException {

public:

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * Constructor for WindowCreationException.
 *
 */
WindowCreationException();

};

}

#endif
