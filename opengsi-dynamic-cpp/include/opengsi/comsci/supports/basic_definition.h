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
 * File:   basic_definition.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_BASIC_DEFINITION_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_BASIC_DEFINITION_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
# include <string>
# include <vector>
# include <utility>
# include <sstream>
# include <iostream>
# include <memory>
# include <iomanip>
# include "macros/char_type.h"

/** @brief basic_definitions
 *  @file basic_definitions.h
 *  @author Young-Mook Kang
 */

// The Definition of Variable Types

OPENGSI_BEGIN_NAMESPACE
typedef bool               CppBool;
typedef short int          CppShort;
typedef int                CppInt;
typedef long int           CppLong;
typedef unsigned short int CppUShort;
typedef unsigned int       CppUInt;
typedef unsigned long int  CppULong;
typedef float              CppFloat;
typedef double             CppDouble;
typedef long double        CppLDouble;
typedef char               CppChar;
typedef unsigned char      CppUChar;
typedef signed char        CppSChar;

# ifdef OPENGSI_ENABLE_LLONG
typedef long long          CppLLong;
typedef unsigned long long CppULLong;
# elif defined(OPENGSI_HAS_MS_INT64)
typedef __int64            CppLLong;
typedef unsigned __int64   CppULLong;
# endif

# ifdef OPENGSI_ENABLE_WCHAR
typedef wchar_t CppWChar;
typedef ::std::wstring        StdWString;
typedef ::std::wstringstream  StdWStringStream;
typedef ::std::wostringstream StdWOStringStream;
typedef ::std::wistringstream StdWIStringStream;
# endif

typedef ::std::string        StdString;
typedef ::std::stringstream  StdStringStream;
typedef ::std::ostringstream StdOStringStream;
typedef ::std::istringstream StdIStringStream;

using ::OPENGSI_NAMESPACE::supports::int_types::GsiInt8;
using ::OPENGSI_NAMESPACE::supports::int_types::GsiInt16;
using ::OPENGSI_NAMESPACE::supports::int_types::GsiInt32;
using ::OPENGSI_NAMESPACE::supports::int_types::GsiUInt8;
using ::OPENGSI_NAMESPACE::supports::int_types::GsiUInt16;
using ::OPENGSI_NAMESPACE::supports::int_types::GsiUInt32;
# if defined(OPENGSI_HAS_INT64)
using ::OPENGSI_NAMESPACE::supports::int_types::GsiInt64;
using ::OPENGSI_NAMESPACE::supports::int_types::GsiUInt64;
# elif defined(OPENGSI_HAS_MS_INT64)
typedef CppLLong   GsiInt64;
typedef CppULLong  GsiUInt64;
# endif

typedef CppBool                GsiBool;
typedef CppFloat               GsiFloat;
typedef CppDouble              GsiDouble;
typedef GsiDouble              GsiReal;

typedef GsiInt8                GsiByte;
typedef GsiInt16               GsiShort;
typedef GsiInt32               GsiInt;

# if defined(OPENGSI_HAS_INT64)
typedef GsiInt64  GsiLong;
# elif defined(OPENGSI_HAS_MS_INT64)
typedef GsiInt64  GsiLong;
# else
#  define OPENGSI_HAS_NO_INT64 OPENGSI_TRUE
typedef GsiInt32  GsiLong;
# endif

# ifdef OPENGSI_USE_QT
#  if   defined(OPENGSI_CPP_INT_BIT) && (OPENGSI_CPP_INT_BIT == 32)
typedef GsiInt  GsiIndex;
#  elif defined(OPENGSI_CPP_INT_BIT) && (OPENGSI_CPP_INT_BIT >= 64)
typedef GsiLong GsiIndex;
#  else
typedef CppInt  GsiIndex;
#  endif
typedef GsiIndex GsiSize;
# else //  ELSE OF OPENGSI_USE_QT
#  ifdef OPENGSI_USE_64BIT
typedef GsiLong GsiIndex;
#  else
typedef GsiInt  GsiIndex;
#  endif
typedef std::string::size_type GsiSize;
# endif // END OF OPENGSI_USE_QT

