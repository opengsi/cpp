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
 * File:   posix.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_POSIX_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_POSIX_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
#include "os_macro.h"

/** @brief posix
 *  @file posix.h
 *  @author Young-Mook Kang
 */
# ifdef OPENGSI_USE_UNIX

#  include <unistd.h>
#  ifdef _POSIX_VERSION
#   ifndef  OPENGSI_USE_POSIX
#    define OPENGSI_USE_POSIX _POSIX_VERSION
#   endif
#   ifndef  OPENGSI_POSIX_VER
#    define OPENGSI_POSIX_VER _POSIX_VERSION
#   endif
#   define OPENGSI_POSIX_1988  198808L
#   define OPENGSI_POSIX_1990  199009L
#   define OPENGSI_POSIX_1993  199309L
#   define OPENGSI_POSIX_1996  199506L
#   define OPENGSI_POSIX_2001  200112L
#   define OPENGSI_POSIX_2008  200809L
#  endif
#  ifdef _XOPEN_VERSION
#   ifndef  OPENGSI_XOPEN_VER
#    if (_XOPEN_VERSION < 5)
#     ifdef _XOPEN_UNIX
#      define OPENGSI_XOPEN_VER (_XOPEN_VERSION * 100 + 10)
#     else 
#      define OPENGSI_XOPEN_VER (_XOPEN_VERSION * 100)
#     endif
#    else
#     define OPENGSI_XOPEN_VER _XOPEN_VERSION
#    endif
#   endif
#   ifndef  OPENGSI_USE_XOPEN
#    define OPENGSI_USE_XOPEN OPENGSI_XOPEN_VER
#   endif
#   define OPENGSI_XOPEN_1989 300
#   define OPENGSI_XOPEN_1992 400
#   define OPENGSI_XOPEN_1995 410
#   define OPENGSI_XOPEN_1998 500
#   define OPENGSI_XOPEN_2003 600
#   define OPENGSI_XOPEN_2008 700
#  endif
# endif
#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_POSIX_H_ */
