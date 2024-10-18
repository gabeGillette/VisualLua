/**
 * @file stub.h
 * @brief  A stub header file.
 * @authors  Gabriel Gillette
 * @copyright  (c) 2024 Gabriel Gillette
 * @date Last Modified: Oct 17, 2024
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

#ifndef STUB_H
#define STUB_H

/*-------------------------------------------------------- STANDARD INCLUDES */

/*----------------------------------------------------------- LOCAL INCLUDES */

/*----------------------------------------------------- THIRD PARTY INCLUDES */

/*-------------------------------------------------------- MACRO DEFINITIONS */

/**
 @def STUB_MACRO
 Description here.
*/
// #define STUB_MACRO


/**
 @namespace stub
 Description here.
*/
namespace stub {

/*------------------------------------------------------- STRUCT DEFINITIONS */

/**
 @struct stub_struct stub.h "stub.h"
 @brief Description
  
*/
// struct stub_struct {
// } stub_struct;

/*----------------------------------------------------------------- TYPEDEFS */

/**
 @typedef stub_in_alias
 @brief Description
*/
// typdef int stub_int_alias

/*-------------------------------------------NAMESPACE VARIABLE DECLARATIONS */

/**
 @var stub_namespace_variable;
 @brief Description
*/
// int stub_namespace_variable;

/*------------------------------------------ NAMESPACE FUNCTION DECLARATIONS */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of functions's parameter
 * @param  ...
 * @return Description of the return value
 */
// void stub_func(); 

/*--------------------------------------------------- CLASS DECLARATION BODY */

class Stub {

private:

/*---------------------------------------------------- PRIVATE CLASS MEMBERS */

/**
 @var stub_member;
 @brief Description
*/
int stub_member;

/*---------------------------------------------------- PRIVATE CLASS METHODS */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
void stub_method();

public:

/*-------------------------------------------------------------- CONSTRUCTOR */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
Stub();

/*--------------------------------------------------------------- DESTRUCTOR */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
virtual ~Stub();

/*--------------------------------------------------------- COPY CONSTRUCTOR */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
Stub(const Stub& other);

/*-------------------------------------------------------------- COPY ASSIGN */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
Stub& operator=(const Stub& other);

/*--------------------------------------------------------- MOVE CONSTRUCTOR */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
Stub(Stub&& other) noexcept;

/*-------------------------------------------------------------- MOVE ASSIGN */

/**
 * <A short one line description>
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  someParameter  Description of method's parameter
 * @param  ...
 * @return Description of the return value
 */
Stub& operator=(Stub&& other) noexcept;

/*----------------------------------------------------- PUBLIC CLASS MEMBERS */

/*----------------------------------------------------- PUBLIC CLASS METHODS */

};

}; 

#endif
