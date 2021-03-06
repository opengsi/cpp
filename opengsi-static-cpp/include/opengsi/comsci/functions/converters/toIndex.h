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
 * File:   toIndex.h
 * Author: Young-Mook Kang <youngmook@opengsi.org>
 * 
 * Library  : Open General Scientific Interfaces(GSI)
 * Homepage : https://www.opengsi.org
 * Project  : https://github.com/opengsi/cpp
 * License  : LGPL 2.1
 */

#ifndef __OPEN_GSI_COMSCI_FUNCTIONS_CONVERTERS_TOINDEX_H_
#define __OPEN_GSI_COMSCI_FUNCTIONS_CONVERTERS_TOINDEX_H_

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// include files
#include "../../supports/basic_definition.h"

/** @brief toIndex
 *  @file toIndex.h
 *  @author Young-Mook Kang
 */

OPENGSI_BEGIN_FUNC_NAMESPACE

        namespace gsiConvert {

    GsiSize toIndex(GsiIndex theInput, GsiSize theContainerLength) {
        if (theInput < 0) {
            GsiIndex localIndex = (static_cast<GsiIndex> (theContainerLength) + theInput);
            if (localIndex < 0)
                return theContainerLength;
            return static_cast<GsiSize> (localIndex);
        } else
            return static_cast<GsiSize> (theInput);
    }

    template<typename _IndexType, typename _SizeType>
    GsiSize toIndex(const _IndexType &theIndex, const _SizeType &theSize) {
        return toIndex(static_cast<GsiIndex> (theIndex), static_cast<GsiSize> (theSize));
    }
}

OPENGSI_END_FUNC_NAMESPACE

#endif  /* __OPEN_GSI_COMSCI_FUNCTIONS_CONVERTERS_TOINDEX_H_ */

