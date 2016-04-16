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
 * File:   stdint_msc.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPENGSI_COMSCI_MACROS_STDINT_H_FILES_MSC_STDINT_H_
#define __OPENGSI_COMSCI_MACROS_STDINT_H_FILES_MSC_STDINT_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
# include <climits>
# include "../compilers/msc.h"

# if defined(OPENGSI_USE_MSC) && (OPENGSI_MSC_VER >= OPENGSI_MSC_VER_10)
#  include <stdint.h>
# elif defined(OPENGSI_USE_MSC) // (OPENGSI_MSC_VER < OPENGSI_MSC_VER_10)
#  ifdef __cplusplus
extern "C" {
#  endif
#  include <cwchar>
#  ifdef __cplusplus
}
#  endif

#  ifndef OPENGSI_MSC_W64
#   if (OPENGSI_MSC_VER >= OPENGSI_MSC_VER_7) && \
       (defined(_X86_) || defined(_M_IX86)) && (!defined(__midl))
#    define OPENGSI_MSC_W64 __w64
#   else
#    define OPENGSI_MSC_W64
#   endif
#  endif

#  if (OPENGSI_MSC_VER < OPENGSI_MSC_VER_7)
typedef   signed char       int8_t;
typedef   signed short     int16_t;
typedef   signed int       int32_t;
typedef unsigned char      uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned int      uint32_t;
#  else // (OPENGSI_MSC_VER < OPENGSI_MSC_VER_7)
typedef   signed __int8     int8_t;
typedef   signed __int16   int16_t;
typedef   signed __int32   int32_t;
typedef unsigned __int8    uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
#  endif
typedef   signed __int64   int64_t;
typedef unsigned __int64  uint64_t;

// The minimum-width integer types
typedef   int8_t      int_least8_t;
typedef  int16_t     int_least16_t;
typedef  int32_t     int_least32_t;
typedef  int64_t     int_least64_t;
typedef  uint8_t     uint_least8_t;
typedef uint16_t    uint_least16_t;
typedef uint32_t    uint_least32_t;
typedef uint64_t    uint_least64_t;

// The fastest integer types
typedef   int8_t       int_fast8_t;
typedef  int16_t      int_fast16_t;
typedef  int32_t      int_fast32_t;
typedef  int64_t      int_fast64_t;
typedef  uint8_t      uint_fast8_t;
typedef uint16_t     uint_fast16_t;
typedef uint32_t     uint_fast32_t;
typedef uint64_t     uint_fast64_t;

#  ifdef  OPENGSI_USE_64BIT
typedef int64_t           intptr_t;
typedef uint64_t         uintptr_t;
#  else //  OPENGSI_USE_64BIT
typedef OPENGSI_MSC_W64 int           intptr_t;
typedef OPENGSI_MSC_W64 unsigned int uintptr_t;
#  endif // OPENGSI_USE_64BIT

// The largest integer types
typedef int64_t   intmax_t;
typedef uint64_t  uintmax_t;

#  if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)
#   define INT8_MIN   ((-_I8_MAX) -1i8)
#   define INT8_MAX             _I8_MAX
#   define INT16_MIN ((-_I16_MAX)-1i16)
#   define INT16_MAX           _I16_MAX
#   define INT32_MIN (-(_I32_MAX)-1i32)
#   define INT32_MAX           _I32_MAX
#   define INT64_MIN ((-_I64_MAX)-1i64)
#   define INT64_MAX           _I64_MAX
#   define UINT8_MAX           _UI8_MAX
#   define UINT16_MAX         _UI16_MAX
#   define UINT32_MAX         _UI32_MAX
#   define UINT64_MAX         _UI64_MAX

#   define INT_LEAST8_MIN      INT8_MIN
#   define INT_LEAST8_MAX      INT8_MAX
#   define INT_LEAST16_MIN    INT16_MIN
#   define INT_LEAST16_MAX    INT16_MAX
#   define INT_LEAST32_MIN    INT32_MIN
#   define INT_LEAST32_MAX    INT32_MAX
#   define INT_LEAST64_MIN    INT64_MIN
#   define INT_LEAST64_MAX    INT64_MAX
#   define UINT_LEAST8_MAX    UINT8_MAX
#   define UINT_LEAST16_MAX  UINT16_MAX
#   define UINT_LEAST32_MAX  UINT32_MAX
#   define UINT_LEAST64_MAX  UINT64_MAX

#   define INT_FAST8_MIN       INT8_MIN
#   define INT_FAST8_MAX       INT8_MAX
#   define INT_FAST16_MIN     INT16_MIN
#   define INT_FAST16_MAX     INT16_MAX
#   define INT_FAST32_MIN     INT32_MIN
#   define INT_FAST32_MAX     INT32_MAX
#   define INT_FAST64_MIN     INT64_MIN
#   define INT_FAST64_MAX     INT64_MAX
#   define UINT_FAST8_MAX     UINT8_MAX
#   define UINT_FAST16_MAX   UINT16_MAX
#   define UINT_FAST32_MAX   UINT32_MAX
#   define UINT_FAST64_MAX   UINT64_MAX

#   ifdef OPENGSI_USE_64BIT
#    define INTPTR_MIN        INT64_MIN
#    define INTPTR_MAX        INT64_MAX
#    define UINTPTR_MAX      UINT64_MAX
#    define PTRDIFF_MIN       INT64_MIN
#    define PTRDIFF_MAX       INT64_MAX
#    ifndef  SIZE_MAX
#     define SIZE_MAX        UINT64_MAX
#    endif
#   else // OPENGSI_USE_64BIT
#    define INTPTR_MIN        INT32_MIN
#    define INTPTR_MAX        INT32_MAX
#    define UINTPTR_MAX      UINT32_MAX
#    define PTRDIFF_MIN       INT32_MIN
#    define PTRDIFF_MAX       INT32_MAX
#    ifndef  SIZE_MAX
#     define SIZE_MAX        UINT32_MAX
#    endif
#   endif // OPENGSI_USE_64BIT

#   define INTMAX_MIN         INT64_MIN
#   define INTMAX_MAX         INT64_MAX
#   define UINTMAX_MAX       UINT64_MAX

#   define SIG_ATOMIC_MIN       INT_MIN
#   define SIG_ATOMIC_MAX       INT_MAX

#   ifdef OPENGSI_ENABLE_WCHAR
#    define  WINT_MIN                  0
#    define  WINT_MAX         UINT16_MAX

#    ifndef  WCHAR_MIN
#     define WCHAR_MIN                 0
#    endif
#    ifndef  WCHAR_MAX
#     define WCHAR_MAX        UINT16_MAX
#    endif
#   endif // OPENGSI_ENABLE_WCHAR
#  endif  //  __STDC_LIMIT_MACROS

#  if !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS)
#   define INT8_C(c)     c##i8
#   define INT16_C(c)   c##i16
#   define INT32_C(c)   c##i32
#   define INT64_C(c)   c##i64

#   define UINT8_C(c)   c##ui8
#   define UINT16_C(c) c##ui16
#   define UINT32_C(c) c##ui32
#   define UINT64_C(c) c##ui64

#   define INTMAX_C    INT64_C
#   define UINTMAX_C  UINT64_C
#  endif // __STDC_CONSTANT_MACROS
# endif // OPENGSI_USE_MSC

#endif  /* __OPENGSI_COMSCI_MACROS_STDINT_H_FILES_MSC_STDINT_H_ */

