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
 * File:   msc.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_COMPILERS_MSC_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_COMPILERS_MSC_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "../opengsi_macro.h"

# if defined(_MSC_VER)
#  ifndef  OPENGSI_USE_MSC
#   define OPENGSI_USE_MSC _MSC_VER
#  endif
#  ifndef  OPENGSI_MSC_VER
#   define OPENGSI_MSC_VER OPENGSI_USE_MSC
#  endif
/*******************************************************************************
 * < MS Visual Studio Version Macros >
 ******************************************************************************/
# define OPENGSI_MSC_VER_1    800
# define OPENGSI_MSC_VER_3    900
# define OPENGSI_MSC_VER_4   1000
# define OPENGSI_MSC_VER_5   1100
# define OPENGSI_MSC_VER_6   1200
# define OPENGSI_MSC_VER_7   1300
# define OPENGSI_MSC_VER_7_1 1310
# define OPENGSI_MSC_VER_8   1400
# define OPENGSI_MSC_VER_9   1500
# define OPENGSI_MSC_VER_10  1600
# endif

# if defined(_MFC_VER)
#  ifndef  OPENGSI_USE_MFC
#   define OPENGSI_USE_MFC _MFC_VER
#  endif
#  ifndef  OPENGSI_MFC_VER
#   define OPENGSI_MFC_VER OPENGSI_USE_MFC
#  endif
/*******************************************************************************
 * < MFC Version Macros >
 ******************************************************************************/
# define OPENGSI_MFC_VER_4   0x0400
# define OPENGSI_MFC_VER_4XX 0x0421
# define OPENGSI_MFC_VER_6   0x0600
# define OPENGSI_MFC_VER_7   0x0700
# define OPENGSI_MFC_VER_8   0x0800
# define OPENGSI_MFC_VER_9   0x0900
# define OPENGSI_MFC_VER_10  0x0A00
# endif


# ifdef OPENGSI_USE_MSC
// Begin wchar_t support
#  ifdef _NATIVE_WCHAR_T_DEFINED
#   ifndef  OPENGSI_ENABLE_WCHAR
#    define OPENGSI_ENABLE_WCHAR OPENGSI_TRUE
#   endif
#  endif
// End wchar_t support

// LONGLONG support
#  if (OPENGSI_MSC_VER >= OPENGSI_MSC_VER_7_1) && defined(_MSC_EXTENSIONS)
#   ifndef  OPENGSI_ENABLE_LLONG
#    define OPENGSI_ENABLE_LLONG OPENGSI_TRUE
#   endif
#  endif

// __int64 support
#  if (OPENGSI_MSC_VER >= OPENGSI_MSC_VER_4)
#   ifndef  OPENGSI_HAS_MS_INT64
#    define OPENGSI_HAS_MS_INT64 OPENGSI_TRUE
#   endif
#  endif

/*******************************************************************************
 * < stdint.h >
 ******************************************************************************/
#  ifndef  OPENGSI_HAS_STDINT_H
#   define OPENGSI_HAS_STDINT_H OPENGSI_TRUE
#  endif
#  if (OPENGSI_MSC_VER >= OPENGSI_MSC_VER_10)
#   ifndef   OPENGSI_STDINT_H_FILE
#    define  OPENGSI_STDINT_H_FILE <stdint.h>
#   endif // OPENGSI_STDINT_H_FILE
#  else
#   ifndef   OPENGSI_STDINT_H_FILE
#    define  OPENGSI_STDINT_H_FILE <opengsi/comsci/supports/macros/stdint_h_files/stdint_msc.h>
#   endif // OPENGSI_STDINT_H_FILE
#  endif

/*******************************************************************************
 * < 64bit System >
 ******************************************************************************/
#  ifdef _WIN64
#   ifndef  OPENGSI_USE_64BIT
#    define OPENGSI_USE_64BIT OPENGSI_TRUE
#   endif
#  endif

/*******************************************************************************
 * < WORDSIZE >
 ******************************************************************************/
#  ifdef _WIN64
#   ifndef  OPENGSI_WORDSIZE
#    define OPENGSI_WORDSIZE 64
#   endif
#  elif defined(_WIN32) && !defined(_WIN64)
#   ifndef  OPENGSI_WORDSIZE
#    define OPENGSI_WORDSIZE 32
#   endif
#  endif

/*******************************************************************************
 * < Version Check >
 * We don't support Visual C++ prior to version 7.1
 ******************************************************************************/
#  if (OPENGSI_MSC_VER < OPENGSI_MSC_VER_7_1)
#   error "OPEN-GSI don't support Visual C++ prior to version 7.1, please reconfigure."
#  endif
# endif // OPENGSI_USE_MSC

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_COMPILERS_MSC_H_ */
