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
 * File:   gnu.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_COMPILERS_GNU_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_COMPILERS_GNU_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "../opengsi_macro.h"

# ifdef  __GNUC__
#  ifdef __GNUC_PATCHLEVEL__
#   define OPENGSI_GNUC_VER   (  __GNUC__ * 10000     \
                               + __GNUC_MINOR__ * 100 \
                               + __GNUC_PATCHLEVEL__  )
#  else
#   define OPENGSI_GNUC_VER (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
#  endif
#  ifndef  OPENGSI_USE_GNUC
#   define OPENGSI_USE_GNUC OPENGSI_GNUC_VER
#  endif

#  include <bits/c++config.h>
// long long support
#  if defined(_GLIBCXX_USE_LONG_LONG) && (_GLIBCXX_USE_LONG_LONG)
#   ifndef  OPENGSI_ENABLE_LLONG
#    define OPENGSI_ENABLE_LLONG OPENGSI_TRUE
#   endif
#  endif

// wchar_t support
#  if defined(_GLIBCXX_USE_WCHAR_T) && (_GLIBCXX_USE_WCHAR_T)
#   ifndef  OPENGSI_ENABLE_WCHAR
#    define OPENGSI_ENABLE_WCHAR OPENGSI_TRUE
#   endif
#  endif

/*******************************************************************************
 * < stdint.h >
 ******************************************************************************/
#  if defined(_GLIBCXX_HAVE_STDINT_H) && (_GLIBCXX_HAVE_STDINT_H)
#   ifndef  OPENGSI_HAS_STDINT_H
#    define OPENGSI_HAS_STDINT_H OPENGSI_TRUE
#   endif
#   ifndef   OPENGSI_STDINT_H_FILE
#    define  OPENGSI_STDINT_H_FILE <stdint.h>
#   endif // OPENGSI_STDINT_H_FILE
#  endif

/*******************************************************************************
 * < 64bit System >
 ******************************************************************************/
#  if defined(__WORDSIZE) && (__WORDSIZE == 64)
#   ifndef  OPENGSI_USE_64BIT
#    define OPENGSI_USE_64BIT OPENGSI_TRUE
#   endif
#  endif

/*******************************************************************************
 * < WORDSIZE >
 ******************************************************************************/
#  if defined(__WORDSIZE)
#   ifndef  OPENGSI_WORDSIZE
#    define OPENGSI_WORDSIZE __WORDSIZE
#   endif
#  endif

/*******************************************************************************
 * < C++ math functions >
 ******************************************************************************/
#  ifndef  OPENGSI_HAS_STDCPP_MATH_FUNCTIONS
#   define OPENGSI_HAS_STDCPP_MATH_FUNCTIONS OPENGSI_TRUE
#  endif

/*******************************************************************************
 * < Version Check >
 * We don't support GNU C++ prior to version 3.40
 ******************************************************************************/
#  if ((__GNUC__ == 3) && (__GNUC_MINOR__ < 40)) || (__GNUC__ < 3)
#   error "OPEN-GSI don't support G++ prior to version 3.4.0, please reconfigure."
#  endif
# endif

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_COMPILERS_GNU_H_ */
