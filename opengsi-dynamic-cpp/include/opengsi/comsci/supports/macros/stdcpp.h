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
 * File:   stdcpp.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDCPP_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDCPP_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

# include "opengsi_macro.h"

# define OPENGSI_STDC_1990 199001L
# define OPENGSI_STDC_1994 199409L
# define OPENGSI_STDC_1999 199901L

# if defined(__STDC__)
#  ifndef  OPENGSI_USE_STDC
#   define OPENGSI_USE_STDC OPENGSI_TRUE
#  endif
#  ifdef __STDC_VERSION__
#   ifndef  OPENGSI_STDC_VER
#    define OPENGSI_STDC_VER __STDC_VERSION__
#   endif
#   ifdef   OPENGSI_USE_STDC
#    undef  OPENGSI_USE_STDC
#   endif
#   define  OPENGSI_USE_STDC OPENGSI_STDC_VER
#  endif
# endif

# if defined(__cplusplus)
#  ifndef  OPENGSI_USE_STDCPP
#   define OPENGSI_USE_STDCPP OPENGSI_TRUE
#  endif
# else
#  error "This Compiler is not C++, please reconfigure"
# endif

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_STDCPP_H_ */