OPENGSI_END_NAMESPACE

# ifndef OPENGSI_HAS_NO_ROOT_GSI_OBJECTS
using OPENGSI_NAMESPACE::GsiBool;
using OPENGSI_NAMESPACE::GsiByte;
using OPENGSI_NAMESPACE::GsiDouble;
using OPENGSI_NAMESPACE::GsiFloat;
using OPENGSI_NAMESPACE::GsiIndex;
using OPENGSI_NAMESPACE::GsiInt;
using OPENGSI_NAMESPACE::GsiLong;
using OPENGSI_NAMESPACE::GsiReal;
using OPENGSI_NAMESPACE::GsiShort;
using OPENGSI_NAMESPACE::GsiSize;

using OPENGSI_NAMESPACE::GsiInt8;
using OPENGSI_NAMESPACE::GsiInt16;
using OPENGSI_NAMESPACE::GsiInt32;
using OPENGSI_NAMESPACE::GsiUInt8;
using OPENGSI_NAMESPACE::GsiUInt16;
using OPENGSI_NAMESPACE::GsiUInt32;

#  ifdef OPENGSI_HAS_INT64
using OPENGSI_NAMESPACE::GsiInt64;
using OPENGSI_NAMESPACE::GsiUInt64;
#  endif // OPENGSI_HAS_NO_INT64
# endif // OPENGSI_HAS_NO_ROOT_GSI_OBJECTS


#define __OPENGSI_DEFINITION_OF_DEFAULT_TYPES__(_Type_) \
typedef _Type_ this_type; \
typedef _Type_ * this_pointer; \
typedef _Type_ & this_reference; \
typedef const _Type_ * this_const_pointer; \
typedef const _Type_ & this_const_reference; \
typedef std::auto_ptr<this_type> this_auto_pointer;

#ifdef OPENGSI_USE_MSC
# define OPENGSI_TYPENAME
#else
# define OPENGSI_TYPENAME typename
#endif

# define OPENGSI_GENERATOR_OF_COMPARABLE_OPERATORS \
    friend GsiBool operator==(this_const_reference __x, this_const_reference __y) { \
        if(__x.compareTo(__y) == 0) return true; \
        else return false; \
    } \
    friend GsiBool operator <(this_const_reference __x, this_const_reference __y) { \
        if(__x.compareTo(__y) < 0) return true;\
        else return false;\
    }\
    friend GsiBool operator!=(this_const_reference __x, this_const_reference __y) {\
        return !(__x == __y);\
    }\
    friend GsiBool operator >(this_const_reference __x, this_const_reference __y) {\
        return  (__y < __x);\
    }\
    friend GsiBool operator>=(this_const_reference __x, this_const_reference __y) {\
        return !(__x < __y);\
    }\
    friend GsiBool operator<=(this_const_reference __x, this_const_reference __y) {\
        return !(__y < __x);\
    }
    
# define OPENGSI_GENERATOR_OF_COMPARABLE_OPERATORS_FOR_ALIKE_STRING \
    friend GsiBool operator==(this_const_reference __x, const GsiString & __y) { \
        if(__x.compareTo(__y) == 0) return true; \
        else return false; \
    } \
    friend GsiBool operator <(this_const_reference __x, const GsiString & __y) { \
        if(__x.compareTo(__y) < 0) return true;\
        else return false;\
    }\
    friend GsiBool operator!=(this_const_reference __x, const GsiString & __y) {\
        return !(__x == __y);\
    }\
    friend GsiBool operator >(this_const_reference __x, const GsiString & __y) {\
        return  (__y < __x);\
    }\
    friend GsiBool operator>=(this_const_reference __x, const GsiString & __y) {\
        return !(__x < __y);\
    }\
    friend GsiBool operator<=(this_const_reference __x, const GsiString & __y) {\
        return !(__y < __x);\
    }
    
#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_BASIC_DEFINITION_H_ */
