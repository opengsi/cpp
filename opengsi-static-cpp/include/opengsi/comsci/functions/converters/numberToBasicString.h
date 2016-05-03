/*
 * Copyright (C) 2016 Young-Mook Kang <youngmook@opengsi.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 */

/* 
 * File:   numberToBasicString.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 *
 */

#ifndef __OPEN_GSI_COMSCI_FUNCTIONS_CONVERTERS_NUMBERTOBASICSTRING_H_
#define __OPEN_GSI_COMSCI_FUNCTIONS_CONVERTERS_NUMBERTOBASICSTRING_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
# include <sstream>
# include "../../supports/basic_definition.h"

OPENGSI_BEGIN_FUNC_NAMESPACE
namespace gsiConvert {
    namespace temp_functions {
        template<typename _AnyType>
        OPENGSI_NAMESPACE::supports::BasicString
        __valueToBasicString(const _AnyType &theValue) {
            std::ostringstream localBuffer;
            localBuffer << theValue;
            return localBuffer.str();
        }
        
        template<typename _AnyType>
        const OPENGSI_NAMESPACE::supports::BasicString &
        __valueToBasicString(const _AnyType &theValue,
                             OPENGSI_NAMESPACE::supports::BasicString &theString) {
            std::ostringstream localBuffer;
            localBuffer << theValue;
            return theString = localBuffer.str();
        }        
    }

    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppShort);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppUShort);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppInt);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppUInt);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppLong);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppULong);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppFloat);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppDouble);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppLDouble);
# ifdef OPENGSI_ENABLE_LLONG
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppLLong);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppULLong);
# endif   
    
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppShort,  OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppUShort, OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppInt,    OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppUInt,   OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppLong,   OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppULong,  OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppFloat,  OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppDouble, OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppLDouble,OPENGSI_NAMESPACE::supports::BasicString&);
# ifdef OPENGSI_ENABLE_LLONG
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppLLong,  OPENGSI_NAMESPACE::supports::BasicString&);
    OPENGSI_NAMESPACE::supports::BasicString numberToBasicString(OPENGSI_NAMESPACE::CppULLong, OPENGSI_NAMESPACE::supports::BasicString&);
# endif       
}

#endif  /* __OPEN_GSI_COMSCI_FUNCTIONS_CONVERTERS_NUMBERTOBASICSTRING_H_ */

