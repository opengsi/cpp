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
 * File:   stdint_size.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDINT_H_FILES_STDINT_SIZE_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDINT_H_FILES_STDINT_SIZE_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
# include <limits.h>

# if (defined(LLONG_MAX)  || defined(LLONG_MIN)     || defined(ULLONG_MAX)     \
   || defined(_LLONG_MAX) || defined(ULONGLONG_MAX) || defined(ULONG_LONG_MAX))\
   ||(defined(_MSC_VER) && (_MSC_VER >= 1310) && defined(_MSC_EXTENSIONS))
#   ifndef  OPENGSI_ENABLE_LLONG
#    define OPENGSI_ENABLE_LLONG 1
#   endif
# endif

# ifdef OPENGSI_ENABLE_LLONG // OPENGSI_ENABLE_LLONG [
#  if defined(LLONG_MAX) && (LLONG_MAX == 9223372036854775807LL )
#   define  OPENGSI_CPP_LLONG_BIT    64
#  else // If the "long long int" type is 128bit,
#   if (LLONG_MAX == 170141183460469231731687303715884105727LL )
#    define OPENGSI_CPP_LLONG_BIT   128
#   else
#    error "This compiler has a wrong value of \"LLONG_MAX\" macro, please watch out."
#   endif
#  endif
# endif

# if   (LONG_MAX == 2147483647L)
#  define   OPENGSI_CPP_LONG_BIT  32
# else
#  if  (LONG_MAX == 9223372036854775807L)
#   define  OPENGSI_CPP_LONG_BIT  64
#  else
#   if (LONG_MAX == 170141183460469231731687303715884105727L)
#    define OPENGSI_CPP_LONG_BIT 128
#   else
#    error "This compiler has a wrong value of \"LONG_MAX\" macro, please watch out."
#   endif
#  endif
# endif

# if    (INT_MAX == 32767)
#  define    OPENGSI_CPP_INT_BIT  16
# else
#  if   (INT_MAX == 2147483647)
#  define    OPENGSI_CPP_INT_BIT  32
#  else
#   if  (INT_MAX == 9223372036854775807)
#    define  OPENGSI_CPP_INT_BIT  64
#   else
#    if (INT_MAX == 170141183460469231731687303715884105727)
#     define OPENGSI_CPP_INT_BIT 128
#    else
#     error "This compiler has a wrong value of \"INT_MAX\" macro, please watch out."
#    endif
#   endif
#  endif
# endif

# if    (SHRT_MAX == 32767)
#  define    OPENGSI_CPP_SHORT_BIT  16
# else
#  if   (SHRT_MAX == 2147483647)
#   define   OPENGSI_CPP_SHORT_BIT  32
#  else
#   if  (SHRT_MAX == 9223372036854775807)
#    define  OPENGSI_CPP_SHORT_BIT  64
#   else
#    if (SHRT_MAX == 170141183460469231731687303715884105727)
#     define OPENGSI_CPP_SHORT_BIT 128
#    else
#     error "This compiler has a wrong value of \"SHRT_MAX\" macro, please watch out."
#    endif
#   endif
#  endif
# endif

# if (defined(OPENGSI_CPP_LLONG_BIT) && (OPENGSI_CPP_LLONG_BIT == 64) )        \
  || (defined(OPENGSI_CPP_LONG_BIT)  && (OPENGSI_CPP_LONG_BIT  == 64) )        \
  || (defined(OPENGSI_CPP_INT_BIT)   && (OPENGSI_CPP_INT_BIT   == 64) )        \
  || (defined(OPENGSI_CPP_SHORT_BIT) && (OPENGSI_CPP_SHORT_BIT == 64) )
#  ifndef  OPENGSI_HAS_INT64
#   define OPENGSI_HAS_INT64 1
#  endif
# endif

# define OPENGSI_CPP_CHAR_BIT CHAR_BIT

# if( defined(__x86_64__)||defined(_M_AMD64 )||defined(__amd64__)||defined(__amd64) \
   || defined(__IA64__  )||defined(__ia64__ )||defined(_M_IA64  )||defined(_WIN64 ) \
   || defined(__s390__  )||defined(__64BIT__)||defined(_M_X64 )                     \
   || defined(_M_ALPHA  )||defined(__alpha__)                                       \
   || defined(__LP64__  )||defined(_LP64    )||(OPENGSI_CPP_LONG_BIT == 64)         \
   ||(defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 8))                     )

#  ifndef  OPENGSI_WORDSIZE
#   define OPENGSI_WORDSIZE  64
#  endif

#  ifndef  OPENGSI_USE_64BIT
#   define OPENGSI_USE_64BIT OPENGSI_WORDSIZE
#  endif

# elif ( ((OPENGSI_CPP_INT_BIT == 32) && (OPENGSI_CPP_LONG_BIT == 32))         \
    ||   defined(_WIN32) ||defined(__i386)||defined(__i386__)                  \
    ||   defined(_M_IX86)||defined(__i686)||defined(__i686__)                  \
    ||  (defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__) == 4)             )
#  ifndef  OPENGSI_WORDSIZE
#   define OPENGSI_WORDSIZE  32
#  endif

#  ifndef  OPENGSI_USE_32BIT
#   define OPENGSI_USE_32BIT OPENGSI_WORDSIZE
#  endif

# else
#  if (OPENGSI_CPP_INT_BIT == 16) && (OPENGSI_CPP_LONG_BIT == 32)
#   ifndef  OPENGSI_WORDSIZE
#    define OPENGSI_WORDSIZE  16
#   endif

#   ifndef  OPENGSI_USE_16BIT
#    define OPENGSI_USE_16BIT OPENGSI_WORDSIZE
#   endif
#  else
#   error "Not support, please watch out."
#  endif
# endif // To Determine 64bit or 32bit

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDINT_H_FILES_STDINT_SIZE_H_ */
