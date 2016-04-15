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
 * File:   loop.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_UTILITIES_LOOP_H_
#define __OPEN_GSI_COMSCI_UTILITIES_LOOP_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
# include "../supports/basic_definition.h"

#define forArray( __index__, __array__ ) \
    for( GsiSize __index__ = 0, index##___size___ = (__array__).size(); \
         __index__ <  index##___size___ ; ++__index__)

#define rforArray( __index__, __array__ ) \
    for( GsiSize __index__ = ((__array__).size() - 1), \
         index##___check___ = GsiSize(-1); \
         index##___check___ != __index__; --__index__)

#define forLength( index, beginIndex, iterLength ) \
    for( GsiSize index(beginIndex), ___localLength(iterLength); \
         index < (beginIndex + ___localLength) ; ++index)

#define rforLength( index, beginIndex, iterLength ) \
    for( GsiSize index = (beginIndex + iterLength - 1), \
         index##___check___  = GsiSize(-1); \
        (index##___check___ != index) && (index >= beginIndex); --index)

#define forRange( index, beginIndex, endIndex ) \
    for( GsiSize index = beginIndex; index < (endIndex) ; ++index)

#define rforRange( index, beginIndex, endIndex ) \
    for( GsiSize index = (endIndex - 1), index##___check___ = GsiSize(-1); \
        (index##___check___ != index) && (index >= beginIndex); --index)

#endif  /* __OPEN_GSI_COMSCI_UTILITIES_LOOP_H_ */

