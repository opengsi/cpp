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
 * File:   opengsi_macro.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_SUPPORTS_MACROS_OPENGSI_MACRO_H_
#define __OPEN_GSI_COMSCI_SUPPORTS_MACROS_OPENGSI_MACRO_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

# define __OPENGSI__                      1
# define __OPENGSI_MAJOR__      __OPENGSI__
# define __OPENGSI_MINOR__                0
# define __OPENGSI_PATCHLEVEL__           0
# define OPENGSI_VER   (__OPENGSI_MAJOR__ * 10000 \
                       +__OPENGSI_MINOR__ * 100   \
                       +__OPENGSI_PATCHLEVEL__    )

# define OPENGSI_TRUE               1
# define OPENGSI_FALSE              0

# define OPENGSI_HAS_EXACT_INT8  OPENGSI_TRUE
# define OPENGSI_HAS_EXACT_INT16 OPENGSI_TRUE
# define OPENGSI_HAS_EXACT_INT32 OPENGSI_TRUE
# define OPENGSI_HAS_EXACT_INT64 OPENGSI_TRUE

# define OPENGSI_NAMESPACE opengsi
# define OPENGSI_GUI_NAMESPACE gui 

# ifdef OPENGSI_NAMESPACE
#  define OPENGSI_BEGIN_NAMESPACE namespace OPENGSI_NAMESPACE {
#  define OPENGSI_END_NAMESPACE }
# else
#  define OPENGSI_BEGIN_NAMESPACE
#  define OPENGSI_END_NAMESPACE
#endif

# ifndef OPENGSI_HAS_NO_ROOT_GSI_OBJECTS
#  define OPENGSI_BEGIN_FUNC_NAMESPACE 
#  define OPENGSI_END_FUNC_NAMESPACE   
# else
#  define OPENGSI_BEGIN_FUNC_NAMESPACE OPENGSI_BEGIN_NAMESPACE 
#  define OPENGSI_END_FUNC_NAMESPACE   OPENGSI_END_NAMESPACE 
# endif

#endif  /* __OPEN_GSI_COMSCI_SUPPORTS_MACROS_OPENGSI_MACRO_H_ */