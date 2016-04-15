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
 * File:   basic_int_type.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDINT_H_FILES_BASIC_INT_TYPE_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDINT_H_FILES_BASIC_INT_TYPE_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

# include "../opengsi_macro.h"
# include "stdint_size.h"

OPENGSI_BEGIN_NAMESPACE
namespace supports { namespace int_types {

    typedef signed char            CppSChar;
    typedef unsigned char          CppUChar;

    typedef short int              CppShort;
    typedef unsigned short int     CppUShort;

    typedef int                    CppInt;
    typedef unsigned int           CppUInt;

    typedef long int               CppLong;
    typedef unsigned long int      CppULong;

# ifdef OPENGSI_ENABLE_LLONG
    typedef long long int          CppLLong;
    typedef unsigned long long int CppULLong;
# endif

// The least int types
    typedef CppSChar  GsiLeastInt8;
    typedef CppUChar  GsiLeastUInt8;

    typedef CppShort  GsiLeastInt16;
    typedef CppUShort GsiLeastUInt16;

# if   defined(OPENGSI_CPP_SHORT_BIT) && (OPENGSI_CPP_SHORT_BIT >= 32)
    typedef CppShort  GsiLeastInt32;
    typedef CppUShort GsiLeastUInt32;
# elif defined(OPENGSI_CPP_INT_BIT)   && (OPENGSI_CPP_INT_BIT   >= 32)
    typedef CppInt    GsiLeastInt32;
    typedef CppUInt   GsiLeastUInt32;
# else
    typedef CppLong   GsiLeastInt32;
    typedef CppULong  GsiLeastUInt32;
# endif

# if   defined(OPENGSI_CPP_SHORT_BIT) && (OPENGSI_CPP_SHORT_BIT >= 64)
    typedef CppShort  GsiLeastInt64;
    typedef CppUShort GsiLeastUInt64;
# elif defined(OPENGSI_CPP_INT_BIT)   && (OPENGSI_CPP_INT_BIT   >= 64)
    typedef CppInt    GsiLeastInt64;
    typedef CppUInt   GsiLeastUInt64;
# elif defined(OPENGSI_CPP_LONG_BIT)  && (OPENGSI_CPP_LONG_BIT  >= 64)
    typedef CppLong   GsiLeastInt64;
    typedef CppULong  GsiLeastUInt64;
# elif defined(OPENGSI_ENABLE_LLONG)
    typedef CppLLong  GsiLeastInt64;
    typedef CppULLong GsiLeastUInt64;
# endif


// Exact Int Types

# if defined(OPENGSI_HAS_EXACT_INT8)
#  if  (OPENGSI_CPP_CHAR_BIT == 8)
    typedef signed char   GsiInt8;
    typedef unsigned char GsiUInt8;
#  else
#   error "This Compiler not supported 8-bit Int Type, please watch out."
#  endif
# else
    typedef GsiLeastInt8  GsiInt8;
    typedef GsiLeastUInt8 GsiUInt8;
# endif

# if defined(OPENGSI_HAS_EXACT_INT16)
#  if   (OPENGSI_CPP_INT_BIT   == 16)
    typedef CppInt    GsiInt16;
    typedef CppUInt   GsiUInt16;
#  elif (OPENGSI_CPP_SHORT_BIT == 16)
    typedef CppShort  GsiInt16;
    typedef CppUShort GsiUInt16;
#  elif (OPENGSI_CPP_CHAR_BIT  == 16)
    typedef CppSChar  GsiInt16;
    typedef CppUChar  GsiUInt16;
#  else
#   error "This Compiler not supported 16-bit Int Type, please watch out."
#  endif
# else
    typedef GsiLeastInt16  GsiInt16;
    typedef GsiLeastUInt16 GsiUInt16;
# endif

# if defined(OPENGSI_HAS_EXACT_INT32)
#  if   (OPENGSI_CPP_INT_BIT   == 32)
    typedef CppInt    GsiInt32;
    typedef CppUInt   GsiUInt32;
#  elif (OPENGSI_CPP_LONG_BIT  == 32)
    typedef CppLong   GsiInt32;
    typedef CppULong  GsiUInt32;
#  elif (OPENGSI_CPP_SHORT_BIT == 32)
    typedef CppShort  GsiInt32;
    typedef CppUShort GsiUInt32;
#  elif (OPENGSI_CPP_CHAR_BIT  == 32)
    typedef CppSChar  GsiInt32;
    typedef CppUChar  GsiUInt32;
#  else
#   error "This Compiler not supported 32-bit Int Type, please watch out."
#  endif
# else
    typedef GsiLeastInt32  GsiInt32;
    typedef GsiLeastUInt32 GsiUInt32;
# endif

# if defined(OPENGSI_HAS_EXACT_INT64)
#  if   (OPENGSI_CPP_INT_BIT   == 64)
    typedef CppInt    GsiInt64;
    typedef CppUInt   GsiUInt64;
#  elif (OPENGSI_CPP_LONG_BIT  == 64)
    typedef CppLong   GsiInt64;
    typedef CppULong  GsiUInt64;
#  elif (OPENGSI_CPP_SHORT_BIT == 64)
    typedef CppShort  GsiInt64;
    typedef CppUShort GsiUInt64;
#  elif (OPENGSI_CPP_CHAR_BIT  == 64)
    typedef CppSChar  GsiInt64;
    typedef CppUChar  GsiUInt64;
#  else
#   if defined(OPENGSI_ENABLE_LLONG) && (OPENGSI_CPP_LLONG_BIT = 64)
    typedef CppLLong  GsiInt64;
    typedef CppULLong GsiUInt64;
#   else
#    error "This Compiler not supported 64-bit Int Type, please watch out."
#   endif
#  endif
# else
#  if defined(OPENGSI_HAS_INT64)
    typedef GsiLeastInt64  GsiInt64;
    typedef GsiLeastUInt64 GsiUInt64;
#  endif
# endif
        
}}

OPENGSI_END_NAMESPACE

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDINT_H_FILES_BASIC_INT_TYPE_H_ */
